import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Set;


public class Universe {
	
	public static void main(String args[]) throws Exception{
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		int noCases = Integer.parseInt(reader.readLine());
		PrintStream out = new PrintStream(args[1]);
		int []switches = new int[noCases];
		for(int i = 0 ;i < noCases;i++) {
			int noEngines = Integer.parseInt(reader.readLine());
			String []engines = new String[noEngines];
			for(int e=0;e<noEngines;e++) {
				engines[e] = reader.readLine();
			}
			int noQueries = Integer.parseInt(reader.readLine());
			String []queries = new String[noQueries];
			for(int q=0;q<noQueries;q++) {
				queries[q] = reader.readLine();
			}
			switches[i] = getMinimumSwitches(out,engines, queries,0); 
		}
		
		for(int i=0 ;i < noCases;i++) {
			out.println("Case #"+(i+1)+": "+switches[i]);
		}
		out.close();
		
	}
	
	public static int getMinimumSwitches(PrintStream out, String[] engines, String[] queries, int startAt) {
		int switches = 0;
		if(queries.length == 0 ){
			return 0;
		}
		int []howManyTimesRepeated = new int[engines.length];
		int []howFarCanItGo= new int[engines.length];
		for(int i=0;i<engines.length;i++) {
			howFarCanItGo[i] = -1;
		}
		int farthestDistance = -1;
		int engineWhichTakesYouFarthest = -1;
		String engine = null;
		String query = null;
		for(int e=0 ;e<engines.length;e++) {
			engine = engines[e];
			for(int q=startAt;q<queries.length;q++) {
				query = queries[q];
				if(engines[e].equals(queries[q])) {
					howManyTimesRepeated[e]++;
					if(howFarCanItGo[e] == -1) {
						howFarCanItGo[e] = q;
						if(q > farthestDistance) {
							farthestDistance = q;
							engineWhichTakesYouFarthest = e;
						}
					}
				}
			}
			if(howManyTimesRepeated[e] == 0) {
				return 0;
			} 
		}
		//We already know the engine that can take you farthest
		//so go that far using the engine;
		//intcrement switches
		switches++;
		if(farthestDistance == (queries.length-1)) {
			return switches;
		}
		
		switches+=getMinimumSwitches(out,engines, queries, farthestDistance);
		return switches;
	}
}
