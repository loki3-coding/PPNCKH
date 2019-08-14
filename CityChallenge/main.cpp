#include "config.h"
#include "lib.h"
#include "metric.h"

using namespace std;

int main(){
    // get filename
    ifstream fi(FILENAME_PATH);
    string filename;
    while (getline(fi, filename)) { 
        // create path
        string pathGTFile = GT_FOLDER + '/' + filename; // groundtruth file name
        string pathPDFile = PD_FOLDER + '/' + filename; // prediction file name
        string pathREFile = RE_FOLDER + '/' + filename; // destination file name
        // calcIoU   
        normalizeFileGT(pathGTFile);
        Metric example(pathGTFile, pathGTFile);
        // write
        ofstream fo(pathREFile);
        fo << "Average IoU = " << example.getIoUAllFrames() << endl;
        fo.close();
    }
    fi.close();
    return 0;
}
