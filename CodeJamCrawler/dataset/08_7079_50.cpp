import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;


public class SearchEngines
{
	public static void main(String[] args)
	{
		try
		{
			PrintStream o= new PrintStream(new File("output2.txt"));
			Scanner s= new Scanner(new File("smallin2.in"));
			ArrayList<String> engines, queries;
			int numCases, numEng, numQuer;
			
			numCases= Integer.valueOf(s.nextLine());
			System.out.println(numCases);
			for(int c= 0; c < numCases; c++)
			{
				engines = new ArrayList<String>();
				queries = new ArrayList<String>();
 
				numEng= Integer.valueOf(s.nextLine());
				System.out.println("eng: " + numEng);
				for(int e= 0; e < numEng; e++)
				{
					engines.add(s.nextLine());
					System.out.println(engines.get(e));
				}
				
				numQuer= Integer.valueOf(s.nextLine());
				System.out.println("quer: " + numQuer);
				for(int q= 0; q < numQuer; q++)
				{
					queries.add(s.nextLine());
					System.out.println(queries.get(q));
				}
				String str = "Case #" + (c+1) + ": " + countSwitches(engines, queries);
				System.out.println(str + "\n____________________\n!!!!!!!!!!!!!!!!!\n\n");
				o.println(str);
			}
		} catch(IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static int countSwitches(ArrayList<String> engines, ArrayList<String> queries)
	{
		int numUsed = 0;
		int switches = 0;
		int i;
		boolean[] usedEngines = new boolean[engines.size()];
		while(queries.size()>0)
		{
			i = engines.indexOf(queries.remove(0));
			if(!usedEngines[i])
			{
				usedEngines[i] = true;
				numUsed++;
				if(numUsed == engines.size())
				{
					switches++;
					usedEngines = new boolean[engines.size()];
					numUsed = 1;
					usedEngines[i] = true;
				}
			}
		}
		return switches;
	}
}