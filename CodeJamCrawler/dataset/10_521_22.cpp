import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.File;
import java.io.FileReader;
import java.io.Writer;
import java.math.BigDecimal;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class ProblemA {
	  public static void main(String[] args)
	  {
		    try{
			      int totalNoOfTestSet = 0, testSetCount = 0;

			      int i = 0;
			      
			      BufferedReader in = new BufferedReader(new FileReader("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-small-attempt0.in"));
			      //BufferedReader in = new BufferedReader(new FileReader("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-large.in"));
			      
			      totalNoOfTestSet = Integer.parseInt(in.readLine());
			      
			      Writer output = null;
			      String progOutput = null;
			      File file = new File("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-small-attempt0.out");
			      //File file = new File("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-large.out");
			      output = new BufferedWriter(new FileWriter(file));
			      
			      while(testSetCount < totalNoOfTestSet){
			      	  int wireCount = Integer.parseInt(in.readLine());
			      	  int[] y1 = new int[wireCount];
			      	  int[] y2 = new int[wireCount];
			      	  String[] ordinate = null;
			      	  for(int count =0; count < wireCount; count++){
			      		ordinate = in.readLine().split(" ");
			      		y1[count] = Integer.parseInt(ordinate[0]);
			      		y2[count] = Integer.parseInt(ordinate[1]);
			      	  }
			      	  BigDecimal intersection = new BigDecimal(0);
			      	  
			      	  for(int count =0; count < wireCount; count++){
			      		  for(int j= count+1; j < wireCount; j++){
			      			  if((y1[count] > y1[j]) && (y2[count] > y2[j])){
			      				  // No Intersection
			      			  }else if((y1[count] < y1[j]) && (y2[count] < y2[j])){
			      				  // No Intersection
			      			  }else{
			      				  intersection = intersection.add(new BigDecimal("1"));
			      			  }
			      		  }
			      	  }			          

			        
			          //System.out.println("Case #" + (testSetCount + 1) + ": " + intersection);
			          progOutput = "Case #" + (testSetCount + 1) + ": " + intersection + "\r\n";
			          output.write(progOutput);
			          
			          testSetCount++;         
			      }
			      output.close();      
			   }catch(Exception ex){
			        ex.printStackTrace();
			   }

	  } 
}
