#include<stdio.h>

#define size 10

void insert(int item,int *r,int q[])
{
	if(*r==size-1)
	{
	printf("Queue overflow\n");
	return;
	}
*r=*r+1;
q[*r]=item;
}

int delete(int q[],int *f,int *r)
{
	int item;
	if(*f>*r)
	{
	printf("queue undrflow\n");
	return -9999;
	}	
item=q[*f];
*f=*f+1;
return item;
}

void display(int q[],int f, int r)
{
int i;
if(f>r)
	{
	printf("queue is empty\n");
	return;
	}
printf("contents are\n");
for(i=f;i<=r;i++)
	printf("%d\n",q[i]);
}

int main()
{
int n=-1,item,f=0,r=-1,ele,q[size];
while(n!=0)
{
printf("ENTER YOUR CHOICE\n");

printf("1=insertion,2=deletion,3=display,0=quit\n");
scanf("%d",&n);






switch(n)
	{
	case 1:printf("enter element\n");
		scanf("%d",&item);
		insert(item,&r,q);
		break;
	case 2:ele=delete(q,&f,&r);
		printf("deleted elemet is %d\n",ele);
		break;
	case 3: display(q,f,r);
		break;
	default:printf("enter valid number\n");
	}
}
return 0;
}
