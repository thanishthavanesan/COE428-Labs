#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

//heap functions:
extern void addHeap(int);
extern void buildHeap();
extern int heapDelete();
extern int heapSize();
extern void printXML(int);


int main(int argc, char * argv[]) {
  int value;
  int deletedVal;
  int n;
  
  //Read input and add to heap
  while (scanf("%d", &value) != EOF) {
	 fprintf(stderr, "READING INPUT: %d\n", value);
     addHeap(value);
     n++;
 }
 
 //Build heap
 buildHeap();
 
 //Print XML
 printf("Heap as XML:\n");
 printXML(0);
 printf("\n");
 
 
//Delete from heap(descending + push to stack
 printf("Descending order:\n");
 while (heapSize() > 0) {
	 int deleted=heapDelete();
	 printf("%d ", deleted);
	 push(deleted);
 }
 printf("\n");
 
 //pop from stack (ascending)
 printf("Ascending order:\n");
 while(!isEmpty()) {
	 deletedVal=pop();
	 printf("%d ", deletedVal);
 }
 printf("\n");
  
 exit(0);
}
