#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
    unsigned int i;
    int j;
    int key;

    for (i = first + 1; i <= last; i++) {
        myCopy(&array[i], &key);
        j = i - 1;

        while (j >= (int)first &&
               myCompare(array[j], key) > 0) {
            mySwap(&array[j], &array[j + 1]);
            j--;
        }
    }
}





