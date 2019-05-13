#ifndef RANKALGORITHM_H
#define RANKALGORITHM_H

#include <iostream>

class RankAlgorithm
{
public:
    RankAlgorithm();
    void swap(int* a, int* b);
    int partition(int arr[], int low, int high);
    void quickSort(int arr[], int low, int high);
    void printArray(int arr[], int size);
};

#endif // RANKALGORITHM_H
