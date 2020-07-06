/*
                                    ASSIGNMENT NO - 04
Assignment Statement:- A Dictionary stores keyword and its meaning.Provid facility for adding new keyword,deleting keyword,updating value
                       of any entry.Provid facility to display data sort in ascending/descending order.Also find how many maximum
                       comparision are required to finding any keyword.Use Binary Search Tree for impelentation.

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/
#include<iostream>
#include<string.h>
using namespace std;

class node//STATR OF CLASS
{
	public:
		node *right,*left;
		char word[20];
		char meaning[20];
};//END OF CLASS

class dict//STATR OF CLASS
{
	public:
		node *root;
		dict()
		{
			root=NULL;
		}
		void inserts();
        int search_element(char []);
        int get_height(node *);
        void inorder(node *);
		void preorder(node *);
		void postorder(node *);
		void descending_order(node *);
		node* delete_node(node*,char[]);
		node* FindMin(node*);
		void getminmax();
};//END OF CLASS

void dict::inserts()//START OF FUNCTION
{
    node *temp,*curr;
    curr=new node;
    cout<<"\n Enter word: ";
    cin>>curr->word;
    cout<<" Enter Meaning: ";
    cin>>curr->meaning;
    curr->left=curr->right=NULL;
    if(root==NULL)
    {
    	root=curr;
    	cout<<"\n"<<" Root is created."<<endl;
    }
    else
    {
        temp=root;
        while(1)
        {
            if(strcmp(curr->word,temp->word)<0)
            {
                if(temp->left==NULL)
                {
                    temp->left=curr;
                    break;
                }
                else
                    temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=curr;
                    break;
                }
                else
                    temp=temp->right;
            }
        }
    }
    cout<<" "<<curr->word<<" is successfully inserted in dictionary."<<endl;
}//END OF FUNCTION

int dict::search_element(char element[20])//START OF FUNCTION
{
    node *temp;
    temp=root;
    while(temp!=NULL)
    {
        if(strcmp(temp->word,element)==0)
        {
            cout<<"\tcount";
            cout<<"\n"<<" "<<temp->word<<": ";
			cout<<temp->meaning<<endl;
            return 1;
            break;
        }
    	else if(strcmp(element,temp->word)<0)
        {
            cout<<"\tcount";
            temp=temp->left;
        }
        else
        {
            cout<<"\tcount";
            temp=temp->right;
        }
    }
}//END OF FUNCTION

int dict::get_height(node *root)//START OF FUNCTION
{
    int hl,hr;
    if(root==NULL)
        return 0;
    else
    {
        hl=get_height(root->left);
        hr=get_height(root->right);
        if(hl>hr)
            return hl+1;
        else
            return hr+1;
    }
}//END OF FUNCTION

void dict::getminmax()//START OF FUNCTION
{
    node *temp;
    temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    cout<<"\n Minimum(left most) element in dictionary is: "<<temp->word;

    temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    cout<<"\n Maximum(right most) element in dictionary is: "<<temp->word;
}//END OF FUNCTION

node* dict::FindMin(node*root)//START OF FUNCTION
{
    while(root->left!=NULL)
        root=root->left;
    return root;

}//END OF FUNCTION


node* dict::delete_node(node*root,char d[30])//START OF FUNCTION
{
	if(root==NULL)
	    return root;
	else if(strcmp(d,root->word)<0)
	{
	    root->left=delete_node(root->left,d);
	}
	else if(strcmp(d,root->word)>0)
	{
	    root->right=delete_node(root->right,d);
	}
	else                                //element is found
	{
	    //Case 1-No Child
	    if(root->left==NULL && root->right==NULL)
	    {
	        delete root;
	        root=NULL;
	    }
	    //Case 2-One Child
	    else if(root->left==NULL)
	    {
	        node*temp=root;
	        root=root->right;
	        delete temp;
	    }
	    else if(root->right==NULL)
	    {
	        node*temp=root;
	        root=root->left;
	        delete temp;
	    }
	    //Case 3-Two Children
	  else
	    {
	        node*temp=FindMin(root->right);
	        strcpy(root->word,temp->word);
	        root->right=delete_node(root->right,temp->word);
	    }
	    return root;
	}
}//END OF FUNCTION


void dict::inorder(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"\n"<<" "<<root->word<<": ";
		cout<<root->meaning<<endl;
		inorder(root->right);
	}
}//END OF FUNCTION

void dict::preorder(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		cout<<"\n"<<" "<<root->word<<": ";
		cout<<root->meaning<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}//END OF FUNCTION

void dict::postorder(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<"\n"<<" "<<root->word<<": ";
		cout<<root->meaning<<endl;
	}
}//END OF FUNCTION

void dict::descending_order(node *root)//START OF FUNCTION
{
	if(root!=NULL)
	{
		inorder(root->right);
		cout<<"\n"<<" "<<root->word<<": ";
		cout<<root->meaning<<endl;
		inorder(root->left);
	}
}//END OF FUNCTION

int main()//START OF FUNCTION
{
    dict dt;
    int no,ne,n,m;
    char ch,se[20],de[20];
	do
	{
		cout<<"\n-----------------------------------------------------------------------\n";
		cout<<"\n 1.Create Dictionary/Insert new element\n 2.IN ORDER (Ascending)Traversing\n 3.Get height of tree\n 4.Delete element\n 5.Search element\n 6.PRE ORDER Traversing\n 7.POST ORDER Traversing\n 8.Minimum and maximum element in Dictionary\n 9.Elements in Descending order\n\n Enter your choice: ";
		cin>>no;
		cout<<"\n-----------------------------------------------------------------------\n";
		switch(no)
		{
		    case 1:
                cout<<"\n Creating Dictionary.... "<<endl;
                cout<<"\n Enter no. of elements to be insert: ";
                cin>>ne;
				for(int i=0;i<ne;i++)
                    dt.inserts();
				break;

			case 2:
                cout<<"\n Dictionary elements in INORDER: ";
				dt.inorder(dt.root);
				break;

            case 3:
                m=dt.get_height(dt.root);
                cout<<"\n Height of the dictionary is: "<<m<<endl;
                break;

            case 4:
                cout<<"\n Enter element to be deleted: ";
                cin>>de;
               	n=dt.search_element(de);
                if(n==1)
                {
                    dt.delete_node(dt.root,de);
                    cout<<"\n "<<de<<" is found in dictionary and it is deleted."<<endl;
                }
                else
                    cout<<"\n "<<de<<" is not found in dictionary and it can not be deleted."<<endl;
                break;

            case 5:
                cout<<"\n Enter element to be searched: ";
                cin>>se;
                n=dt.search_element(se);
                if(n==1)
                    cout<<"\n "<<se<<" is found in dictionary."<<endl;
                else
                    cout<<"\n "<<se<<" is not found in dictionary."<<endl;
                break;

			case 6:
				cout<<"\n dictionary elements in PREORDER: ";
				dt.preorder(dt.root);
				break;

			case 7:
				cout<<"\n dictionary elements in POSTORDER: ";
				dt.postorder(dt.root);
				break;

            case 8:
                dt.getminmax();
                break;

            case 9:
                cout<<"\n Dictionary elements in descending order: ";
                dt.descending_order(dt.root);
                break;

			default:
				cout<<"\n Enter valid choice."<<endl;\
				break;
		}
		cout<<"\n-----------------------------------------------------------------------\n";
		cout<<"\n Do you want to continue?(y or n): ";
		cin>>ch;
	}
	while(ch=='y'|| ch=='Y');
	cout<<"\n-----------------------------------------------------------------------\n";
    return 0;
}//END OF FUNCTION
// OUTPUT
/*
-----------------------------------------------------------------------

 1.Create Dictionary/Insert new element
 2.IN ORDER (Ascending)Traversing
 3.Get height of tree
 4.Delete element
 5.Search element
 6.PRE ORDER Traversing
 7.POST ORDER Traversing
 8.Minimum and maximum element in Dictionary
 9.Elements in Descending order

 Enter your choice: 1

-----------------------------------------------------------------------

 Creating Dictionary....

 Enter no. of elements to be insert: 5

 Enter word: direction
 Enter Meaning: way

 Root is created.
 direction is successfully inserted in dictionary.

 Enter word: real
 Enter Meaning: existing
 real is successfully inserted in dictionary.

 Enter word: help
 Enter Meaning: need
 help is successfully inserted in dictionary.

 Enter word: little
 Enter Meaning: small
 little is successfully inserted in dictionary.

 Enter word: synonym
 Enter Meaning: same
 synonym is successfully inserted in dictionary.

-----------------------------------------------------------------------

 Do you want to continue?(y or n): y

-----------------------------------------------------------------------

 1.Create Dictionary/Insert new element
 2.IN ORDER (Ascending)Traversing
 3.Get height of tree
 4.Delete element
 5.Search element
 6.PRE ORDER Traversing
 7.POST ORDER Traversing
 8.Minimum and maximum element in Dictionary
 9.Elements in Descending order

 Enter your choice: 2

-----------------------------------------------------------------------

 Dictionary elements in INORDER:
 direction: way

 help: need

 little: small

 real: existing

 synonym: same

-----------------------------------------------------------------------

 Do you want to continue?(y or n): y

-----------------------------------------------------------------------

 1.Create Dictionary/Insert new element
 2.IN ORDER (Ascending)Traversing
 3.Get height of tree
 4.Delete element
 5.Search element
 6.PRE ORDER Traversing
 7.POST ORDER Traversing
 8.Minimum and maximum element in Dictionary
 9.Elements in Descending order

 Enter your choice: 3

-----------------------------------------------------------------------

 Height of the dictionary is: 4

-----------------------------------------------------------------------

 Do you want to continue?(y or n): y

-----------------------------------------------------------------------

 1.Create Dictionary/Insert new element
 2.IN ORDER (Ascending)Traversing
 3.Get height of tree
 4.Delete element
 5.Search element
 6.PRE ORDER Traversing
 7.POST ORDER Traversing
 8.Minimum and maximum element in Dictionary
 9.Elements in Descending order

 Enter your choice: 4

-----------------------------------------------------------------------

 Enter element to be deleted: direction
        count
 direction: way

 direction is found in dictionary and it is deleted.

-----------------------------------------------------------------------

 Do you want to continue?(y or n): y

-----------------------------------------------------------------------

 1.Create Dictionary/Insert new element
 2.IN ORDER (Ascending)Traversing
 3.Get height of tree
 4.Delete element
 5.Search element
 6.PRE ORDER Traversing
 7.POST ORDER Traversing
 8.Minimum and maximum element in Dictionary
 9.Elements in Descending order

 Enter your choice: 5

-----------------------------------------------------------------------

 Enter element to be searched: direction
        count
 direction: way

 direction is found in dictionary.

-----------------------------------------------------------------------

 Do you want to continue?(y or n): y

-----------------------------------------------------------------------

 1.Create Dictionary/Insert new element
 2.IN ORDER (Ascending)Traversing
 3.Get height of tree
 4.Delete element
 5.Search element
 6.PRE ORDER Traversing
 7.POST ORDER Traversing
 8.Minimum and maximum element in Dictionary
 9.Elements in Descending order
 */