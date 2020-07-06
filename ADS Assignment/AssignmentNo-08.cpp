/*
                                    ASSIGNMENT NO - 08

Assignment Statement:- Impement all the functions of dictionary( ADT ) using hashing data: set of(key,value)pairs,keys are mapped to 
					   values,key must be comparable,key must be unique.Standard operation: Insert(key,value),find(key),Delete(key).

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;
string upper(string);
struct node//STATR OF CLASS
{
	public:
	string word;
	string meaning;
	node *next;
};//END OF CLASS
class dictionary//STATR OF CLASS
{
	public:
	node *nd[26];
	int MAX;

	dictionary()
	{
		MAX=150;
		for(int i=0;i<26;i++)
		{
			nd[i]=new node;
			nd[i]->word=" ";
			nd[i]->meaning=" ";
			nd[i]->next=NULL;
		}
	}	
	void insert();
	int hash(string);
	void linearprobing(node *);
	void display();
	int search(string);
	int delete1(string);
};//END OF CLASS
int dictionary::hash(string key)//START OF FUNCTION
{
	return (key[0]-65);
}//END OF FUNCTION
void dictionary::insert()//START OF FUNCTION
{	
	int n;
	node *curr;
	ifstream fin("dictionary.txt");
	cout<<"Enter Number of Words: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		curr=new node;
		curr->next=NULL;
		getline(fin,curr->word);
		getline(fin,curr->meaning);
		
		curr->word=upper(curr->word);
		curr->meaning=upper(curr->meaning);
		linearprobing(curr);
	}
}//END OF FUNCTION

void dictionary::display()//START OF FUNCTION
{
	node *temp;
	char m;
	for(int i=0;i<26;i++)
	{
		m=i+65;
		cout<<m<<":-"<<endl;
		temp=nd[i];
		int n=0;
		while(temp!=NULL)
		{
			if(temp->word!=" ")
			{
				cout<<"  "<<n+1<<". "<<temp->word<<" - "<<temp->meaning<<endl;
				n++;
			}
			temp=temp->next;
		}
		cout<<endl;
	}
}//END OF FUNCTION

/*void dictionary::linearprobing(node *curr)
{
	int t;
	node *temp;
	t=hash(curr->word);
	if(nd[t]->word==" ")
	{
		nd[t]=curr;
	}
	else
	{
		temp=nd[t];
		do{
			if(temp->next==NULL)
			{
				temp->next=curr;
				break;
			}
			else
				temp=temp->next;
		}while(1);
	}
}*/
void dictionary::linearprobing(node *curr)//START OF FUNCTION
{
	int t;
	node *temp;
	t=hash(curr->word);
	if(nd[t]->word==" ")
	{
		nd[t]=curr;
	}
	else
	{
		temp=nd[t];
		do{
			if(temp->next==NULL)
			{
				temp->next=curr;
				break;
			}
			else
				temp=temp->next;
		}while(1);
	}
}//END OF FUNCTION


int dictionary:: search(string ch)//START OF FUNCTION
{
	int m=hash(ch);
	cout<<m;	
	node *temp=nd[m];
	while(temp!=NULL)
	{
		if(temp->word==ch)
		{
			cout<<"\n\t======================================================="<<endl;
			cout<<setw(15)<<"INDEX"<<setw(20)<<"WORD"<<setw(25)<<"MEANING"<<"\t\t"<<endl;
			cout<<"\t======================================================="<<endl;
			cout<<setw(15)<<m<<setw(20)<<temp->word<<setw(25)<<temp->meaning<<"\t\t"<<endl;
			return m;
		}
		temp=temp->next;
	}
	cout<<"\n\tNOT FOUND"<<endl;
	return 0;
}//END OF FUNCTION

int dictionary::delete1(string ch)//START OF FUNCTION
{
	int m=hash(ch);
	cout<<m;
	node *temp=nd[m];
	while(temp!=NULL)
	{
		if(temp->word==ch)
		{
			if(nd[m]->next!=NULL)
			{
				nd[m]=temp->next;
			}
			else
			{
				temp->word=" ";
				temp->meaning=" ";
			}
			return 1;
		}
		else if(temp->next->word==ch)
		{
			node *t=temp->next;
			temp->next=t->next;
			delete(t);
			return 1;
		}
		else
		temp=temp->next;
	}
	cout<<"\n\tNOT FOUND"<<endl;
	return 0;
}//END OF FUNCTION
string upper(string ch)//START OF FUNCTION
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]>=97&&ch[i]<=122)
		{
			ch[i]=ch[i]-32;
		}
		else
			ch[i]=ch[i];
	}
	ch[i]='\0';
	return ch;
}//END OF FUNCTION
int main()//START OF FUNCTION
{
	string ch1;
	string ch2;
	int ch,i;
	dictionary ht;
	do{
		cout<<"\n------------------------"<<endl;
        cout<<"1.Insert "<<endl;
        cout<<"2.Display Dictionary. "<<endl;
        cout<<"3.Search Meaning in Dictionary."<<endl;
        cout<<"4.Delete Word."<<endl;
        cout<<"5.Exit."<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                    ht.insert();
                    break;
            case 2:
                    ht.display();
                    break;
            case 3:
            		cout<<"\nEnter Word to Search: ";
            		cin>>ch1;
            		ch1=upper(ch1);
            		ht.search(ch1);
                    break;
            case 4:
            		cout<<"\nEnter Word to Delete: ";
            		cin>>ch2;
            		ch2=upper(ch2);
                    ht.delete1(ch2);
                    break;
            case 5:
                   exit(1);       
        }
    }while(ch!=5);	
	return 0;
}//END OF FUNCTION

// OUTPUT
/*
------------------------
1.Insert
2.Display Dictionary.
3.Search Meaning in Dictionary.
4.Delete Word.
5.Exit.
---------------------------
Choice:1
Enter Number of Words: 20

------------------------
1.Insert
2.Display Dictionary.
3.Search Meaning in Dictionary.
4.Delete Word.
5.Exit.
---------------------------
Choice:2
A:-
  1. ABNEGATION - -RENOUNCING A BELIEF OR DOCTRINE
  2. AGGRANDIZE - -ENHANCE POWER, WEALTH OR STATUS
  3. ALACRITY - -EAGERNESS
  4. ANACHRONISTIC - -MISPLACED CHRONOLOGICALLY
  5. ARCHETYPAL - -QUINTESSENTIAL OF A CERTAIN KIND
  6. ASCETIC - -ONE WHO PRACTICES SELF-DENIAL AS PART OF SPIRITUAL DISCIPLINE

B:-
  1. BEGUILE - -INFLUENCE SOMEONE IN A DECEPTIVE WAY
  2. BLANDISHMENT - -INTENTIONAL FLATTERY FOR PERSUASION

C:-
  1. CAJOLE - -PERSUADE BY FLATTERY OR COAXING
  2. CALLOUS - -DISREGARD FOR OTHERS
  3. CAMARADERIE - -A SENSE OF SOLIDARITY ARISING OUT OF FAMILIARITY AND SOCIABILITY
  4. CIRCUMLOCUTION - -EXPRESSING SOMEONE IN AN INDIRECT WAY
  5. CLAMOR - -PROCLAIM SOMETHING NOISILY
  6. COGNIZANT - -AWARENESS OR REALIZATION
  7. CONSTRUE - -INTERPRET OR ASSIGN MEANING
  8. CONVIVIAL - -ENJOYABLE ATMOSPHERE OR JOVIAL COMPANY

D:-
  1. DEMAGOGUE - -A POLITICAL LEADER WHO USES RHETORIC TO APPEAL TO PREJUDICES AND DESIRES OF ORDINARY CITIZENS
  2. DENIGRATE - -BELITTLE SOMEONE
  3. DIDACTIC - -INSTRUCTIVE WITH A MORAL INTENT
  4. DISPARATE - -OF A DISTINCT KIND

E:-

F:-

G:-

H:-

I:-

J:-

K:-

L:-

M:-

N:-

O:-

P:-

Q:-

R:-

S:-

T:-

U:-

V:-

W:-

X:-

Y:-

Z:-


------------------------
1.Insert
2.Display Dictionary.
3.Search Meaning in Dictionary.
4.Delete Word.
5.Exit.
---------------------------
Choice:3

Enter Word to Search: cajole
2
        =======================================================
          INDEX                WORD                  MEANING
        =======================================================
              2              CAJOLE-PERSUADE BY FLATTERY OR COAXING

------------------------
1.Insert
2.Display Dictionary.
3.Search Meaning in Dictionary.
4.Delete Word.
5.Exit.
---------------------------
Choice:4

Enter Word to Delete: cajole
2
------------------------
1.Insert
2.Display Dictionary.
3.Search Meaning in Dictionary.
4.Delete Word.
5.Exit.
---------------------------
Choice:5
*/