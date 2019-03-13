# Tinh tuý của exercise 11-3
## 1. Create matrix using double-pointer and 2D dynamic array

```cpp

/* 1 */ T ** ptr;
/* 2 */ ptr = new T*[row]; 
/* 3 */ for (int i = 0; i < n; i++){
            *(ptr + i) = new T[col];
        }
/* 4 */ *(*(ptr + i) + j) /* To access index [i][j] */


Note:   T is type of each value.
        T* : is pointer to T.

ptr ----1-----.                   _____ col _____
              |                  /               \
              v                 /                 \   
          / [ T* ]   --2-->    [ T | T |...| T | T ]
         /  [ T* ]   --2-->    [        ...        ]
       row  [....]   --2-->    [        ...        ]
         \  [ T* ]   --2-->    [        ...        ]
          \ [ T* ]   --2-->    [ T | T |...| T | T ]

```
## 2. Destroy!
Phá huỷ liên kết 2, sau đó phá huỷ liên kết 1.
```cpp
for (int i = 0; i < row; i++ ){
		delete []*(ptr + i);
	}
delete []ptr;
```
## 3. Input:
Sử dụng `*(*(ptr + i) + j)` để gán giá trị cho phần tử [i][j]
## 4. Khai báo class template và member function theo template.
```cpp
template <typename T>
class matrix{
    int size; // kích cỡ của matrix
    T** ptr;
public:
    matrix(int n = 0); // n là kích cỡ của matrix
    ~matrix();
    void input();
    T frobNorm();
}
// constructor
template <class T>
matrix<T>::matrix(int n) : size(n){
    ...
}
// destructor
template <class T>
matrix<T>::~matrix(){
    ...
}
template <class T>
void matrix<T>::input(){
    ...
}
template <class T>
T matrix<T>::frobNorm(){
    T norm;
    ...
    return norm;
}
```
