#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE create()
{
    NODE p=(NODE)malloc(sizeof(NODE));
    if(p==NULL)
	{
	printf("memory is not allocated\n");
	return p;
	}
    return p;
}

NODE insert_end(NODE head,int item)
{
    NODE p,q;
    q=create();
    q->data=item;
    if(head==NULL)
	{
	q=head;
	return head;
	}
    p=head;
    while(p->next != NULL)
	{
	p=p->next;
	}
    p->next=q;
    q->next=NULL;
    return head;
}

void display(NODE head)
{
    NODE p=head;
    if (head==NULL)
	{
	printf("list is empty\n");
	return;
	}
    while(p != NULL)
	{
	printf("%d\n",p->data);
	p=p->next;
	}
}

NODE sort(NODE head)
{
    int temp;
    NODE p=head;
    NODE q=NULL;
    if(head==NULL)
	return head;
    while(p->next != NULL)
	{
	q=p->next;
	while(q!=NULL)
	    {
	    if(p->data>q->data)
		 {
		 temp=p->data;
		 p->data=q->data;
		 q->data=temp;
		 }
	    q=q->next;
	    }
	p=p->next;
	}
     return head;
}

NODE concatenate(NODE head,NODE head2)
{
    NODE p=head;
    while(p!=NULL)
	{
	p=p->next;
	}
    p->next=head2;
    return head;
}

NODE reverse(NODE head)
{
    NODE curr=head,prev=NULL,next;
    while(curr!=NULL)
	{
	next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;
	}
    head=prev;
    return head;
}

void main()
{
    NODE head=NULL;
    NODE head2=NULL;
    int ch,i=-1,item;
    while(i!=0)
	{
	printf("ENTER YOUR CHOICE\n");
	printf("1=insertion\n2=concatenate\n3=sort\n4=reverse\n5=display\n0=exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: printf("enter element to be inserted:");
		scanf("%d",&item);
		head=insert_end(head,item);
		break;
	case 2:printf("enter elements to be inserted for two lists:");
		scanf("%d",&item);
		head=insert_end(head,item);
		scanf("%d",&item);
		head2=insert_end(head2,item);
		head=concatenate(head,head2);
		display(head);
		break;
	case 3:head=sort(head);
		display(head);
		break;
	case 4:head=reverse(head);
		display(head);
		break;
	default:exit(0);
	}
    }
}

