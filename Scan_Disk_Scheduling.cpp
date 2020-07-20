#include<stdio.h>
#include<conio.h>

#define M 4999

int main()
{
 int a[20],b[20],n,i,j,temp,x;
 int head , pre_head;
 int sum = 0;
 printf("*****************WELCOME TO SCAN DISK SCHEDULING PROGRAM******************\n");

 printf("Enter head pointer position:");
 scanf("%d",&a[0]);
 head=a[0];
 printf("\nEnter previous head position : ");
 scanf("%d",&pre_head);

 printf("\nEnter number of processes:");
 scanf("%d",&n);
 printf("\nEnter processes in request order : \n");
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
 for(i=1;i<=n+1;i++)
 {
  if(head==a[i])
  	x = i;
 }
 j=0;
 if(head<pre_head)
 {
  for(i=x;i>0;i--)
  {
   sum+=(a[i]-a[i-1]);
   b[j++]=a[i];
  }
  sum+=a[x+1]-a[0];
  b[j++]=a[0];
  for(i=x+1;i<n+1;i++)
  {
   sum+=(a[i+1]-a[i]);
   b[j++]=a[i];
  }
  b[j++]=a[i];
 }
 else
 {
  for(i=x;i<n+2;i++)
  {
   sum+=(a[i+1]-a[i]);
   b[j++]=a[i];
  }
  sum+=a[n+2]-a[x-1];
  b[j++]=a[n+2];
  for(i=x-1;i>1;i--)
  {
   sum+=(a[i]-a[i-1]);
   b[j++]=a[i];
  }
  b[j++]=a[i];
 }
 printf("\nProcessing order : \n");
 for(i=0;i<=n+1;i++)
 printf("%d -->",b[i]);
 printf("\nTotal Head Movement : %d",sum);
 getch();
}
