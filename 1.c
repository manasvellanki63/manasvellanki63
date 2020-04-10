#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
void reverse(char *a)
{
int i;
char res[10]={'\0'};
stack<char>s;
for(i=0;i<strlen(a);i++)
{
s.push(a[i]);
}
while(!s.empty())
{
strncat(res,&s.top(),1);
s.pop();
}
printf("%s",res);
}
main()
{
char a[10],res[10];
printf("enter the string");
scanf("%s",a);
reverse(a);
}

