```c
int main(){
	NodePtr headPtr = NULL;
	NodePtr tailPtr = NULL;
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
					printf("Enter the value: "); scanf(" %c", &item);
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
## Case 1:
1. Linked list:  
        `Insert(&headPtr, item);`
2. Stack:  
        ``
3. Queue:  
        `Enqueue(&headPtr, &tailPtr, item);`
## Case 2:
1. Linked list	
    ```
    if (Delete(&headPtr, item) != '\0'){
        printf("%c is deleted.\n", item);
    } else printf("%c is not existed in the list.\n");
    ```
2. 
3. Queue:
    ```
    item = Dequeue(&headPtr, &tailPtr);
    printf("%c has been dequeue.\n", item);
    ```