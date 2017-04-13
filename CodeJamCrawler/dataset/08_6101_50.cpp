import java.io.*;

public class B 
{
	public static final int TIME = 60 * 24 + 1;
	public static int nA;
	public static int nB;
	public static int t;
	public static int [] startA = new int [101];
	public static int [] finishA = new int [101];
	public static int [] startB = new int [101];
	public static int [] finishB = new int [101];
	public static int [] dA = new int [2 * TIME];
	public static int [] dB = new int [2 * TIME];
	public static int solA;
	public static int solB;
	
	public static int parseTime (String time)
	{
		String [] tmp = time.split(":");
		return Integer.parseInt(tmp [0]) * 60 + Integer.parseInt(tmp [1]); 
	}
	
	public static void solve ()
	{
		for (int i = 0; i < 2 * TIME; i++)
		{
			dA [i] = 0;
			dB [i] = 0;
		}
		for (int i = 0; i < nA; i++)
		{
			dA [startA [i]]--;
			dB [finishA [i] + t]++;
		}
		for (int i = 0; i < nB; i++)
		{
			dB [startB [i]]--;
			dA [finishB [i] + t]++;
		}
		solA = 0;
		solB = 0;
		int currentA = 0;
		int currentB = 0;
		for (int i = 0; i < TIME; i++)
		{
			if (currentA + dA [i] >= 0)
				currentA += dA [i];
			else
			{
				solA -= (dA [i] + currentA);
				currentA = 0;
			}
			if (currentB + dB [i] >= 0)
				currentB += dB [i];
			else
			{
				solB -= (dB [i] + currentB);
				currentB = 0;
			}
		}
	}

	public static void main(String[] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("B.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("B.out"));
		
		int numTest = Integer.parseInt(in.readLine());
		for (int testCase = 0; testCase < numTest; testCase++)
		{
			t = Integer.parseInt(in.readLine());
			String [] line = in.readLine().split(" ");
			nA = Integer.parseInt(line [0]);
			nB = Integer.parseInt(line [1]);
			
			for (int i = 0; i < nA; i++)
			{
				line = in.readLine().split(" ");
				startA [i] = parseTime(line [0]);
				finishA [i] = parseTime(line [1]);
			}
			for (int i = 0; i < nB; i++)
			{
				line = in.readLine().split(" ");
				startB [i] = parseTime(line [0]);
				finishB [i] = parseTime(line [1]);
			}
			
			solve ();
			
			out.write("Case #" + (testCase + 1) + ": " + solA + " " + solB);
			out.newLine();
		}
		in.close();
		out.close();
	}

}
