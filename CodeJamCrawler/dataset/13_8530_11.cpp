import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProbA {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		init();
		in = new Scanner(openFile());
		// in = new Scanner(System.in);
		// for (int i = 0; i < 100; i++) {
		// System.out.println(getRingQty(i);
		// }
		int no = in.nextInt();
		for (int q = 0; q < no; q++) {
			long r = in.nextLong();
			long qty = in.nextLong();
			int count = 0;
			while (qty > 0) {
				qty -= getRingQty(r);
				r += 2;
				if (qty >= 0)
					count++;
			}
			output(q + 1, count + " ");
		}
		out.close();
		in.close();
	}

	static long getRingQty(long inner) {
		return 1 + 2 * inner;
	}

	static Scanner in = null;

	static FileInputStream openFile() throws FileNotFoundException {
		File file = new File("A-small-attempt12.in");
		return new FileInputStream(file);
	}

	static void init() {
		try {
			out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
					new File("out.txt"))));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	static PrintWriter out = null;

	static void output(int caseNum, String output) {
		out.flush();
		System.out.println("Case #" + caseNum + ": " + output);
		out.println("Case #" + caseNum + ": " + output);
	}

}
