#include<iostream>
using namespace std;
template<class T>
class stack
{
	public:
		int top,MAX;
		T s[20];
		stack()
		{
			top=-1;
			MAX=20;
		}
		
		int isempty()
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}
		int isfull()
		{
			if(top==MAX-1)
				return 1;
			else 
				return 0;
		}
		void push(T x)
		{
			if(!isfull())
				s[++top]=x;
			else
				cout<<"\nStack is Full"<<endl;
		}
		
		T pop()
		{
			if(!isempty())
				return s[top--];
			else
				cout<<"\nStack is Empty"<<endl;
		}
};
