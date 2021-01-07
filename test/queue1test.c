#include<tm_queue.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
Queue *queue;
queue=createQueue();
int x[10],i=0;
printf("Calling addInQueue\n");
while(i<=9)
{
printf("%d",i);
x[i]=3*i;
addInQueue(queue,&x[i]);
i++;
}
i=sizeOfQueue(queue);
printf("\nSize of queue= %d\n\n",i);
printf("Calling remove from queue:\n");
int j;
j=(int)removeFromQueue(queue);
printf("Item removed: %d\n",j);
i=sizeOfQueue(queue);
printf("Size of new queue= %d\n\n",i);
printf("Peek into fromt of queue: %d\n",(int)peekIntoFrontOfQueue(queue));
printf("Peek into rear of queue: %d\n",(int)peekIntoRearOfQueue(queue));
clearQueue(queue);
i=sizeOfQueue(queue);
printf("Size of queue after clearing= %d\n\n",i);
removeQueue(queue);
return 0;
}