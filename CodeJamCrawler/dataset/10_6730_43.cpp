import java.io.*;

public class A 
{
	
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader input =  new BufferedReader (new FileReader (new File ("A-small.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("A-small.out")));

			int testNumber = Integer.parseInt(input.readLine());
			for (int t = 1; t <= testNumber; t++)
			{
				String line [] = input.readLine().split(" ");
				int n = Integer.parseInt(line [0]);
				int k = Integer.parseInt(line [1]);
				System.out.println(n + " " + k);
				int pow = (1 << n) - 1;
				if ((k & pow) == pow)
					output.write("Case #" + t + ": ON");
				else
					output.write("Case #" + t + ": OFF");
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
