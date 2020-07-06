/*
											ASSIGNMENT NO - 02

Assignment Statement:- Beginning with empty binary search tree,Construct binary search tree by inserting the values in the order given.
                       After construction a binary tree-
							1)Insert new node
							2)Find number of nodes in longest path
							3)Minimum data value found in the tree
							4)Search the value

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A									
*/
#include<iostream>
#include<fstream>
#include"stack.h"
using namespace std;

class node//START OF CALSS NODE
{
	public:
	node *left; //POINTER DECLARATION
	char data;	//VARIABLE DECLARATION
	node *right;//POINTER DECLARATION
};//END OF CLASS NODE

class binaryTree//START OF CLASS BINARYTREE
{
	public:
		node *root;
		binaryTree()//CONSTRUCTOR
		{
			root=NULL;
		}
		
		void create()//START OF CREATE FUNCTION
		{
			int n;
			char ans,l,r,m;
			ifstream file("ip.txt");
			node *curr,*temp;
			//cout<<"\nEnter NO of Nodes: ";
			file>>n;
			cout<<n;
			for(int i=0;i<n;i++){//for lOOP START
				curr=new node;
				//cout<<"\nEnter node ELEMENT: ";
				file>>m;
				curr->data=m;
				curr->left=curr->right=NULL;
				
				if(root==NULL)
					root=curr;
				else
				{
					temp=root;
					do
					{
						//cout<<"Enter LEFT or RIGHT of  "<<temp->data<<" :";
						file>>ans;
							if(ans=='l')
							{
								if(temp->left==NULL)
								{
									temp->left=curr;
									break;
								}
								else
									temp=temp->left;
							}
							else if(ans=='r')
							{
								if(temp->right==NULL)
								{
									temp->right=curr;
									break;
								}
								else
									temp=temp->right;
							}
							else
								cout<<"Enter Valid Choice"<<endl;	
					}while(1);
				}
			}//END OF FOOR LOOP
		}//END OF FUNCTION
		
		void inorder(node *root)//START OF FUNCTION
		{
			if(root!=NULL)
			{
				inorder(root->left);
				cout<<root->data<<" ";
				inorder(root->right);
			}
		}//END OF FUNCTION
		void preorder(node *root)//START OF FUNCTION
		{
			if(root!=NULL)
			{
				cout<<root->data<<" ";
				preorder(root->left);
				preorder(root->right);
			}
		}//END OF FUNCTION
		void postorder(node *root)//START OF FUNCTION
		{
			if(root!=NULL)
			{
				postorder(root->left);
				postorder(root->right);
				cout<<root->data<<" ";
			}
		}//END OF FUNCTION
		void non_reinorder(node *root)//START OF FUNCTION
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
					cout<<temp->data<<" ";
					temp=temp->right;
				}
				else
					break;
			}while(1);
		}//END OF FUNCTION
		void non_repreorder(node *root)//START OF FUNCTION
		{
			stack <node*>s;
			node *temp;
			temp=root;
			do
			{
				while(temp!=NULL)
				{
					cout<<temp->data<<" ";
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
		void non_repostorder(node *root)//START OF FUNCTION
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
							cout<<temp->data<<" ";
							temp=NULL;
						}
					}
					else
						break;
			}while(1);
		}//END OF FUNCTION
};//END OF CLASS

int main()//START OF MAIN FUNCTION
{
	binaryTree bT;
	int  ch;
	
	do
	{
		cout<<"\n---------------------------"<<endl;
		cout<<"1.Insert Node in Tree"<<endl;
		cout<<"2.Display Tree in IN order"<<endl;
		cout<<"3.Display Tree in PRE order"<<endl;
		cout<<"4.Display Tree in POST order"<<endl;
		cout<<"5.Display Tree in NON RECURSIVE IN order"<<endl;
		cout<<"6.Display Tree in NON RECURSIVE PRE order"<<endl;
		cout<<"7.Display Tree in NON RECURSIVE POST order"<<endl;
		cout<<"8.EXIT"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Enter Choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				bT.create();
				break;
			case 2:
				cout<<"Inorder: ";
				bT.inorder(bT.root);
				break;
			case 3:
				cout<<"Preorder: ";
				bT.preorder(bT.root);
				break;
			case 4:
				cout<<"Postorder: ";
				bT.postorder(bT.root);
				break;
			case 5:
				cout<<"Non RE Inorder: ";
				bT.non_reinorder(bT.root);
				break;
			case 6:
				cout<<"Non RE preorder: ";
				bT.non_repreorder(bT.root);
				break;
			case 7:
				cout<<"Non RE postorder: ";
				bT.non_repostorder(bT.root);
				break;
			case 8:
				cout<<"\nEXIT"<<endl;
				break;
		}
	}while(ch<8);
}//END OF MAIN FUNCTION

// OUTPUT
/*
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 1
8
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 2
Inorder: V E B M A Q C D
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 3
Preorder: A B E V M C Q D
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 4
Postorder: V E M B Q D C A
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 5
Non RE Inorder: V E B M A Q C D
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 6
Non RE preorder: A B E V M C Q D
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 7
Non RE postorder: V E M B Q D C A
---------------------------
1.Insert Node in Tree
2.Display Tree in IN order
3.Display Tree in PRE order
4.Display Tree in POST order
5.Display Tree in NON RECURSIVE IN order
6.Display Tree in NON RECURSIVE PRE order
7.Display Tree in NON RECURSIVE POST order
8.EXIT
---------------------------
Enter Choice: 8

EXIT
*/