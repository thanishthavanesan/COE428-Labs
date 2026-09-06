#include <stdlib.h>
#include <stdio.h>

#define MAX_States 8

                        /* functions used */

/* nextState: Returns next state based on current state and input */
char nextState(char states[][3], char current, char input) {
	int currentIndex=-1;
	
	for (int i=0; i<MAX_States; i++) {
		if(states[i][0]== current) {
			currentIndex=i;
			break;
		}
	}
	
	if (currentIndex== -1) {
		printf("Error:Current state not found\n");
		return current;
	}
		
	if (input== '0') {
		return states[currentIndex][1];  //Return next state for input 0
	}
	else if (input== '1') {
		return states[currentIndex][2]; //Return next state for input 1
	}
	else  {
		printf("Invalid input\n");
	}

	return current;
}


/* printS: Prints the current FSM table ignoring deleted states */				
void printS(char states[][3]) {
	for (int i=0; i<MAX_States; i++) {
		if (states[i][0] != '-') {   
			printf("%c %c %c\n", states[i][0], states[i][1],states[i][2]);
		}
	 }
}

/* changeState: Updates the transition of a given state based on command */								
void changeState(char command[10], char states[][3], char currentState) {
	char input=command[2];
	char newState= command[4];
	
	  for (int i=0; i<MAX_States; i++) {
		  if (states[i][0]==currentState && states[i][0] !='-') {
			  if (input=='0') {              //Modify transition for input 0
				  states[i][1]=newState;
			  }
			  if (input=='1') {              //Modify transition for input 1
				  states[i][2]=newState;
			  }
			  break;
		  }
	  }
  }
 
 /* deleteStates: Deletes all garbage states from FSM  */
 void deleteStates(char states[][3], int numStates, char garbageList[MAX_States]) {
	 int count=0;
	 
	  for (int i=0; i<MAX_States; i++) {
		  for (int j=0; j<MAX_States; j++) {
			  if (garbageList[i]==states[j][0]) {
				  printf("Deleted: %c\n", states[j][0]);
				  
				  states[j][0]= '-';
				  states[j][1]= '-';
				  states[j][2]= '-';
				  count++;
			  }
		  }
	  }
	  numStates-=count;
	  
	  if (count==0) {
		  printf("No states detected\n");
	  }
  }
  
 /* deleteState: Deletes a specific garbage state from FSM */
void deleteState(char states[][3], int numStates, char targetState, char garbageList[MAX_States]) {
	 int count=0;
	 
	  for (int i=0; i<MAX_States; i++) {
		  if (garbageList[i]==targetState) {
			for (int j=0; j<MAX_States; j++) {
				if (states[j][0]== targetState) {
				  
					states[j][0]= '-';
					states[j][1]= '-';
					states[j][2]= '-';
				  
					printf("Deleted: %c\n", targetState);
					count++;
				}
			}
		}
	}
	numStates-=count;
	  
	if (count==0) {
		printf("State not deleted\n");
	  }
  }
	  
 /* findUnreachableStates: Finds unreachable or garbage states in FSM */
void findUnreachableStates(char states[][3], int numStates, char garbageList[MAX_States]) {
	
	for(int i=0; i<MAX_States; i++) {
		garbageList[i]='\0';
	}
	
	int count=0;     //Number of garbage states
	int refCount=0;  //number of transitions pointing to state
	int g=0;         //position in garbageList
	
	//go through FSM, and if both next states are the same, mark that state as garbage(Self-loop)
	for(int i=0; i<MAX_States; i++) {
		if (states[i][1]==states[i][0] && states[i][2]==states[i][0]) {
			garbageList[g]=states[i][0];
			g++;
			count++;			
		}
	}
	//Detect states that are never reached by any transition
	for(int i=0; i<MAX_States; i++) {  //goes through each state and checks transitions
		for (int j=0;j<MAX_States; j++) {
			if(states[i][0]==states[j][1] || states[i][0]==states[j][2]) {
				refCount++;
			}
		}
		
		if(refCount==0) {
			garbageList[g]= states[i][0];
			g++;
			count++;
		}
		refCount=0; //Reset count for next state
	}
	//Print results
	if (count==0) {
		printf("No garbage detected \n");
	}
	else {
		for(int i=0; i<MAX_States; i++) {
			if(garbageList[i]>='A' && garbageList[i]<='H') {
				printf("Garbage: %c\n", garbageList[i]);
			}
		}
	}
}

		

int main(int argc, char * argv[]) {
	char states[MAX_States][3]= {
		{'A','F','H'},
		{'B','B','E'},
		{'C','D','A'},
		{'D','A','B'},
		{'E','H','C'},
		{'F','G','D'},
		{'G','B','F'},
		{'H','C','G'}
	};
	
	char garbageList[MAX_States]={'\0'}; //Initialize as null array
	char currentState='E';
	char command[10];
	int numStates=8;
	
	printf("Starting state: %c\n", currentState);
	
	while(1) {
		printf("Enter command: ");
		fgets(command, sizeof(command), stdin);  //Use fgets to read input by user
		
		if(command[0]== '0' || command[0]== '1') {
			currentState=nextState(states, currentState, command[0]);
			printf("Current State: %c\n", currentState);
		}
		
		else if(command[0]== 'p') {
			printS(states);
		}
		
		else if(command[0]== 'c') {
			changeState(command,states, currentState);
		}

		else if(command[0]== 'g') {
			findUnreachableStates(states, numStates, garbageList);
		}
		
		else if(command[0]== 'd') {
			
			if (command[1]=='\n') {
				deleteStates(states, numStates, garbageList);
			}
			else {
				deleteState(states, numStates, command[2], garbageList);
			}
			
		/*Check if currentState still exists when deleted*/	
		int found=0;
		
		for(int i=0; i<MAX_States; i++) {
			if(states[i][0]==currentState) {
				found=1;
				break;
			}
		}
		if(!found) {
			currentState= states[0][0];
			printf("CurrentState is reset to %c\n", currentState);
		}
	}
		
		else if(command[0]== 'e') {
			exit(0);
		}
		
		else {
			printf("Invalid command\n");
		}
	}
	return 0;
}
		
		
			
				
		
		

			
		
		
	
  
