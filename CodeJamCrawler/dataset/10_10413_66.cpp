import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.lang.Math;

public class ProblemOne
{
	public static void main(String args[])
	{
		String filename = args[0];
	  	int i=0;
		  int testcase=0 ;
		  int n=0,k=0;
      String out="";
	BufferedWriter bufferedWriter = null;
      try { BufferedReader in = new BufferedReader(new FileReader(filename));
      String str;
      
      boolean output;
      str = in.readLine();
      testcase = Integer.parseInt(str);
     
      
            //Construct the BufferedWriter object
            bufferedWriter = new BufferedWriter(new FileWriter("output.txt"));
      for (i=0;i <testcase; i++)
      {
	      str = in.readLine();
   
	      String str1= str.substring(0, str.indexOf(' '));
	      String str2= str.substring( str.indexOf(' ')+1);
	      n = Integer.parseInt(str1);
	      k = Integer.parseInt(str2);
	      output = logic(n,k);
    if (output)
	                 out="Case #"+(i+1)+": ON\n";
	    else
	      out="Case #"+(i+1)+": OFF\n";
bufferedWriter.write(out);
	    bufferedWriter.newLine();
      }
       in.close(); } 
       catch (IOException ex) {               ex.printStackTrace();} 
	finally {
            //Close the BufferedWriter
            try {
                if (bufferedWriter != null) {
                    bufferedWriter.flush();
                    bufferedWriter.close();
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
	
}

public static boolean logic(int n,int k)
{
   if((k+1)%Math.pow(2,n)==0)
                return true;
            return false;
}

}
