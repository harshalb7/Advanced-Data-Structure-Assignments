/*
                                    ASSIGNMENT NO - 05

Assignment Statement:- Convert a given Binary Tree into Threaded Binary Tree.Analyze space and time complexity of Algorithm.
                                    
Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/
#include<iostream>
using namespace std;
class node//STATR OF CLASS
{
	public:
	int data;
	node *left,*right;
	int lthread,rthread;
	node()
	{
		lthread=1;rthread=1;	 
	}
};//END OF CLASS

class tbst//STATR OF CLASS
{
	public:
		node *root;
		node *head;
		tbst()
		{
			root=NULL;
		} 
		void insert();
		void preorder(node *root);
		void inorder(node *root);
		int inordersuccessor(node *root,int key);
};//END OF CLASS

void tbst::insert()//START OF FUNCTION
{
	node *curr,*temp;
    curr=new node;
    cout<<"\nEnter the value of node: ";
    cin>>curr->data;
    curr->left=curr->right=NULL;
    if(root==NULL)
    {
    	root=curr;
    	head=new node;
    	head->left=root;
    	head->right=NULL;
    	root->left=root->right=head;
    }
    else
    {
    	temp=root;
    	 while(1)
    	 {
    	 	if(curr->data<temp->data)
    	 	{
    	 		if(temp->lthread==1)
    	 		{
    	 			curr->left=temp->left;
    	 			temp->left=curr;
    	 			temp->lthread=0;
    	 			curr->right=temp;
    	 			break;
    	 		}
    	 		else
    	 			temp=temp->left;
    	 	}
    	 	else
    	 	{
    	 		if(temp->rthread==1)
    	 		{
    	 			curr->right=temp->right;
    	 			temp->right=curr;
    	 			temp->rthread=0;
    	 			curr->left=temp;
    	 			break;
    	 		}
    	 		else
    	 			temp=temp->right;
    	 	}
    	 }	
    }
}//END OF FUNCTION

void tbst::preorder(node *root)//START OF FUNCTION
{
	node *temp;
	int flag=0;
	temp=root;
	while(temp!=head)
	{
		if(flag==0)
			cout<<temp->data<<" ";
		if(temp->lthread==0&&flag==0)
			temp=temp->left;
		else
		{
			if(temp->rthread==0)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->right;
				flag=1;
			}
		} 
	}
}//END OF FUNCTION
void tbst::inorder(node *root)//START OF FUNCTION
{
	node *temp;
	int flag=0;
	temp=root;
	while(temp!=head)
	{
		if(temp->lthread==0 && flag==0)
			temp=temp->left;
		else
		{
			cout<<temp->data<<" ";
			if(temp->rthread==0)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->right;
				flag=1;
			}
		} 
	}
}//END OF FUNCTION
int tbst::inordersuccessor(node *temp,int key)//START OF FUNCTION
{
	while(temp!=head)
	{
		if(temp->data==key)
			break;
		else if(key<temp->data && temp->lthread==0)
            temp=temp->left;  
        else if(key>temp->data && temp->rthread==0)
            temp=temp->right;
	}
	if(temp->rthread==0)	
		temp=temp->right;
	if(!temp->rthread)
	{
		while(!temp->lthread)
		{
			temp=temp->left;
		}
	}
	return temp->data;	
}//END OF FUNCTION


int main()//START OF FUNCTION
{
    tbst bt;
    int ch;
    int m=0,n,lm;
    int key;
    do
    {
        cout<<"\n----------------------------------------"<<endl;
        cout<<"1.Insert NEW Node in A TREE. "<<endl;
        cout<<"2.Find Inorder Succesor. "<<endl;
        cout<<"3.Inorder."<<endl;
        cout<<"4.Preorder."<<endl;
        cout<<"5.Exit."<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Choice:";
        cin>>ch;
 
        switch(ch)
        {
            case 1:
                    bt.insert();
                    break;
            case 2:
                    cout<<"\nEnter Number: "<<endl;
                    cin>>key;
                    m=bt.inordersuccessor(bt.root,key);
                    cout<<"Inorder Successor of "<<key<<" is: "<<m<<endl;
                    break;
            case 3:
                    bt.inorder(bt.root);
                    break;
            case 4:
                    bt.preorder(bt.root);
                    break;

            case 5:
                    cout<<"\nExit"<<endl;
                    break;
        }
  }while(ch<5);
}//END OF FUNCTION

//OUTPUT
/*
----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:1

Enter the value of node: 20

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:1

Enter the value of node: 10

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:1

Enter the value of node: 30

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:1

Enter the value of node: 6

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:1

Enter the value of node: 12

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:1

Enter the value of node: 24

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:1

Enter the value of node: 35

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:2

Enter Number:
10
Inorder Successor of 10 is: 12

----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:3
6 10 12 20 24 30 35
----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:4
20 10 6 12 30 24 35
----------------------------------------
1.Insert NEW Node in A TREE.
2.Find Inorder Succesor.
3.Inorder.
4.Preorder.
5.Exit.
-----------------------------------------
Choice:5

Exit
*/
