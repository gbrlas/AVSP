import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


class Bullseye {

	static void paint(long radius, long total, int time) {
		long x = radius;
		long counter = 0;
		while (true) {
			long toPaint = 2 * x + 1;
			if (total >= toPaint) {
				total -= toPaint;
				counter++;
				x += 2;
				//System.out.println(toPaint);
			} else {
				System.out.println("Case #" + time + ": " + counter);
				return;
			}
		}
	}
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("A-small-attempt0.in"));
		int n = scanner.nextInt();
		for (int i = 0; i < n; i++) {
			long r = scanner.nextLong();
			long t = scanner.nextLong();
			paint(r, t, i + 1);
		}
		scanner.close();
	}

}
