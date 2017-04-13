import java.io.*;

public class D
{
	public static int n;
	public static int k;
	public static int sol;
	public static String s;
	public static int [] p = new int [20];
	public static int [] mark = new int [20];
	
	public static int rle (String s)
	{
		int i = 0;
		int toReturn = 0;
		while (i < s.length())
		{
			char c = s.charAt(i);
			while ((i < s.length()) && (s.charAt(i) == c))
				i++;
			toReturn++;
		}
		return toReturn;
	}
	
	public static void solve(int i)
	{
		if (i == k)
		{
			String newS = "";
			for (int j = 0; j < n / k; j++)
			{
				String tmp = "";
				for (int index = 0; index < k; index++)
					tmp += s.charAt(j * k + index);
				for (int index = 0; index < k; index++)
					newS += tmp.charAt(p [index]);
			}
			if (sol > rle (newS))
				sol = rle (newS);
		}
		else
		{
			for (int j = 0; j < k; j++)
				if (mark [j] == 0)
				{
					mark [j] = 1;
					p [i] = j;
					solve (i + 1);
					p [i] = 0;
					mark [j] = 0;
				}
		}
	}

	public static void main(String[] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("D-small.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("D-small.out"));
		
		int numTest = Integer.parseInt(in.readLine());
		for (int testCase = 0; testCase < numTest; testCase++)
		{
			System.out.println(testCase);
			k = Integer.parseInt(in.readLine());
			s = in.readLine();
			n = s.length();
			sol = 10000000;
			for (int i = 0; i < k; i++)
			{
				p [i] = 0;
				mark [i] = 0;
			}
			solve (0);
			
			out.write("Case #" + (testCase + 1) + ": " + sol);
			out.newLine();
		}
		in.close();
		out.close();
	}

}
