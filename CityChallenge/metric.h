#ifndef __METRIC_H_
#define __METRIC_H_

#include "iostream"
#include "string"
#include "fstream"
#include "algorithm"

#include "sortList.h"
#include "config.h"
#include "lib.h"

using namespace std;

class Metric{
    private:
        float *IoU; // matrix of IoU
        int **listGT;   // list of Ground truth
        int lenListGT;  // length of listGT
        int **listPD;   // list of prediction
        int lenListPD;  // lenght of listPD
        int *checkPointGT; // list of checkpoint gt
        int lenCheckPGT;
        int *checkPointPD; // list of checkpoint pd  
        int lenCheckPPD;
    public:
    // construction
    Metric(const string &gt_path, const string &pd_path);

    // Get IoU each Frame
    float getIoUOneFrame(const int &frame);

    // Get IoU all Frames
    float getIoUAllFrames();

    // destruction
    ~Metric();
};

#endif