# LINKED LIST: 
*Complete code is in the end.*
### Conventions:  
1. The struct:  
    ```c
        struct node {
            char data;
            struct node * nextPtr;
        };
    ```
    `nextPtr` is a pointer to next node.
2. Synonyms: *_for easier typing and understanding code_*  
    ```c
    typedef struct node Node;
    typedef Node * NodePtr;
    ```
    - `Node` replaces for `struct node`.  
    - `NodePtr` replaces for `Node *`. 
3. `startPtr` and `sPtr`: refer to pointer which points to the first element of the linked list.  
    ```
    void Insert(NodePtr *sPtr, char insertData);
    Insert(&startPtr, 'a');
    (*sPtr)->data
    ``` 
4. `malloc()` and _*[Warning] incompatible implicit declaration of built-in function 'free'*_  
    - `newPtr = (NodePtr) malloc(sizeof(Node))`  
    - `#inlude <stdlib.h>`  
## INSERT FUNCTION:  
[NOT return anything]

Passing `&startPtr` *(address of the pointer to the first node)* and `(char) insertValue` to be inserted.  
1. Create new node, assign data and `nextPtr` holds `NULL`.  
2. Initialize `previousPtr = NULL` and `currentPtr = *sPtr`.  
3. While `currentPtr != NULL` and `insertValue > currentPtr->data`, assign `previousPtr = currentPtr` and `currentPtr = currentPtr->nextPtr`.  
4.  - If `previousPtr == NULL`, then assign `newPtr->nextPtr = *sPtr` and `*sPtr = newPtr`.  
    - Otherwise, if `previousPtr != NULL` then assign `previous->nextPtr = newPtr` and `newPtr->nextPtr = currentPtr`.  
## DELETE FUNCTION:  
[OPTION return deleted data or FALSE/TRUE to check whether deletion is successful or not]

Passing `&startPtr`and `(char) deleteValue` to be deleted.  
1. If data matchs first node. Free this first node. [Return deleted value].  
2. Otherwise, initialize `previousPtr = *sPtr` and `currentPtr = (*sPtr)->nextPtr`.  
    - While `currentPtr != NULL` and `deleteValue != currentPtr->data`, assign `previousPtr = currentPtr` and `currentPtr  = currentPtr->nextPtr`.  
    - If `currentPtr != NULL`. Assign `previousPtr = currentPtr->nextPtr`. Free `currentPtr` node. [Return deleted value]. Otherwise, if `currentPtr == NULL`, return FALSE, that `deleteValue` is not existed in the list.
## PRINT FUNCTION


## COMPLETE CODE
```c
#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node * nextPtr;
};
typedef struct node Node;
typedef Node * NodePtr;

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

void Print(NodePtr *sPtr){
	if (*sPtr == NULL){
		printf("Empty list.\n");
	} else {
		NodePtr currentPtr = *sPtr;
		while (currentPtr != NULL){
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf(" NULL");
	}
}
int main(){
	NodePtr startPtr = NULL;
	Insert(&startPtr, 'a');
	Insert(&startPtr, 'b');
	Insert(&startPtr, 'c');
	Insert(&startPtr, 'd');
	
	Delete(&startPtr, 'c');
	
	
	Print(&startPtr);
	
	return 0;
}
```
## SORTING LINKED LIST HAS MORE THAN 2 ELEMENTS.
`Insert()` is the function while read input from user it also chooses right position to place that input in linked list. Only sort by name or by age. 
```c
struct node {
    char name[20];
    int age;
    struct node * nextPtr;
}
```
How do I sort by age for a linked list that has sorted by name before?  
*"SON, YOU ONLY NEED TO SWAP THE DATA, DO NOT SWAP THE NODES."*  
Using buble sort, the hardest part is swapping two nodes, do not think about "real swapping", we only need the data place in proper position, right?

