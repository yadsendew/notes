# Structure
### Note: Should not declare string elements of `struct` by `char *string`. Using `char string[]` instead.
```c
struct Student {
      char Name[20];
      int ID;
      int Age;
      char Class[20];
} student;

struct Student input(){
    struct Student s1;
    printf("Enter name: "); gets(s1.Name);
    printf("Enter class: "); gets("%s", s1.Class);
    printf("Enter grade: "); scanf("%f", &s1.Grade);
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
      int ID;
      int Age;
      char Class[20];
} student;
void Input(struct Student *student1){
    printf("Enter name: ");
    // Vì Name là string, Name vốn là pointer của string. Không cần lấy & nữa.
    scanf("%[^\n]%*c", student1 --> Name);
    printf("Enter student ID: ");
    // hàm scanf cần pointer của biến, &(student1 --> ID) lấy địa chỉ của biến.
    scanf(%d), &(student1 --> ID));
}
```
Note: `%[^\n]%*c` lấy các ký tự của hàng cho tới khi gặp '`\n`'.