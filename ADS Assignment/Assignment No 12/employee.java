/*

										ASSIGNMENT NO - 12

Assignment Statement:- Create a class Employee
						data members
							1.Name : String
							2.Mobile : String
							3.Birth_Date : Date     (Age : int )
							4.Salary : float
						Create employee records of maximum 5 employees and validate input through exceptions 
						1. Age < 18 not allowed   2. Mobile number = 10 Digits only 3. Salary should not be <=0
						Check array limit bound error for employee data more than 5 records

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/


import java.lang.ArithmeticException;                           //importing packages 
import java.util.Scanner;                                      
class employee                                              //declaring class
{
	
	String name[]=new String[5];                           //declaring variables 
	int age[]=new int[5];
	String mob[]=new String[5];
	int birthdate[]=new int[5];
	float salary[]=new float[5];
	int records;
	Scanner s=new Scanner(System.in);                      //object of scanner class
	employee()                                            //default constructor
	{
		for(int i=0;i<5;i++)
		{
			name[i]="";
			age[i]=0;
			mob[i]="0";
			salary[i]=0;
			birthdate[i]=0;
		}
	}
	public void read()                                    //reading data from user 
	{
		int x=0,x1=0,x2=0;
		System.out.println("\n HOW MANY RECORD YOU WANT TO INSERT");
		records=s.nextInt();                           //reading total number of records want to insert
		for(int i=0;i<records;i++)
		{
			System.out.println("\n Enter NAME");    //reading name
			name[i]=s.next();
			//------------------------------------------------------------
			System.out.println("\n Enter BIRTH YEAR");    //reading birth year to calculate age
			birthdate[i]=s.nextInt();
			//------------------------------------------------------------
			age[i]=calculate_age(birthdate[i]);
			x=validateage(age[i]);                       //validaing age
			if(x==1)
				System.out.println("VALID..........");
			//------------------------------------------------------------	
			System.out.println("\n Enter MOBILE NUMBER");  //reading mobile number
			mob[i]=s.next();
			x1=validatemob(mob[i]);                     //validating mobile number
			if(x1==1)
				System.out.println("VALID..........");
			//------------------------------------------------------------	
			System.out.println("\n Enter SALARY");          //reading salray
			salary[i]=s.nextFloat();
			//------------------------------------------------------------
			x2=validaterecords(i);                      //validating record number
			if(x2==1)
				System.out.println("VALID ENTRY....... ");
		}
	}//end read
	public void display()                    //displaying data
	{
		for(int i=0;i<records;i++)             
			System.out.println("\n RECORD NUMBER:"+(i+1)+"\n NAME:"+name[i]+"\n BIRTHDATE:"+birthdate[i]+"\n AGE:"+age[i]+"\n MOBILE NO:"+mob[i]+"\n SALARY:"+salary[i]);
	}//end dispaly
	public int calculate_age(int date)                  //calculating age from birth year
	{
		return(2020-date);
	}//end calculate_age
	static int validaterecords(int records)                //function to validate recordnumber
	{
		if(records>5)
		{
			throw new ArithmeticException("NOT VALID");
		}
		else
		{
			return 1;
		}
	}//end validaterecords
	static int validateage(int age)                       //function to validate age
	{
		if(age<18)
		{
			throw new ArithmeticException("NOT VALID");
		}
		else
		{
			return 1;
		}
	}//end validateage
	
	static int validatemob(String m)                     //function to validate mobilenumber
	{
		if(m.length()!=10)
			throw new ArithmeticException("NOT VALID");
		else
			return 1;
	}//end validatemob
	public static void main(String args[])                //main function
	{
		employee e1=new employee();              //creating object e1 of class employee
		e1.read();
		e1.display();	
	}//end main 
};//end of program	
/*
 
 harshal@LAPTOP-G2N0HOPI:/mnt/c/Users/Harshal/Desktop$ javac employee.java
harshal@LAPTOP-G2N0HOPI:/mnt/c/Users/Harshal/Desktop$ java employee

 HOW MANY RECORD YOU WANT TO INSERT
4

 Enter NAME
Harshal

 Enter BIRTH YEAR
2001
VALID..........

 Enter MOBILE NUMBER
70578199063
Exception in thread "main" java.lang.ArithmeticException: NOT VALID
        at employee.validatemob(employee.java:113)
        at employee.read(employee.java:66)
        at employee.main(employee.java:120)
harshal@LAPTOP-G2N0HOPI:/mnt/c/Users/Harshal/Desktop$ java employee

 HOW MANY RECORD YOU WANT TO INSERT
4

 Enter NAME
Harshal

 Enter BIRTH YEAR
2001
VALID..........

 Enter MOBILE NUMBER
7057819906
VALID..........

 Enter SALARY
12000
VALID ENTRY.......

 Enter NAME
Amit

 Enter BIRTH YEAR
2000
VALID..........

 Enter MOBILE NUMBER
7090909090
VALID..........

 Enter SALARY
2000
VALID ENTRY.......

 Enter NAME
Abhishek

 Enter BIRTH YEAR
2000
VALID..........

 Enter MOBILE NUMBER
1010101010
VALID..........

 Enter SALARY
6000000
VALID ENTRY.......

 Enter NAME
Vikas

 Enter BIRTH YEAR
2300
Exception in thread "main" java.lang.ArithmeticException: NOT VALID
        at employee.validateage(employee.java:102)
        at employee.read(employee.java:60)
        at e
*/


	
