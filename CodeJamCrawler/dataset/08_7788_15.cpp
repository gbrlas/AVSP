import java.io.*;
import java.util.*;
import java.math.*;

public class B2
{
	public static void main(String[] args) throws Throwable
	{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader("A-small.in")));
		// BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		in.nextToken();
		int t = (int)in.nval, iter = 0;
		while(t-->0)
		{
			iter++;
			in.nextToken();
			int N = (int)in.nval;
			in.nextToken();
			int M = (int)in.nval;
			in.nextToken();
			int A = (int)in.nval;
			int x1 = 0, y1 = 0, x2 = 0, x3 = 0, y2 = 0, y3 = 0;
			boolean f = false;
			if(N*M >= A)
			{
				out:for(x2 = 0; x2 <= N; x2++)
				for(y2 = 0; y2 <= M; y2++)
				for(x3 = 0; x3 <= N; x3++)
				for(y3 = 0; y3 <= M; y3++)
					if(Math.abs(x2*y3-y2*x3)==A)
					{
						f = true;
						break out;
					}
				
			}
			if(f)
				out.println("Case #"+iter+": "+x1+" "+y1+" "+x2+" "+y2+" "+x3+" "+y3);
			else
				out.println("Case #"+iter+": IMPOSSIBLE");
		}
		out.close();
		System.exit(0);
	}
}