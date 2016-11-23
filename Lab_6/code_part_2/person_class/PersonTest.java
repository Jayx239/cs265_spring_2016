import java.util.*;

public class PersonTest
{
	public static void main(String[] args)
	{
		
		Date D=new Date();
		System.out.println(D);
		System.out.println();		

		Person P=new Person("Harry", "Hacker", "Beatty_Rd", "Sprinfield", "NJ"); 
		P.setAge(22);
		P.setSex("male");
		System.out.println(P.getFirstName());
		System.out.println(P.getLastName());
		System.out.println(P.getStreet());
		System.out.println(P.getCity());
		System.out.println(P.getState());
		System.out.println(P.getSex());
		System.out.println(P.getAge());
	}
}

class Person
{
	// constructor
	public Person(String aFirst, String aLast, String aStreet, String aCity, String aState)	
	{
		firstname=aFirst;
		lastname=aLast;
		street=aStreet;
		city=aCity;
		state=aState;
	}

	//methods
	public String getFirstName()
	{
		return firstname;
	}

	public String getLastName()
	{
		return lastname;
	}

	public String getStreet()
	{
		return street;
	}

	public String getCity()
	{
		return city;
	}

	public String getState()
	{
		return state;
	}

	public String getSex()
	{
		return sex;
	}

	public int getAge()
	{
		return age;
	}

	public void setAge(int aAge)
	{	
		age=aAge;
	}

	public void setSex(String aSex)
	{	
		sex=aSex;
	}
		
	//fields
	private String firstname;
	private String lastname;
	private String street;
	private String city;
	private String state;
	private String  sex="";
	private int age=0;

}
