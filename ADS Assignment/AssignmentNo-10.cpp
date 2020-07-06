/*
                                    ASSIGNMENT NO - 10
Assignment Statement:- Read a marks obtained by students of second year in an online examination of a particular subject.Find minimu and 
                       maximum marks obtained in that subject.Use heap data structure.Analyze algorithm.                                    
Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/
#include<iostream>
#include<iomanip>
using namespace std;

class heapsorting//STATR OF CLASS
{
	int marks[10]={10,63,45,85,74,21,63,41,78,55};
	int n=10;
public:
	heapsorting()
	{
		/*n=10;
		int marks[]={10,63,45,85,74,21,63,41,78,55};*/
	}

	void enterMarks();
	void displayMarks();
	void heapify(int marks[], int n, int i);
	void heapSort();
	void maxMark();
	void minMark();
};

void heapsorting::enterMarks()//START OF FUNCTION
{
	cout<<"\nEnter Number of Student to Enter Marks: ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Marks of "<<i+1<<" Student"<<endl;
		cin>>marks[i];
	}	
}//END OF FUNCTION

void heapsorting::displayMarks()//START OF FUNCTION
{
	for(int i=0;i<n;i++)
		cout<<" "<<marks[i];
	cout<<endl;
}//END OF FUNCTION

void heapsorting::heapify(int marks[], int n, int i)//START OF FUNCTION
{
    int largest = i;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && marks[l] > marks[largest])
        largest = l;

    if (r < n && marks[r] > marks[largest])
        largest = r;

    if (largest != i) 
    {
        swap(marks[i], marks[largest]);
        heapify(marks, n, largest);
    }
}//END OF FUNCTION
void heapsorting:: heapSort()//START OF FUNCTION
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(marks, n, i);

    for (int i = n - 1; i >= 0; i--) 
    {
        swap(marks[0], marks[i]);
		heapify(marks, i, 0);
    }
}//END OF FUNCTION
void heapsorting::maxMark()//START OF FUNCTION
{
	cout<<"\nMaximum Mark is: "<<marks[n-1];
}//END OF FUNCTION
void heapsorting::minMark()//START OF FUNCTION
{
	cout<<"\nMMinimum Mark is: "<<marks[0];
}//END OF FUNCTION
int main()//START OF FUNCTION
{
	int ch;
	heapsorting hs;
	while(1)
	{
		cout<<"\n=============================="<<endl;
		cout<<"1.Get Marks Of Studens"<<endl;
		cout<<"2.Get Maximum Marks Of Student"<<endl;
		cout<<"3.Get Minimum Marks Of Student"<<endl;
		cout<<"4.display Marks Of Students"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"\n=============================="<<endl;
		cout<<"Choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				//hs.enterMarks();
				hs.heapSort();
				break;
			case 2:
				hs.maxMark();
				break;
			case 3:
				hs.minMark();
				break;
			case 4:
				hs.displayMarks();
				break;
			case 5:
				exit(1);
		}
	}//END OF FUNCTION
}//END OF CLASS
//OUTPUT

/*
==============================
1.Get Marks Of Studens
2.Get Maximum Marks Of Student
3.Get Minimum Marks Of Student
4.display Marks Of Students
5.Exit

==============================
Choice: 1

==============================
1.Get Marks Of Studens
2.Get Maximum Marks Of Student
3.Get Minimum Marks Of Student
4.display Marks Of Students
5.Exit

==============================
Choice: 2

Maximum Mark is: 85
==============================
1.Get Marks Of Studens
2.Get Maximum Marks Of Student
3.Get Minimum Marks Of Student
4.display Marks Of Students
5.Exit

==============================
Choice: 3

MMinimum Mark is: 10
==============================
1.Get Marks Of Studens
2.Get Maximum Marks Of Student
3.Get Minimum Marks Of Student
4.display Marks Of Students
5.Exit

==============================
Choice: 4
 10 21 41 45 55 63 63 74 78 85

==============================
1.Get Marks Of Studens
2.Get Maximum Marks Of Student
3.Get Minimum Marks Of Student
4.display Marks Of Students
5.Exit

==============================
Choice: 5
*/