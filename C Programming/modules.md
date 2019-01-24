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