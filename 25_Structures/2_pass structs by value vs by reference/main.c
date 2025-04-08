#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[20];
    int age;
    float grade;
    int id;
} Student;

void printStudents(Student st)
{
    printf("Student name: %s \n", st.name);
    printf("Student age: %d \n", st.age);
    printf("Student grade: %.1f \n", st.grade);
    printf("Student id: %d \n", st.id);
}

void updateAge(Student st)
{
    st.age++;
}

void updateName(Student *st)
{
    char newName[] = "Tom Cruise";
    int lengthStudent = strlen(newName);
    for(int i=0; i<lengthStudent; i++)
    {
        (*st).name[i] = newName[i];
    }
    (*st).name[lengthStudent] = '\0';
}

void updateGrade(Student *st)
{
    (*st).grade = 20;
}

int main() {

    Student student1 = {"John Doe", 21, 18.5, 11};
    printStudents(student1);    // Values before update
    updateAge(student1);        // Send variable of struct type by value
    updateName(&student1);      // Send variable of struct type by reference to change name globally
    updateGrade(&student1);     // Send variable of struct type by reference to change grade globally
    printf("--------------------\n");
    printStudents(student1);    // Values after update

    return 0;
}

