#include<tm_queue.h>
int main()
{
int x=100,y=777;
Queue *queue=createQueue();
addInQueue(queue,&x);
printf("item added\n");
y=(int)removeFromQueue(queue);
printf("Item removed: %d\n",y);
return 0;
}