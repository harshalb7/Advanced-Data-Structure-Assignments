/*									
									ASSIGNMENT NO - 03

Assignment Statement:- For a given expression e.g. a-b*c-d/e+f construct inorder sequence and traverse it using postorder traversal 
					   ( Non- recursive ). Change a tree so that the roles of left and right pointers are swapped at every node.

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/

#include<iostream>
#include"stack.h"
#include"Queue.h"
using namespace std;
class node//STATR OF NODE CALSS
{
public:
	node *left,*right;//POINTER DELCARATION
	char data;//VARIABLE DECLARATION
};//END OF CALSS
class expressiontree//STATR OF CLASS
{
public:
	node *root,*t;
	expressiontree()//CONSTRUCTOR INITILIZATION
	{
		root=NULL;
	}

	void insert();
	void swap(node *root);
	void inorder(node *root);
	void preorder(node *root);
	void postorder(node *root);
	void non_reinorder(node *root);
	void non_repreorder(node *root);
	void non_repostorder(node *root);
	void bfs(node *root);
};//END OF CALSS

void expressiontree::insert()//START OF FUNCTION
{
	stack <node*>s1;
	stack <node*>s2;
	char postfix[20];
	char ch;
	int i=0;
	node *curr,*temp1,*temp2;
	cout<<"Enter the POSTFIX expression: ";
	cin>>postfix;

	while(postfix[i]!='\0')
	{
		ch=postfix[i];
		i++;

		curr=new node;
		curr->data=ch;
		curr->left=curr->right=NULL;

		if(ch>='a' && ch<='z')
			s1.push(curr);

		else
		{
			temp1=s1.pop();
			temp2=s1.pop();
			curr->left=temp2;
			curr->right=temp1;
			s1.push(curr);
		}
	}root=s1.pop();
}//END OF FUNCTION

void expressiontree::swap(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		swap(root->left);
		swap(root->right);
		t=root->left;
		root->left=root->right;
		root->right=t;
	}
}//END OF FUNCTION
void expressiontree::inorder(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
	}
}//END OF FUNCTION
void expressiontree::preorder(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		cout<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}//END OF FUNCTION
void expressiontree::postorder(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data;
	}
}//END OF FUNCTION
void expressiontree::non_reinorder(node *root)//START OF FUNCTION
{
	stack <node*>s;
	node *temp;
	temp=root;
	do
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		if(!s.isempty())
		{
			temp=s.pop();
			cout<<temp->data;
			temp=temp->right;
		}
		else
			break;
	}while(1);
}//END OF FUNCTION
void expressiontree:: non_repreorder(node *root)//START OF FUNCTION
{
	stack <node*>s;
	node *temp;
	temp=root;
	do
	{
		while(temp!=NULL)
		{
			cout<<temp->data;
			s.push(temp);
			temp=temp->left;
		}
		if(!s.isempty())
		{
			temp=s.pop();
			temp=temp->right;
		}
		else
			break;
	}while(1);
}//END OF FUNCTION
void expressiontree::non_repostorder(node *root)//START OF FUNCTION
{
	stack <node*>s1;
	stack <char>s2;
	char ch;
	node *temp;
	temp=root;
	do
	{
	while(temp!=NULL)
		{
			s1.push(temp);
			s2.push('L');
			temp=temp->left;
		}
		if(!s1.isempty())
		{
			temp=s1.pop();
			ch=s2.pop();

			if(ch=='L')
			{
				s1.push(temp);
				s2.push('R');
				temp=temp->right;
			}
			else
			{
				cout<<temp->data;
				temp=NULL;
			}
		}
		else
			break;
	}while(1);
}//END OF FUNCTION

void expressiontree::bfs(node *root)//START OF FUNCTION
{
	Queue<node*>Q;
	node *temp,*t;
	temp=root;
	Q.insert(temp);
	cout<<" "<<temp->data<<endl;
	while(!Q.isempty())
	{
		t=Q.delete1();
		if(t->left!=NULL)
		{
			Q.insert(t->left);
			cout<<t->left->data<<" ";
		}
		if(t->right!=NULL)
		{
			Q.insert(t->right);
			cout<<t->right->data<<" "; 
		}
	}
}//END OF FUNCTION

int main()//START OF FUNCTION
{
	expressiontree exT;
	int choice;
	do
	{
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"1.Create a Expression Tree"<<endl;
		cout<<"2.Display Expression Tree in IN order"<<endl;
		cout<<"3.Display Expression Tree in PRE order"<<endl;
		cout<<"4.Display Expression Tree in POST order"<<endl;
		cout<<"5.Display Expression Tree in NON RECURSIVE IN order"<<endl;
		cout<<"6.Display Expression Tree in NON RECURSIVE PRE order"<<endl;
		cout<<"7.Display Expression Tree in NON RECURSIVE POST order"<<endl;
		cout<<"8.Swap"<<endl;
		cout<<"9.BFS"<<endl;
		cout<<"10.EXIT"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				exT.insert();
				break;
			case 2:
				cout<<"Inorder: ";
				exT.inorder(exT.root);
				cout<<endl;
				break;
			case 3:
				cout<<"Preorder: ";
				exT.preorder(exT.root);
				cout<<endl;
				break;
			case 4:
				cout<<"Postorder: ";
				exT.postorder(exT.root);
				cout<<endl;
				break;
			case 5:
				cout<<"Non RE Inorder: ";
				exT.non_reinorder(exT.root);
				cout<<endl;
				break;
			case 6:
				cout<<"Non RE preorder: ";
				exT.non_repreorder(exT.root);
				cout<<endl;
				break;
			case 7:
				cout<<"Non RE postorder: ";
				exT.non_repostorder(exT.root);
				cout<<endl;
				break;
			case 8:
				exT.swap(exT.root);
				cout<<endl;
				break;
			case 9:
				exT.bfs(exT.root);
				cout<<endl;
				break;
			case 10:
				cout<<"\nEXIT"<<endl;
				break;
		}
	}while(choice<10);
	return 0;
}//END OF FUNCTION

// OUTPUT
/*
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 1
Enter the POSTFIX expression: ab+cd+*
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 2
Inorder: a+b*c+d
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 3
Preorder: *+ab+cd
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 4
Postorder: ab+cd+*
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 5
Non RE Inorder: a+b*c+d
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 6
Non RE preorder: *+ab+cd
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 7
Non RE postorder: ab+cd+*
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 9
 *
+ + a b c d
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 8

-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 2
Inorder: d+c*b+a
-------------------------------------------------------
1.Create a Expression Tree
2.Display Expression Tree in IN order
3.Display Expression Tree in PRE order
4.Display Expression Tree in POST order
5.Display Expression Tree in NON RECURSIVE IN order
6.Display Expression Tree in NON RECURSIVE PRE order
7.Display Expression Tree in NON RECURSIVE POST order
8.Swap
9.BFS
10.EXIT
-----------------------------------------------------
Enter Choice: 10

EXIT
*/
