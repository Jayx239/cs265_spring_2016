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
        //newEntryMap.put("",splitLine[13]);
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
            System.out.print(file.isFile() + "\n" + args[0]);
            
        Path filePath = file.toPath();
        //filePath.resolve(args[0]);
        BufferedReader br = new BufferedReader(new InputStreamReader( Files.newInputStream(filePath)));// new BufferedReader(args[1]);
        String line;
        line = br.readLine();
        GADS tempGADS = new GADS(line);
        while((line = br.readLine()) != null){
            if(line.contains("ACMCMODEG")){
                //tempGADS.GetDataEntry("1");
                allGADS.add(tempGADS);
                tempGADS = new GADS(line);
            }
            else{
                tempGADS.addLine(line);
            }
        }
            //allGADS.add(new GADS(line));
        }
        catch(Exception e){
            System.out.print("Error opening file\n");
        }
        allGADS.get(0).getDataEntry("1");
        System.out.println(allGADS.get(0).getAverageFlightHeight());
        System.out.println(allGADS.get(0).getAverageWindSpeed());
        System.out.println(allGADS.get(0).getAverageTemperature());
        
        System.out.println(allGADS.get(0).getStandardDeviationFlightHeight());
        System.out.println(allGADS.get(0).getStandardDeviationWindSpeed());
        System.out.println(allGADS.get(0).getStandardDeviationTemperature());
        //Scanner userReader = new Scanner(System.in);
        
        /*do{
        System.out.print("Enter a measurement indece: ");
        String userInput = userReader.nextLine();
        GADS requestedSet;
            if(userInput.contains("-1"))
                break;
            else
                requestedSet = searchGADS(allGADS,userInput);
            if(requestedSet != null)
                requestedSet.printData();
        }while(true);
        */
    }
}
