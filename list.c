#include<stdio.h>
#include<string.h>
struct student{
	int id;
	char name[10];
	unsigned age;
};
void sprint(struct student *st);

void sprint(struct student *st)
{
	printf("id is %p\n",st);
	printf("name is %p\n",st);
	printf("age is %p",st);
}
int main(){
	struct student st;

	st.age = 6273485;
	st.id = 1234432;	
	strcpy(st.name,"asd");

	sprint(&st);
}