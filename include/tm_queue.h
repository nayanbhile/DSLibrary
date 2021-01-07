#ifndef __$__tm_queue_h
#define __$__tm_queue_h 1324
#include<stdio.h>
#include<tm_doubly.h>
#include<tm_required.h>
#include<stdlib.h>

typedef struct _$_queue
{
DoublyLinkedList *dll;
}Queue;

Queue * createQueue();
void addInQueue(Queue *queue,void *ptr);
void * removeFromQueue(Queue *queue);
void * peekIntoFrontOfQueue(Queue *queue);
void * peekIntoRearOfQueue(Queue *queue);
int sizeOfQueue(Queue *queue);
void clearQueue(Queue *queue);
void removeQueue(Queue *queue);

#endif