#ifndef __CONFIG_H_
#define __CONFIG_H_

#include "string"
#include "iostream"

using namespace std;

#define MAX_LEN 100000
#define MAX_CLASS 5
#define SKIP_FRAME 30

const string GT_FOLDER = "./data/groundtruth";    // groundtruth  path
const string PD_FOLDER = "./data/predict";    // prediction folder path
const string RE_FOLDER = "./data/IoU";    // result folder path
const string TEST_FOLDER = "./data/test";    // test folder path

const string FILENAME_PATH = "./data/listData.txt";    // dataset.txt path
const string TESTNAME_PATH = "./data/listTest.txt";    // listTest.txt path
#endif