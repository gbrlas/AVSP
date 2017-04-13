import java.io.*;

public class A
{
	public static int n;
	public static int value;
	public static int sol;
	public static int [] gate = new int [20002];
	public static int [] change = new int [20002];
	public static int [] start = new int [20002];
	public static int [][] d = new int [20002][2];
	
	public static int evaluation (int a, int b, int oper)
	{
		if (oper == 1)
		{
			if ((a == 1) && (b == 1))
				return 1;
			else
				return 0;
		}
		else
		{
			if ((a == 0) && (b == 0))
				return 0;
			else
				return 1;
		}
	}
	
	public static void solve()
	{
		for (int i = -1 + (n - 1) / 2; i >= 0; i--)
		{
			d [i][0] = -1;
			d [i][1] = -1;
			for (int a = 0; a <= 1; a++)
				for (int b = 0; b <= 1; b++)
					if ((d [2 * i + 1][a] != -1) && (d [2 * i + 2][b] != -1))
					{
						if (d [i][evaluation(a, b, gate [i])] == -1) 
							d [i][evaluation(a, b, gate [i])] = d [2 * i + 1][a] + d [2 * i + 2][b];
						else
							d [i][evaluation(a, b, gate [i])] = Math.min(d [i][evaluation(a, b, gate [i])], d [2 * i + 1][a] + d [2 * i + 2][b]);
					}
			if (change [i] == 1)
			{
				for (int a = 0; a <= 1; a++)
					for (int b = 0; b <= 1; b++)
						if ((d [2 * i + 1][a] != -1) && (d [2 * i + 2][b] != -1))
						{
							if (d [i][evaluation(a, b, 1 - gate [i])] == -1) 
								d [i][evaluation(a, b, 1 - gate [i])] = d [2 * i + 1][a] + d [2 * i + 2][b] + 1;
							else
								d [i][evaluation(a, b, 1 - gate [i])] = Math.min(d [i][evaluation(a, b, 1 - gate [i])], d [2 * i + 1][a] + d [2 * i + 2][b] + 1);
						}
			}
//			System.out.println((i + 1) + ": " + d [i][0] + " " + d [i][1]);
		}
	}

	public static void main(String[] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A-large.out"));
		
		int numTest = Integer.parseInt(in.readLine());
		for (int testCase = 0; testCase < numTest; testCase++)
		{
			System.out.println(testCase);
			String [] tmp = in.readLine().split(" ");
			n = Integer.parseInt(tmp [0]);
			value = Integer.parseInt(tmp [1]);
			for (int i = 0; i < (n - 1) / 2; i++)
			{
				tmp = in.readLine().split(" ");
				gate [i] = Integer.parseInt(tmp [0]);
				change [i] = Integer.parseInt(tmp [1]);
			}
			for (int i = (n - 1) / 2; i < n; i++)
			{
				start [i] = Integer.parseInt(in.readLine());
				d [i][start [i]] = 0;
				d [i][1 - start [i]] = -1;
			}
			
			solve ();
			
			if (d [0][value] == -1)
				out.write("Case #" + (testCase + 1) + ": " + "IMPOSSIBLE");
			else
				out.write("Case #" + (testCase + 1) + ": " + d [0][value]);
			out.newLine();
		}
		in.close();
		out.close();
	}

}
