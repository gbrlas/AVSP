import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Repeater {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner scanner = new Scanner(new File("A-small-attempt3.in"));
		PrintWriter writer = new PrintWriter("A-small.out");
		
		int cases = scanner.nextInt();
		int c = 1;
		
		while (cases --> 0) {
			int n = scanner.nextInt();
			String[] strings = new String[n];
			for (int i = 0; i < n; ++i)
				strings[i] = scanner.next();
			
			List<Character> chars = new ArrayList<Character>();
			
			
			char prev = 0;
			for (int j = 0; j < strings[0].length(); ++j) {
				if (strings[0].charAt(j) != prev) {
					chars.add(strings[0].charAt(j));
					prev = strings[0].charAt(j);
				}
			}
			
			int[][] counts = new int[n][chars.size()];
			
			boolean valid = true;
			for (int i = 0; valid && i < n; ++i) {
				int idx = 0;
				int count = 0;
				for (int j = 0; j < strings[i].length(); ++j) {
					if (idx >= chars.size() || strings[i].charAt(j) != chars.get(idx)) {
						if (count == 0) {
							valid = false;
							break;
						}
						counts[i][idx] = count;
						idx++;
						if (idx >= chars.size()) {
							valid = false;
							break;
						}
						if (strings[i].charAt(j) == chars.get(idx))
							count = 1;
						else {
							valid = false;
							break;
						}
					}
					else {
						count++;
					}
				}
				if (idx == chars.size() - 1)
					counts[i][idx] = count;
				else
					valid = false;
			}
			
			int total = 0;
			if (valid) {
//				for (int i = 0; i < n; ++i) {
//					for (int j = 0; j < chars.size(); ++j)
//						System.out.print(counts[i][j] + " ");
//					System.out.println();
//				}
				
				double avg;
				for (int j = 0; j < chars.size(); ++j) {
					int temp = 0;
					for (int i = 0; i < n; ++i)
						temp += counts[i][j];
					avg = temp * 1.0 / n;
					long num = Math.round(avg);
//					System.out.println(num);
					for (int i = 0; i < n; ++i)
						total += Math.abs(num - counts[i][j]);
				}
				
			}
			
			if (valid)
				writer.println("Case #" + c++ + ": " + total);
			else
				writer.println("Case #" + c++ + ": Fegla Won");
			
		}
		
		writer.close();
		
		
	}

}
