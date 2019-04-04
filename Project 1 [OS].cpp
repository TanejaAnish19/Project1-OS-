#include<stdio.h>
#include<conio.h>

#define M 4999

int main()
{
 int a[20],b[20],n,i,j,temp,x;
 int head , pre_head;
 int sum = 0;

 printf("Enter head pointer position:");
 scanf("%d",&a[0]);
 head=a[0];
 printf("\nEnter previous head position : ");
 scanf("%d",&pre_head);

 printf("\nEnter number of processes:");
 scanf("%d",&n);
 printf("\nEnter processes in request order");
 for(i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
 }
 a[n+1]=M;
 a[n+2]=0;
 for(i=n+1;i>=0;i--)
 {
  for(j=0;j<=i;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }

