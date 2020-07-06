/*
                                    ASSIGNMENT NO - 07
                                    
Assignment Statement:- Consider telephone book database of N clients.Make use of hash table impelementation to quickly look up client's 
				       telephone number.

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define max 26
using namespace std;

 struct contact_list//STATR OF CLASS
{
	string name;
	long int mob;
};//END OF CLASS

class hash_t//STATR OF CLASS
{
	contact_list ht[26];
	public:
		hash_t()
		{
			for(int i=0;i<26;i++)
			{
				ht[i].name="";
				ht[i].mob=0;
			}
		}
		void get_data();
		void put_data();
		int hash(string key);
		void delete_contact();
		void linearprobing(contact_list);
		void search();
};//END OF CLASS

int hash_t::hash(string key)//START OF FUNCTION
{
	return(key[0]-97);
}//END OF FUNCTION

void hash_t::get_data()//START OF FUNCTION
{
	
	contact_list temp;
	
		cout<<"\n Enter Name: ";
		cin>>temp.name;
		cout<<"\n Enter contact number: ";
		cin>>temp.mob;
		linearprobing(temp);

}//END OF FUNCTION

void hash_t::linearprobing(contact_list temp)//START OF FUNCTION
{
	int i,t;
	t=hash(temp.name);
	
	if(ht[t].name=="")
	{
		ht[t]=temp;
	}
	else
	{
		for(int i=t+1;i%max!=t;i=i%max+1)
		{
			if(ht[i].name=="")
			{
				ht[i]=temp;
				break;
			}
		}
	}
	
}//END OF FUNCTION

void hash_t::put_data()//START OF FUNCTION
{
	cout<<"\n Index\tName\t\tContact No."; 
	for(int i=0; i<26;i++)
	{
		cout<<"\n "<<i<<"\t"<<ht[i].name<<"\t\t"<<ht[i].mob;
	}
}//END OF FUNCTION

void hash_t::search()//START OF FUNCTION
{
	string name1;
	int i,flag=0;
	

	cout<<"enter the name you want to search:";
	cin>>name1;
	for(i=0;i<26;i++)
	{
		if(ht[i].name==name1)
		{
			cout<<"contact found at index no"<<i<<endl;
			cout<<"contact details are:"<<endl;
			cout<<"name:"<<ht[i].name<<endl;
			cout<<"mob no.:"<<ht[i].mob<<endl;
			
			flag++;
			break;
		}
		
	}

	if(flag==0)
	{
		cout<<"contact does not found";
	}

	
}//END OF FUNCTION

void hash_t::delete_contact()//START OF FUNCTION
{
	string name1;
	int i,flag=0;
	

	cout<<"enter the name you want to delete:";
	cin>>name1;

	for(i=0;i<26;i++)
	{
		if(ht[i].name==name1)
		{
			ht[i].name="";
			ht[i].mob=0;
			flag++;
			cout<<"contact is removed";
		}
	}

	if(flag==0)
	{
		cout<<"no match found";
	}
}//END OF FUNCTION

int main()//START OF FUNCTION
{
	hash_t h;
	int ch;
	while(1)
	{
		cout<<"1.insert\n2.display\n3.search\n4.delete\n5.exit\nenter your choice";
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				h.get_data();
				break;
			}

			case 2:
			{
				h.put_data();
				break;
			}

			case 3:
			{
				h.search();
				break;
			}

			case 4:
			{
				h.delete_contact();
				break;
			}
			
			case 5:
			{
				exit(0);
			}
		}
	}	
}//END OF FUNCTION

//OUTPUT
/*
1.insert
2.display
3.search
4.delete
5.exit
enter your choice1

 Enter Name: harshal

 Enter contact number: 123456
1.insert
2.display
3.search
4.delete
5.exit
enter your choice1

 Enter Name: amit

 Enter contact number: 852741
1.insert
2.display
3.search
4.delete
5.exit
enter your choice1

 Enter Name: abhishek

 Enter contact number: 9637414
1.insert
2.display
3.search
4.delete
5.exit
enter your choice1

 Enter Name: vidit

 Enter contact number: 1456321
1.insert
2.display
3.search
4.delete
5.exit
enter your choice1

 Enter Name: akash

 Enter contact number: 753951
1.insert
2.display
3.search
4.delete
5.exit
enter your choice2

 Index  Name            Contact No.
 0      amit            852741
 1      abhishek                9637414
 2      akash           753951
 3                      0
 4                      0
 5                      0
 6                      0
 7      harshal         123456
 8                      0
 9                      0
 10                     0
 11                     0
 12                     0
 13                     0
 14                     0
 15                     0
 16                     0
 17                     0
 18                     0
 19                     0
 20                     0
 21     vidit           1456321
 22                     0
 23                     0
 24                     0
 25                     01.insert
2.display
3.search
4.delete
5.exit
enter your choice3
enter the name you want to search:harshal
contact found at index no7
contact details are:
name:harshal
mob no.:123456
1.insert
2.display
3.search
4.delete
5.exit
enter your choice4
enter the name you want to delete:vidit
contact is removed1.insert
2.display
3.search
4.delete
5.exit
enter your choice5
*/