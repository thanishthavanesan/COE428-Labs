void mySort(int d[], unsigned int n)
{
  /* Insertion sort method */
	int key;                  //Temporary stoage for array
	int i;
	int j;
	
	for(i=1; i<n; i++) {    
		key=d[i];           //Temporary storage is instance array
		j=i-1;
		
		while (j>=0 && d[j]>key) {
		  d[j+1]=d[j];
		  j=j-1;
	  }
	  d[j+1]=key;
  }
		  		
}
