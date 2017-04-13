package net.antiwalking;

import java.io.*;
import java.text.*;
import java.util.Hashtable;
import java.util.Vector;



public class CenterOfMass {
	  private static final CenterOfMass instance = new CenterOfMass();
	  private CenterOfMass(){};
	  public static CenterOfMass getInstance(){
	    return CenterOfMass.instance;
	  }
	  
	  
	  private String solve(int[][] matrix){
		 String answer = "";
		 double x = 0, y = 0, z = 0;
		 double vx = 0, vy = 0, vz = 0;
		 double t;
		 double d;
		 for(int i = 0 ; i < matrix.length ;i++){
			 x += matrix[i][0];
			 y += matrix[i][1];
			 z += matrix[i][2];
			 vx += matrix[i][3];
			 vy += matrix[i][4];
			 vz += matrix[i][5];
		 }
		 if(vx == 0 && vy == 0 && vz == 0)
			 t = 0;
		 else
			 t = - (x * vx + y * vy + z * vz) / (vx * vx + vy * vy + vz * vz);
		 
		 if(t < 0)
			 t = 0;
		 d = Math.sqrt((x + t * vx) * (x + t * vx) + (y + t * vy) * (y + t * vy) + (z + t * vz) * (z + t * vz)) / (double) matrix.length ;
		 DecimalFormat df = new DecimalFormat();
		 df.applyLocalizedPattern("0.00000000");
		 //System.out.print(df.format(d));
		 //System.out.println(" " + df.format(t));
		 String temp;
		 if(df.format(t).equals("-0.00000000"))
			 temp = "0.00000000";
		 else
			 temp = df.format(t);
		 answer += df.format(d) + " " + temp;
		 return answer;
	  }
	  
	  
	  public static void main(String args[]) throws IOException{
		  int cases;
		  //File inputFile = new File(args[0]);
		  //File inputFile = new File("B-small.test");
		  File inputFile = new File("B-large.in");
		  FileReader in = new FileReader(inputFile);
		  BufferedReader br = new BufferedReader(in);
		  String line;
		  
		  //read the 1st line
		  line = br.readLine();
		  cases = Integer.parseInt(line);
		  
		  for(int i = 0; i < cases ;i ++) {
			  int h = 0;
			  line = br.readLine();
			  h = Integer.parseInt(line);
			  int[][] matrix = new int [h][6];
			  for(int j = 0; j < h ; j ++){
				  line = br.readLine();
				  int k = 0;
				  for(String num :line.split("\\s")){
					 matrix[j][k++] = Integer.parseInt(num); 
				  }
			  }
			  //if(i != 4)
				  //continue;
			  System.out.print("Case #" + (i+1) + ": ");
			  System.out.println(instance.solve(matrix));
		  }
		  
		  br.close();
		  in.close();
		  
	  }
}
