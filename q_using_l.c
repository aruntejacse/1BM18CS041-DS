#include<stdio.h>
#include<stdlib.h>

struct node
    {
    int data;
    struct node *next;
    };
typedef struct node *NODE;

NODE create()
    {
    NODE p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
	{
	printf("List is empty");
	return p;
	}

    return p;
    }

NODE insert_rear(int item,NODE head)
    {
    NODE p,q;
    q=create();
    q->data=item;
    q->next=NULL;
    p=head;
    if(head==NULL)
	{
	head=q;
	return head;
	}
    while(p->next!=NULL)
	{
	p=p->next;
	}
    p->next=q;
    return head;
    }

NODE delete_front(NODE head)
    {
    if(head==NULL)
	{
	printf("List is empty");
     	return head;
	}
    printf("deleted element is %d\n",head->data); 
    head=head->next;
    return head;
    }


void display(NODE head)
    {
    NODE p;
    if(head==NULL)
	{
	printf("List is empty");
 	return;
	}
    p=head;
    while(p!=NULL)
	{
	printf("%d\n",p->data);
	p=p->next;
	}
    }



void main()
    {
    NODE head=NULL;
    int n=-1,item;
    while(n!=0)
	{
	printf("1=push element to queue\n2=pop element\n3=display\n0=exit\n");
	scanf("%d",&n);
	switch(n)
	    {
	    case 1:printf("Enter element to be pushed:");
		   scanf("%d",&item);
		   head=insert_rear(item,head);
		   break;
	    case 2:head=delete_front(head);
		   break;
	    case 3:display(head);
		   break;
	    default:printf("Enter 0 to exit\n");
		    break;
	    }
	}
     }

