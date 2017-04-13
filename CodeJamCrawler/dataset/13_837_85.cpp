import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Treasure {

	public int[] keys;
	public int[] typeForChest;
	public int[][] keysInChest;
	
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(new File("test.txt"));
		PrintStream p = new PrintStream(new File("output.txt"));
		//System.setOut(p);
		int i = s.nextInt();
		Treasure t;
		int[] res;
		int k = 1;
		for(;i>0;i--) {
			t = new Treasure(s);
			res = t.solve();
			System.out.printf("Case #%d:", k);
			k++;
			if(res == null)
				System.out.println(" IMPOSSIBLE");
			else {
				for(int j : res) {
					System.out.printf(" %d", j);
				}
				System.out.println();
			}
		}
		
	}
	
	
	public Treasure(Scanner s) {
		int numKey = s.nextInt();
		int numChests = s.nextInt();
		int keysAvail[] = new int[400];
		keys = new int[400];
		int k;
		for(int i = 0; i < numKey; i++) {
			k = s.nextInt();
			keys[k]++;
			keysAvail[k]++;
		}
		typeForChest = new int[numChests];
		keysInChest = new int[numChests][];
		int numInside = 0;
		for(int i = 0; i < numChests; i++) {
			typeForChest[i] = s.nextInt();
			keysAvail[typeForChest[i]]--;
			numInside = s.nextInt();
			keysInChest[i] = new int[numInside];
			for(int j = 0; j < numInside; j++) {
				k = s.nextInt();
				keysInChest[i][j] = k;
				keysAvail[k]++;
			}
		}
		for(int l : keysAvail) {
			if(l < 0) {
				keys = null;
				break;
			}
		}
	}
	
	//Return true if screwed
	public boolean areWeScrewed(int key, boolean[] opened) {
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(11, new Comparator<Integer>() {
			public int compare(Integer a , Integer b) {
				return b - a;
			}
		});
		int totalCount = keys[key]; //Total keys we can get
		int totalDoors = 0; //Doors we'll have to open
		
		for(int i = 0; i < opened.length; i++) {
			if(opened[i]) continue;
			if(typeForChest[i] == key) {
				totalDoors += 1;
				int count = 0;
				for(int j : keysInChest[i]){
					if(j == key) count++;
				}
				pq.add(count);
			} else {
				for(int j : keysInChest[i]) {
					if(j == key) {
						totalCount++;
					}
				}
			}
		}
		while(totalCount > 0 && !pq.isEmpty()) {
			totalCount += pq.poll() - 1;
		}
		
		
		return totalCount < 0 || !pq.isEmpty();
	}
	
	public int[] solve() {
		if(keys == null) return null;
		boolean[] opened = new boolean[typeForChest.length];
		
		for(int i = 1; i < 400; i++) {
			if(areWeScrewed(i, opened)) {
				return null;
			}
		}
		return solve(new boolean[typeForChest.length], 0, 0, new int[typeForChest.length]);
	}
	
	public int[] solve(boolean[] opened, int toTry, int numOpened, int[] order) {
		int[] ret;
		if(toTry == opened.length)
			return null;
		if(numOpened == opened.length)
			return order;
		while(opened[toTry] == true || keys[typeForChest[toTry]] == 0) {
			toTry = toTry+1;
			if(toTry == opened.length)
				return null;
		}
		
		if(keys[typeForChest[toTry]] > 0) {
			keys[typeForChest[toTry]]--;
			for(int i : keysInChest[toTry])
				keys[i]++;
			opened[toTry] = true;
			int bkp = order[numOpened];
			order[numOpened] = toTry+1;
			if(!areWeScrewed(typeForChest[toTry], opened)) {
				ret = solve(opened, 0, numOpened+1, order);
				if(ret != null)
					return ret;
			}
			for(int i : keysInChest[toTry])
				keys[i]--;
			keys[typeForChest[toTry]]++;
			opened[toTry] = false;
			order[numOpened] = bkp;
			
		}
		return solve(opened, toTry + 1, numOpened, order);
	}

}
