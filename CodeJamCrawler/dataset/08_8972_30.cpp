import java.io.*;

/**
 * Summary description for Program
 */
public class SaveUniverse
{
	private int getBlockSize(String engineName, String[] queries, int startPoint)
	{
		for (int i = startPoint; i < queries.length; i++)
		{
			if (queries[i].equals(engineName))
				return i;
		}

		return queries.length;
	}

	private int findSwitches(String[] engines, String[] queries) 
	{		
		int block = -1;
		int bestChoice = -1;
		int minBlock = -1;
		int switches = 0;
		int startPoint = 0;
		boolean completeSearch = false;
		

		while (!completeSearch) {
			for (int i = 0; i < engines.length; i++)
			{
				block = getBlockSize(engines[i], queries, startPoint);
				if (i != bestChoice)
				{					
					if (block > minBlock || block == -1)
					{
						minBlock = block;
						bestChoice = i;
					}
				}
			}
			startPoint = minBlock;
			if (startPoint == queries.length)
				completeSearch = true;
			else
			{
				switches++;				
				minBlock = -1;
			}
		}

		return switches;
	}

	private int processCase(BufferedReader buf) throws IOException
	{
		int engineCount = new Integer(buf.readLine()).intValue();
		String[] engines = new String[engineCount];

		for (int i =0; i < engineCount; i++) 		
			engines[i]= buf.readLine();
	
		int searchStringCount = new Integer(buf.readLine()).intValue();
		String[] queries = new String[searchStringCount];

		for (int i = 0; i < searchStringCount; i++)
			queries[i] = buf.readLine();

		return findSwitches(engines, queries);	
	}

	public SaveUniverse()
	{
		int cases = 0;
		String rawLine = null;

		try
		{
			BufferedReader buf = new BufferedReader(new FileReader("D:\\GoogleContest\\A-small-attempt1.in"));
			FileWriter out = new FileWriter("D:\\GoogleContest\\A-small-attempt1.out");
			
			rawLine = buf.readLine();
			cases = new Integer(rawLine).intValue();

			for (int i = 0; i < cases; i++)
			{
				out.write("Case #" + (i+1) + ": " +processCase(buf) + "\n");
			}
			buf.close();
			out.close();
		}
		catch (IOException ex)
		{
			System.out.println("IO Error: " + ex.getMessage());
		}
		catch (Exception e)
		{
			System.out.println("Unknown Error: " + e.getMessage());
		}
		
	}

	public static void main(String[] args)
	{
		new SaveUniverse();	
	}
}
