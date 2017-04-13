import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.logging.Level;
import java.util.logging.Logger;




public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 try {
	            // TODO code application logic 
	            BufferedReader reader = new BufferedReader(new FileReader("E:\\CODE PRACTICE\\codejam\\B-large.in"));
	            BufferedWriter writer = new BufferedWriter(new FileWriter("E:\\CODE PRACTICE\\codejam\\bl.out"));
	            int T = Integer.parseInt(reader.readLine());
	          
	        
	            for (int i = 1; i <= T; i++)
	          
	            {  
	            	
	            	  String[] s = reader.readLine().split(" ");
	                
	                double  C =Double.parseDouble(s[0]);
	                double F = Double.parseDouble(s[1]);
	               double  X = Double.parseDouble(s[2]);	
	               double p =0, q = X,s1=X/2,t =0;
	               
	               int r=0;
	               
	             
	               while((p+s1)<=q)
	               {
	            	 
	            	    t =t+p;
	            	   p =C /(2+r*F);
	            
	            	  
	            	   q = s1;
	            	   s1= X/(2+(r+1)*F);
	            	
	            	   r++;
	            
	            	 
	               }
	               System.out.println( t+q);
	               double z = t+q;
	               writer.write("Case #"+i+": " + z);
	                  writer.newLine();
	  
	            
	            }
	            
	            reader.close();
	            writer.close();
	            }catch (Exception ex) {
		            Logger.getLogger(A2013.class.getName()).log(Level.SEVERE, null, ex);
	            
	           
		 }

	}

}
