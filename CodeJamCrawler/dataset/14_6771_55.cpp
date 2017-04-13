import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class War {

	public static void main(String[] args)  throws FileNotFoundException {
		
		Scanner scanner = new Scanner(new File("D-large.in"));
		PrintWriter writer = new PrintWriter("War_large.out");
		
		int cases = scanner.nextInt();
		int count = 1;
		
		while (cases --> 0) {
			int num = scanner.nextInt();
			double[] n = new double[num];
			double[] k = new double[num];
			
			for (int i = 0; i < num; ++i)
				n[i] = scanner.nextDouble();
			
			for (int i = 0; i < num; ++i)
				k[i] = scanner.nextDouble();
			
			Arrays.sort(n);
			Arrays.sort(k);
			
			double[] k_war = k.clone();
			
			int warPoints = 0;
			
			// Simulate war
			for (int i = num-1; i >= 0; --i) {
				boolean found = false;
				for (int j = 0; j < num; ++j) {
					if (k_war[j] > n[i]) {
						k_war[j] = Double.MIN_VALUE;
						found = true;
						break;
					}
				}
				if (!found) {
					for (int j = 0; j < num; ++j) {
						if (k_war[j] != Double.MIN_VALUE) {
							k_war[j] = Double.MIN_VALUE;
							break;
						}
					}
					warPoints++;
				}
				
			}
			
			int maxWins = 0;
			
			// Simulate deceitful war
			for (int i = 0; i < num; ++i) {
				int wins = 0;
				for (int j = i; j < num; ++j) {
					if (n[j] > k[j-i]) {
						wins++;
					}
				}
				if (wins > maxWins)
					maxWins = wins;
			}
			
			writer.println("Case #" + count++ + ": " + maxWins + " " + warPoints);
			
		}
		
		writer.close();
	}
}
