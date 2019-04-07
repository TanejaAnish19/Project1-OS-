#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;

int main()
{
	queue<int> teacher;
	queue<int> student;
	int n,m;
	cout<<"ENTER THE NUMBER OF TEACHERS"<<endl;
	cin>>n;
	cout<<"ENTER THE NUMBER OF STUDENTS"<<endl;
	cin>>m;
	int arr[m+n];
	int tCount=0;
	int sCount=n;
	cout<<"ENTER YOUR CHOICE: \n PRESS 1 FOR TEACHER.. \t PRESS 2 FOR STUDENT..\n";
	for(int i=0;i<n+m;i++)
	{  
		
	  r:{ cout<<"1.FOR TEACHER \n2.FOR STUDENT "<<endl;
	   int x;
	   cin>>x;
	   switch(x)
	   {
   	   	case 1:
   	   		  re:{ 
			if(tCount<n)
   	   		{
	   		   cout<<"ENTER THE BURST TIME : ";
	   		   int tb;
	   		   cin>>tb;
	   		   arr[tCount++]=tb;
			}
				else 
			{   
				cout<<"TEACHER LIMIT EXCEEDED.."<<endl;
				cout<<"ENTER FOR NEXT STUDENT.."<<endl;
				goto ree;
		    }  
				}
	   		     
	   		   break;
	   	case 2:
	   		
	   		ree:{ 
			   if(sCount<m+n)
   	   		   {
					 
	   				cout<<"ENTER THE BURST TIME : ";
	   		   		int sb;
	   		   		cin>>sb;
	   		   		arr[sCount++]=sb;
				}
				else
				 { 
				    cout<<"STUDENT LIMIT EXCEEDED.."<<endl;
				    cout<<"ENTER FOR NEXT TEACHER.."<<endl;
				 goto re;
				  } 
			   }	  
	   		   break;
	   		   default: cout<<"SORRY..INVALID CHOICE.."<<endl;
	   		             goto r;
	   		
		   }	}
	}
	
   for(int i=0;i<n;i++)
   {
   	 teacher.push(i);
   }
   for(int i=n;i<n+m;i++)
   {
   	 student.push(i);
   }
   
   int tq=4;
   int seq[n+m];
   int count=0;
   while(!teacher.empty())
   {
   	  int flag1=teacher.front();
   	  if(arr[flag1]<=4)
   	  {   arr[flag1]=0;
   	      teacher.pop();
   	      seq[count++]=flag1;
		 }
	   else
	   {
	   	 teacher.pop();
	   	 student.push(flag1);
	   }
   }
	
	while(!student.empty())
	{
		int flag2=student.front();
		seq[count++]=flag2;
		student.pop();
	}
	
	cout<<" THE SEQUENCE IN WHICH THEY ARE SERVED IS :"<<endl;
	for(int i=0;i<n+m;i++)
	{
		if(seq[i]<n)
		{
			cout<<"Teacher"<<seq[i]+1;
		}
		if(seq[i]>=n)
		{
			cout<<"Student"<<seq[i]-(n-1);
		}
		if(i!=(n+m-1))
		{
			cout<<"------>";
		}
	}
}
