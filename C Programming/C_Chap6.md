# String compare `strcmp` 
Không phân biệt hoa, thường:
```
int ic_strcmp(char *s1, char *s2) 
{ 
    int i; 
    for (i = 0; s1[i] && s2[i]; ++i) 
    {
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i]) 
           continue; 
        else
           break; 
    } 
    if (s1[i] == s2[i]) 
        return 0; 

    if ((s1[i] | 32) < (s2[i] | 32))  
        return -1; 
    return 1; 
} 
```
Phân biệt hoa thường, đổi `if` lại:  
1. `if (s1[i] == s2[i])` 2. `if (s1[i] < s2[i])`

# Bubble Sort
```c
for (pass = 1; pass < SIZE; pass++ ) {
    for ( i = 0; i < SIZE - 1; i++ ) {
        if ( a[ i ] > a[ i + 1 ] ) {
            swap();
        }
    }
}
```
# Search
### 1. Linear search:
```c
int linearSearch( const int array[], int searchKey, int size )
{
    int n;
    for ( n = 0; n < size; ++n ) {
        if ( array[ n ] == key ) {
            return n; // return location of found element.
        }
    }
    return -1; // not found
}
```
### 2. Binary search:
Nhớ thay đổi kiểu dữ liệu của array và searchKey:
```c
int binarySearch( const int b[], int searchKey, int low, int high ){
    int middle;
    while ( low <= high ){
        middle = (low + high) / 2;
        if ( searchKey == b[ middle ] ){
            return middle;
        } else if ( searchKey < b [middle] ){
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return -1;
}
```

# lowercase
```c
for( i = 0; string[i] != '\0'; i++){
    string[i] = string[i] | 32;
}
```
# UPPERCASE
Modifying `if` statement:
```c
if (string[i] >= 'a' && string[i] <= 'z'){
    string[i] = string[i] - 32;
}
```
### Mixed lower & UPPER
```c
    if character in [a,z] chr -= 32;
    if character in [A, Z] chr += 32;
```
# Reverse string & array
```c
int start = 0;
int end = #ELEMENTS - 1;
while (start < end){
    str2[start] = str1[end];
    start++; end--;
}
```

# Random

# Uncategory:
1.  Given an array: 13, 18, 13, 14, 13, 16, 14, 21, 13  
    Mean: (13 + 18 + 13 + 14 + 13 + 16 + 14 + 21 + 13) ÷ 9 = 15   
    Median: 13, 13, 13, 13, `14`, 14, 16, 18, 21  
    Mode: phần tử xuất hiện nhiều lần nhất  
    Range: largest trừ smallest
2.  

