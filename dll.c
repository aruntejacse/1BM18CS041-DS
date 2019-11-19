#include<stdio.h>
#include<stdlib.h>

struct node
    {
    int data;
    struct node *next;
    struct node *prev;
    };
typedef struct node *NODE_DLL;

NODE_DLL getnode()
    {
    NODE_DLL p;
    p=(NODE_DLL)malloc(sizeof(struct node));
    if(p!=NULL)
        return p;
    else
        {
        printf("Memory is not allocated");
        exit(0);
        }
    }
    
NODE_DLL insert_front(NODE_DLL head,int value)
    {
    NODE_DLL newn=getnode();
    newn->data=value;
    if(head==NULL)
        {
        newn->prev=NULL;
        newn->next=NULL;
        head=newn;
        return head;
        }
    newn->next=head;
    head->prev=newn;
    newn->prev=NULL;
    head=newn;
    return head;
    }
    
NODE_DLL insert_left(NODE_DLL head,int value,NODE_DLL n)
    {
    NODE_DLL newn=getnode();
    newn->data=value;
    if(n->prev==NULL)
        {
        newn->next=head;
        head->prev=newn;
        newn->prev=NULL;
        head=newn;
        return head;
        }
    newn->prev=n;
    n->prev->next=newn;
    n->prev=newn;
    newn->next=n;
    return head;
    }
    
NODE_DLL del_spec(NODE_DLL head,int del_ele)
    {
    NODE_DLL p;
    if(head==NULL)
        {
        printf("List is empty\n");
        return head;
        }
    if(head->next==NULL)
        {
        if(head->data==del_ele)
            {
            free(head);
            return NULL;
            }
        else
            {
            printf("Element not found\n");
            return head;
            }
        }
    p=head;
    while(p!=NULL)
        {
        if(p->data==del_ele)
            {
            if(p->next==NULL)
                {
                 p->prev->next==NULL;
		free(p);
		return head;
		}
            else
                {
                 p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
		return head;
                 
                 }
             }
         p=p->next;
         }
     if(p==NULL)
         {
         printf("Value not found in list\n");
         return head;
         }
     }
     
void display(NODE_DLL head)
    {
    NODE_DLL p;
    if(head==NULL)
        {
        printf("List is empty\n");
        exit(0);
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
    NODE_DLL head=NULL;
    int ch,i=1,item,pos,c=0;
    while(i==1)
	{
	printf("ENTER YOUR CHOICE\n");
	printf("1=insertion from front\n2=insertion at left of a node\n3=Delete a specified element\n4=display\n0=exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: printf("enter element to be inserted:");
		scanf("%d",&item);
		head=insert_front(head,item);
		break;
	case 2:printf("enter element to be inserted and position of node:");
		scanf("%d%d",&item,&pos);
		NODE_DLL p=head;
		    while(p!=NULL)
		        {
		        c++;
		        if(c==pos)
		            {
		            head=insert_left(head,item,p);
		            }
		        p=p->next;
		        }
		break;
	case 3:printf("enter element to be deleted:");
		scanf("%d",&item);
		head=del_spec(head,item);
		break;
	case 4:display(head);
		break;
	default:exit(0);
	}
    }
}
       
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
