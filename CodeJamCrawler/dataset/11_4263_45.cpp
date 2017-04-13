import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


public class Magicka {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int casesNumber = scn.nextInt();

		for(int c = 0; c < casesNumber; c++) {

			Set<String> opposedSet = new HashSet<String>();
			Map<String,Character> combinationMap = new HashMap<String,Character>();

			int combinationNumber = scn.nextInt();
			for (int comb_i = 0; comb_i < combinationNumber; comb_i++) {
				String comb = scn.next();
				//use it
				combinationMap.put(reorderCombination(comb), comb.charAt(2));				
			}

			int oposedNumber = scn.nextInt();
			for (int opo_i = 0; opo_i < oposedNumber; opo_i++) {
				String oposed = scn.next();
				//use it
				opposedSet.add(reorder(oposed));
			}

			scn.nextInt();
			String magic = scn.next();
			List<Character> output = new ArrayList<Character>();
			if (magic.length() > 0) {
				output.add(magic.charAt(0));
			}
			for (int i = 1; i < magic.length(); i++) {
				char cur = magic.charAt(i);
				if (output.size() == 0) {
					output.add(cur);
					continue;
				}
				String joint = reorder("" + output.get(output.size()-1) + cur);

				if (combinationMap.containsKey(joint)) {
					output.remove(output.size()-1);
					output.add(combinationMap.get(joint));
				} else {
					boolean clean = false;
					for(char iter = 0; iter < output.size(); iter++) {
						String s = output.get(iter) + "" + cur;
						if (opposedSet.contains(reorder(s))) {
							output.clear();
							clean = true;
							break;
						}
					}
					if (!clean) {
						output.add(cur);
					}
				}
			}
			System.out.println("Case #" + (c+1) + ": " + output);
		}
	}

	private static String reorderCombination(String comb) {
		char a = comb.charAt(0);
		char b = comb.charAt(1);
		if (a < b) {
			return "" + a + b;
		}
		return "" + b + a;
	}

	private static String reorder(String comb) {
		return reorderCombination(comb);
	}

}
