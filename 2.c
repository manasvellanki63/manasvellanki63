#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
stack<char>s;
bool isoperator(char c)
{
if(c=='+'||c=='-'||c=='*'||c=='/')
{
return true;
}
else
{
return false;
}
}
int order(char a)
{
if(a=='*'||a=='/')
{
return 2;
}
if(a=='+'||a=='-')
{
return 1;
}
}
bool highorder(char a,char b)
{
if(order(a)<=order(b))
{
return 1;
}
else
{
return 0;
}
}
bool isnumeric(char c)
{
if(c>='0' && c<='9')
{
return 1;
}
else
{
return 0;
}
}
bool isopening(char c)
{
if(c=='(')
{
return 1;
}
else
{
return 0;
}
}
bool isclosing(char c)
{
if(c==')')
{
return 1;
}
else
{
return 0;
}
}
char *infixtopostfix(char exp[])
{
int i;
char res[20]={'\0'};
for(i=0;i<strlen(exp);i++)
{
if(isoperator(exp[i]))
{
while(!s.empty() && highorder(exp[i],s.top()) && !isopening(s.top()))
{
strncat(res,&s.top(),1);
s.pop();
}
s.push(exp[i]);
}
else if(isnumeric(exp[i]))
{
strncat(res,&exp[i],1);
}
else if(isopening(exp[i]))
{
s.push(exp[i]);
}
else if(isclosing(exp[i]))
{
while(!s.empty() && !isopening(s.top()))
{
strncat(res,&s.top(),1);
s.pop();
}
s.pop();
}
}
while(!s.empty())
{
strncat(res,&s.top(),1);
s.pop();
}
return res;
}
main()
{
char exp[20],r[20];
printf("enter the expression");
scanf("%s",exp);
strcpy(r,infixtopostfix(exp));
printf("%s",r);
}

