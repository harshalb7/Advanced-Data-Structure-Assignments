/* 

										ASSIGNMENT NO - 13

Assignment Statement:- Create a drawing consists of multiple shapes. Create an Abstract base class Shape and define all the methods that different types of Shape objects will implement. 
						draw() to draw the shape and 
						Area() that will return the area of the shape.
						Perimeter() will return perimeter of shape
						Different shapes are rectangle, circle,triangle, rhombus etc

Name   :- Harshal Bhimrao Bodhare
SUB    :- ADSL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A
*/

abstract class shape               //abstract class shape
{
	public abstract void area();     //declaring abstract functions
	public abstract void perimeter();
	public abstract void draw();
	String objectname;
	shape(String name)              //constructor
 	{
		this.objectname=name;
	}
};
class rectangle extends shape         //class rectangle is child of shape
{
	int length,breadth;
	rectangle(int length,int breadth,String name)
	{
		super(name);
		this.length=length;
		this.breadth=breadth;
	}
	public void draw()             //overridden
	{
		System.out.println("RECTANGLE DRAWN");
	}
	public void area()              //overridden
	{
		System.out.println("AREA IS:"+(length*breadth));
	}
	public void perimeter()          //overridden 
	{
		System.out.println("PERIMETER IS:"+(2*length+2*breadth));
	}
};
class square extends shape     //class square is child of shape
{
	int side;
	square(int side,String name)
	{
		super(name);
		this.side=side;
	}
	public void draw()             //overridden  
	{
		System.out.println("SQUARE DRAWN");
	}
	public void area()             //overridden
	{
		System.out.println("AREA IS:"+(side*side));
	}
	public void perimeter()          //overridden
	{
		System.out.println("PERIMETER IS:"+(4*side));
	}
	
};
class rhombus extends shape     //class rhombus is child of shape
{
	int side,diagonal1,diagonal2;
	rhombus(int side,int diagonal1,int diagonal2,String name)
	{
		super(name);
		this.side=side;
		this.diagonal1=diagonal1;
		this.diagonal2=diagonal2;
	}
	public void draw()             //overridden  
	{
		System.out.println("RHOMBUS DRAWN");
	}
	public void area()             //overridden
	{
		System.out.println("AREA IS:"+(diagonal1*diagonal2)/2);
	}
	public void perimeter()          //overridden
	{
		System.out.println("PERIMETER IS:"+(4*side));
	}
	
};

class circle extends shape      //class circle is child of shape
{
	int radius;
	circle(int radius,String name)
	{
		super(name);
		this.radius=radius;
	}
	public void draw()          //overridden
	{
		System.out.println("CIRCLE DRAWN");
	}
	public void area()           //overridden
	{
		System.out.println("AREA IS:"+(3.14*radius*radius));
	}
	public void perimeter()       //overridden
	{
		System.out.println("PERIMETER IS:"+(2*3.14*radius));
	}
	
};

class triangle extends shape      //class triangle is child of shape
{
	int height,base,side2,side3;
	triangle(int base,int height,int side2,int side3,String name)
	{
		super(name);
		this.base=base;
		this.side2=side2;
		this.side3=side3;
		this.height=height;
	}
	public void draw()          //overridden
	{
		System.out.println("TRIANGLE DRAWN");
	}
	public void area()           //overridden
	{
		System.out.println("AREA IS:"+(0.5*base*height));
	}
	public void perimeter()       //overridden
	{
		System.out.println("PERIMETER IS:"+(base+side2+side3));
	}
	
};
public class abstractbase
{
	public static void main(String args[])            //main function 
	{
		shape rect=new rectangle(10,15,"RECTANGLE");
		rect.area();
		rect.perimeter();
		rect.draw();
		
		System.out.println("******************************************");
		shape sq=new square(10,"SQUARE");
		sq.area();
		sq.perimeter();
		sq.draw();
			
		System.out.println("******************************************");
		shape cr=new circle(10,"CIRCLE");
		cr.area();
		cr.perimeter();
		cr.draw();
		
		System.out.println("******************************************");
		shape tr=new triangle(10,15,20,25,"CIRCLE");
		tr.area();
		tr.perimeter();
		tr.draw();

		System.out.println("******************************************");
		shape rh=new rhombus(10,15,25,"RHOMBUS");
		rh.area();
		rh.perimeter();
		rh.draw();

	}
};

/*question 1>What is interface?
answer:
	a>like a class, an interface can have methods and variables, but the methods declared in an interface are by default 		abstract (only method signature, no body).  

    	b>Interfaces specify what a class must do and not how. It is the blueprint of the class.
    	
    	c>An Interface is about capabilities like a Player may be an interface and any class implementing Player must be able 	to 	(or must implement) move(). So it specifies a set of methods that the class has to implement.
    	
    	d>If a class implements an interface and does not provide method bodies for all functions specified in the interface, 	then 	the class must be declared abstract. 
    	
question 2>what is abstract class
answer:	
	a>A class that is declared using “abstract” keyword is known as abstract class. It can have abstract methods(methods 	without body) as well as concrete methods (regular methods with body). A normal class(non-abstract class) cannot have 	  abstract methods.  
	
question 3>Compare Abstract class and Interface
answer;
	
	1) Abstract class can have abstract and non-abstract methods.	Interface can have only abstract methods. Since Java 8, 	  it can have default and static methods also.
	2) Abstract class doesn't support multiple inheritance.	Interface supports multiple inheritance.
	3) Abstract class can have final, non-final, static and non-static variables.	Interface has only static and final 		variables.
	4) Abstract class can provide the implementation of interface.	Interface can't provide the implementation of abstract 	class.
	5) The abstract keyword is used to declare abstract class.	The interface keyword is used to declare interface.
	6) An abstract class can extend another Java class and implement multiple Java interfaces.	An interface can 	extend another Java interface only.
	7) An abstract class can be extended using keyword "extends".	An interface can be implemented using keyword 	  	  "implements".
	8) A Java abstract class can have class members like private, protected, etc.	Members of a Java interface are 		public by default.
	9)Example:
	public abstract class Shape{
		public abstract void draw();	
	}	
	Example:
	public interface Drawable{
	void draw();
	}   	
 
question 4>When to use Abstract class or Interface?
answer:
	a>Abstract classes should be used primarily for objects that are closely related, whereas interfaces are best suited for 	providing a common functionality to unrelated classes.
	b>Interfaces are a good choice when we think that the API will not change for a while.
	c>Interfaces are also good when we want to have something similar to multiple inheritances since we can implement 		multiple interfaces.
	d>If we are designing small, concise bits of functionality, use interfaces. If we are designing large functional units, 		use an abstract class.


AREA IS:150
PERIMETER IS:50
RECTANGLE DRAWN
******************************************
AREA IS:100
PERIMETER IS:40
SQUARE DRAWN
******************************************
AREA IS:314.0
PERIMETER IS:62.800000000000004
CIRCLE DRAWN
******************************************
AREA IS:75.0
PERIMETER IS:55
TRIANGLE DRAWN
******************************************
AREA IS:187
PERIMETER IS:40
RHOMBUS DRAWN

*/
