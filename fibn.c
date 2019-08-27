#include<stdio.h>
int fib(int n)
{
if(n<=1)
     return n;
return (fib(n-1)+fib(n-2));

}
int main()
{
int n,num;


printf("Enter the number for fibonacci series");
scanf("%d",&n);
num=fib(n);
printf("%d",num);

}


