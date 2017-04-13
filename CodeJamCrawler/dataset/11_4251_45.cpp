import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Robots {

	public static Robot orange;
	public static Robot blue;
	public static int current = 0;
	public static int moves = 0;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		
		Scanner scn = new Scanner(System.in);
		int casesNumber = scn.nextInt();
		for (int c = 0; c < casesNumber; c++) {
			
			int input = scn.nextInt();
			
			orange = new Robot('O', input);
			blue = new Robot('B', input);

			
			for (int i = 0; i < input; i++) {
				char name = scn.next().charAt(0);
				int pos = scn.nextInt();
				
				Entry entry = new Entry(pos, i, name);
				
				if (name == 'O') {
					orange.addEntry(entry);
				} else {
					blue.addEntry(entry);
				}
			}
			
			//solve it
			current = 0;
			moves = 0;
			boolean a;
			boolean b;
			while(current < input) {
				a = orange.move();
				b = blue.move();
				if (a || b) {
					current++;
				}
				moves++;
			}
			StringBuilder builder = new StringBuilder("Case #");
			builder.append((c+1));
			builder.append(": ");
			builder.append(moves);
			System.out.println(builder.toString());
		}
	}

}

class Entry {
	
	public Entry(int pos, int i, char r) {
		robot = r;
		button = pos;
		number = i;
	}
	
	char robot;
	int button;
	int number;
}

class Robot {
	
	char name;
	int pos;
	List<Entry> entries;
	int currentEntry;
	
	public Robot(char c, int total) {
		name = c;
		pos = 1;
		entries = new ArrayList<Entry>(total);
		currentEntry = 0;
	}

	public boolean move() {
		if (currentEntry >= entries.size()) {
			return false;
		}
		boolean ret = false;
		Entry e = entries.get(currentEntry);
		if (e.button > pos) {
			//move
			pos++;
		} else if (e.button < pos) {
			//move
			pos--;
		} else {
			//press?
			if (Robots.current == e.number) {
				ret = true;
				currentEntry++;
			}
		}
		return ret;
	}

	public void addEntry(Entry entry) {
		entries.add(entry);
	}
}
