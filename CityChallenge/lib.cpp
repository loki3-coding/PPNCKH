#include "lib.h"
#include "config.h"

using namespace std;

// count lines of file
int countLinesFile(const string &path){
    ifstream fi(path);
    if (!fi){
        cout << "can not find " << path << endl;
        return -1;
    }
    // count
    int res = 0;
    string line;
    while (getline(fi, line))
        res++;

    fi.close();
    return res;
}

int **getInputFile(const string &path, int &len){
    /*
    use: get all data from file in format [[frame, xmin, ymin, xmax, ymax],...]
    input:
        path    -   string
            path of file containing data
        len     -   int
            len of 'list' data returned below
    output:
        list    -   int**
            data returned in format [[frame, xmin, ymin, xmax, ymax],...]
            has length = 'len' above
    */

    ifstream fi(path);
    if (!fi){
        cout << "can not find " << path << endl;
        return NULL;
    }
    // Get len of file
    int maxLen = (countLinesFile(path));
    // cout << "maxLen =" << maxLen << endl;

    // Create list containt [frame, xmin, ymin, xmax, ymax]
    int **list = new int*[maxLen];
    for (int i = 0; i < maxLen; i++)
        list[i] = new int[MAX_CLASS];
    
    for (int i = 0; i < maxLen; i++) {
        for (int j = 0; j < MAX_CLASS; j++) {
            fi >> list[i][j];
            // cout << list[i][j] << " ";  // testing
        }
        // cout << endl;    // testing
    }
    fi.close();
    len = maxLen;
    return list;
}


int *getCheckPoints(int **Data, const int &lenData, int &lenCheckPoints){
    /*
    use: create and return list of CheckPoints of data. CheckPoint give 
        first position each frame in data.
    input:
        Data    -   int**
            data which we must get CheckPoints from
        lenDat  -   int
            length of Data
        lenCheckPoints   -   &int
            length of List of CheckPoint returned below
        SKIP_FRAME   -   int
            get 1 checkPoint of (1 frame) / (SKIP_FRAME frame),
            usually frame at k*SKIP_FRAME. This defines in config.h
    output:
        res     -   int*
            list of checkPoints    
    */

    lenCheckPoints = Data[lenData-1][0]/SKIP_FRAME + 2;
    int *res = new int[lenCheckPoints];
    int p = 0;
    res[0] = 0;
    for (int i = 1; i < lenData; i++)
        if (Data[i][0] != Data[i-1][0]){
            p++;
            res[p] = i;
        }
    res[++p] = lenData;
    return res;
}

float getIoU(int *boxA, int *boxB){
    /*
    use: get intersection over union of boxA and boxB
    input:
        boxA    -   int*
            type [frame, xmin, ymin, xmax, ymax], element of frames.
        boxB    -   int*
            type [frame, xmin, ymin, xmax, ymax], element of frames.
    output:
        iou     -   float
            IoU of rectangleA and B
    */
    int y_topright = min(boxA[4], boxB[4]);
    int x_topright = min(boxA[3], boxB[3]);
    int y_botleft  = max(boxA[2], boxB[2]);
    int x_botleft  = max(boxA[1], boxB[1]);

    int inter = max(0, x_topright - x_botleft) * max(0, y_topright - y_botleft);
    int S_recA =  max(0, boxA[3] - boxA[1]) * max(0, boxA[4] - boxA[2]);
    int S_recB =  max(0, boxB[3] - boxB[1]) * max(0, boxB[4] - boxB[2]);
    float iou = inter / (1.0*S_recA + S_recB - inter);
    return iou;
}

void normalizeFileGT(const string &path){
    /*
    use: normalize Data in GroundTruth file, esier for solving in another problems. 
        We just input Data of video including [[frame, xmin, ymin, xmax, ymax],...],
        mantain frame which mod SKIP_FRAME = 0. After all, rewrite GroundTruth file.
    input:  
        path    -   string
            path to GroundTruth file.
        SKIP_FRAME  -   int
            get 1 checkPoint of (1 frame) / (SKIP_FRAME frame), usually frame at 
            k*SKIP_FRAME. This defines in config.h
    output: nothing.
    */
    // Get list from file
    int lenFile = countLinesFile(path);
    int **list = getInputFile(path, lenFile);
    // create newList which use instead for list lately
    int **newList = new int*[lenFile];
    for (int i = 0; i < lenFile; i++)
        newList[i] = new int[MAX_CLASS];
    // normalize
    int lenNewList = 0;
    for (int i = 0; i < lenFile; i++){
        if (list[i][0] % SKIP_FRAME == 0){
            newList[lenNewList][0] = list[i][0];
            for (int j = 1; j < MAX_CLASS; j++)
                newList[lenNewList][j] = list[i][j]; 
            lenNewList++;
        }
    }
    // save new file Groundtruth
    ofstream fo(path);
    for (int i = 0; i < lenNewList; i++){
        for (int j = 0; j < MAX_CLASS; j++)
            fo << newList[i][j] << " ";
        fo << endl;
    }
    fo.close();
    // delete pointer
    for (int i = 0; i < lenFile; i++)
        delete []newList[i];
    delete []newList;
}