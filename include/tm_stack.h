#ifndef __$__tm_stack_h
#define __$__tm_stack_h 234
#include<tm_singly.h>
#include<tm_required.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _$_Stack
{
SinglyLinkedList *list;
}Stack;

Stack * createStack();
void pushOnStack(Stack *stack,void *ptr);
void * popFromStack(Stack *stack);
void * peekIntoStack(Stack *stack);
int sizeOfStack(Stack *stack);
void clearStack(Stack * stack);
void removeStack(Stack *stack);

#endif
