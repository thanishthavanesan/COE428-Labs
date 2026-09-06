
#include <stdio.h>
static int heap[100];
static int size=0;


/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

//swap two elements in heap
void swap(int i, int j) {
	int temp=heap[i];
	heap[i]=heap[j];
	heap[j]=temp;
}

//Maintain max-heap property
void heapify(int i) {
	int largest=i;
	int left=2*i+1;     //Formula to find left child
	int right=2*i+2;    //Formula to find right child
	
	
	//If left child is bigger than parent
	if (left<size && heap[left]>heap[largest]) {
		largest=left;
	}
	//If right child is bigger than parent
	if (right<size && heap[right]>heap[largest]) {
		largest=right;
	}
	
	//If parent is not the largest, swap and go down the heap
	if (largest !=i) {
		swap(i, largest);
		heapify(largest);
	}
}

//Convert array into heap
void buildHeap() {
	for (int i=(size/2)-1; i>=0; i--) {
		heapify(i);
	}
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete() {
	if (size ==0) {
		return -1;
	}
	
	int root= heap[0];        //Max value
	heap[0]=heap[size -1];    //Switch last number with root
	heap[size-1]=0;
	size=size-1;
	
	heapify(0);
	
	return root; 
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add) {
	if (size==100) {
		fprintf(stderr, "Error: Heap is full\n");
		return;
	}
	
	heap[size]=thing2add;
	size=size+1;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;
}


void printXML(int i) {
	if (i<size) {
		printf("<node id=\"%d\">", heap[i]);
		printXML(2*i+1); //Print left child
		printXML(2*i+2); //print right child
		printf("</node>");
	}
}


