import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Lottery {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("B-small-attempt0.in"));
		PrintWriter writer = new PrintWriter("B-small.out");
		
		int cases = scanner.nextInt();
		int c = 1;
		
		while (cases --> 0) {
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			int k = scanner.nextInt();
			
			int total = 0;
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; ++j)
					if ((i & j) < k)
						total++;
			
			writer.println("Case #" + c++ + ": " + total);
		}
		writer.close();
	}
}
