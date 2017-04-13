import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class NewThread implements Runnable
{
	


  static int[] rslt = new int[5000]; 
   String[] que = new String[10000];
	Thread t;
	
	   NewThread(String[] sr) {
	      
	      t = new Thread(this, "Demo Thread");
	      System.out.println("Child thread: " + t);
	      t.start(); // Start the thread
	      que = sr;
	   }
	   public static boolean pld(long n) {
			  if ((n < 4 && n > 10) || (n < 23 && n > 100) || (n < 2003 && n > 10000) || (n < 20103 && n > 100000) || (n < 2001003 && n > 10000000))
	          {
	              return false;
	          }
			String st1=	String.valueOf(n);
			String st2 = new StringBuilder(st1).reverse().toString();
			return st1.equals(st2);
			
		}
	   // This is the entry point for the second thread.
	   public void run() {
	      try {

	  		for (int i5 =5000;i5<10000;i5++){
	  			
	  			
	  			String[] s = que[i5].split(" ");   
	  			int count=0;
	  			 
	  			
	  			long f = Long.parseLong(s[0]);
	  			long l = Long.parseLong(s[1]);
	  			
	  			
	  			long a = (long)Math.ceil(Math.sqrt(f));
	  			long b =(long)Math.floor(Math.sqrt(l));
	  			
	  		for (long j1 = a; j1 <= b; j1++) {
	  			
	  			
	  			
	  		
	  		if(pld(j1))
	  		{
	  			
	  			if (pld(j1*j1))
	  			{
	  				count++;
	  				
	  			}
	  			
	  			
	  			
	  			
				
	  					
	  		}
	  			
	  		}
	  			
	  			
	  		rslt[i5-5000]=count;
	  			
	  			
	  		
	  			
	  	
	  			
	  			
	  			
	  			
	  		}
	  		
	  		
	  		fair11.data(rslt);
	         
	     } catch (Exception e) {
	         System.out.println("Child interrupted.");
	     }
	     System.out.println("Exiting child thread.");
	   }








}













public class  fair11{
	
	
	static int[] rslt = new int[5000];
	public static boolean pld(long n) {
		  if ((n < 4 && n > 10) || (n < 23 && n > 100) || (n < 2003 && n > 10000) || (n < 20103 && n > 100000) || (n < 2001003 && n > 10000000))
          {
              return false;
          }
		String st1=	String.valueOf(n);
		String st2 = new StringBuilder(st1).reverse().toString();
		return st1.equals(st2);
		
	}
	
	
	
	
	
	
	public static void data(int[] rs) {
		
		rslt = rs;
		
		
		
	}
	
	
	public static void main(String[] args) throws InterruptedException {

		BufferedReader br = null;
		BufferedWriter ot;
		String st,st1,st2;
		
		
		
		try {
 
		
			File file = new File("F:\\codejam\\outputlrg.out");
			file.createNewFile();
			br = new BufferedReader(new FileReader("F:\\codejam\\C-large-1.in"));
			ot = new BufferedWriter(new FileWriter(file));
		    st =	br.readLine();
		    int sl = Integer.parseInt(st);
		    
		    String[] sr = new String[sl];
		
	
		
		for (int i = 0; i <sl ; i++) {
			
			sr[i] = br.readLine();
			
		}
		
		 new NewThread(sr);
		 
		for (int i5 =0;i5<sl/2;i5++){
			
			Thread.sleep(3);
			String[] s = sr[i5].split(" ");   
			int count=0;
			 
			
			long f = Long.parseLong(s[0]);
			long l = Long.parseLong(s[1]);
			
			
			long a = (long)Math.ceil(Math.sqrt(f));
			long b =(long)Math.floor(Math.sqrt(l));
			
		for (long j1 = a; j1 <= b; j1++) {
			
			
			
		
		if(pld(j1))
		{
			
			if (pld(j1*j1))
			{
				count++;
				
			}
			
			
			
			
					
		}
			
		}
			
			
			
			
			
			
			
			System.out.println("Case #"+(i5+1)+": "+count+"");
			ot.write("Case #"+(i5+1)+": "+count+"");
			ot.write("\n");
			
		}
		
		for (int pp = 0; pp < 5000; pp++) {
			System.out.println("Case #"+(pp+5001)+": "+NewThread.rslt[pp]+"");
			ot.write("Case #"+(pp+5001)+": "+NewThread.rslt[pp]+"");
			ot.write("\n");
		}
		
		
		 	ot.close();
	        br.close();
			
			/*System.out.println(sr[i]);*/
			
			
		
		
		
		
        
        
        
        
      /*  for (int i3 = 0; i3 < ln1.length; i3++) {
        	 System.out.println(ln1[i3]);	
		}
       */
        
		
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
 
	}





	
}

		
		
		
		





