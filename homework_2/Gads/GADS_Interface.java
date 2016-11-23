/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Map;
import java.util.Vector;

/**
 *
 * @author Jason
 */
public interface GADS_Interface {
     String line = null;
     
     Map<String,Map<String,String>> indece= null;
     String getDataEntry(String entryIndex, String entryKey);
     double getAverageFlightHeight();
     double getAverageWindSpeed();
     double getAverageTemperature();
     double getStandardDeviationFlightHeight();
     double getStandardDeviationWindSpeed();
     double getStandardDeviationTemperature();
     
     
     /*Vector<String> date= null;
     Vector<String> time= null;
     Vector<String> wSpeed= null;
     Vector<String> height= null;
     Vector<String> wAngle= null;
     Vector<String> latitude= null;
     Vector<String> longitude= null;
     Vector<String> temperature= null;
     Vector<String> machNumber= null;
     Vector<String> groundSpeed= null;
     Vector<String> minVerticalAcceleration= null;
     Vector<String> maxVerticalAcceleration= null;
     Vector<String> weight= null;
     */
}
