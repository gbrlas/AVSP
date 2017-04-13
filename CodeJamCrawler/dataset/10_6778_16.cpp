import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class B 
{
	
	public static int n, p, sol;
	public static int m [] = new int [10001];
	public static int num [] = new int [10001];
	
	
	public static void calc (int node, int val) 
	{
		if (node >= n) 
			return;
		if (num [node] > val) 
		{
			sol++;
			calc(2 * node + 1, val + 1);
			calc(2 * node, val + 1);
		}
	}
	
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader input =  new BufferedReader (new FileReader (new File ("B-small1.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("B-small1.out")));
			int testNumber = Integer.parseInt(input.readLine());
			for (int t = 1; t <= testNumber; t++)
			{
				p = Integer.parseInt(input.readLine());
				int count = 0;
				for (int i = 0; i <= p; i++)
				{
					String line [] = input.readLine().split(" ");
					for (int j = 0; j < line.length; j++)
					{
						m [count] = Integer.parseInt(line [j]);
						count++;
					}
				}
				
				n = 1 << p;
				for (int i = 0; i < n; i++)
					m [i] = p - m [i];
				for (int i = n; i <= 2 * n - 1; i++)
					num [i] = m [i - n];
				for (int i = n - 1; i > 0; i--)
				{
					num [i] = num [2 * i];
					if (num [i] < num [2 * i + 1])
						num [i] = num [2 * i + 1];
				}
				System.out.println(t + " " + n);
				
				sol = 0;
				calc (1, 0);
				output.write("Case #" + t + ": " + sol);
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
