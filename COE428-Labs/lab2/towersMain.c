#include <stdlib.h>
#include "towers.h"
#include <stdio.h>


int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    
    if (argc==1) {
	}
	
    else if (argc ==2) {
        n = atoi(argv[1]);
        if (n<0) {
		fprintf(stderr, "number of disks should be positive");
		exit(1);	
    }
}
    
    else if (argc=4) {
		n = atoi(argv[1]);
		from = atoi(argv[2]);
		dest = atoi(argv[3]);
		
		if (n<0) {
		fprintf(stderr, "number of disks should be positive");
		exit(1);
	}
		
		if (from<1 || from>3 || dest<1|| dest>3 || from==dest) {
			fprintf(stderr, "Incorrect input");
			exit(1);
		}
	}
	
	else {
	      fprintf(stderr, "Invaid number of argument");
          exit(1);
	  }
	  
    towers(n, from, dest);
    exit(0);
}

