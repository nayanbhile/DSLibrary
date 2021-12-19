#include<tm_required.h>
#include<tm_singly.h> 
#include<string.h> 
#include<stdlib.h> 
#include<stdio.h> 
struct Student 
{ 
int rollNumber; 
char *name; 
}Student; 
int main()
{ 
int ch,i; 
int count; 
int success; 
struct Student *s; 
SinglyLinkedList *list; 
char m; 
int rollNumber; 
char name[22]; 
list=createSinglyLinkedList(); 
if(list==NULL) 
{ 
printf("Insufficient memory\n"); 
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

if(ch==1) 
{ 
printf("Enter roll number : "); 
scanf("%d",&rollNumber); 
fflush(stdin); 
printf("Enter name : "); 
fgets(name,22,stdin); 
fflush(stdin); 
name[strlen(name)-1]='\0'; 
printf("Save (Y/N) : "); 
m=getchar(); 
fflush(stdin); 
if(m!='y' && m!='Y') 
{ 
printf("Student not added\n"); 
continue; 
} 
s=(struct Student *)malloc(sizeof(struct Student)); 
if(s==NULL) 
{ 
printf("Unable to add student, memory full\n"); 
continue; 
} 
s->rollNumber=rollNumber;
s->name=(char *)malloc(sizeof(char)*(strlen(name)+1)); 
if(s->name==NULL) 
{ 
printf("Unable to add student, memory full\n"); 
free(s); 
continue; 
} 
strcpy(s->name,name); 
addToSinglyLinkedList(list,s,&success); 
if(success) 
{ 
printf("Student added\n"); 
} 
else 
{ 
free(s->name); 
free(s); 
printf("Unable to add student, memory full\n"); 
} 
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
int pos;
printf("Enter the position to insert:");
scanf("%d",&pos);
fflush(stdin);
if(pos<1 && pos>getSizeOfSinglyLinkedList(list)) 
{
printf("Invalid position\n");
continue;
}
printf("Save(y/n)");
scanf("%c",&m);
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not added\n");
continue;
}
s=(struct Student *)malloc(sizeof(struct Student));
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
int i=0;
while(i<pos-1) i++;
insertIntoSinglyLinkedList(list,i,s,&success);
continue;
}

if(ch==3)
{
printf("------------Remove Student module------------\n");
int pos;
printf("Enter the position to remove:");
scanf("%d",&pos);
fflush(stdin);
if(pos<1 && pos>getSizeOfSinglyLinkedList(list)) 
{
printf("Invalid position\n");
continue;
}
int i=0;
while(i<pos-1) i++;
s=getElementFromSinglyLinkedList(list,i,&success);
printf("RollNumber: %d, Name: %s\n Remove(y/n)?",s->rollNumber,s->name);
scanf("%c",&m);
fflush(stdin);
if(m!='Y' && m!='y') printf("Student not deleted\n");
else 
{
removeFromSinglyLinkedList(list,i,&success);
printf("Student deleted\n");
}
continue;
}





if(ch==4) 
{
printf("------Display Student List Module------\n");
count=getSizeOfSinglyLinkedList(list); 
for(i=0;i<count;i++) 
{
s=getElementFromSinglyLinkedList(list,i,&success); 
printf("Roll Number: %d, Name: %s\n",s->rollNumber,s->name); 
} 
} 

if(ch==10) break; 


} 
count=getSizeOfSinglyLinkedList(list); 
for(i=0;i<count;i++) 
{ 
s=getElementFromSinglyLinkedList(list,i,&success); 
free(s->name); 
free(s); 
} 
releaseSinglyLinkedList(list); 
return 0; 
}
