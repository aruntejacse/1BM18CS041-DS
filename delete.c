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
	printf("memory is not allocated\n");
	return NULL;
	}
    return p;
}

NODE insert_front(int item,NODE head)
{
    NODE p=create();
    p->data=item;
    p->next=head;
    head=p;
    return head;
}

void display(NODE head)
{
    NODE p;
    if (head==NULL)
	{
	printf("list is empty");
	return;
	}
    p=head;
    while(p != NULL)
	{
	printf("%d\n",p->data);
	p=p->next;
	}
}

void insert_end(int item,NODE head)
{
    NODE p,q;
    q=create();
    q->data=item;
    p=head;
    while(p->next != NULL)
	{
	p=p->next;
	}
    p->next=q;
    q->next=NULL;
}

NODE insert_pos(NODE head,int item, int pos)
{
    NODE curr,prev=NULL,newn;
    int count=1;
    newn=create();
    newn->data=item;
    newn->next=NULL;
    if(head==NULL)
	{
	if(pos==1)
	    {
	    return newn;
	    }
        else
	    {
	    printf("Invalid position\n");
	    return head;
	    }
	}
    if(pos==1)
	{
	newn->next=head;
	head=newn;
	return head;
	}
    else
	{
	curr=head;
	while(curr != NULL && count !=pos)
	    {
	    prev=curr;
	    curr=curr->next;
	    count=count+1;
	    }
        if(count==pos)
	    {
	    prev->next=newn;
	    newn->next=curr;
	    return head;
	    }
        else
	    {
	    prev->next=newn;
	    newn->next=curr;
	    return head;
	    }
	}
    }


NODE delete_front(NODE head)
{
    NODE p=head;
    if(head==NULL)
	{
	printf("list is empty");
	return head;
	}
    printf("Deleted element is %d\n",p->data);
    head=p->next;
    free(p);
    return head;
}

NODE delete_rear(NODE head)
{
    NODE p=head;
    if(head->next==NULL)
	{
	printf("deleted element is %d",head->data);
	return head;
	}
	while((p->next)->next != NULL)
	    {
	    p=p->next;
	    }
	p->next=NULL;
	return head;
}
void main()
{
    NODE head=NULL;
    int ch,i=1,item,pos;
    while(i==1)
	{
	printf("ENTER YOUR CHOICE\n");
	printf("1=insertion from front\n2=insertion at a position\n3=insertion from end\n4=display\n5=delete from front\n6=delete from rear\n0=exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: printf("enter element to be inserted:");
		scanf("%d",&item);
		head=insert_front(item,head);
		break;
	case 2:printf("enter element to be inserted and position:");
		scanf("%d%d",&item,&pos);
		head=insert_pos(head,item,pos);
		break;
	case 3:printf("enter element to be inserted:");
		scanf("%d",&item);
		insert_end(item,head);
		break;
	case 4:display(head);
		break;
	case 5:head=delete_front(head);
		break;
	case 6:head=delete_rear(head);
		break;
	default:exit(0);
	}
    }
}

