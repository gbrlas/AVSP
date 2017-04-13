import java.io.*;
import java.util.Scanner;


public class CodeJamA {
	
	public static void main(String args[])throws FileNotFoundException,IOException
	{
		File input = new File("A-large.in");
		Scanner in = new Scanner(input);
		BufferedWriter out = new BufferedWriter(new FileWriter("large.out"));
		
		int T = in.nextInt();
		
		for(int i=0;i<T; i++)
		{
		int N = in.nextInt();
		
		long k = in.nextLong();
			
		boolean flag = false;
		if( (k% (1<<N)  ) == ((1<<N)-1))
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
