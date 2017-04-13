import java.io.*;

public class C 
{
	public static final int MAX = 1000;
	public static int n;
	public static int m;
	public static int [] x;
	public static int [] y;
	public static int sol;
	public static int [] r = new int [MAX * MAX];
	public static int [][] mark = new int [MAX][MAX];
	
	public static void solve ()
	{
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				mark [i][j] = -1;
		
		r [0] = 2;
		r [1] = 6;
		mark [2][6] = 0;
		m = 2;
		while (true)
		{
			r [m] = (6 * r [m - 1] - 4 * r [m - 2]) % 1000;
			if (r [m] < 0)
				r [m] += 1000;
			if (mark [r [m - 1]][r [m]] == -1)
				mark [r [m - 1]][r [m]] = m - 1;
			else
				break;
			m++;
		}
		
		sol = (r [n % m] + 999) % 1000;  
	}
	
	public static String convert (int num)
	{
		if (num == 0)
			return "000";
		if (num < 10)
			return ("00" + Integer.toString(num));
		if (num < 100)
			return ("0" + Integer.toString(num));
		return Integer.toString(num);
	}

	public static void main(String[] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("C.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C.out"));
		
		int numTest = Integer.parseInt(in.readLine());
		for (int testCase = 0; testCase < numTest; testCase++)
		{
			n = Integer.parseInt(in.readLine());
			
			solve ();
			
			out.write("Case #" + (testCase + 1) + ": " + convert (sol));
			out.newLine();
		}
		in.close();
		out.close();
	}

}
