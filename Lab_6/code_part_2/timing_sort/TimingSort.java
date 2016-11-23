import java.util.*;

public class TimingSort
{
	public static void main(String[] args)
	{
		int n=0;
		if(args.length>0)
			n=Integer.valueOf(args[0]).intValue();

		int[] numbers = new int[n];
		
		for(int i=0; i<numbers.length; i++)
			numbers[i]=(int)(Math.random()*n);

		long start=System.currentTimeMillis();
		Arrays.sort(numbers);
		long stop=System.currentTimeMillis();
		
		System.out.println("Sorting time in milliseconds:");
		System.out.println(stop-start);

	}
}
