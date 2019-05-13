#include "rankalgorithm.h"

RankAlgorithm::RankAlgorithm()
{

}

void RankAlgorithm::swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int RankAlgorithm::partition(int arr[], int low, int high){
    int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high- 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
}
void RankAlgorithm::quickSort(int arr[], int low, int high){
    if (low < high){
          int pi = partition(arr, low, high);
          quickSort(arr, low, pi - 1);
          quickSort(arr, pi + 1, high);
      }
}

void RankAlgorithm::printArray(int arr[], int size){
    int i;
     for (i=0; i < size; i++)
         printf("%d ", arr[i]);
     printf("n");
}

/*
Usage Example

  int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: n");
    printArray(arr, n);
    return 0;

*/
