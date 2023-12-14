/*Assignment no 2
Title: Write a menu driven program to perform following operations 
on singly linked list: Create, Insert, Delete, reverse, search, 
count and Display.*/


#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
int info;
struct node *next;
}NODE;
NODE* createlist(NODE *list); 
void Display (NODE *list);
void search (NODE *list);
NODE* insertbeg(NODE *list);
NODE* insertbetween(NODE *list);
NODE* insertlast(NODE *list);
NODE* delvalue(NODE *list);
void reverse(NODE *list);
NODE* Count (NODE *list);
//MAIN FUNCTION
void main ()
{
 printf(">>Singly Linked List<<");
NODE*list=NULL, *temp;
 int ch,n,pos;
do
{
printf("\n1. Create:");
printf("\n2. Display");
printf("\n3.Insert AtFirst");
printf("\n4.Insert AtMiddle");
printf("\n5.Insert AtLast");
printf("\n6. Delete");
printf("\n7. Search");
printf("\n8.Reverse");
printf("\n9.Count");
printf("\n10. Exit\n");
printf("\n Enter your choice:");
scanf("%d", &ch);
switch(ch)
{
case 1:
list=createlist (list);
break;
case 2:
Display (list);
break;
case 3:
list=insertbeg (list);
break;
case 4:
list=insertbetween (list);
break;
case 5:
list=insertlast (list);
break;
case 6:
delvalue(list);
break;
case 7:
search (list);
break;
case 8:
reverse(list);
break;
case 9:
list = Count(list);
break;
case 10:printf("_END_");
break;
} 
}while(ch != 10);
}
//CREATE FUNCTION
NODE* createlist (NODE *list)
{
int n,count;
NODE *temp, *newnode;
printf ("\nHow many nodes you want to enter ? \n");
scanf("%d" ,&n);
for(count=1 ; count<=n; count++)
 {
 newnode=(NODE*)malloc(sizeof(NODE));
newnode->next=NULL;
 printf( "Enter the node data:- " );
scanf ("%d",&newnode->info);
if (list==NULL)
 {
 list=temp=newnode;
 }
 else 
{ 
 temp->next=newnode;
 temp=newnode;
 }
}
 return list;
}
//DISPLAY
void Display (NODE *list)
{
 NODE *temp=list;
 if(temp == NULL)
 {
 printf("List is Empty...\n");
 }
 else
 {
 
 while(temp!=NULL)
 {
 printf ("%d",temp->info);
 printf("-->");
 temp=temp->next ;
}
 printf("NULL \n");
}
}
//Insert AT BEGINING
NODE * insertbeg(NODE *list)
{
int n;
printf("Enter the node you want to insert at first position:");
scanf("%d", &n);
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->info=n;
newnode->next=list;
list=newnode;
return list;
}
//INSERT IN BETWEEN
NODE * insertbetween(NODE *list)
{
NODE *newnode, *temp=list;
int n,i,pos;
printf("Enter the node data and position you want to insert between the node: \t");
scanf("\n%d", &n);
scanf("\n%d", &pos);
newnode=(NODE*)malloc(sizeof(NODE));
newnode->next=NULL;
newnode->info=n;
for(i=1; i<pos-1&&temp->next!=NULL; i++)
temp=temp->next;
newnode->next=temp->next;
temp->next=newnode;
return list;
}
//INSERT AT LAST
NODE * insertlast(NODE *list)
{
int n;
printf("Enter the node data you want to insert at last position: \t");
scanf("%d", &n);
NODE *newnode, *temp;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->info=n;
newnode->next=NULL;
for(temp=list; temp->next!=NULL; temp=temp->next);
temp->next=newnode;
return list;
}
//SEARCH
void search (NODE *list)
{
int num, flag=0;
NODE *temp;
printf("Enter the element to be search:");
scanf("%d", &num);
for(temp=list; temp!=NULL; temp=temp->next)
{
if(temp->info==num)
{
printf(">>%d is Found<<\n",num);
flag=1;
exit;
}
}
if(flag==0)
printf(">>%d is not found<<\n", num);
}
NODE* delvalue(NODE *list)
{
NODE *temp=list, *temp1;
int num;
printf("Enter node data to delete that node \t");
scanf("%d", &num);
if(list->info==num)
{
list=list->next;
free (temp);
return list;
exit;
}
for(temp=list; temp->next!=NULL; temp=temp->next)
if(temp->next->info==num)
{
temp1=temp->next;
temp->next=temp1->next;
free (temp1);
return list;
exit;
}
printf(">>Element is not found<<\n");
return list;
} 

void reverse(NODE *list)
{
struct node *t1, *t2,*temp;
t1=t2=NULL;
if(list == NULL)
printf("List is empty");
else
{
while(list != NULL)
{
t2=list->next;
list->next = t1;
t1=list;
list=t2;
}
list=t1;
temp=list;
printf("\nReversed Link List\n");
while(temp!=NULL)
{
 printf ("%d",temp->info);
 printf("-->");
 temp=temp->next ;
}
 printf("NULL \n");
}
}


NODE* Count (NODE *list)
{
int cnt = 0;
 NODE *temp=list;
 
 while(temp!=NULL)
 {
 temp = temp->next;
cnt++;
 }
printf("Total Node in linked list is --> %d \n",cnt);
}
