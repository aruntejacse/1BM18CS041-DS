#include<stdio.h>
#define size 20
void insert(int item,int *r,int q[])
{
	if(*r==size-1)
	{
		printf("Queue overflow\n");
		return;
	}
	q[++(*r)]=item;
}
int main()
{
	int q[size];
	int i,n,item;
	int r=-1;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter the time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		insert(item,&r,q);
	}
	printf("Process 1 starts at 0th second and ends at %dth second \n",q[0]);	
	for(i=1;i<n;i++)
	{
		q[i]=q[i-1]+q[i];
		printf("Process %d starts at %dth second and ends at %dth second \n",(i+1),q[i-1],q[i]);
	}
	return 0;
}	
