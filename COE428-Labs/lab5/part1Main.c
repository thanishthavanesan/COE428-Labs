#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char *pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char *argv[]) {
    int   ch;
    char  tag[100];
    int   i;
    char *poppedch;
    
	//only process characters that are relevent  
    while ((ch = getchar()) != EOF) {
        if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
            continue;

        if (ch == '<') {
            ch = getchar(); //Reads next character

            if (isalpha(ch)) {
                /* read full tag name into tag[] */
                i = 0;
                while (ch != '>' && ch != EOF) {
                    tag[i] = ch;
                    i++;
                    ch = getchar();
                }
                tag[i] = '\0';           //Adds null to add to array as String

                if (ch == EOF) {
                    printf("Incomplete tag\n");  //no >
                    exit(1);
                }

                char *newTag = (char *)malloc(i + 1);
                
                //Stores tag name into newTag
                int k = 0;
                while (tag[k] != '\0') {
                    newTag[k] = tag[k];
                    k++;
                }
                newTag[k] = '\0';
                push(newTag);

            } else if (ch == '/') {
                ch = getchar();

                /* read full tag name into tag[] */
                i = 0;
                while (ch != '>' && ch != EOF) {
                    tag[i] = ch;
                    i++;
                    ch = getchar();
                }
                tag[i] = '\0';

                if (ch == EOF) {
                    printf("Incomplete tag\n");
                    exit(1);
                }

                if (isEmpty()) {
                    printf("Stack is empty\n");
                    exit(1);
                }

                poppedch = pop();
                
                //Checks if one string is longer than the other
                int match = 1;
                int j = 0;
                while (tag[j] != '\0' && poppedch[j] != '\0') {
                    if (poppedch[j] != tag[j]) {
                        match = 0;
                        break;
                    }
                    j++;
                }
                if (tag[j] != '\0' || poppedch[j] != '\0') {
                    match = 0;
                }
                if (!match) {
                    printf("Invalid XML: Tags do not match\n");
                    exit(1);
                }
            }
        }
    }

    if (isEmpty()) {
        printf("Valid XML\n");
    } else {
        printf("Invalid XML\n");
    }

    exit(0);
}




			
