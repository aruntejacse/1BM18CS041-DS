#include<stdio.h>

void toh(int n, char f_rod, char t_rod, char a_rod)
{
if(n==1)
	{
	printf("The disk %d is moved from %c rod to %c rod\n",n,f_rod,t_rod);
	return;
	}
toh(n-1,f_rod,a_rod,t_rod);
printf("The disk %d is moved from %c rod to %c rod\n",n,f_rod,t_rod);
toh(n-1, a_rod, t_rod, f_rod); 
}


int main()
{
int n=4;
toh(n,'A','C','B');
return 1;
}
		
