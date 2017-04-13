import java.io.BufferedWriter;
//port java.util.*;


//port java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;	
import java.util.StringTokenizer;
//import java.lang.Math;
//import java.util.ArrayList;
//import java.util.HashMap;
public class RCP1
{
	public static void main(String args[])
	{
		String filename = args[0];
		int i=0,j=0;
		int testcase=0 ;
		int n=0,k=0;
		String out="";
		BufferedWriter bufferedWriter = null;
		try { BufferedReader in = new BufferedReader(new FileReader(filename));
		String str;

		boolean output;
		str = in.readLine();
		testcase = Integer.parseInt(str);
 int C;
		//Construct the BufferedWriter object
		bufferedWriter = new BufferedWriter(new FileWriter("oneoutput.txt"));
		
		for (n=0;n <testcase; n++)
		{
			String Name=null;
			StringTokenizer st1=null;
			int N=0, result;
		/*	ArrayList<Integer> o=new ArrayList<Integer>();
			ArrayList<Integer> b=new ArrayList<Integer>();
			ArrayList<String> next=new ArrayList<String>();
		*/	
			str = in.readLine(); //name n
			st1 = new StringTokenizer(str, " ");

			Name = st1.nextToken();
			N = Integer.parseInt(st1.nextToken());
			
			
			//logic
			result=logic(Name,N);
			
			//logic end
			
			//logic ends here output has a string	
			out="Case #"+(n+1)+": "+result;
		/*	for(int r1=0;r1<output1.length();r1++)
			out = out+output1.charAt(r1)+", ";
			if (output1.length()>0)
			out= out.substring(0, out.length()-2);
			out=out+"]";
		*/	bufferedWriter.write(out);
			if (i !=testcase)
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

	public static int logic( String Name, int N)
	{
		int M=0;
		// get all strings with N letter substrings
		int Len=Name.length();
		for(int i=0;i<Len;i++)
		{
			for(int j=i+N;j<=Len;j++)
			{
				String s=Name.substring(i,j);
			//	System.out.println("Checking substring."+s);
				int k=check(s,N);
			
				if(k==1)
				{
				 M++;
		//		 System.out.println("true "+s);
				}
		//		else
		//			System.out.println("false "+s);
			}
			
		}
		
		return M;
	}

	public static int check( String Name, int N)
	{
		int Len=Name.length();
		int M=0,MAxM=0;
		for(int i=0;i<Len;i++)
		{
		//	System.out.println("Checking substring."+MAxM+" "+M);
			if(Name.charAt(i)!='a'
					&&Name.charAt(i)!='e'
					&&Name.charAt(i)!='i'
							&&Name.charAt(i)!='o'
									&&Name.charAt(i)!='u'
											&&Name.charAt(i)!='A'
													&&Name.charAt(i)!='E'
															&&Name.charAt(i)!='I'
																	&&Name.charAt(i)!='O'
																			&&Name.charAt(i)!='U'
					){
				M++;
				if(MAxM<M)
					MAxM=M;
			}
			else
				M=0;
			
			
		}
			
		if(MAxM>=N)
				return 1;
		return 0;
	}	
		
	
}
