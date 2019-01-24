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
    Push(&stackPtr, item);
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
    printf("The popped value is %c.\n", Pop(&stackPtr));
    ```
3. Queue:
    ```
    item = Dequeue(&headPtr, &tailPtr);
    printf("%c has been dequeue.\n", item);
    ```