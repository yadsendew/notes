# Print reverse order of a sortted list. 
```c
CurrentPtr = startPtr
NodePtr startReversePtr
While currentPtr not NULL
         Push(&startReversePtr, currentPtr->data);
         CurentPtr = currentPtr->nẽtPtr;
}
Print(startReversePtr);
```
# Sort a sorted list
## A. Keep old list. Swap data. 
```c
Int swapped;
Do {
     Swapped = 0;
     previousPtr = first node;
     CurrentPtr = second node;
     While (currentPtr != null)
     {
        If (previous->data > current->data)
        {
          swap();
          swapped = 1;
        }
        previous = current
        Current = current->nextPtr
     }
}
CurrentPtr = startPtr
NodePtr startReversePtr
While currentPtr not NULL
         Push(&startReversePtr, currentPtr->data);
         CurentPtr = currentPtr->nẽtPtr;
}
Print(startReversePtr);
While (swapped != 0)
```
## B.  Create new list 
1. Pop first node out, store data, prepare to free. 
2. startAgeSortPtr = Null
3. Insert popped node to AgeSort linked list. 
4. Free node. Repeat 1. Until NULL node.
