import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

@SuppressWarnings("unchecked")
public class A 
{
	public static int n;
	public static int m;
	public static int count;
	public static HashMap<String, Boolean> [] directories = new HashMap [1000];
	
	public static void add (String s, boolean exist)
	{
		String [] d = s.split("/");
		String current_dir = "";
		for (int i = 1; i < d.length; i++)
		{
			current_dir += "/" + d [i];
			if (directories [i].containsKey(current_dir) == false)
				directories [i].put(current_dir, exist);
		}
	}
	
	public static void main(String[] args) 
	{
		try
		{
			for (int i = 0; i < directories.length; i++)
				directories [i] = new HashMap<String, Boolean>();

			BufferedReader input =  new BufferedReader (new FileReader (new File ("A-large.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("A-large.out")));
			int testNumber = Integer.parseInt(input.readLine());
			for (int t = 1; t <= testNumber; t++)
			{
				String line [] = input.readLine().split(" ");
				int n = Integer.parseInt(line [0]);
				int m = Integer.parseInt(line [1]);
				System.out.println(n + " " + m);
				for (int i = 0; i < directories.length; i++)
					directories [i].clear();
					
				for (int i = 0; i < n; i++)
					add (input.readLine(), true);
				for (int i = 0; i < m; i++)
					add (input.readLine(), false);
				
				count = 0;
				for (int i = 0; i < directories.length; i++)
					for (Boolean exist : directories [i].values())
						if (exist == false)
							count++;
				output.write("Case #" + t + ": " + count);
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
