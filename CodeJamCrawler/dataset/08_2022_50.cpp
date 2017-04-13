package gcj.qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.LinkedList;
import java.util.List;

public class Main {
	public static int solve(List<String> engines, List<String> queries) {
		if (queries.isEmpty()) {
			return 0;
		}
		
		int minSwitches = 0;
		while (!queries.isEmpty()) {
			int maxSwitchThis = 0;
			for (String e : engines) {
				int nextSwitch = queries.indexOf(e);
				if (nextSwitch == -1) {
					// Not found, so we can use this engine forever:
					return minSwitches;
				} else {
					maxSwitchThis = Math.max(maxSwitchThis, nextSwitch);
				}
			}
			queries = queries.subList(maxSwitchThis, queries.size());
			minSwitches++;
		}
		return minSwitches;
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		List<String> engines = new LinkedList<String>();
		List<String> queries = new LinkedList<String>();
		LineNumberReader r = new LineNumberReader(new BufferedReader(new FileReader(args[0])));
		try {
			int numCases = Integer.parseInt(r.readLine());
			for (int i = 0; i < numCases; i++) {
				engines.clear();
				queries.clear();
				int numEngines = Integer.parseInt(r.readLine());
				for (int e = 0; e < numEngines; e++) {
					engines.add(r.readLine());
				}
				int numQueries = Integer.parseInt(r.readLine());
				for (int q = 0; q < numQueries; q++) {
					queries.add(r.readLine());
				}
				System.out.println("Case #" + (i + 1) + ": " + solve(engines, queries));
			}
		} catch (IOException e) {
			System.err.println(args[0] + ": " + e);
		} finally {
			r.close();
		}
	}

}
