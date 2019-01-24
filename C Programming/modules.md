## THE FUNCTIONS
1. Linked List:  
	- Insert:  need `&startPtr`
		```c
		void Insert(NodePtr *sPtr, char chr){
			NodePtr newPtr;
			
			newPtr = (NodePtr) malloc( sizeof( Node ) );
			newPtr->data = chr;
			newPtr->nextPtr = NULL;
			
			NodePtr previousPtr = NULL;
			NodePtr currentPtr = *sPtr;
			
			while (currentPtr != NULL && chr > currentPtr->data){
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
			if (previousPtr == NULL){
				newPtr->nextPtr = (*sPtr);
				*sPtr = newPtr;
			} else {
				previousPtr->nextPtr = newPtr;
				newPtr->nextPtr = currentPtr;
			}
		}
		```
	- Delete: return delete value, if not existed return "\0"
		```c
		char Delete(NodePtr *sPtr, char chr){
			if (chr == (*sPtr)->data) {
				NodePtr freePtr = *sPtr;
				*sPtr = (*sPtr)->nextPtr;
				free(freePtr);
				return chr;
			}
			else {
				NodePtr previousPtr = *sPtr;
				NodePtr currentPtr = (*sPtr)->nextPtr;
				while (currentPtr != NULL && chr != currentPtr->data){
					previousPtr = currentPtr;
					currentPtr = currentPtr->nextPtr;
				}
				if (currentPtr != NULL){
					previousPtr->nextPtr = currentPtr->nextPtr;
					NodePtr freePtr = currentPtr;
					free(freePtr);
					return chr;
				} else return '\0';
			}
		}
		```
2. Stack:  need `&stackPtr` 
	- Push:  
		```c
		void Push(NodePtr *topPtr, char value){
			NodePtr newPtr = (NodePtr) malloc(sizeof(Node));
			if (newPtr != NULL){
				newPtr->data = value;
				newPtr->nextPtr = *topPtr;
				*topPtr = newPtr;
			} else {
				printf("%c not inserted. No memory avaible.\n", value);
			}
		}
		```
	- Pop:  
		```c
		int Pop(NodePtr *topPtr){
			NodePtr freePtr = *topPtr;
			char popValue = (*topPtr)->data;
			*topPtr = (*topPtr)->nextPtr;
			free(freePtr);
			return popValue;
		}
		```
3. Queue: need `&headPtr` and `&tailPtr`
	- Enqueue:  
		```c
		void Enqueue(NodePtr *headPtr, NodePtr * tailPtr, char value){
			NodePtr newPtr = (NodePtr) malloc(sizeof(Node));
			if (newPtr != NULL){
				newPtr->data = value;
				newPtr->nextPtr = NULL;
				// if queue is empty
				if (*headPtr == NULL){
					*headPtr = newPtr;
				} else {
					(*tailPtr)->nextPtr = newPtr;
				}
				*tailPtr = newPtr;
			} else printf("Not enough memory!\n");
		}	
		```
	- Dequeue: return dequeued value.
		```c
		char Dequeue(NodePtr *headPtr, NodePtr *tailPtr){
			char value = (*headPtr)->data;
			NodePtr freePtr = *headPtr;
			*headPtr = (*headPtr)->nextPtr;
			if (isEmpty(&headPtr)) *tailPtr = NULL;
			free(freePtr);
			return value;
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