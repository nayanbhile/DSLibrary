#include<tm_queue.h>
int main()
{
Queue *queue=createQueue();
int x[10];
int i;
i=0;
while(i<=9)
{
x[i]=5*i;
i++;
}

i=0;
while(i<=9)
{
addInQueue(queue,&x[9-i]);
i++;
}
printf("Size: %d\n",sizeOfQueue(queue));
printf("Front: %d\n",peekIntoFrontOfQueue(queue));
printf("Rear: %d\n\n",peekIntoRearOfQueue(queue));
i=0;
while(i<=9)
{
printf("%d removed\n",removeFromQueue(queue));
i++;
}
printf("Size: %d\n",sizeOfQueue(queue));
printf("Front: %d\n",peekIntoFrontOfQueue(queue));
printf("Rear: %d\n",peekIntoRearOfQueue(queue));
return 0;
}