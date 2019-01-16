# Structure
```c
struct Student {
      char Name[20];
      float Grade;
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
