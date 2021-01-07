#ifndef __$__tm_queue_c
#define __$__tm_queue_c 5343
#include<stdio.h>
#include<tm_queue.h>
#include<tm_doubly.h>
#include<stdlib.h>
#include<tm_required.h>

int success;
struct _$_createDoublyLinkedListNode *node;

Queue * createQueue()
{
Queue * queue= (Queue *)malloc(sizeof(Queue));
queue->dll=createDoublyLinkedList();
return queue;
}
void addInQueue(Queue *queue,void *ptr)
{
if(queue==NULL) return;
addToDoublyLinkedList(queue->dll,ptr,&success);
}
void * removeFromQueue(Queue *queue)
{
if(queue==NULL) return NULL;
node= removeFromDoublyLinkedList(queue->dll,0,&success);
return node->ptr;
}
void * peekIntoFrontOfQueue(Queue *queue)
{
if(queue==NULL) return NULL;
node= getElementFromDoublyLinkedList(queue->dll,0);
return node->ptr;
}

void * peekIntoRearOfQueue(Queue *queue)
{
if(queue==NULL) return NULL;
int size;
size=getSizeOfDoublyLinkedList(queue->dll);
node= getElementFromDoublyLinkedList(queue->dll,size-1);
return node->ptr;
}

int sizeOfQueue(Queue *queue)
{
int size=getSizeOfDoublyLinkedList(queue->dll);
return size;
}
void clearQueue(Queue *queue)
{
if(queue==NULL) return;
clearDoublyLinkedList(queue->dll);
}
void removeQueue(Queue *queue)
{
if(queue==NULL) return;
releaseDoublyLinkedList(queue->dll);
}
#endif