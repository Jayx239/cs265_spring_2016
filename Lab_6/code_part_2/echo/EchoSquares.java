public class EchoSquares
{
	public static void main(String[] args)
	{
		int j;
		for(int i=0;i<args.length;i++)
		{
			j=Integer.valueOf(args[i]).intValue();
			System.out.println(j*j);
		}
	}
}

