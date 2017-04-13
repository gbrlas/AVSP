import java.io.*;

public class Round1A
{
	public static void main(String[] args)
	{
		String[] fileInput;
		long[] output;
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt2.in"));
			PrintWriter pw = new PrintWriter(new FileOutputStream("output.out"));
			
			int T = Integer.valueOf(br.readLine());
			
			fileInput = new String[T];
			output = new long[T];
			
			for(int i = 0; i < T; i++)
			{
				fileInput[i] = br.readLine();
			}
			br.close();
						
			for(int i = 0; i < fileInput.length; i++)
			{
				String temp = fileInput[i];
				String temp2 = "";
				int distinct = 0;
				char symbol;
				
				do
				{
					symbol = temp.charAt(0);
					temp2 = "";
					for(int j = 0; j < temp.length(); j++)
					{
						if(symbol != temp.charAt(j))
							temp2 = temp2 + temp.charAt(j);
						
					}
					temp = temp2;
					distinct++;
				}
				while(temp != "");
				
				output[i] = findOut(fileInput[i], distinct);
				
			}
			
			for(int j = 0; j < T; j++)
			{
				System.out.println("Case #" + (j+1) + ": " + output[j]);
				pw.println("Case #" + (j+1) + ": " + output[j]);
			}
			pw.close();
		}
		catch(IOException e)
		{
			System.out.println("IOException");
		}
	}
	
	static long findOut(String in, int base)
	{
		long out = 0;
		String checked = "";
		
		for(int i = 0; i < in.length(); i++)
		{
			int j = checked.length();
			
			if(j == 0)
				j = 1;
			else if(j == 1)
				j = 0;
			
			boolean found = false;
			for(int k = 0; k < checked.length(); k++)
			{
				if(checked.charAt(k) == in.charAt(i))
				{
					j = k;
					if(j == 0)
						j = 1;
					else if(j == 1)
						j = 0;
					
					found = true;
				}
			}
			
			if(!found)
				checked = checked + in.charAt(i);

			out += j * Math.pow(base, in.length() - (i+1));
		}
		
		if(checked.length() == 1)
		{
			out = 0;
			for(int i = 0; i < in.length(); i++)
			{
				if(checked.charAt(0) == in.charAt(i))
				{
					out += 1 * Math.pow(2, in.length() - (i+1));
				}
			}
		}
		
		return out;
	}
}

