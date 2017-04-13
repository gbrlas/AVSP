import java.io.*;
import java.util.*;

public class SavingTU {

	private final String filename;
	
	private TreeMap<String, Integer> sEngs;
	Set<Map.Entry<String, Integer>> entries;
	private String[] queries;
	
	
	public SavingTU(String filename)
	{
		this.filename = filename;
	}
	
	public void process() throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(filename)));
		
        Writer writer = new OutputStreamWriter(new FileOutputStream("output.txt"), "ISO8859_1");
        PrintWriter output = new PrintWriter(writer);
		
		int iTestCases = Integer.parseInt(input.readLine());
		for( int i = 0; i < iTestCases; i++ )
		{
			this.sEngs = new TreeMap<String, Integer>();
			int iSEngs = Integer.parseInt(input.readLine());
			for( int j = 0; j < iSEngs; j++ )
				this.sEngs.put(input.readLine(), 0);
			entries = this.sEngs.entrySet();
				
			int iQueries = Integer.parseInt(input.readLine());
			this.queries = new String[iQueries];
			for( int j = 0; j < iQueries; j++ )
				this.queries[j] = input.readLine();	
		
			output.println("Case #"+(i+1)+": "+nrOfSwitches(0,0));
		}
		input.close();
		output.close();
	}
	
	private int nrOfSwitches(int iStart, int switches)
	{
		int i = iStart;
		for( ; i < queries.length; i++ )
		{
			this.sEngs.put(queries[i], this.sEngs.get(queries[i])+1);
			if( !sEngs.containsValue(0) )
				break;
		}
		
		if( i == queries.length )
			return switches;
		else
		{
			for(Map.Entry<String, Integer> e: entries)
				e.setValue(0);
		}
		
		return nrOfSwitches(i,++switches);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args)
		throws IOException, FileNotFoundException 
	{
		SavingTU stu = new SavingTU("input.txt");	
		
		stu.process();

	}

}
