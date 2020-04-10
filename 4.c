#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *leftlink;
struct node *rightlink;
}*root=NULL;
struct node* insert(struct node* root,int e)
{
if(root==NULL)
{
root=(struct node*)malloc(sizeof(struct node));
root->data=e;
root->leftlink=root->rightlink=NULL;
return root;
}
else if(root->data>e)
{
root->leftlink=insert(root->leftlink,e);
}
else if(root->data<e)
{
root->rightlink=insert(root->rightlink,e);
}
return root;
}
int minimum(struct node* root)
{
if(root->leftlink==NULL)
{
return root->data;
}
else
{
return minimum(root->leftlink);
}
}
struct node* remove(struct node* root,int e)
{
if(root==NULL)
{
return root;
}
else if(root->data>e)
{
root->leftlink=remove(root->leftlink,e);
}
else if(root->data<e)
{
root->rightlink=remove(root->rightlink,e);
}
else
{
if(root->leftlink==NULL && root->rightlink==NULL)
{
delete root;
return NULL;
}
else if(root->leftlink==NULL)
{
root=root->rightlink;
}
else if(root->rightlink==NULL)
{
root=root->leftlink;
}
else
{
int key=minimum(root->rightlink);
root->data=key;
root->rightlink=remove(root->rightlink,key);
}
}
return root;
}
void inorder(struct node *root)
{
if(root==NULL)
{
return;
}
inorder(root->leftlink);
printf("%d",root->data);
inorder(root->rightlink);
}
main()
{
int n,i,e;
printf("enter no of elements");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the element");
scanf("%d",&e);
root=insert(root,e);
}
inorder(root);
printf("\n");
printf("enter the element to to remove");
scanf("%d",&e);
root=remove(root,e);
inorder(root);
}
