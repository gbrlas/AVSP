import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer
;
public class ProblemThree
{
	public static void main(String args[])
	{
		String filename = args[0];
	  	int i=0,j=0;
		  int testcase=0 ;
		  int n=0,k=0,r=0;
      String out="";
	BufferedWriter bufferedWriter = null;
      try { BufferedReader in = new BufferedReader(new FileReader(filename));
      String str;
      
      int output;
      str = in.readLine();
      testcase = Integer.parseInt(str);
     
      	    System.out.println("testcase="+testcase);
            //Construct the BufferedWriter object
            bufferedWriter = new BufferedWriter(new FileWriter("thirdoutput.txt"));
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
            int grp[] = new int[n];
	    StringTokenizer st = new StringTokenizer(str);
           int sum=0;
	   System.out.println("out5");
	    for(j=0;j<n;j++)
	    {grp[j]=Integer.parseInt(st.nextToken());
	            sum += grp[j];
	    }
	      System.out.println("r="+r + "k="+k+"n="+n+"sum="+sum);
	       output = logic(	r,k,n,grp,sum);
	    System.out.println("Final=" +output);
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

public static int logic(int r,int k,int n,int[] grp,int sum)
{
           int totalmoney = 0;
           int arrptr = 0;
           if(k>sum)
		 totalmoney = r*sum;
	   else
	   {
	    
            for(int i=0; i<r; i++)                                  
            {
                int ppl =0;   
                int iptr = arrptr;
                while(ppl+grp[arrptr]<=k)
                {
                    ppl = ppl+grp[arrptr];
                    arrptr = (arrptr+1)%n;
                    if(iptr == arrptr)
                        break;

                }
                totalmoney = totalmoney+ppl;
            }
           }
            return totalmoney;            
}

}
