import java.io.*;

class QuickSortTest 
{
        public static void main(String[] args)throws IOException 
	{
                int N=5;

		//We place N integers in reverse order inside an Integer array A
                Integer[] A=new Integer[N];
                for(int i=0;i<N;i++)
                        A[i]=new Integer(N-i);

		//We apply quicksort method for sorting integers
                quicksort(A,0,N-1,new Icmp());

		//We print out the numbers after sorting
		System.out.println("Sorted numbers are:");
                for(int i=0;i<N;i++)
                        System.out.println(A[i]);
		System.out.println();
		
		//We construct an input stream is
		//It allows us to read input text line by line
        	InputStreamReader converter = new InputStreamReader(System.in); 
		BufferedReader is = new BufferedReader(converter); 

             	//We prompt the user for N strings
		//We store input strings inside a String array B
                String[] B=new String[N];
                System.out.println("Enter input strings, one string per line:");
                for(int i=0;i<N;i++)
                        B[i]=is.readLine();
		System.out.println();

		//We apply quicksort method for sorting strings
                quicksort(B,0,N-1,new Scmp());

		//We print out the strings after sorting
                System.out.println("Sorted strings are:");
                for(int i=0;i<N;i++)
                        System.out.println(B[i]);
        }

	public static void quicksort(Object[] v, int left, int right, Cmp cmp)
	{
		int i, last;
		if(left>=right)
			return;
		//move pivot to the v[left]
		swap(v, left, rand(left, right));
		last=left;
		//partition 
		for(i=left+1; i<= right; i++)
			 if(cmp.cmp(v[i],v[left])<0)
				swap(v, ++last, i);
		//restore pivot element
		swap(v, left, last);
		//recursively sort each part
		quicksort(v, left, last-1, cmp);
		quicksort(v, last+1, right, cmp);
	} 

	static void swap(Object[] v,int i,int j)
	{
		Object temp;

		temp=v[i];
		v[i]=v[j];
		v[j]=temp;
	}
	
	public static int rand(int left, int right)
	{
		return left+(int)(Math.random()*(right-left+1));
	}
}

interface Cmp 
{
        int cmp(Object x, Object y);
}

class Icmp implements Cmp 
{
        public int cmp(Object o1, Object o2)
        {
                int i1=((Integer) o1).intValue();
                int i2=((Integer) o2).intValue();
                if(i1<i2)
                        return -1;
                else if(i1==i2)
                        return 0;
                else
                        return 1;
        }
}

class Scmp implements Cmp 
{
        public int cmp(Object o1, Object o2)
        {
                String s1=(String) o1;
                String s2=(String) o2;
                return s1.compareTo(s2);
        }
}



