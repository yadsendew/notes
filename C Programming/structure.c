#include<stdio.h> 
#include <string.h>

struct Student {
      char Name[20];
      float Grade;
      int Age;
      char Class[20];
} student;

struct Student input(){
    struct Student s1;
    printf("Enter name: "); gets(s1.Name);
    printf("Enter class: "); gets(s1.Class);
    printf("Enter grade: "); scanf("%f", &s1.Grade);
    printf("Enter age: "); scanf("%d", &s1.Age);

    return s1;
}
void output(struct Student student){
    printf("Name: %s\n", student.Name);
    printf("Grade: %f\n", student.Grade);
    printf("Age: %d\n", student.Age);
    printf("Class: %s\n", student.Class);
}
int main() 
{
    struct Student student1;
    student1 = input();
    output(student1);
  return 0; 
}
