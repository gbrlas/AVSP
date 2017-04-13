import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;


public class Bullseye {
	
	public static int numOfCircles (int r , int t)
	{
		int count = 0;
		int n = 1;
		int newr = 0;
		newr = r + (n-1) * 2;
		while (t >= 2 * newr + 1)
		{
			t= t - (2 * newr + 1);
			count ++ ;
			n++;
			newr = r + (n-1) * 2;
		}
		return count ;
	}
		
	public static void main(String[] args) throws Exception {
		
		BufferedReader in = new BufferedReader(new FileReader("input.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		String in_line = "";
		String [] parms ;
		int numOfCases = Integer.parseInt(in.readLine());
		for (int i =0;i<numOfCases;i++)
		{
			in_line = in.readLine();
			parms = in_line.split(" ");					
			out.println("Case #" + (i+1) +": "+ (numOfCircles(Integer.parseInt(parms[0]),Integer.parseInt(parms[1]) )));
		}
		
		in.close();
		out.close();
		
	}
}
