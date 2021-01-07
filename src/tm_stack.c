#ifndef __$__tm_stack_c
#define __$__tm_stack_c 45
#include<stdio.h>
#include<tm_required.h>
#include<stdlib.h>
#include<tm_stack.h>
#include<tm_singly.h>

Stack * createStack()
{
Stack *stack=(Stack *)malloc(sizeof(Stack));
return stack;
}

int sizeOfStack(Stack *stack)
{
return stack->list->count;
}

void pushOnStack(Stack *stack,void *ptr)
{
int success;
SinglyLinkedList *sll=stack->list;
if(!sll) return;
insertIntoSinglyLinkedList(sll,0,ptr,&success);
stack->list=sll;
}

void * popFromStack(Stack *stack)
{
int success;
SinglyLinkedList *sll=stack->list;
if(!sll) return NULL;
removeFromSinglyLinkedList(sll,0,&success);
stack->list=sll;
}

void * peekIntoStack(Stack *stack)
{
int success;
SinglyLinkedList *sll=stack->list;
if(!sll) return NULL;
getElementFromSinglyLinkedList(sll,0,&success);
stack->list=sll;
}

void clearStack(Stack *stack)
{
int success;
SinglyLinkedList *sll=stack->list;
if(!sll) return;
clearSinglyLinkedList(sll);
stack->list=sll;
}

void removeStack(Stack *stack)
{
SinglyLinkedList *sll=stack->list;
if(!sll) return;
releaseSinglyLinkedList(sll);
stack->list=sll;
free(stack);
}

#endif