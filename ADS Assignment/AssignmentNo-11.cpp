/*
                                    ASSIGNMENT NO - 11
Assignment Statement:- Department maintains the student information.The file contaions name,roll number,division,address.Allow user to add,
                       delete information of student.Display informationof particular student.If record o particular student does not exits
                       an approprite message is displayed. If it is,then the system display student details.Use sequentialile to maintain 
                       data.

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

class information//STATR OF CLASS
{
public:
	int rollNo;
	char division[2];
	char CLASS[5];
	char name[20];
	char address[10];
	information()
	{
		rollNo=0;
		strcpy(division," ");
		strcpy(CLASS," ");
		strcpy(name," ");
		strcpy(address," ");
	}
	void getData();
	void display();
};//END OF CLASS
class studentInfo//STATR OF CLASS
{
public:
	fstream file;
	information temp1;

	void putData();
	void searchData();
	void deleteData();
	void modifyData();
	void displayData();
};//END OF CLASS

void information::getData()//START OF FUNCTION
{
	cout<<"\nEnter Roll Number: ";
	cin>>rollNo;
	cout<<"\nEnter Name       : ";
	cin>>name;
	cout<<"\nEnter class      : ";
	cin>>CLASS;
	cout<<"\nEnter Division   : ";
	cin>>division;
	cout<<"\nEnter Address    : ";
	cin>>address;
}//END OF FUNCTION
void information::display()//START OF FUNCTION
{
	cout<<setw(12)<<rollNo<<setw(12)<<name<<setw(12)<<CLASS<<setw(12)<<division<<setw(12)<<address<<setw(12)<<endl;
}//END OF FUNCTION
void display1()//START OF FUNCTION
{	
	cout<<setw(12)<<"Roll No"<<setw(12)<<"Name"<<setw(12)<<"Class"<<setw(12)<<"Division"<<setw(12)<<"Address"<<setw(12)<<endl;
}//END OF FUNCTION

void studentInfo::putData()//START OF FUNCTION
{
	int wloc,no;
	file.open("Student_Information.txt",ios::out|ios::in|ios::app);
	cout<<"\nEnter Number of Data to be added: ";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		temp1.getData();
		file.write((char *)&temp1,sizeof(temp1));
	}
	file.close();
	
}//END OF FUNCTION
void studentInfo::searchData()//START OF FUNCTION
{
	int searchNo,sloc=0;
	file.open("Student_Information.txt",ios::out|ios::in);
    cout<<"\nEnter Roll Number to Search Information: ";
    cin>>searchNo;

    while(file.read(reinterpret_cast<char*>(&temp1),sizeof(temp1))){
    	if(searchNo==temp1.rollNo){
    		sloc=1;
    		break;
    	}
    	else
    		sloc=0;
    }
    if(sloc==1){
    	display1();
    	temp1.display();
    }
	else
		cout<<"\nData NOT Found....."<<endl;
    file.close();	
}//END OF FUNCTION
void studentInfo::deleteData()//START OF FUNCTION
{
	int deleteNo,dloc=0;
	fstream file1;
	cout<<"\nEnter Roll Number to Delete Information: ";
    cin>>deleteNo;
	file.open("Student_Information.txt",ios::in);
	file1.open("Student_Information1.txt",ios::out);
	
   	while(file.read((char*)&temp1,sizeof(temp1))){
   		if(temp1.rollNo==deleteNo){
   			display1();
   			temp1.display();
   			dloc=1;
   		}
   		else
   			file1.write((char*)&temp1,sizeof(temp1));
   	}
    file.close();
    file1.close();
   remove("Student_Information.txt");
   rename("Student_Information1.txt","Student_Information.txt");
    if(dloc==1)
	    cout<<"\nRecord deleted successfully!"<<endl;
	else
		cout<<"\nData NOT Found....."<<endl;
}//END OF FUNCTION
void studentInfo::modifyData()//START OF FUNCTION
{
	int	modifyNo,mloc=0;
	file.open("Student_Information.txt",ios::out|ios::in);
	cout<<"\nEnter Roll Number to Modify Information: ";
    cin>>modifyNo;
    while(!file.eof()){
    	mloc=file.tellg();
    	file.read((char*)&temp1,sizeof(temp1));
    	if(modifyNo==temp1.rollNo){
    		temp1.getData();
    		file.seekp(mloc);
    		file.write((char*)&temp1,sizeof(temp1));
    		mloc=1;
    		break;
    	}
    }
    file.close();
    if(mloc==1)
    	cout<<"\nRecord updated successfully!"<<endl;
    else
    	cout<<"\nRecord NOT Found....."<<endl;
}//END OF FUNCTION
void studentInfo::displayData()//START OF FUNCTION
{
	display1();
	file.open("Student_Information.txt",ios::in);
	while(file.read(reinterpret_cast<char*>(&temp1),sizeof(temp1)))
	{
		temp1.display();
	}
	file.close();
}//END OF FUNCTION
int main()//START OF FUNCTION
{
	int ch;
	char ch1;
	studentInfo stIn; 
	while(1){
		cout<<"\n====================================\n";
		cout<<"\n1.Enter Data In the File ";
		cout<<"\n2.Display All Data in File ";
		cout<<"\n3.Search Data in the File ";
		cout<<"\n4.Delete Data in the File";
		cout<<"\n5.Modify Data in the File";
		cout<<"\n6.EXIT";
		cout<<"\n====================================\n";
		cout<<"Enter Choice: ";
		cin>>ch;
		switch(ch)
		{

			case 1:
				stIn.putData();
				break;

			case 2:
				stIn.displayData();
				break;

            case 3:
				stIn.searchData();
                break;
            case 4:
            	stIn.deleteData();
           		break;

            case 5:
            	stIn.modifyData();
                break;
            case 6:
              	exit(1);
		}
	}
	return 0;
}//END OF FUNCTION
//OUTPUT
/*
====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 1

Enter Number of Data to be added: 3

Enter Roll Number: 1

Enter Name       : Harshal

Enter class      : SE

Enter Division   : A

Enter Address    : Nashik

Enter Roll Number: 2

Enter Name       : Amit

Enter class      : Se

Enter Division   : A

Enter Address    : Nashik

Enter Roll Number: 3

Enter Name       : Abhi

Enter class      : SE

Enter Division   : A

Enter Address    : Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 2
     Roll No        Name       Class    Division     Address
           1     Harshal          SE           A      Nashik
           2        Amit          Se           A      Nashik
           3        Abhi          SE           A      Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 3

Enter Roll Number to Search Information: 2
     Roll No        Name       Class    Division     Address
           2        Amit          Se           A      Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 4

Enter Roll Number to Delete Information: 1
     Roll No        Name       Class    Division     Address
           1     Harshal          SE           A      Nashik

Record deleted successfully!

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 6
harshal@LAPTOP-G2N0HOPI:/mnt/d/programs/TOUPLOAD$ g++ AssignmentNo-11.cpp
harshal@LAPTOP-G2N0HOPI:/mnt/d/programs/TOUPLOAD$ ./a.out

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 3

Enter Roll Number to Search Information: 2
     Roll No        Name       Class    Division     Address
           2        Amit          Se           A      Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 2
     Roll No        Name       Class    Division     Address
           2        Amit          Se           A      Nashik
           3        Abhi          SE           A      Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 5

Enter Roll Number to Modify Information: 3

Enter Roll Number: 3

Enter Name       : Abhi

Enter class      : TE

Enter Division   : B

Enter Address    : PUNE

Record updated successfully!

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 2
     Roll No        Name       Class    Division     Address
           2        Amit          Se           A      Nashik
           3        Abhi          TE           B        PUNE

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 1

Enter Number of Data to be added: 1

Enter Roll Number: 1

Enter Name       : Harshal

Enter class      : SE

Enter Division   : A

Enter Address    : Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 2
     Roll No        Name       Class    Division     Address
           2        Amit          Se           A      Nashik
           3        Abhi          TE           B        PUNE
           1     Harshal          SE           A      Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 4

Enter Roll Number to Delete Information: 3
     Roll No        Name       Class    Division     Address
           3        Abhi          TE           B        PUNE

Record deleted successfully!

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 2
     Roll No        Name       Class    Division     Address
           2        Amit          Se           A      Nashik
           1     Harshal          SE           A      Nashik

====================================

1.Enter Data In the File
2.Display All Data in File
3.Search Data in the File
4.Delete Data in the File
5.Modify Data in the File
6.EXIT
====================================
Enter Choice: 6
*/