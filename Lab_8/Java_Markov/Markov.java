import java.util.*;
import java.io.*;
class Markov {
	static final int MAXGEN = 10000; // maximum words generated

	public static void main(String[] args) throws IOException
	{
		try{
			File inputFile = new File(args[0]);
			FileInputStream reader = new FileInputStream(inputFile);
			Chain chain = new Chain();
                	int nwords = MAXGEN;
        	        chain.build(reader);
	                System.out.println(chain.generate(nwords)? "Success: All Prefixes Used" : "Error: Not All Prefixes Used");
		}
		catch(Exception e){

		}
//		File inputFile = new File(args[0]);
//		Scanner reader = new Scanner(inputFile);
//		Chain chain = new Chain();
//		int nwords = MAXGEN;
//		chain.build(reader);
//		chain.generate(nwords);
	}
} 
