import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.io.BufferedWriter;
import java.io.IOException;

public class FairAndSquare {
	private static int low;
	private static int high;
	public static void main(String[] args) throws IOException {
		File in = new File("C-small-attempt0.in");
		Scanner s = new Scanner(in);
		int n = s.nextInt();
		s.nextLine();
		File out = new File("output.txt");
		FileWriter f = new FileWriter(out);
		BufferedWriter o = new BufferedWriter(f);
		for (int i = 0; i < n; i++) {
			String next = s.nextLine();
			System.out.println(next);
			String[] vals = next.split(" ");
			low = Integer.parseInt(vals[0]);
			high = Integer.parseInt(vals[1]);
			o.write("Case #" + (i + 1) + ": " + getSol());
			o.newLine();
		}
		
		o.close();
	}
	
	public static int getSol() {
		int counter = 0;
		int current = (int)Math.sqrt(low);
		int highest = (int)Math.sqrt(high);
		if (current * current < low) current++;
		while (true) {
			String sRep = "" + current;
			if (current > highest) break;
			boolean isPaly = true;
			
			for (int i = 0; i < sRep.length() / 2; i++) {
				if (sRep.charAt(i) != sRep.charAt(sRep.length() - 1 - i)) {
					isPaly = false;
					break;
				}
			}
			
			if (isPaly) {
				sRep = "" + (current * current);
				for (int i = 0; i < sRep.length() / 2; i++) {
					if (sRep.charAt(i) != sRep.charAt(sRep.length() - 1 - i)) {
						isPaly = false;
						break;
					}
				}
				
				if (isPaly) counter++;
			}
			
			current++;
		}
		
		return counter;
	}
}
