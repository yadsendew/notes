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
