import java.io.*;
import java.util.Scanner;


public class CodeJamC {
	
	public static void main(String args[]) throws FileNotFoundException,IOException
	{
		File input = new File("C-small-attempt0.in");
		Scanner in = new Scanner(input);
		//Scanner in = new Scanner(System.in);
		
		
	   BufferedWriter out = new BufferedWriter(new FileWriter("small.out"));
		
		long T = in.nextLong();
		//long T = 1;
		
		for(long i=0;i<T;i++)
		{
			long R = in.nextLong();
			//long R = 100;
			long k = in.nextLong(); //capacity
			//long k = 10;
			int N = in.nextInt();
			//int N = 1;
			long arr[] = new long[N]; //size of each group
			for(int j=0;j<N;j++)
				arr[j] = in.nextLong();
			
			int curr=0;
			
			long load=0;
			long result=0;
			for(long j=0;j<R;j++)//R times a day
			{
				int prev=-1;
				
				while( (load + arr[curr]) <=k  && curr!= prev)
				{
					if(load==0) prev = curr;
					load+=arr[curr];
					curr = (curr+1)%N;
				}
				
					result+=load;
					load=0;	
				
			}
			
			
			String str = new String("Case #"+(i+1)+": "+(result));
			str+="\n";
			System.out.print(str);
			out.write(str);
				
		}
		
			out.close();	
		
		
	}

}
