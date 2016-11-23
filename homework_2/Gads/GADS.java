/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.Vector;

/**
 *
 * @author Jason
 */
public class GADS implements GADS_Interface{
    GADS(String headerIn){
        header = headerIn;//.substring(4);
        EntryMap =  new HashMap<String,HashMap<String,String>>();
    }
    
    private String header;
    private Map<String,HashMap<String,String>> EntryMap;
    private String[] keys = {
        "Index","Date","Time","WindSpeed","Height","WindAngle",
        "Latitude","Longitude","Temperature","MachNumber","GroundSpeed",
        "MinimumVerticalAcceleration","MaximumVerticalAcceleration", "Weight"
    };
    
    public void addLine(String inputLine){
        sortData(normalizeSpace(inputLine));
    }
    
    private String normalizeSpace(String input){
        String normalizedInput = input;
        while(normalizedInput.contains("  "))
            normalizedInput = normalizedInput.replace("  ", " ");
        
        return normalizedInput;
    }
    
    private void sortData(String inputLine){
        String[] splitLine = inputLine.split(" ");
        HashMap<String,String> newEntryMap = new HashMap<String,String>();
        newEntryMap.put("Index", splitLine[1]);
        
        newEntryMap.put("Date",splitLine[2]);
        newEntryMap.put("Time",splitLine[3]);
        newEntryMap.put("WindSpeed",splitLine[4]);
        newEntryMap.put("Height",splitLine[5]);
        newEntryMap.put("WindAngle",splitLine[6]);
        newEntryMap.put("Latitude",splitLine[7]);
        newEntryMap.put("Longitude",splitLine[8]);
        newEntryMap.put("Temperature",splitLine[9]);
        newEntryMap.put("MachNumber",splitLine[10]);
        newEntryMap.put("GroundSpeed",splitLine[11]);
        newEntryMap.put("MinimumVerticalAcceleration",splitLine[12]);
        newEntryMap.put("MaximumVerticalAcceleration",splitLine[13]);
        newEntryMap.put("Weight",splitLine[14]);
        EntryMap.put(newEntryMap.get("Index"), newEntryMap);
    }
    
    public void getDataEntry(String entryIndex){
        if(!EntryMap.containsKey(entryIndex)){
            System.out.println("Invalid index entered!");
            return;
        }  
        HashMap EntryRow = EntryMap.get(entryIndex);
        System.out.println("Data at index " + entryIndex + ":");
        for(int i=0; i< keys.length; i++){
            System.out.println(keys[i] + ": " + EntryRow.get(keys[i]));
        }
    }
    
    public String getDataEntry(String entryIndex, String entryKey){
        return EntryMap.get(entryIndex).get(entryKey);
    }
    
    private double getAverage(String valueKey){
        Iterator keys = EntryMap.keySet().iterator();
        int numEntrys = 0;
        double sum = 0;
        while(keys.hasNext()){
            sum += Double.parseDouble(EntryMap.get(keys.next()).get(valueKey));
            numEntrys++;
        }
        return sum/numEntrys;
    }
    
    public double getAverageFlightHeight(){
        return getAverage("Height");
    }
    
    public double getAverageWindSpeed(){
        return getAverage("WindSpeed");
    }
    
    public double getAverageTemperature(){
        return getAverage("Temperature");
    }
    
    public double getStandardDeviation(String valueKey){
        Iterator keys = EntryMap.keySet().iterator();
        int numEntrys = 0;
        double sum = 0;
        while(keys.hasNext()){
            sum += Math.pow(Double.parseDouble(EntryMap.get(keys.next()).get(valueKey))-getAverage(valueKey),2);
            numEntrys++;
        }
        sum/=numEntrys;
        return Math.sqrt(sum);
    }
    public double getStandardDeviationFlightHeight(){
        return getStandardDeviation("Height");
    }
    
    public double getStandardDeviationWindSpeed(){
        return getStandardDeviation("WindSpeed");
    }
    
    public double getStandardDeviationTemperature(){
        return getStandardDeviation("Temperature");
    }
    
    public static void main(String[] args){
        Vector<GADS> allGADS = new Vector<GADS>();
        
        try{
            	File file = new File(args[0]);
		Path filePath = file.toPath();
	        BufferedReader br = new BufferedReader(new InputStreamReader( Files.newInputStream(filePath)));
        	
		String line;
	        line = br.readLine();
        	GADS tempGADS = new GADS(line);
        	while((line = br.readLine()) != null){
	        	if(line.contains("ACMCMODEG")){
                		allGADS.add(tempGADS);
	                	tempGADS = new GADS(line);
        	    	}
            		else{
                		tempGADS.addLine(line);
            		}
        	}
        }
        catch(Exception e){
        	System.out.print("Error opening file\n");
        }
        
	if(args.length == 1){
		allGADS.get(0).getDataEntry("1");
        	System.out.println("Average Flight Height: " + allGADS.get(0).getAverageFlightHeight());
	        System.out.println("Average Wind Speed: " + allGADS.get(0).getAverageWindSpeed());
        	System.out.println("Average Temperature: " + allGADS.get(0).getAverageTemperature());
        
	        System.out.println("Flight Height Standard Deviation: " + allGADS.get(0).getStandardDeviationFlightHeight());
        	System.out.println("Wind Speed Standard Deviation: " + allGADS.get(0).getStandardDeviationWindSpeed());
	        System.out.println("Temperature Standard Deviation: " + allGADS.get(0).getStandardDeviationTemperature());

		System.out.println();        
	}
	else{
		Scanner userReader = new Scanner(System.in);
       		System.out.println("Welcome to user input mode\n Enter a flight number followed by the measurement index to view the indexed flight data.\n The flight numbers range from 0 to " + ((allGADS.size())-1) + "\n Enter an invalid flight number to exit (ie -1)\n"); 
		do{
        		System.out.print("Enter a Flight Entry Number: ");
			String userInput = userReader.nextLine();
			GADS requestedSet;
			int entryInt =  Integer.parseInt(userInput);
		    	if(userInput.contains("-1") || entryInt >= allGADS.size())
        	       		 break;
		        else
        			requestedSet = allGADS.elementAt(entryInt);
	        	if(requestedSet != null){
	               		System.out.println("Enter an entry number: ");
				userInput = userReader.nextLine();
				requestedSet.getDataEntry(userInput);
				System.out.println("\n All Flight Data: ");
				System.out.println("Average Flight Height: " + requestedSet.getAverageFlightHeight());
		                System.out.println("Average Wind Speed: " + requestedSet.getAverageWindSpeed());
                		System.out.println("Average Temperature: " + requestedSet.getAverageTemperature());

		                System.out.println("Flight Height Standard Deviation: " + requestedSet.getStandardDeviationFlightHeight());
                		System.out.println("Wind Speed Standard Deviation: " + requestedSet.getStandardDeviationWindSpeed());
		                System.out.println("Temperature Standard Deviation: " + requestedSet.getStandardDeviationTemperature());
			}
			System.out.println();
        	}while(true);
        
	}
    }
}
