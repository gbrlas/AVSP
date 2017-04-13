import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class B {
	int MAX = 11000;
	BigInteger[] factorials = new BigInteger[MAX];
	
	public void computeFactorials() {
		factorials[0] = new BigInteger("1");
		for (int i=1; i<MAX; i++) {
			factorials[i] = new BigInteger(""+i).multiply(factorials[i-1]);
		}
	}
	public void solve(Scanner sc, PrintWriter pw, int test) {
		System.out.println("Test " + test);
		pw.print("Case #" + test + ": ");
		int n = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int k;
		for (k=0; ;k++) {
			if ((k+1) * (2*k+1) > n) break;
		}
		k--;
		// levels 0...k are full.
		
		int rest = n - (k+1) * (2*k+1);
		int lev = (Math.abs(x)+Math.abs(y))/2;
		
//		System.out.println(k + " " + lev + " " + rest);
		if (lev <= k) {
			pw.println("1");
			return;
		}
		else if (lev > k+1) {
			pw.println("0");
			return;
		}
		// lev == k+1
		if (x == 0) {
//			System.out.println("test " + test + " " + lev + " " + k);
			pw.println("0");
			return;
		}
		int h = y + 1;
		if (rest >= 2*lev + h) {
//			System.out.println("!!!test " + test + " " + lev + " " + k);
			pw.println("1");
			return;
		}
		
		BigInteger sum = new BigInteger("0");
		for (int i=h; i<=rest; i++) {
			BigInteger comb = factorials[rest];
			comb = comb.divide(factorials[rest-i]);
			comb = comb.divide(factorials[i]);
			sum = sum.add(comb);
		}
		sum = sum.multiply(new BigInteger("10000000"));
		BigInteger pow2 = new BigInteger("2").pow(rest);
		sum = sum.divide(pow2);
		int p = Integer.parseInt(sum.toString());
		pw.println(((double)p) / 10000000);
	}
	
	public void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B.in"));
		PrintWriter pw = new PrintWriter("B.txt");
		computeFactorials();
		int numTests = sc.nextInt();
		
		for (int test = 1; test <= numTests; test++) {
			solve(sc, pw, test);
		}
		pw.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new B().run();
	}
}
