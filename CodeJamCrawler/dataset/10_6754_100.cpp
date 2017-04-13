import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class B 
{
	public static int n;
	public static int k;
	public static int barn;
	public static int time;
	public static int count;
	public static int v [] = new int [100];
	public static int x [] = new int [100];
	public static double times [] = new double [100];
	
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader input =  new BufferedReader (new FileReader (new File ("B-small1.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("B-small1.out")));
			int testNumber = Integer.parseInt(input.readLine());
			for (int t = 1; t <= testNumber; t++)
			{
				System.out.println(t);
				String line [] = input.readLine().split(" ");
				n = Integer.parseInt(line [0]);
				k = Integer.parseInt(line [1]);
				barn = Integer.parseInt(line [2]);
				time = Integer.parseInt(line [3]);
				line = input.readLine().split(" ");
				for (int i = 0; i < n; i++)
					x [i] = Integer.parseInt(line [i]);
				line = input.readLine().split(" ");
				for (int i = 0; i < n; i++)
					v [i] = Integer.parseInt(line [i]);
				
//				for (int i = 0; i < n; i++)
//					for (int j = i + 1; j < n; j++)
//						if (x [i] > x [j])
//						{
//							int tmp = x [i];
//							x [i] = x [j];
//							x [j] = tmp;
//							tmp = v [i];
//							v [i] = v [j];
//							v [j] = tmp;
//						}
				
				for (int i = 0; i < n; i++)
					times [i] = (double)(barn - x [i]) / (double)v [i];
				
				count = 0;
				int i = n - 1;
				while ((k > 0) && (i >= 0))
				{
					if (times [i] <= time)
					{
						i--;
						k--;
					}
					else
					{
						int j = i;
						while ((j >= 0) && (times [j] > time))
							j--;
						if (j < 0)
						{
							i = -1;
							break;
						}
						else
						{
							for (int ii = j; ii < i; ii++)
							{
								double tmp = times [ii];
								times [ii] = times [ii + 1];
								times [ii + 1] = tmp;
							}
							count = count + (i - j);
						}
					}
				}
				if (k > 0) 
					count = -1;
				if ((i < 0) && (k > 0)) 
					count = -1;
				
				if (count > -1)
					output.write("Case #" + t + ": " + count);
				else
					output.write("Case #" + t + ": " + "IMPOSSIBLE");
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
