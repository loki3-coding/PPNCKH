#ifndef __SORTLIST_H_
#define __SORTLIST_H_

#include "algorithm"
#include "config.h"

// sort ListData
void sortList(int **Data, const int &lenData);

// comparision of listData
int compareListMember(const void *a, const void *b);

#endif