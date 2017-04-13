import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

public class A {
	static final String fin = "A.in";
	static final String fout = "A.out";
	Scanner sc;
	PrintWriter pw;

	void init() {
		try {
			sc = new Scanner(new File(fin));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File(
					fout))));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	void dispose() {
		pw.close();
	}

	long GCD(long a, long b) {
		if (b == 0) {
			return a;
		}
		if(a==0){
			return b;
		}
		long k;
		if (a > b) {
			k = a;
			while (b < k) {
				k -= b;
			}
			return GCD(b, a - b);
		} else {
			k = b;
			while (a < k) {
				k -= a;
			}
			return GCD(a, b - a);
		}
	}

	void run() {
		int n = sc.nextInt();
		for (int tcase = 1; tcase <= n; tcase++) {
			long N = sc.nextLong();
			long  Pd = sc.nextLong();
			long Pg = sc.nextLong();
			long PdD = 100/GCD(Pd,100);
			long PgD = 100/GCD(Pg,100);
			long PdE = Pd/GCD(Pd,100);
			long PgE = Pg/GCD(Pg,100);
			if(PdD > N){
				pw.println("Case #" + tcase + ": " + "Broken");
				System.out.println("Case #" + tcase + ": " + "Broken");
				continue;
			}
			if(Pg == 100 && Pd != 100){
				pw.println("Case #" + tcase + ": " + "Broken");
				System.out.println("Case #" + tcase + ": " + "Broken");
				continue;
			}
			if(Pg == 0 && Pd != 0){
				pw.println("Case #" + tcase + ": " + "Broken");
				System.out.println("Case #" + tcase + ": " + "Broken");
				continue;
			}
			pw.println("Case #" + tcase + ": " + "Possible");
			System.out.println("Case #" + tcase + ": " + "Possible");
			continue;
		}
	}

	public static void main(String args[]) {
		A t = new A();
		t.init();
		t.run();
		t.dispose();
	}
}