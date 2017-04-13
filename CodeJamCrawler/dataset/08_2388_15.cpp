import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Q1 {

	static Scanner scn = new Scanner(System.in);
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ArrayList<Integer> v1 = new ArrayList<Integer>();
		ArrayList<Integer> v2 = new ArrayList<Integer>();
		
		int cases = scn.nextInt();
		
		for (int i = 1; i <= cases; i++) {
			v1.clear();
			v2.clear();
			int size = scn.nextInt();
			for (int j = 0; j < size; j++) {
				v1.add(scn.nextInt());
			}
			for (int j = 0; j < size; j++) {
				v2.add(scn.nextInt());
			}
			
			Collections.sort(v1, new MyComparator());
			Collections.sort(v2, new MyComparator2());
//			System.out.println(v1);
//			System.out.println(v2);
			int res = product(v1, v2);
			System.out.println("Case #" + i + ": " + res);
		}

	}

	private static int product(ArrayList<Integer> v1, ArrayList<Integer> v2) {
		int sum = 0;
		for (int i = 0; i < v1.size(); i++) {
			sum += v1.get(i) * v2.get(i);
		}
		return sum;
	}


	
}

class MyComparator implements Comparator<Integer> {

	@Override
	public int compare(Integer o1, Integer o2) {

		
		if (o1 < 0 && o2 < 0) {
			return o1 - o2;
		}
		if (o1 < 0 ) {
			return -1;
		}
		if (o2 < 0) {
			return 1;
		}
		
		return o1 - o2;
	}

	
}

class MyComparator2 implements Comparator<Integer> {

	@Override
	public int compare(Integer o1, Integer o2) {

		
		if (o1 < 0 && o2 < 0) {
			return o2 - o1;
		}
		if (o1 < 0 ) {
			return 1;
		}
		if (o2 < 0) {
			return -1;
		}
		
		return o2 - o1;
	}

	
}
