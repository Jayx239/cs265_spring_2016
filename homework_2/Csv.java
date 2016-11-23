/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;
import java.time.*;

/**
 *
 * @author Jason
 */
public class Csv {
    Csv(String fieldSeperator){
        fieldSep = fieldSeperator;
    }
    private String line;
    private String fld;
    private Vector<String> field;
    int nField;
    String fieldSep;
    
    public long getField(String csvText){
        String[] split =  csvText.split(fieldSep);
	long start;
	long end;
	start = System.nanoTime();
        for(int i=0; i<split.length; i++)
        {
            if(split[i].contains("\""))
            {
                split[i] = split[i].substring(1,split[i].length()-1);   // Remove leading and trailing qotes while keeping interior
            }
        }
	end = System.nanoTime();

	// Seperate printout from timing
	for(int i=0; i<split.length; i++)
		System.out.print("Entry " + i + ": " + split[i] + "\n");
	return end-start;
    }
    
    
    public static void main(String[] args){
        BufferedReader reader = null;
        Csv csvParser = new Csv(",");
	long elapsedTime = 0;
	int lineNum = 0;

        try{
            File inputFile = new File(args[0]);
           // System.out.println(inputFile.toPath());
            
            Scanner fileReader = new Scanner(new File(args[0]));
            
            String line = "";
            while(fileReader.hasNext()){
                line = fileReader.nextLine();
	        System.out.println("File input line " + ++lineNum + ":");
		elapsedTime += csvParser.getField(line);
            }
            fileReader.close();
        }
        catch(IOException e){
            System.out.println("Error opening file!");
        }
        finally{
            
        }
        Scanner cin = new Scanner(System.in);
        Csv csv = new Csv(",");
        System.out.println("Elapsed Time: " + elapsedTime/1000000);
        System.out.println(lineNum);	
    }
}
