import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.out;

public class GCJA
{
	public static void main(String[] args) throws Throwable
	{
		// StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader("A-small.in")));
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
		int N = Integer.parseInt(in.readLine());
		int iter = 0;
		while(N-->0)
		{
			iter++;
			int S = Integer.parseInt(in.readLine());
			String[] s = new String[S];
			for(int i = 0; i < S; i++)
				s[i] = in.readLine();
			Arrays.sort(s);
			boolean[] used = new boolean[S];
			int unused = S;
			int Q = Integer.parseInt(in.readLine());
			int sw = 0;
			for(int i = 0; i < Q; i++)
			{
				String q = in.readLine();
				int curr = Arrays.binarySearch(s, q);
				if(!used[curr])
				{
					unused--;
					used[curr] = true;
				}
				if(unused == 0)
				{
					Arrays.fill(used, false);
					unused = S-1;
					used[curr] = true;
					sw++;
				}
			}
			out.println("Case #"+iter+": "+sw);
		}
		out.close();
		System.exit(0);
	}
}