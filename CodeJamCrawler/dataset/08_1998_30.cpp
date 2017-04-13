import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class ExerciseA {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(
		    new InputStreamReader(System.in));

		String line = br.readLine();

		Integer count = new Integer(line);
		Integer testCaseTotal = count;

		while (count > 0) {
			line = br.readLine();
			Integer searchEngineCount = new Integer(line);
			Map<String, Boolean> map = new HashMap<String, Boolean>();
			while (searchEngineCount != 0 && (line = br.readLine()) != null) {
				map.put(line, false);
				searchEngineCount--;
			}

			line = br.readLine();
			Integer queriesCount = new Integer(line);
			List<String> queries = new LinkedList<String>();
			while (queriesCount != 0 && (line = br.readLine()) != null) {
				queries.add(line);
				queriesCount--;
			}

			System.out.println("Case #" + (testCaseTotal - count + 1)
					+ ": " + calculate(map, queries));

			count--;
		}
	}

	public static int calculate(Map<String, Boolean> map,
			List<String> queries) {
		int count = 0;
		for (int i = 0; i < queries.size(); i++) {
			String string = queries.get(i);
			
			if (map.containsKey(string)) {
				map.put(string, true);
			}

			boolean needSwitching = true;
			for (Boolean value : map.values()) {
				if (!value) {
					needSwitching = false;
					break;
				}
			}

			if (needSwitching) {
				count++;
				for (String key : map.keySet()) {
					map.put(key, false);
				}

				map.put(string, true);
			}
		}

		return count;
	}
}
