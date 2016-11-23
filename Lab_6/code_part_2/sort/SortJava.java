import java.util.*;

public class SortJava
{
	public static void main(String[] args)
	{
		int n=5;
		int[] numbers = new int[n];
		
		//The Math.random() method returns a random floating 
		//point number in the range [0,1). We multiply this 				//number by n and then we cast its type to
		//integer.
		for(int i=0; i<numbers.length; i++)
			numbers[i]=(int)(Math.random()*n);

		System.out.println("Random numbers before sorting");

		for(int i=0; i<numbers.length; i++)
			System.out.println(numbers[i]);

		System.out.println();

		System.out.println("Random numbers after sorting");

		//We call sort method of Arrays class. Import 
		//statement java.util.* allows us to access it.
		Arrays.sort(numbers);

		for(int i=0; i<numbers.length; i++)
			System.out.println(numbers[i]);

	}
}
