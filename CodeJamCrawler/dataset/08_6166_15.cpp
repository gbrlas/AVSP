import java.io.*;

public class C
{
	public static int n;
	public static int m;
	public static int sol;
	public static String [] mark = new String [20];
	public static int deg;
	public static int [] d = new int [2000];
	public static int [] p = new int [2000];
	public static int [] ones = new int [2000];
	
	public static boolean moze (int dole, int gore)
	{
		for (int i = 0; i < m; i++)
			if ((dole & (1 << i)) != 0)
			{
				if ((i > 0) && ((gore & (1 << (i - 1))) != 0))
					return false;
				if ((i < m - 1) && ((gore & (1 << (i + 1))) != 0))
					return false;
			}
		return true;
	}
	
	public static boolean valid (int i, int row)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (((i & (1 << j)) != 0) && ((i & (1 << (j + 1))) != 0))
				return false;
		}
		
		for (int j = 0; j < m; j++)
			if ((mark [row].charAt(j) == 'x') && ((i & (1 << j)) != 0))
				return false;
		return true;
	}
	
	public static void solve()
	{
		deg = 1 << m;
		for (int i = 0; i < deg; i++)
		{
			ones [i] = 0;
			for (int j = 0; j < m; j++)
				if ((i & (1 << j)) != 0)
					ones [i]++;
		}
		
		for (int i = 0; i < deg; i++)
		{
			if (valid (i, 0) == true)
				d [i] = ones [i];
			else
				d [i] = 0;
		}
		
		for (int k = 1; k < n; k++)
		{
			for (int i = 0; i < deg; i++)
				p [i] = d [i];
			
			for (int i = 0; i < deg; i++)
			{
				if (valid (i, k) == false)
				{
					d [i] = 0;
					continue;
				}
				d [i] = ones [i];
				
				for (int j = 0; j < deg; j++)
					if ((valid (j, k - 1) == true) && (moze (j, i) == true))
						d [i] = Math.max(d [i], ones [i] + p [j]);
			}
		
		}
		
		sol = 0;
		for (int i = 0; i < deg; i++)
			sol = Math.max (sol, d [i]);
			
	}

	public static void main(String[] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("C-small.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C-small.out"));
		
		int numTest = Integer.parseInt(in.readLine());
		for (int testCase = 0; testCase < numTest; testCase++)
		{
			System.out.println(testCase);
			String [] tmp = in.readLine().split(" ");
			n = Integer.parseInt(tmp [0]);
			m = Integer.parseInt(tmp [1]);
			for (int i = 0; i < n; i++)
				mark [i] = in.readLine();
			solve ();
			
			out.write("Case #" + (testCase + 1) + ": " + sol);
			out.newLine();
		}
		in.close();
		out.close();
	}

}
