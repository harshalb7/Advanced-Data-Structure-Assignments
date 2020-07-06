#include<iostream>
using namespace std;
template<class T>
class Queue
{
	public:
		int front,rear,MAX;
		T s[50];
		Queue()
		{
			front=-1;
			rear=-1;
			MAX=50;
		}
		
		int isempty()
		{
			if(rear==-1)
				return 1;
			else 
				return 0;
		}
		int isfull()
		{
			if(rear==MAX-1)
				return 1;
			else 
				return 0;
		}
		void insert(T x)
		{
			if(!isfull())
				{
					if(rear==-1)
					{
						front=0;
						rear=0;
						s[rear]=x;
					}
					else
					{
						s[++rear]=x;
					}
				}
			else
				cout<<"\nQueue is Full"<<endl;
		}
		
		T delete1()
		{
			T x;
			if(!isempty())
			{
				x=s[front];	
				if(rear==front)
				{
					rear=-1;
					front=-1;
					return x;
				}
				else
				{
					front++;
					return x;
				}
			}
			else
			{
				cout<<"\nQueue is Empty"<<endl;
				return 0;
			}
		}
};
/*int main()
{
	Queue <char> q1;
	int m;
	q1.add(1);
	q1.add(2);
	q1.add(3);
	m=q1.del();
	cout<<m;
	m=q1.del();
	cout<<m;
	m=q1.del();
	cout<<m;
	m=q1.del();
	cout<<m;
	m=q1.del();
	cout<<m;
}*/

