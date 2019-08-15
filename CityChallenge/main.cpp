#include "config.h"
#include "lib.h"
#include "metric.h"

using namespace std;

// Use should read comment to avoid some problems.
int main(){
    string filename;
    
    // Get IoU each file prediction.
    // get filename
    ifstream fi(FILENAME_PATH);
    while (getline(fi, filename)) { 
        // create path
        string pathGTFile = GT_FOLDER + '/' + filename; // groundtruth file name
        string pathPDFile = PD_FOLDER + '/' + filename; // prediction file name
        string pathREFile = RE_FOLDER + '/' + filename; // destination file name
        
        // If file has not been normalized, use below. If no, delete it
        // normalizeFileGT(pathGTFile);
        // normalizeFilePD(pathPDFile);
        
        // calcIoU  
        Metric *example = new Metric(pathGTFile, pathPDFile);
        // write
        ofstream fo(pathREFile);
        fo << "Average IoU = " << example->getIoUAllFrames() << endl;
        example->~Metric();
        fo.close();
    }
    fi.close();

    // If testResult has not been normalized, use below. If no, delete it.
    // Normalize testResult data
    // ifstream fi(TESTNAME_PATH);
    // while (getline(fi, filename)) {
    //     string pathTestName = TEST_FOLDER + '/' + filename;
    //     normalizeFilePD(pathTestName);
    // }
    // fi.close();
    // return 0;
}
