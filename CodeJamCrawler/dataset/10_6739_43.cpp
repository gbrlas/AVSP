import java.io.*;
import java.math.BigInteger;

public class C 
{
	
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader input =  new BufferedReader (new FileReader (new File ("C-small.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("C-small.out")));

			int testNumber = Integer.parseInt(input.readLine());
			for (int t = 1; t <= testNumber; t++)
			{
				String line [] = input.readLine().split(" ");
				int r = Integer.parseInt(line [0]);
				int k = Integer.parseInt(line [1]);
				int n = Integer.parseInt(line [2]);
				line = input.readLine().split(" ");
				System.out.println(r + " " + k + " " + n);
				int [] g = new int [n];
				for (int i = 0; i < n; i++)
					g [i] = Integer.parseInt(line [i]);
				
				int [] mark = new int [n];
				int [] score = new int [n];
				int [] group = new int [n];
				for (int i = 0; i < n; i++)
				{
					mark [i] = 0;
					score [i] = 0;
					group [i] = 0;
				}
				int index = 0;
				while (mark [index] == 0)
				{
					mark [index] = 1;
					int j = index;
					int sum = 0;
					while ((sum + g [index] <= k) && ((sum == 0) || (index != j)))
					{
						sum = sum + g [index];
						index = index + 1;
						if (index == n)
							index = 0;
					}
					group [j] = index;
					score [j] = sum;
				}

				BigInteger sol = new BigInteger ("0");
				index = 0;
				while (r > 0)
				{
					sol = sol.add(new BigInteger (Integer.toString(score [index])));
					index = group [index];
					r--;
				}
				output.write("Case #" + t + ": " + sol.toString());
				output.newLine();
			}
			output.close();
			input.close();
		}
		catch (IOException ex)
		{
			ex.printStackTrace();
		}

	}

}
