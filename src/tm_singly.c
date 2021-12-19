#ifndef __$__tm_singly_c
#define __$__tm_singly_c 3223
#include<stdio.h>
#include<stdlib.h>
#include<tm_required.h>
#include<tm_singly.h>

SinglyLinkedList * createSinglyLinkedList()
{
SinglyLinkedList *sll;
sll=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
if(sll==NULL) return NULL;
sll->start=NULL;
sll->end=NULL;
sll->count=0;
return sll;
}

int getSizeOfSinglyLinkedList(SinglyLinkedList *sll)
{
if(sll==NULL) return 0;
return sll->count;
}

void addToSinglyLinkedList(SinglyLinkedList *sll,void * ptr, int *success)
{
struct _$_SinglyLinkedListNode *t;
if(success) *success=false;
if(sll==NULL) return;
t=(struct _$_SinglyLinkedListNode *)malloc(sizeof(struct _$_SinglyLinkedListNode));
if(t==NULL) return;
t->ptr=ptr;
t->next=NULL;
if(sll->start==NULL)
{
sll->start=t;
sll->end=t;
}
else
{
sll->end->next=t;
sll->end=t;
}
sll->count++;
if(success) *success=true;
}


void insertIntoSinglyLinkedList(SinglyLinkedList *sll,int index,void *ptr,int *success)
{
if(success) *success=false;
if(!sll) return;
if(index<0 || index>sll->count) return;
struct _$_SinglyLinkedListNode *node;
node=(struct _$_SinglyLinkedListNode *)malloc(sizeof(struct _$_SinglyLinkedListNode));
node->ptr=ptr;
node->next=NULL;
if(index==0) 
{
node->next=sll->start;
sll->start=node;
sll->count++;
if(success) *success=true;
return;
}
if(index==sll->count) addToSinglyLinkedList(sll,ptr,success);
if(index!=sll->count)
{
int i=0;
struct _$_SinglyLinkedListNode *t,*r;
t=sll->start;
while(i<index)
{
r=t;
t=t->next;
i++;
}
node->next=t;
r->next=node;
}
if(success) *success=true;
sll->count++;
}



void * getElementFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success)
{
int i;
struct _$_SinglyLinkedListNode *t;
if(success) *success=false;
if(sll==NULL) return NULL;
if(index<0 || index>=sll->count) return NULL;
t=sll->start;
for(i=0;i<index;i++) t=t->next;
if(success) *success=true;
return t->ptr;
}


void * removeFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success)
{
if(success) *success=false;
if(!sll) return NULL;
if(index<0 || index>=sll->count) return NULL;
struct _$_SinglyLinkedListNode *t,*r;
if(index==0)
{
t=sll->start;
sll->start=t->next;
}
if(index==(sll->count-1))
{
t=sll->start;
int i=0;
while(i<index)
{
r=t;
t=t->next;
i++;
}
r->next=NULL;
sll->end=r;
}
if(index>0 && index<sll->count-1)
{
int i=0;
t=sll->start;
while(i<index)
{
r=t;
t=t->next;
i++;
}
r->next=t->next;
}
if(success) *success=true;
sll->count--;
return t;
}



void clearSinglyLinkedList(SinglyLinkedList *sll)
{
if(sll==NULL) return;
struct _$_SinglyLinkedListNode *t;
while(sll->start)
{
t=sll->start;
sll->start=sll->start->next;
free(t);
}
sll->count=0;
sll->end=NULL;
}

void releaseSinglyLinkedList(SinglyLinkedList *sll)
{
if(sll==NULL) return;
clearSinglyLinkedList(sll);
free(sll);
}
#endif