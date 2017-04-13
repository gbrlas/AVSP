// Google CodeJam 2010
// Question 3: Theme Park

import java.util.*;
import java.io.*;

public class RollerCoaster {

	public static void main(String[] args) {
	
		File input = new File("C-small-attempt1.in");
		Scanner sc = null;
		try {
			sc = new Scanner(input);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
		int T = sc.nextInt();
		
		int R, k, N, numPassengers, profit, peopleBoarded, groupsBoarded;
		String line;
		LinkedList<Integer> l = null;
		StringTokenizer st = null;
		
		for (int i = 0; i < T; i++) {
			R = sc.nextInt();
			k = sc.nextInt();
			N = sc.nextInt();
			
			l = new LinkedList<Integer>();
			for (int j = 0; j < N; j++) {
				l.add(sc.nextInt());
			}
			
			profit = 0;
			
			for (int j = 0; j < R; j++) {
				numPassengers = 0;
				groupsBoarded = 0;
				while (numPassengers < k && groupsBoarded < N) {
					if (numPassengers + l.peek() <= k) {
						peopleBoarded = l.removeFirst();
						numPassengers += peopleBoarded;
						l.addLast(peopleBoarded);
						groupsBoarded ++;
					}
					else {
						break;
					}
				}
				profit += numPassengers;
			}
			
			System.out.println("Case #" + (i+1) + ": " + profit);
			
		}
		
	
	}
	
}