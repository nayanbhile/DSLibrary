#ifndef __$__tm_doubly_h
#define __$__tm_doubly_h 134

struct _$_createDoublyLinkedListNode
{
void *ptr;
struct _$_createDoublyLinkedListNode *next;
struct _$_createDoublyLinkedListNode *previous;
};
typedef struct _$_createDoublyLinkedList
{
struct _$_createDoublyLinkedListNode *start;
struct _$_createDoublyLinkedListNode *end;
unsigned int size;
}DoublyLinkedList;

DoublyLinkedList * createDoublyLinkedList();
void addToDoublyLinkedList(DoublyLinkedList *dll,void *ptr,int *success);
void insertIntoDoublyLinkedList(DoublyLinkedList *dll,int index,void *ptr,int *success);
void * getElementFromDoublyLinkedList(DoublyLinkedList *dll, int index);
void * removeFromDoublyLinkedList(DoublyLinkedList *dll,int index,int *success);
int getSizeOfDoublyLinkedList(DoublyLinkedList *dll);
void clearDoublyLinkedList(DoublyLinkedList *dll);
void releaseDoublyLinkedList(DoublyLinkedList *dll);
#endif