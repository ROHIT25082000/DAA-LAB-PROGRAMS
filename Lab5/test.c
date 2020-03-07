#include<stdio.h>
#include<stdlib.h>
struct node
{
    int age;
    char name[20];
};
typedef struct node node;

void print(node*A,int n);

int main()
{
    node wow[10];
    printf("Enter ten number for the number of the record.\n");
    for(int i=0;i<3;i++)
    {
        printf("Enter the age:");
        scanf("%d",&wow[i].age);
        printf("Enter the name:");
        scanf("%s",wow[i].name);
    }
    print(wow,10);
}
void print(node*A,int n)
{
    for(int i=0;i<3;i++)
    {
        printf("Age : %d\n",(A+i)->age);
        printf("Name : %s\n",(A+i)->name);
    }
}
