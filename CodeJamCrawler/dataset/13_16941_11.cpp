package y2013.Round1A;
import static java.util.Arrays.deepToString;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
/**
 * 
 * @author PierreB
 * Notes:
 * 	The area of radius 1 cm is pi cm squared.
 * 	This means that pi r squared is still used.
 */
public class A {
	long t, r;
	double prevSize, paint, radius, prevRadius;
	void read(Scanner sc) {
		prevSize = 0;
		r = sc.nextLong();
		t = sc.nextLong();
		paint = t;
		radius = 1;
	}

	void solve() {
		int rings = 0;
		radius += r;
		while(paint > 0) {
			double size = (radius*radius) - ((radius-1)*(radius-1));
			double paintUsed = size;
			radius += 2;
			paint = paint -(paintUsed);
			if(paint < 0) break;
			rings++;				
		}
		System.out.println(rings);
	}

	void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("y2013/Round1A/a.in"));
		int caseN = sc.nextInt();
		sc.nextLine();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read(sc);
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args)  {
		try {
			new A().run();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.out.println(System.getProperty("user.dir"));
		}
	}
}
