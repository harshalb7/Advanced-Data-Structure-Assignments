/*
                                    ASSIGNMENT NO - 06

Assignment Statement:- There are filght paths between cities.If there is filght between city A and city B then there is an edge between 
					   cities.The cost of the edge can be the time thatflight takes to reach city B from city A, or the amount of Fuel 
					   used for the journey.Represent this as a graph.The node can be represented by Airpot Name or name of the city.
					   Use Adjacency list representation of the graph or use Adjacency matrix representation of the graph.Justify the
					   storage representation used.

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/
#include<iostream>
#include<string.h>
#include"qu.h"
#include<fstream>
using namespace std;
class node//STATR OF CLASS
{
		int v;
		string city;
		float distance;
		node* next;
		friend class Graph;
};//END OF CLASS
class Graph//STATR OF CLASS
{
		node* head[10];
		string city1[10];
		int visited[20];
		int visited1[20];
		
	public :
		Graph()
		{
			city1[1]="Nashik";city1[2]="Nagpur";city1[3]="Delhi";city1[4]="Pune";city1[5]="Mumbai";
			for(int i=1;i<=5;i++)
			{
				head[i]=new node;
				head[i]->v=i;
				head[i]->city=city1[i];
				head[i]->distance=0;
				head[i]->next=NULL;
				visited[i]=0;
				visited1[i]=0;
			}
		}
		
		void create()//START OF FUNCTION
		{
			node *curr,*temp;
			ifstream file("flight.txt");
			int x;
			for(int i=1;i<=5;i++)
			{
				temp=head[i];
				//cout<<"\nHow many cities are connected to "<<city1[i]<<": ";
				file>>x;
				for(int j=1;j<=x;j++)
				{
					curr=new node;
					/*for(int i=1;i<6;i++)
						cout<<i<<"."<<city1[i]<<endl;
					cout<<"\nEnter City Number: ";*/
					file>>curr->v;
					/*if(curr->v==i)
					{
						while(curr->v==i)
						{
							cout<<"\nEnter a valid city number!!!!!!!\t"<<endl;
							for(int i=1;i<6;i++)
								cout<<i<<"."<<city1[i]<<endl;
							cout<<"\nEnter City Number: ";
							file>>curr->v;
						}
					}*/
					curr->city=city1[curr->v];
					//cout<<"\nEnter Distance between Cities: ";
					file>>curr->distance;
					curr->next=NULL;
					temp->next=curr;
					temp=curr;
				}
			}
		} //END OF FUNCTION
		void display()//START OF FUNCTION
		{
			node *temp;
			cout<<endl<<endl;
			for(int i=1;i<=5;i++)
			{
				temp=head[i]->next;
				cout<<head[i]->v<<"  "<<head[i]->city;
				while(temp!=NULL)
				{
					if(head[i]->next!=NULL)
						cout<<"----->"<<temp->v<<" "<<temp->city<<" "<<temp->distance;
					temp=temp->next;
				}
				cout<<endl;
			}
		}//END OF FUNCTION
		void available()//START OF FUNCTION
		{
			int l,m;
			node *temp;
			cout<<"\n-------------------------------------------"<<endl;
			for(int i=1;i<6;i++)
				cout<<i<<"."<<city1[i]<<endl;
			
			cout<<"\nEnter Citiies Code to Check flight: "<<endl;
			cout<<"1st City : ";
			cin>>l; 
			cout<<"2nd City : ";
			cin>>m; 
			temp=head[l]->next;
			while(temp!=NULL)
			{
				if(temp->v==m)
				{
					cout<<"\nFlight is Available between Citie "<<endl;
					cout<<"Distance Between "<<head[l]->city<<" and "<<temp->city<<" is: "<<temp->distance<<endl;
					break;
				}
				else
					temp=temp->next;
			}
		}//END OF FUNCTION
		int dfs(int x)//START OF FUNCTION
		{
			visited[x]=1;
			node *temp;
			cout<<x<<" ";
			temp=head[x];
			while(temp!=NULL)
			{
				if(visited[temp->v]==0)
					dfs(temp->v);
				temp=temp->next;
			}
		}//END OF FUNCTION

		void bfs(int m)//START OF FUNCTION
		{
			Queue <int> q2;
			node *temp;
			visited1[m]=1;
			q2.add(m);
			while(q2.isempty()!=1)
			{
				int i=q2.del();
				cout<<" "<<i<<" ";
				temp=head[i];
				while(temp!=NULL)
				{
					if(visited1[temp->v]==0)
					{
						q2.add(temp->v);
						visited1[temp->v]=1;
					}
					temp=temp->next;
				}
			}
		}//END OF FUNCTION
};//END OF CLASS

int main()//START OF FUNCTION
{
	Graph g;
	int x,m;
	long int ch;
	while(1){
		cout<<"\n----------------------"<<endl;
		cout<<"1.Create "<<endl;
		cout<<"2.Display "<<endl;
		cout<<"3.Check flights"<<endl;
		cout<<"4.DFS"<<endl;
		cout<<"5.BFS"<<endl;
		cout<<"6.EXIT"<<endl;
		cout<<"\n----------------------"<<endl;
		cout<<"Chioce: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					g.create();
					break;
			case 2:
					g.display();
					break;
			case 3:
					g.available();
					break;
			case 4:
					cout<<"\nEnter Vertex: ";
					cin>>x;
					cout<<"DFS is: ";
					g.dfs(x);
					cout<<endl;
					break;
			case 5:
					cout<<"\nEnter Vertex: ";
					cin>>m;
					cout<<"BFS is: ";
					g.bfs(m);
					cout<<endl;
					break;
			case 6:
					exit(1);
		}
	}
	return 0;
}//END OF FUNCTION

// OUTPUT
/*
----------------------
1.Create
2.Display
3.Check flights
4.DFS
5.BFS
6.EXIT

----------------------
Chioce: 1

----------------------
1.Create
2.Display
3.Check flights
4.DFS
5.BFS
6.EXIT

----------------------
Chioce: 2


1  Nashik----->2 Nagpur 100----->3 Delhi 200
2  Nagpur----->1 Nashik 100----->5 Mumbai 270----->3 Delhi 800
3  Delhi----->1 Nashik 200----->2 Nagpur 800----->4 Pune 123----->5 Mumbai 369
4  Pune----->3 Delhi 123
5  Mumbai----->3 Delhi 369----->2 Nagpur 270

----------------------
1.Create
2.Display
3.Check flights
4.DFS
5.BFS
6.EXIT

----------------------
Chioce: 3

-------------------------------------------
1.Nashik
2.Nagpur
3.Delhi
4.Pune
5.Mumbai

Enter Citiies Code to Check flight:
1st City : 3
2nd City : 2

Flight is Available between Citie
Distance Between Delhi and Nagpur is: 800

----------------------
1.Create
2.Display
3.Check flights
4.DFS
5.BFS
6.EXIT

----------------------
Chioce: 3

-------------------------------------------
1.Nashik
2.Nagpur
3.Delhi
4.Pune
5.Mumbai

Enter Citiies Code to Check flight:
1st City : 1
2nd City : 4

----------------------
1.Create
2.Display
3.Check flights
4.DFS
5.BFS
6.EXIT

----------------------
Chioce: 4

Enter Vertex: 2
DFS is: 2 1 3 4 5

----------------------
1.Create
2.Display
3.Check flights
4.DFS
5.BFS
6.EXIT

----------------------
Chioce: 5

Enter Vertex: 5
BFS is:  5  3  2  1  4

----------------------
1.Create
2.Display
3.Check flights
4.DFS
5.BFS
6.EXIT

----------------------
Chioce: 6
EXIT
*/