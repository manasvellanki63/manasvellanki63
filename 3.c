#include<stdio.h>
#include<stack>
using namespace std;
stack<int>s1;
stack<int>s2;
main()
{
int i,n,e;
printf("enter the no of elements");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the element");
scanf("%d",&e);
s1.push(e);
}
printf("removing the bottom element:\n");
while(!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
s2.pop();
while(!s2.empty())
{
s1.push(s2.top());
s2.pop();
}
printf("after removing the front element:\n");
while(!s1.empty())
{
printf("%d",s1.top());
s1.pop();
}
}
