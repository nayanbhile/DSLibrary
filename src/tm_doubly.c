#ifndef __$__tm_doubly_c
#define __$__tm_doubly_c
#include<stdio.h>
#include<stdlib.h>
#include<tm_required.h>
#include<tm_doubly.h>

DoublyLinkedList * createDoublyLinkedList()
{
DoublyLinkedList *dll=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(!dll) return NULL;
dll->start=NULL;
dll->end=NULL;
dll->size=0;
return dll;
}

int getSizeOfDoublyLinkedList(DoublyLinkedList *dll)
{
return dll->size;
}

void addToDoublyLinkedList(DoublyLinkedList *dll,void *ptr,int *success)
{
if(success) *success=false;
if(!dll) return;
struct _$_createDoublyLinkedListNode *node;
node=(struct _$_createDoublyLinkedListNode *)malloc(sizeof(struct _$_createDoublyLinkedListNode));
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(dll->start==NULL) // when no node exists in dll
{
dll->start=node;
dll->end=node;
}
else // when there is atleat a node in dll
{
struct _$_createDoublyLinkedListNode *t;
t=dll->start;
while(t->next!=NULL)
{
t=t->next;
}
t->next=node;
node->previous=t;
dll->end=t->next;
}
dll->size++;
if(success) *success=true;
}
void insertIntoDoublyLinkedList(DoublyLinkedList *dll,int index,void *ptr,int *success)
{
if(success) *success=false;
if(!dll) return;
if(index<0 || index>dll->size) return;
struct _$_createDoublyLinkedListNode *node;
node=(struct _$_createDoublyLinkedListNode *)malloc(sizeof(struct _$_createDoublyLinkedListNode));
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(index==0) 
{
dll->start=node;
dll->end=node;
}
if(index==dll->size) addToDoublyLinkedList(dll,ptr,success);
if(index!=dll->size)
{
int i=0;
struct _$_createDoublyLinkedListNode *t,*r;
t=dll->start;
while(i<index)
{
r=t;
t=t->next;
i++;
}
node->next=t;
node->previous=r;
r->next=node;
t->previous=node;
}
if(success) *success=true;
dll->size++;
}

void *getElementFromDoublyLinkedList(DoublyLinkedList *dll,int index)
{
if(!dll) return NULL;
if(index<0 || index>=dll->size)
{
return NULL;
}
int i=0;
struct _$_createDoublyLinkedListNode *t;
t=dll->start;
while(i<index)
{
t=t->next;
i++;
}
return t->ptr;
}

void * removeFromDoublyLinkedList(DoublyLinkedList *dll,int index,int *success)
{
if(success) *success=false;
if(!dll) return NULL;
if(index<0 || index>=dll->size) return NULL;
struct _$_createDoublyLinkedListNode *t,*r;
if(index==0)
{
t=dll->start;
if(t->next!=NULL) 
{
dll->start=t->next;
t->next->previous=NULL;
}
else
{
dll->start=NULL;
dll->end=NULL;
}
}
if(index==(dll->size-1))
{
t=dll->end;
dll->end=t->previous;
t->previous->next=NULL;
}
if(index>0 && index<dll->size-1)
{
int i=0;
t=dll->start;
while(i<index)
{
r=t;
t=t->next;
i++;
}
r->next=t->next;
t->next->previous=r;
}
if(success) *success=true;
dll->size--;
return t->ptr;
}

void clearDoublyLinkedList(DoublyLinkedList *dll)
{
if(!dll) return;
struct _$_createDoublyLinkedListNode *t;
while(dll->start)
{
t=dll->start;
dll->start=dll->start->next;
free(t);
}
dll->size=0;
dll->end=NULL;
}

void releaseDoublyLinkedList(DoublyLinkedList *dll)
{
if(!dll) return;
clearDoublyLinkedList(dll);
free(dll);
}

#endif