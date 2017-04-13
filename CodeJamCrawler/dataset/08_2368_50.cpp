import java.util.ArrayList;
import java.util.Scanner;


public class SavingTheUniverse {

	static Scanner scn;
	static String NL = System.getProperty("line.separator");
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		scn = new Scanner(System.in);
		
		int cases = Integer.parseInt(scn.nextLine());
		for (int c = 1; c <= cases; c++) {
			
			int enginesCount = Integer.parseInt(scn.nextLine());
			
			ArrayList<String> engines = new ArrayList<String>(enginesCount);
			for (int e = 0; e < enginesCount; e++) {
				engines.add(scn.nextLine());
			}
			
			int queriesCount = Integer.parseInt(scn.nextLine());
			String current = null;
			boolean[] used = new boolean[engines.size()];
			int left = used.length;
			int switches = 0;
			for (int q = 0; q < queriesCount; q++) {
				String query = scn.nextLine();
				if (current != null) {
					if (query.equals(current)) {
						used = new boolean[engines.size()];
						left = used.length;
						current = null;
						switches++;
					}
				}
				if (current == null) {
					int index = engines.indexOf(query);
					if (!used[index]) {
						used[index] = true;
						left--;
					}
				}
				if (left == 1) {
					int index = -1;
					for (int i = 0; i < used.length; i++) {
						if (!used[i]) {
							index = i;
							break;
						}
					}
					current = engines.get(index);
				}
			}
			System.out.println("Case #" + c + ": " + switches);
		}
	}

}


