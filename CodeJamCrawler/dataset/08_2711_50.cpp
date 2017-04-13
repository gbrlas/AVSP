import java.io.*;
import java.util.*;

public class SafeSearch {
	public static void main(String args[])
	{
		String filename = args[0];
		File file = new File(filename);
		BufferedReader br;
		try
		{
			br = new BufferedReader(new FileReader(file));
			int n = Integer.parseInt(br.readLine());
			
			for (int i =0; i < n; i++)
				System.out.println("Case #" + (i + 1) + ": " + checkCase(br));
		}
		catch (Exception e) 
		{
			e.printStackTrace();
		}
	}
	
	private static int checkCase(BufferedReader br)
	{
		HashMap<String,Integer> engines = null;
		
		try
		{
			int s = Integer.parseInt(br.readLine());
			engines = new HashMap<String,Integer>(s);
			for (int i =0; i < s; i++){
				String engine  = br.readLine();
				engines.put(engine , 0);
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		return calcSwitches(br, engines);
	}
	
	
	private static int calcSwitches(BufferedReader br, HashMap<String,Integer> engines)
	{
		int switches = 0;
		try 
		{
			String engine;
			Iterator it;
			int edges;	
			int q = Integer.parseInt(br.readLine());
			if (q > 0){
				String[] strs = new String[q];
				
				String lastEngine;
				for(int i=0; i <q; i++){
					strs[i] = br.readLine();
				}
				
				lastEngine = chooseEngine(engines, strs, 0); 
				for(int i=1; i < q; i++){
					//System.out.println(">>" + strs[i] + " " + lastEngine );
					if(lastEngine.equals(strs[i])){
						lastEngine = chooseEngine(engines, strs, i);
						switches++;
					}
				}
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		return switches;
	}
	
	
	private static String chooseEngine(HashMap<String, Integer> engines, String[] strs, int i){
		Iterator it;
		
		it= engines.keySet().iterator();
		while (it.hasNext())
			engines.put((String) it.next(), new Integer(strs.length));
	
		int enginesFound = 0;
		for(int j=i; j < strs.length; j++){
			if((Integer) engines.get(strs[j]) > j) 
				engines.put(strs[j], j);
		}
		
		it= engines.keySet().iterator();
		int maxDist = -1;
		String maxEngine = "";
		while (it.hasNext()){
			String engine = (String) it.next();
			int dist = engines.get(engine);
			if (dist > maxDist){
				maxDist = dist;
				maxEngine = engine;
			}
		}
		//System.out.println(maxEngine + " " + maxDist);
		return maxEngine;
	}
}


