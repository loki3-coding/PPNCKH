#ifndef __LIB_H_
#define __LIB_H_

#include "fstream"
#include "iostream"
#include "algorithm"

using namespace std;

// count lines of file from path
int countLinesFile(const string &path);

// get all input of file from path
int **getInputFile(const string &path, int &len);

// getCheckPoints from listData
int *getCheckPoints(int **Data, const int &lenData, int &lenCheckPoints);

// get IoU of predict & groundtruth
float getIoU(int *listA, int *listB);

// normalize file groundTruth
void normalizeFileGT(const string &path);

#endif