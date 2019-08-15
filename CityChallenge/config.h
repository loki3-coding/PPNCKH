#ifndef __CONFIG_H_
#define __CONFIG_H_

#include "string"
#include "iostream"

using namespace std;

#define MAX_LEN 100000  // max len use for pointer
#define MAX_CLASS 5 // len of classList 
#define SKIP_FRAME 30   //  mantain 1 img / SKIP_FRAME img
#define THRESHOLD 0.7   // IoU >= THRESHOLD  ->  object

const string GT_FOLDER = "./data/groundtruth";    // groundtruth  path
const string PD_FOLDER = "./data/predict";    // prediction folder path
const string RE_FOLDER = "./data/IoU";    // result folder path
const string TEST_FOLDER = "./data/test";    // test folder path

const string FILENAME_PATH = "./data/listData.txt";    // dataset.txt path
const string TESTNAME_PATH = "./data/listTest.txt";    // listTest.txt path
#endif