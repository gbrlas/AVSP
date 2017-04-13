import java.util.ArrayList;
import java.util.Scanner;


public class Q2 {

static Scanner scn = new Scanner(System.in);

/**
 * @param args
 */
public static void main(String[] args) {
	
	int cases = scn.nextInt();
	for (int i = 1; i <= cases; i++) {
		
		int flavors = scn.nextInt();
		int customers = scn.nextInt();
		ArrayList<Customer> customersList = new ArrayList<Customer>(customers);
		
		int[] malted = new int[flavors];
		int[] unmalted = new int[flavors];
		boolean[] result = new boolean[flavors];
		for (int cust = 0; cust < customers; cust++) {
			int n = scn.nextInt();
			Customer c = new Customer();
			for (int x = 0; x < n; x++) {
				int a,b;
				a = scn.nextInt();
				b = scn.nextInt();
				
				c.add(a,b);
				if (b == 0) {
					unmalted[a-1]++;
				} else {
					malted[a-1]++;
				}
			}
			customersList.add(c);
		}
		try {
		while (!satisfies(result, customersList)) {
			inc(result, 0);
		}
		System.out.println("Case #" + i + ": " + printArray(result));
		}
		catch (Exception e) {
			System.out.println("Case #" + i + ": IMPOSSIBLE");
		}
		
		
		
	}
	

}

private static void inc(boolean[] result, int i) throws Exception {
	if (i >= result.length ) {
		throw new Exception("acabou");
	}
	if (!result[i]) {
		result[i] = true;
	} else {
		result[i] = false;
		inc(result, i+1);
	}
}

private static boolean satisfies(boolean[] result, ArrayList<Customer> customersList) {
	for(Customer c : customersList) {
		if (!c.satisfies(result)) {
			return false;
		}
	}
	return true;
}

private static String printArray(boolean[] result) {
	StringBuffer out = new StringBuffer();
	for (int i = 0; i < result.length; i++) {
		out.append(result[i] ? 1 : 0);
		out.append(" ");
	}
	return out.toString().trim();
}

}

class Shake {
	public Shake(int a, int b) {
		n = a;
		malted = (b == 1);
	}
	public Shake(int a, boolean b) {
		n = a;
		malted = b;
	}
	int n;
	boolean malted;
	
	public boolean equals(Object obj) {
		if (obj instanceof Shake) {
			Shake s = (Shake) obj;
			return s.n == n && s.malted == malted;
		}
		return false;
	}
}

class Customer {

	ArrayList<Shake> shakes;
	
	public Customer() {
		shakes = new ArrayList<Shake>();
	}
	
	public boolean satisfies(boolean[] result) {
		for (int i = 0; i < result.length; i++) {
				if (shakes.contains(new Shake(i+1, result[i]))) {
					return true;
				}
		}
		return false;
	}

	public void add(int a, int b) {

		shakes.add(new Shake(a, b));
		
	}
	
}