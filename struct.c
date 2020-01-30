#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[20];
    unsigned age;
};

void sprint(struct student stu);

void sprint(struct student stu)
{
    printf(" Id is: %d \n", stu.id);
    printf(" Name is: %s \n", stu.name);
    printf(" Age is: %u \n", stu.age);
}

int main()
{
    struct student stu;
    stu.age = 18;
    strcpy(stu.name, "Tiger");
    stu.id = 22588;
    sprint(stu);
}