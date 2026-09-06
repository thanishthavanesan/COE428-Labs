Comments:

Everything worked as intended. sortMain and SortMain2 worked correctly. Although, when executing the new sortMain2, \testSort2 was used instead of \testSort.



Questions:

1. Suppose you were given an object module (with no access to source code) that sorted an array of integers very efficiently. However, the sort function in the object module must be invoked with the following signature: betterSort(int data[], first, last); where the array to sort is data and the parameters first and last give the indices of the portion of the array that is to be sorted. How could you write a mySort() function with the signature used in this lab that could exploit the better sorting function in the supplied object module?

With the signature used in this lab, mySort() can exploit the better sorting function by setting the 1st index of the array to 0, and the index of the last element to n-1. This is done because betterSort has 3 parameters, including the array, the first element, and the last element. The 1st index always starts at 0, and the last element is at index n-1. Written down, it would look like:

mySort(int data[ ], unsigned int n) {

	betterSort(data, 0, n-1) ;
}
