# Why do we need double pointers in linked list, stack and queue?
Suppose we have the struct below and use it as a node in stack.
```c
struct node {
    char name[20];
    struct node *nextPtr;
} Node;
typedef Node * NodePtr;
```

`NodePtr` is a pointer to a struct named "Node".  
Consider `NodePtr stackPtr` (1), it is a pointer to a Node structure.
```c
1   Node firstNode;
2   NodePtr stackPtr = &firstNode;
```
Now `stackPtr` points to `firstNode` (2). We want to call `stackPtr` by the Push() function to add new node. We have 2 options: **call by value** and **call by reference**. Once we Push(), the `stackPtr` points to new node. 
1. Call by value: make a copy of stackPtr, the copy is changed. But the original is not.
2. Call by reference: the changes of original `stackPtr` are saved after the `Push()` ended. 
    ```c
    // Prototype of function
    void Push(NodePtr *stackPtr, "Phat");
    //Call function
    Push(&stackPtr, "Phat");
    ```

**Call by reference of a pointer variable, forms a double pointer.**