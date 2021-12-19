#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<tm_stack.h>

int main()
{
int x[5];
int i,p,l,r,lb,ub;
x[0]=50;
x[1]=30;
x[2]=70;
x[3]=20;
x[4]=60;
Stack *s1=createStack();
Stack *s2=createStack();
pushOnStack(s1,0);
pushOnStack(s2,4);
while(sizeOfStack(s1)!=0)
{
lb=popFromStack(s1);
ub=popFromStack(s2);
i=x[lb];
l=lb;
r=ub;
while(x[l]<=i && l<ub)
{
l++;
}
while(i>x[r])
{
r--;
}
if(l<r)
{
swap l,r
}
else
{
swap r,i
}
}




return 0;
}