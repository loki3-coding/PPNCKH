# PPNCKH
2019-PPNCKH

There are 2 Project in this repo: Pneunomia & CityChallenge

Pneunomia - use for previous Project (finish in 6/2019).
It contains report, charts and sources running in Kaggle.

CityChallenge - later Project (finish 7/2019). 
It contains C/Cpp sources, dataset and result file. You have to read comment in main.cpp carefully to run it in true way. in data folder, there are 3 subfolders and 2 file:
  + Groundtruth - contains groundtruth files.
  + Prediction  - contains prediction files.
  + IoU - contains average IoU Prediction & GroundTruth.
  + test  - containt test files // after normalize :D 
  + listData.txt  - contains filenames in Groundtruth, IoU & Precdiction.
  + listTest.txt  - contains filenames in test folder.
How to use? 
  + insert file Loc1_1.txt(groundtruth file) + Loc1_1.txt (predict file) -> data/groundtruth + data/predict folder.
  + insert 'Loc1_1.txt' into listData.txt.
  + use terminal, cd /CityChallenge && ./all.
  + Get result data/IoU/Loc1_1.txt.