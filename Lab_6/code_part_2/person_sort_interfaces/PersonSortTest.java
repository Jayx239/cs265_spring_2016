import java.util.*;

public class PersonSortTest
{
	public static void main(String[] args)
	{
		Person[] P=new Person[3];

		P[0]=new Person("Harry", "Hacker", "Beatty_Rd", "Sprinfield", "NJ"); 
		P[0].setAge(22);
		P[0].setSex("male");
		P[1]=new Person("Carl", "Cracker", "Daylestown_Blvd", "Tredyffrin", "CA"); 
		P[1].setAge(21);
		P[1].setSex("male");
		P[2]=new Person("Tony", "Tester", "Gartt_Rd", "Upper_Darby", "NY"); 
		P[2].setAge(23);
		P[2].setSex("male");
		
		//We sort array P according to alphabetical ordering of last names
		Arrays.sort(P);
		
		//After sorting we print out first names and last names of objects of P
		for(int i=0;i<P.length;i++)
			System.out.println(P[i].getFirstName()+" "+P[i].getLastName());
		
	}
}

class Person implements Comparable
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

	//the implementation of compareTo method
	public int compareTo(Object otherObject)
	{
		Person other=(Person) otherObject;
		return lastname.compareTo(other.lastname);
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
