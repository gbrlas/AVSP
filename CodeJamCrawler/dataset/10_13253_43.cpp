import java.io.*;
import java.util.Scanner;


public class CodeJamA {
	
	public static void main(String args[])throws FileNotFoundException,IOException
	{
		File input = new File("A-small-attempt2.in");
		Scanner in = new Scanner(input);
		BufferedWriter out = new BufferedWriter(new FileWriter("small.out"));
		
		int T = in.nextInt();
		
		for(int i=0;i<T; i++)
		{
		int N = in.nextInt();
		
		long k = in.nextLong();
		
		long p = (long)Math.pow(2.0, N);
		
		
		boolean flag = false;
		if( k%p == (p-1))
			flag = true;
		
		String str= new String("Case #"+(i+1)+": ");
		 if(flag)
		 {
			 str+="ON";
		 }
		 else
			 str+="OFF";
		
	
	
	   str+="\n";
	   System.out.println(str);
	   out.write(str);
		
		
	   
		}
		out.close();
		
		System.out.println("am done");
	}

}
