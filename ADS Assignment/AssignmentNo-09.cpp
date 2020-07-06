/*
                                    ASSIGNMENT NO - 09

Assignment Statement:- A Dictionary stores keyword and its meaning.Provid facility for adding new keyword,deleting keyword,updating value of
			           any entry.Provid facility to display data sort in ascending/descending order.Also find how many maximum comparision
			           are required to finding any keyword.Use height balance tree and find the complexity for finding a keyword.
Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

struct avlNode//STATR OF CLASS
{
public:
	string word;
	string meaning;
	struct avlNode *left;
	struct avlNode *right;
}*root;//END OF CLASS

class avlTree//STATR OF CLASS
{
public:
	avlTree()
	{
		root=NULL;
	}

	avlNode* insert(avlNode *,string,string);
	avlNode* balance(avlNode *);
	avlNode *rrRotation(avlNode *);
	avlNode *rlRotation(avlNode *);
	avlNode *llRotation(avlNode *);
	avlNode *lrRotation(avlNode *);
	int height(avlNode *);
	int diff(avlNode *);
	void inorder(avlNode *);
	void preorder(avlNode *);
	void postorder(avlNode *);
	void deleteNode(avlNode *,string);
	void updateNode(avlNode *,string);
	void searchNode(avlNode *,string);
};//END OF CLASS

avlNode *avlTree::insert(avlNode *root,string word1,string meaning1)//START OF FUNCTION
{
	if(root==NULL)
	{
		//cout<<"\n1."<<endl;
		root=new avlNode;
		root->word=word1;
		root->meaning=meaning1;
		root->left=NULL;
		root->right=NULL;
		//cout<<root->word;
		return root;
	}
	else if(word1 < root->word)
	{
		//cout<<"\n2."<<endl;
		root->left=insert(root->left,word1,meaning1);
		root=balance(root);
	}
	else if(word1 >= root->word)
	{
		//cout<<"\n3."<<endl;
		root->right=insert(root->right,word1,meaning1);
		root=balance(root);
	}
	return root;
}//END OF FUNCTION

avlNode *avlTree::balance(avlNode *temp)//START OF FUNCTION
{
	int balFactor=diff(temp);

	if(balFactor > 1)
	{
		//cout<<"\n4."<<endl;
		if( diff( temp -> left ) > 0){
			temp=llRotation(temp);
			//cout<<"\n5."<<endl;
		}
		else{
			temp=lrRotation(temp);
			//cout<<"\n6."<<endl;
		}
	}
	else if( balFactor < -1)
	{
		if( diff( temp -> right ) > 0){
			//cout<<"\n7."<<endl;
			temp=rlRotation(temp);
		}
		else{
			//cout<<"\n8."<<endl;
			temp=rrRotation(temp);
		}
	}

	return temp;
}//END OF FUNCTION

int avlTree::diff(avlNode *temp)//START OF FUNCTION
{
	//cout<<"\n9."<<endl;
	int l_height=height(temp->left);
	int r_height=height(temp->right);
	int b_factor=l_height - r_height;
	return b_factor;
}//END OF FUNCTION
int avlTree :: height( avlNode *temp)//START OF FUNCTION
{
	int h=0;
	if(temp!=NULL)
	{
		//cout<<"\n10."<<endl;
		int l_height=height(temp->left);
		int r_height=height(temp->right);
		int max_height=max(l_height,r_height);
		h=max_height+1;
	}

	return h;
}//END OF FUNCTION

avlNode *avlTree:: rrRotation(avlNode *parent)//START OF FUNCTION
{
	//cout<<"\n11."<<endl;
	avlNode *temp;
	temp=parent->right;
	parent->right=temp->left;
	temp->left=parent;
	return temp;
}//END OF FUNCTION
avlNode *avlTree:: rlRotation(avlNode *parent)//START OF FUNCTION
{
	//cout<<"\n12."<<endl;
	avlNode *temp;	
	temp=parent->right;
	parent->right=llRotation(temp);
	return rrRotation(parent);
}//END OF FUNCTION
avlNode *avlTree:: llRotation(avlNode *parent)//START OF FUNCTION
{
	//cout<<"\n13."<<endl;
	avlNode *temp;
	temp=parent->left;
	parent->left=temp->right;
	temp->right=parent;
	return temp;
}//END OF FUNCTION
avlNode *avlTree:: lrRotation(avlNode *parent)//START OF FUNCTION
{
	//cout<<"\n14."<<endl;
	avlNode *temp;
	temp=parent->left;
	parent->left=rrRotation(temp);
	return llRotation(parent);
}//END OF FUNCTION

void avlTree :: inorder(avlNode *temp)//START OF FUNCTION
{
	
	if(temp!=NULL)
	{
		//cout<<"\n15."<<endl;
		inorder(temp->left);
		cout<<temp->word<<":-"<<temp->meaning<<endl;
		inorder(temp->right);
	}
}//END OF FUNCTION
void avlTree :: preorder(avlNode *temp)//START OF FUNCTION
{
	if(temp==NULL)
		return;
	cout<<temp->word<<":-"<<temp->meaning<<endl;
	inorder(temp->left);
	inorder(temp->right);
}//END OF FUNCTION
void avlTree :: postorder(avlNode *temp)//START OF FUNCTION
{
	if(temp==NULL)
		return;
	inorder(temp->left);
	inorder(temp->right);
	cout<<temp->word<<":-"<<temp->meaning<<endl;
}//END OF FUNCTION

void avlTree::searchNode(avlNode *temp,string word1)//START OF FUNCTION
{
	int count=0;
	while(temp!=NULL)
	{
		if(word1 < temp-> word)
		{
			count++;
			temp=temp->left;
		}

		else if(word1 > temp ->word)
		{
			count++;
			temp=temp->right;
		}

		else if(word1==temp->word)
		{
			count++;
			cout<<"\nFound........."<<endl;
			cout<<"\nNumber Of Comparisions Required: ";
			cout<<count<<endl;
			cout<<temp->word<<":-"<<temp->meaning;
			break;
		}
		else
		{
			cout<<"\nNOT Found........."<<endl;
			break;
		}
	}	
}//END OF FUNCTION

void avlTree::updateNode(avlNode *temp,string word1)//START OF FUNCTION
{
	string w1;
	string m1;
	while(temp!=NULL)
	{
		if(word1 < temp-> word)
		{
			temp=temp->left;
		}

		else if(word1 > temp ->word)
		{
			temp=temp->right;
		}

		else if(word1==temp->word)
		{
			cout<<"\nEnter Word   : ";
			cin>>w1;
			cout<<"\nEnter Meaning: ";
			cin>>m1;
			temp->word=w1;
			temp->meaning=m1;
			break;
		}
	}	
}//END OF FUNCTION
int main()//START OF FUNCTION
{
	int choice;
	avlTree AT;
	string word1;
	string meaning1;
	string w2;
	string w3;
	while(1)
	{
		cout<<"\n==================================="<<endl;
		cout<<"1.Insert Elements in the Tree"<<endl;
		cout<<"2.Search Meaningin AVL Tree"<<endl;
		cout<<"3.In-order Traversal"<<endl;
		cout<<"4.Pre-order Traversal"<<endl;
		cout<<"5.Post-orde Traversal"<<endl;
		cout<<"6.Update Information"<<endl;
		cout<<"7.EXIT from PROGRAM"<<endl;
		cout<<"\n==================================="<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\nEnter Word    : ";
				cin>>word1;
				cout<<"\nEnter Meaning : ";
				cin>>meaning1;
				root=AT.insert(root,word1,meaning1);
				cout<<"\nData Succesfully Added in Tree....."<<endl;
				break;
			case 2:
				cout<<"\nEnter Word to Search : ";
				cin>>w2;
				AT.searchNode(root,w2);
				break;
			case 3:
				cout<<"\nIn Order Traversal: "<<endl;
				AT.inorder(root);
				break;
			case 4:
				cout<<"\nPre Order Traversal: "<<endl;
				AT.preorder(root);
				break;
			case 5:
				cout<<"\nPost Order Traversal: "<<endl;
				AT.postorder(root);
				break;
			case 6:
				cout<<"\nEnter Word to Update : ";
				cin>>w3;
				AT.updateNode(root,w3);
				break;
			case 7:
				cout<<"\nEXIT........."<<endl;
				exit(1);
				break;
		}
	}
	return 0;
}//END OF FUNCTION

//OUTPUT
/*

1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : a

Enter Meaning : a

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : z

Enter Meaning : z

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : t

Enter Meaning : t

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : d

Enter Meaning : d

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : g

Enter Meaning : g

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : k

Enter Meaning : k

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : q

Enter Meaning : q

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : m

Enter Meaning : m

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 1

Enter Word    : c

Enter Meaning : c

Data Succesfully Added in Tree.....

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 3

In Order Traversal:
a:-a
c:-c
d:-d
g:-g
k:-k
m:-m
q:-q
t:-t
z:-z

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 2

Enter Word to Search : k

Found.........

Number Of Comparisions Required: 4
k:-k
===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 4

Pre Order Traversal:
g:-g
a:-a
c:-c
d:-d
k:-k
m:-m
q:-q
t:-t
z:-z

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 5

Post Order Traversal:
a:-a
c:-c
d:-d
k:-k
m:-m
q:-q
t:-t
z:-z
g:-g

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 6

Enter Word to Update : t

Enter Word   : t

Enter Meaning: q

===================================
1.Insert Elements in the Tree
2.Search Meaningin AVL Tree
3.In-order Traversal
4.Pre-order Traversal
5.Post-orde Traversal
6.Update Information
7.EXIT from PROGRAM

===================================
Enter Choice: 7

EXIT.........
*/