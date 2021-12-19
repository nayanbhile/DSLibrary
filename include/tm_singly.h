#ifndef __$__tm_singly_h
#define __$__tm_singly_h 234
struct _$_SinglyLinkedListNode
{
void * ptr;
struct _$_SinglyLinkedListNode *next;
};
typedef struct _$_SinglyLinkedList
{
struct _$_SinglyLinkedListNode *start;
struct _$_SinglyLinkedListNode *end;
unsigned int count;
}SinglyLinkedList;

SinglyLinkedList * createSinglyLinkedList();
void addToSinglyLinkedList(SinglyLinkedList *sll,void *ptr,int *success);
void insertIntoSinglyLinkedList(SinglyLinkedList *sll,int index,void *ptr,int *success);
void * removeFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success);
int getSizeOfSinglyLinkedList(SinglyLinkedList *sll);
void * getElementFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success);
void clearSinglyLinkedList(SinglyLinkedList *sll);
void releaseSinglyLinkedList(SinglyLinkedList *sll);
#endif
