#include "mySort.h"

#define MAX_SIZE_N_TO_SORT 100000

static void merge(int array[], unsigned int first, unsigned int mid, unsigned int last) {

    int leftLength = mid - first + 1;
    int rightLength = last - mid;
    
    int L[leftLength];
    int R[rightLength];

    int i, j, k;

    for (i = 0; i < leftLength; i++) {
        myCopy(&array[first + i], &L[i]);
    }

    for (j = 0; j < rightLength; j++) {
        myCopy(&array[mid + 1 + j], &R[j]);
    }

    i = 0;
    j = 0;
    k = first;

    while (i < leftLength && j < rightLength) {
        if (myCompare(L[i], R[j]) <= 0) {
            myCopy(&L[i], &array[k]);
            i++;
        } else {
            myCopy(&R[j], &array[k]);
            j++;
        }
        k++;
    }

    while (i < leftLength) {
        myCopy(&L[i], &array[k]);
        i++;
        k++;
    }

    while (j < rightLength) {
        myCopy(&R[j], &array[k]);
        j++;
        k++;
    }
}

void mySort(int array[], unsigned int first, unsigned int last)
{
    unsigned int mid;

    if (first < last) {

        mid = first + (last - first) / 2;
        mySort(array, first, mid);
        mySort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}

