import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.ArrayList;

public class ProblemThreeRo 
{
	public static void main(String args[])
	{
		String filename = args[0];
	  	int i=0,j=0;
		  int testcase=0 ;
		  long n=0,k=0,r=0;
      String out="";
	BufferedWriter bufferedWriter = null;
      try { BufferedReader in = new BufferedReader(new FileReader(filename));
      String str;
      
      long output;
      str = in.readLine();
      testcase = Integer.parseInt(str);
     
      	    //System.out.println("testcase="+testcase);
            //Construct the BufferedWriter object
            bufferedWriter = new BufferedWriter(new FileWriter("thirdoutput1.txt"));
      for(i=0;i <testcase; i++)
      {
	      str = in.readLine();
	      int a=str.indexOf(' ');
	      String str1= str.substring(0, a);
	      String str2= str.substring(a+1);
	      a=str2.indexOf(' ');
	      String str3= str2.substring(0, a);
	      String str4= str2.substring(a+1);
	      r = Integer.parseInt(str1);
	      k = Integer.parseInt(str3);
	      n = Integer.parseInt(str4);
	      str = in.readLine();
	      int p = Integer.parseInt(str4);;
            long grp[] = new long[p];
	    StringTokenizer st = new StringTokenizer(str);
           int sum=0;
	   //System.out.println("out5");
	    for(j=0;j<n;j++)
	    {grp[j]=Integer.parseInt(st.nextToken());
	            sum += grp[j];
	    }
//	      System.out.println("r="+r + "k="+k+"n="+n+"sum="+sum);
	       output = logic(	r,k,n,grp);
//	    System.out.println("Final=" +output);
           bufferedWriter.write("Case #"+(i+1)+": "+output);
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

public static long logic(long r,long k, long n1, long [] g)
{
      long totalmoney = 0;
            int arraypointer = 0;
	    int n=(int)n1;
            ArrayList arkeys = new ArrayList();
            ArrayList arvals = new ArrayList();
           
            for(int i=0; i<r; i++)                                  
            {
                long ppl =0;   
                //boolean flag = false;
                long initialpointer = arraypointer;
                while(ppl+g[arraypointer]<=k)
                {
                    ppl = ppl+g[arraypointer];
                    arraypointer = (arraypointer+1)%n;
                    if(initialpointer == arraypointer)
                    {
                        return r*ppl;
                    }

                }
                 
                if(arkeys.contains(arraypointer))
                {
                    //pattern found
                    totalmoney = totalmoney+ppl;
                    i++;
                    int abc = arkeys.indexOf(arraypointer);
                    //arkeys.removeRange(0,abc);
                    //arvals.removeRange(0,abc);
                    arkeys.add(arraypointer);
                    arvals.add(ppl);
                    Object [] arrvalarr = arvals.toArray();
                    while(i<r)
                    {
			    int pr= arkeys.size();
                        for (int j=abc+1 ; j<pr && i<r;j++)
                        {
                            long  val =Long.parseLong(arrvalarr[j].toString());
			    
                            totalmoney = totalmoney+val;
                            i++;
                        }
                    }
               
                   
                }
                else
                {
                    arkeys.add(arraypointer);
                    arvals.add(ppl);
                }
                if(i<r)
                totalmoney = totalmoney+ppl;
            }

            return totalmoney;            
}
}
