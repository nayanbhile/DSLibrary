#include<stdio.h>
#include<stdlib.h>
#include<tm_required.h>
#include<tm_doubly.h>
#include<string.h>

typedef struct Student
{
int rollNumber;
char *name;
}Student;

int main()
{
int ch,i;
char m;
int rollNumber;
int count;
int success;
char name[22];
Student *s;
DoublyLinkedList *list=createDoublyLinkedList();
if(!list)
{
printf("Insificient memory!!\n");
return 0;
}
while(1)
{
printf("\n1. Add Student\n");
printf("2. Insert Student\n");
printf("3. Remove Student\n");
printf("4. Display list of Students\n");
printf("10. Exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
fflush(stdin);
if(ch<1 || ch>10 || (ch>4 && ch<10))
{
printf("Invalid input\n\n");
continue;
}

if(ch==1)
{
printf("--------Add student module--------\n");
printf("Enter Roll Number: ");
scanf("%d",&rollNumber);
fflush(stdin);
printf("Enter name: ");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Save(y/n)");
scanf("%c",&m);
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not added\n");
continue;
}
s=(Student *)malloc(sizeof(Student));
if(s==NULL)
{
printf("Unable to add student. Insuficient memory\n");
continue;
}
s->rollNumber=rollNumber;
s->name=(char *)malloc(sizeof(strlen(name)+1));
if(s->name==NULL)
{
printf("Unable to add name. Insuficient memory.\n");
continue;
}
strcpy(s->name,name);
addToDoublyLinkedList(list,s,&success);
if(success) printf("Student added successfully");
else printf("Unable to add student. Insufficient memory\n");
continue;
}

if(ch==2)
{
printf("---------Insert Student Module---------\n");
printf("Enter Roll Number: ");
scanf("%d",&rollNumber);
fflush(stdin);
printf("Enter name: ");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Save(y/n)");
scanf("%c",&m);
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not added\n");
continue;
}
s=(Student *)malloc(sizeof(Student));
if(s==NULL)
{
printf("Unable to add student. Insuficient memory\n");
continue;
}
s->rollNumber=rollNumber;
s->name=(char *)malloc(sizeof(strlen(name)+1));
if(s->name==NULL)
{
printf("Unable to add name. Insuficient memory.\n");
continue;
}
strcpy(s->name,name);
int pos;
printf("Enter the position to insert:");
scanf("%d",&pos);
fflush(stdin);
if(pos<1 && pos>getSizeOfDoublyLinkedList(list)) 
{
printf("Invalid position\n");
continue;
}
int i=0;
while(i<pos-1) i++;
insertIntoDoublyLinkedList(list,i,s,&success);
if(success) printf("Student inserted successfully\n");
else printf("Unable to insert student\n");
continue;
}

if(ch==3)
{
printf("------------Remove Student module------------\n");
int pos;
printf("Enter the position to remove:");
scanf("%d",&pos);
fflush(stdin);
if(pos<1 && pos>getSizeOfDoublyLinkedList(list)) 
{
printf("Invalid position\n");
continue;
}
int i=0;
while(i<pos-1) i++;
s=getElementFromDoublyLinkedList(list,i);
printf("RollNumber: %d, Name: %s\n Remove(y/n)?",s->rollNumber,s->name);
scanf("%c",&m);
fflush(stdin);
if(m!='Y' && m!='y') printf("Student not deleted\n");
else 
{
removeFromDoublyLinkedList(list,i,&success);
printf("Student deleted\n");
}
continue;
}

if(ch==4)
{
printf("------Display Student List Module------\n");
Student *s;
int i=0;
while(i<getSizeOfDoublyLinkedList(list))
{
s=getElementFromDoublyLinkedList(list,i);
printf("RollNumber: %d, Name: %s\n",s->rollNumber,s->name);
i++;
}
}

if(ch==10) break;
}
clearDoublyLinkedList(list);
releaseDoublyLinkedList(list);
return 0;
}