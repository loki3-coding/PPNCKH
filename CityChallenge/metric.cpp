#ifndef __METRIC_H_
#include "metric.h"
#endif

/**
 * This is private values of class Metric 
    float *IoU; // matrix of IoU
    int **listGT;   // list of Ground truth
    int lenListGT;
    int **listPD;   // list of prediction
    int lenListPD;
    int *checkPointGT; // list of checkpoint gt
    int lenCheckPGT;
    int *checkPointPD; // list of checkpoint pd   
    int lenCheckPPD;
**/

Metric::Metric(const string &gt_path, const string &pd_path){
    /*
    use: input data from file, sort them and create IoU each predicted bounding 
        box.
    input:  
        gt_path -   string
            path of groundtruth file.
        pd_path -   string
            path of prediction file.
    output: nothing
    */
    // printf("----------get input-------------------\n");
    this->listGT = getInputFile(gt_path, this->lenListGT);
    this->listPD = getInputFile(pd_path, this->lenListPD);
    
    // printf("----------sort------------------------\n");
    sortList(this->listGT, this->lenListGT);
    sortList(this->listPD, this->lenListPD);
    
    // printf("----------get checkpoint---------------\n");
    this->checkPointGT = getCheckPoints(this->listGT, this->lenListGT, this->lenCheckPGT);
    this->checkPointPD = getCheckPoints(this->listPD, this->lenListPD, this->lenCheckPPD);

    // printf("----------IoU--------------------------\n");
    this->IoU = new float[this->lenListPD];
    int frameBegin = 0;
    int frameEnd = this->lenCheckPPD-1;
    // Go each frame i of Predict & frame i of Ground truth
    // Calc maxIoU of each boundingBox
    for (int framei = frameBegin; framei < frameEnd; framei++){
        for (int i = this->checkPointPD[framei]; i < this->checkPointPD[framei+1]; i++){
            this->IoU[i] = 0;
            for (int j = this->checkPointGT[framei]; j < this->checkPointGT[framei+1]; j++){
                // testing frame Predict must = frame GroundTruth
                if (listGT[j][0] != listPD[i][0]){
                    printf("frame PD %d != %d frame GT\n", listPD[i][0],listGT[j][0]);
                }
                // Calc iou
                float iou = getIoU(this->listPD[i], this->listGT[j]);
                if (iou > this->IoU[i])
                    this->IoU[i] = iou;
            }    
        }
    }

    // If you want to testing your config, just use source below.
    // I tested carefully so you can believe me. 

    // printf("-----------test IoU----------------------\n");
    // for (int i = 0; i < this->lenListPD; i++){
    //     printf(" frame %d, max(IoU) = %f\n", listPD[i][0], IoU[i]);
    // }

    // printf("-----------test List----------------------\n")
    // for (int i = 0; i < this->lenListPD; i++){
    //     for (int j = 0; j < MAX_CLASS; j++)
    //         cout << this->listPD[i][j] << " ";
    //     cout << endl;
    // }

    // printf("----------test checkpoint-----------------\n");
    // printf("groundtruth\n");
    // printf("lenPD = %d\n", lenListGT);
    // printf("lenCP = %d\n", lenCheckPGT);
    // for (int i = 0; i < lenCheckPGT; i++){
    //     printf("i = %d, checkP = %d\n", i, checkPointGT[i]);
    // }
    // printf("predict\n");
    // printf("lenPD = %d\n", lenListPD);
    // printf("lenCP = %d\n", lenCheckPPD);
    // for (int i = 0; i < lenCheckPPD; i++){
    //     printf("i = %d, checkP = %d\n", i, checkPointPD[i]);
    // }
}

// Just destructor
Metric::~Metric(){
    for (int i = 0; i < this->lenListGT; i++)
        delete []this->listGT[i];
    for (int i = 0; i < this->lenListPD; i++)
        delete []this->listPD[i];
    delete []this->listGT;
    delete []this->listPD;
    delete []this->checkPointGT;
    delete []this->checkPointPD;
}

// average IoU of one frame
float Metric::getIoUOneFrame(const int &frame){
    int posBegin = this->checkPointPD[frame/SKIP_FRAME];
    int posEnd = this->checkPointPD[frame/SKIP_FRAME + 1];
    float sumIoU = 0;
    for (int i = posBegin; i < posEnd; i++)
        sumIoU += this->IoU[i];
    return sumIoU/(posEnd-posBegin);
}

// average IoU all video
float Metric::getIoUAllFrames(){
    int posBegin = 0;
    int posEnd = this->checkPointPD[this->lenCheckPPD-1];
    float sumIoU = 0;
    for (int i = posBegin; i < posEnd; i++)
        sumIoU += this->IoU[i];
    return sumIoU/(posEnd-posBegin);
}