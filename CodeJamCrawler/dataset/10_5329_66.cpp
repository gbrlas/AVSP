import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * 
 * @author "Blake Arnold"
 * 
 */
public class ThemePark {

	private final static String filename = "C-small-attempt0.in";
	private final static String outFilename = "file0.out";

	public static void main(String[] args) throws IOException,
			InterruptedException {
		// System.out.println("gcd: "
		// +gcd(800000000000000000001f+99999999999999999999f,900000000000000000001f+99999999999999999999f));

		Scanner sc = new Scanner(new File(filename));
		BufferedWriter out = new BufferedWriter(new FileWriter(outFilename));
		long time = System.currentTimeMillis();
		int totalTests = new Integer(sc.nextLine());

		String results[] = new String[totalTests + 1];
		Thread last[] = new Thread[totalTests + 1];
		for (int i = 1; i < totalTests + 1; i++) {
			String line[] = sc.nextLine().split("\\s");
			int R = new Integer(line[0]);
			int k = new Integer(line[1]);
			int N = new Integer(line[2]);
			int groups[] = new int[N];
			line = sc.nextLine().split("\\s");
			for(int j =0; j< N; j++){
				groups[j] = new Integer(line[j]);
			}
			last[i] = new Thread(new findIt(R, k, groups, results, i));
			last[i].start();

		}
		for (int i = 1; i < totalTests + 1; i++) {
			System.out.println("reaped " + i);
			last[i].join();

		}
		for (int i = 1; i < totalTests + 1; i++) {

			out.write("Case #" + i + ": ");
			out.write(results[i]);
			out.write("\n");
		}
		System.out.println("Done. " + (System.currentTimeMillis() - time));
		out.close();

	}

	public static int gcd(int a, int b) {
		if (b == 0)
			return a;

		return gcd(b, a % b);
	}
}

class findIt implements Runnable {

	String[] results;
	int i;
	int R, k;
	int[] g;

	public findIt(int R, int k, int[] g, String[] results, int i) {
		this.R = R;
		this.k = k;
		this.g = g;
		this.results = results;
		this.i = i;
	}

	@Override
	public void run() {
		Group[] groups = new Group[g.length];

		
		/*
		 * initializes Group classes 
		 */
		for (int j = 0; j < g.length; j++) {
			int total = g[j];
			int next = j+1;
			
			if(next == g.length) //make circular
				next = 0;
			
			while ((total + g[next]) <= k && next != j){
				total += g[next];
				if(++next == g.length) //make circular
					next = 0;
			}
			System.out.println("Group: " + j + " total: " + total + " next "
					+ next);
			groups[j] = new Group(total, next);
		}
		
		
		/*
		 * Simulates rides
		 */
		int next = 0;
		int totalRides = 0;
		for(int j = 1; j<=R ; j++){
			totalRides += groups[next].getRiders();
			next = groups[next].getNext();
			System.out.println(i + "sym# " + j +" total: " + totalRides);
		}
		System.out.println(i + " total: " + totalRides);
		synchronized (results) {
			
			results[i] = totalRides+"";
			
		}

	}

}

class Group {
	private int riders;
	private int next;

	public Group(int riders, int next) {
		this.riders = riders;
		this.next = next;
	}

	public int getRiders() {
		return riders;
	}

	public void setRiders(int riders) {
		this.riders = riders;
	}

	public int getNext() {
		return next;
	}

	public void setNext(int next) {
		this.next = next;
	}

}
