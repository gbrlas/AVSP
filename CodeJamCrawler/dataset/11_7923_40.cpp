import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Magicka {
	public static void main(String[] args) {
		int cases;
		Scanner sc = new Scanner(System.in);
		cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			List<Character> elementList = new LinkedList<Character>();
			List<String> combinationList = new LinkedList<String>();
			List<String> oppositionList = new LinkedList<String>();
			String elementString;
			
			int combinations = sc.nextInt();
			for (int j=0; j<combinations; j++) {
				combinationList.add(sc.next("[A-Z]+"));
				//System.out.println("Combo: "+sc.next("[A-Z]+"));
			}
			int oppositions = sc.nextInt();
			for (int j=0; j<oppositions; j++) {
				oppositionList.add(sc.next("[A-Z]+"));
				//System.out.println("Opposition: "+sc.next("[A-Z]+"));
			}
			int elements = sc.nextInt();
			elementString = sc.next("[A-Z]+");
			
			for (char c :elementString.toCharArray()) {
				elementList.add(c);
				boolean combined = false;
				for (String combo:combinationList) {
					if (elementList.size() < 2) continue;
					if ((combo.toCharArray()[0]==elementList.get(elementList.size()-2) && combo.toCharArray()[1]==c)
							|| (combo.toCharArray()[1]==elementList.get(elementList.size()-2) && combo.toCharArray()[0]==c)) {
						elementList.remove(elementList.size()-1);
						elementList.remove(elementList.size()-1);
						elementList.add(combo.toCharArray()[2]);
						combined = true;
					}
				}
				if (combined) continue;
				for (String opposition:oppositionList) {
					if (elementList.size() < 2) continue;
					if ((elementList.contains(opposition.toCharArray()[0]) && opposition.toCharArray()[1]==c)
							|| (elementList.contains(opposition.toCharArray()[1]) && opposition.toCharArray()[0]==c)) {
						elementList = new LinkedList<Character>();
					}
				}
			}
			System.out.println("Case #" + i + ": " + elementList.toString());
		}

	}
}
