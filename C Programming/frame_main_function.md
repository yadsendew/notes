```c
#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node * nextPtr;
};
typedef struct node Node;
typedef Node * NodePtr;

void Instruction(){
	printf("Enter your choice:\n"
	"	1 to add an item to the queue\n"
	"	2 to remove an item from the queue\n"
	"	3 to end\n"
	);
}
int isEmpty(NodePtr startPtr/stackPtr/headPtr){
	return headPtr == NULL;
}
void Print(NodePtr currentPtr){
	if (currentPtr == NULL){
		printf("Queue is empty.\n\n");
	} else {
		printf("Queue: \n");
		
		while (currentPtr != NULL){
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n");
	}
}
/*  	1. Linked List 
	2. Stack
	3. Queue	*/
int main(){
	/* Declare HEAD TAIL */
	int choice = 0;
	char item;
	
	Instruction();
	printf("> "); scanf("%d", &choice);
	
	while (choice != 3){
		switch (choice){
			case 1:
				printf("Enter the value: "); scanf(" %c", &item);
				/* Case 1 */
				Print(headPtr);
				break;
			case 2:
				if ( !isEmpty(headPtr)){
				    /* Case 2 */	
				}
				Print(headPtr);
				break;
			default:
				printf("Your choice must be 1, 2 or 3!\n");
				Instruction();
				break;
		}
		printf("> "); scanf("%d", &choice);
	}
	printf("End of run.\n");
	return 0;
}
```
## Declare HEAD TAIL:  
1. `NodePtr startPtr = NULL;`
2. `NodePtr stackPtr = NULL;`
3. `NodePtr headPtr = NULL; NodePtr tailPtr = NULL;`
## Case 1:
1. Linked list:  
    ```
    Insert(&startPtr, item);
    ```
2. Stack:  
    ```
    Push(&stackPtr, value)
    ```
3. Queue:  
    ```
    Enqueue(&headPtr, &tailPtr, item);
    ```
## Case 2:
1. Linked list	
    ```
    printf("Enter the value: "); scanf(" %c", &item);
    if (Delete(&startPtr, item) != '\0'){
        printf("%c is deleted.\n", item);
    } else printf("%c is not existed in the list.\n");
    ```
2. Stack:  
    ```
    printf("The popped value is %d.\n", Pop(&stackPtr));
    ```
3. Queue:
    ```
    printf("Enter the value: "); scanf(" %c", &item);
    item = Dequeue(&headPtr, &tailPtr);
    printf("%c has been dequeue.\n", item);
    ```