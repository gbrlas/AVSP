import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;


public class d {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try {
            // TODO code application logic 
            BufferedReader reader = new BufferedReader(new FileReader("E:\\CODE PRACTICE\\codejam\\D-large.in"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("E:\\CODE PRACTICE\\codejam\\dl.out"));
            int T = Integer.parseInt(reader.readLine());
            for (int i = 1; i <= T; i++)
            {   
            	int count =0, count1 =0;
            	
            	int N = Integer.parseInt(reader.readLine());
            	String[] s = reader.readLine().split(" ");
            	String[] s1 = reader.readLine().split(" ");
            	
            	double []ken = new double[N];
            	double []naomi = new double[N];
            //	   System.out.println(" ");
     for (int j=0; j<s1.length;j++)
     {
    	 ken[j] = Double.parseDouble(s1[j]);
    	 //System.out.print(" ken"+j+" "+ken[j]+" ");
    	
     }
    // System.out.println(" ");
     for (int y=0; y<s.length;y++)
     {
    	 naomi[y] = Double.parseDouble(s[y]);
    	 //System.out.print(" nao"+y+" "+naomi[y]+" ");
    	
     }
            	
            	Arrays.sort(ken);
            	Arrays.sort(naomi);
           /* 	System.out.println(" ");
            	for (int ch= 0; ch<ken.length;ch++)
            	{
            		
            		System.out.print(" ken"+ch+" "+ken[ch]+" ");
            	   
            		
            	}
            	System.out.println(" ");
            	
             	
            	for (int ch= 0; ch<naomi.length;ch++)
            	{
            		
            		 System.out.print(" nao"+ch+" "+naomi[ch]+" ");
            	}
            	*/
            	
            	int p=0,r =0;
            while(p!=N){	
            	
            				if(ken[p]>naomi[r])
            					{
            					
      //    System.out.println(ken[p]+" ken na	"+naomi[r]);
            					
            						count++;
        //    		System.out.println(count +" count");
            						p++;
            						r++;
            					}else
            						{
            							p++;
            						}
            }
            	
            
            
            int X = (N-count);
            
            p =0;
            r=0;
            
            
            while (r!=N)
            {
            	if (naomi[r]>ken[p])
            	{
            		count1++;
            		r++;
            		p++;
            	}else
            	{
            		r++;
            	}
            	
            }
            
            int Z = count1;
            
     System.out.println(X+"	"+Z);
            
     writer.write("Case #"+i+": " + Z+ " " + X);
     writer.newLine();
            
            
            }
            reader.close();
            writer.close();
		}catch(Exception e)
		{
		e.printStackTrace();
		}

	}

}
