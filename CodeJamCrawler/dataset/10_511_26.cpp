import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.File;
import java.io.FileReader;
import java.io.Writer;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class ProblemA {
	  public static void main(String[] args)
	  {
	    try{
	      int totalNoOfTestSet = 0, testSetCount = 0;
	      
	      BufferedReader in = new BufferedReader(new FileReader("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-small-attempt0.in"));
	      //BufferedReader in = new BufferedReader(new FileReader("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-large.in"));
	      
	      totalNoOfTestSet = Integer.parseInt(in.readLine());
	      
	      Writer output = null;
	      String progOutput = null;
	      File file = new File("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-small-attempt0.out");
	      //File file = new File("C:/LAPTOP/Projjwal/Workspace/CodeJam2010/src/A-large.out");
	      output = new BufferedWriter(new FileWriter(file));
	      
	      String tempDirPath = null;
	      
	      while(testSetCount < totalNoOfTestSet){
	    	  
		      String[] firstLine = in.readLine().split(" ");
		      String[] folder = null;
		      
		      int existingDirCount = Integer.parseInt(firstLine[0]);
		      int createDirCount = Integer.parseInt(firstLine[1]);
		      
		      HashMap existDir = new HashMap();

		      for(int i = 0; i < existingDirCount; i++){
		    	  tempDirPath = in.readLine().substring(1);
		    	  folder = tempDirPath.split("/");
		    	  
		    	  int dirLength = folder.length;
		    	  StringBuffer directories = new StringBuffer("");
		    	  
		    	  for(int j=0; j < dirLength; j ++){
		    		  directories.append("/"+folder[j]);
		    		  
		    		  existDir.put(directories.toString(), directories.toString());	
	      		  }
	      	  }
	      	  
		      int mkDirCount = 0;
		      
	      	  for(int i = 0; i < createDirCount; i++){
	      		
	      		tempDirPath = in.readLine().substring(1);
	      		folder = tempDirPath.split("/");
	      		
	      		if(existDir.containsKey(tempDirPath)){
	      			// Do Nothing
	      		}else{
	      			int dirLength = folder.length;
			    	StringBuffer directories = new StringBuffer("");
			    	  	      			
	      			for(int j=0; j < dirLength; j ++){
	      				directories.append("/"+folder[j]);
	      				
	      				if(existDir.containsKey(directories.toString())){
	      					// Do Nothing
	      				}else{
	      					existDir.put(directories.toString(), directories.toString());
	      					mkDirCount++;
	      				}
	      			}
	      		}
	      	  }

	      	//System.out.println("Case #" + (testSetCount + 1) + ": " + mkDirCount);
	        
	          //System.out.println("Case #" + (testSetCount + 1) + ": " + "HERE GOES OUTPUT");
	          progOutput = "Case #" + (testSetCount + 1) + ": " + mkDirCount + "\r\n";
	          output.write(progOutput);
	          
	          testSetCount++;         
	      }
	      output.close();
	      System.out.println("Done");
	    }catch(Exception ex){
	        ex.printStackTrace();
	    }
	  } 
}
