# Structure
### Note: Should not declare string elements of `struct` by `char *string`. Using `char string[]` instead.
```c
struct Student {
      char Name[20];
      char Class[20];
      int Code;
      int Age;
};

struct Student input(){
    struct Student s1;
    printf("Enter name: "); gets(s1.Name);
    printf("Enter class: "); gets("%s", s1.Class);
    printf("Enter code: "); scanf("%f", &s1.Code);
    printf("Enter age: "); scanf("%d", &s1.Age);
    return s1;
}
int main() 
{
    struct Student student1;
    student1 = input();
  return 0; 
} 
```
### Return `struct` from function
1. Create `struct Student s1` inside _input function_.
2. Use `gets()` for string input, `scanf()` for number input.
3. Return `s1`  
Note: Should place `gets(`_string_ `)` above a `scanf(`_number_`)`
### Call by reference with Structure
```
struct Student {
      char Name[20];
      char Class[20];
      int Code;
      int Age;
};
void input(struct Student *a){
    // a->Name là biến string, nó đã là pointer nên không cần thêm &.
	printf("Name: "); gets(a->Name);
	printf("Class: "); gets(a->Class);
	printf("Code: "); scanf("%d", &(a->Code));
	printf("Age: "); scanf("%d", &(a->Age));
}
```
#  `typedef`
```
typedef struct {
    char *face;
    char *suit; 
} Card;
```
# `union`
Kiểu dữ liệu `union number` mang hai kiểu: `int` và `double`: 
```c
union number {
    int x;
    double y;
}
```
Giả sử tạo biến `value` mang kiểu dữ liệu `union number`:
```
union number value = { 10 }; // int
union number value = { 1.43 }; // double
```
