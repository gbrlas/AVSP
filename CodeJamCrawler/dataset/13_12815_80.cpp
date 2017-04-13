import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class FairAndSquare {

	static String temp_str;
	public static boolean Ispalindrome (Long a)
	{
		temp_str = a+"";
		return temp_str.equals(new StringBuffer(temp_str).reverse().toString());
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("input.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		String in_line = "";
		String [] parms ;
		int numOfCases = Integer.parseInt(in.readLine());
		int count ;
		double root;
		for (int i =0;i<numOfCases;i++)
		{
			count = 0 ;
			in_line = in.readLine();
			parms = in_line.split(" ");
			for (Long k =Long.parseLong(parms[0]);k<=Long.parseLong(parms[1]);k++)
			{
				root = Math.sqrt(k);
				if (root == (int)root && Ispalindrome((long) root) && Ispalindrome(k))
					count++;
			}
			
			out.println("Case #" + (i+1) + ": "+count);
		}
		
		in.close();
		out.close();
		
		
	}
}
