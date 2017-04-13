import java.io.FileReader;
import java.util.Scanner;

public class R2A {
	static Scanner s;
	static boolean[] op = new boolean[10000];
	static boolean[] change = new boolean[10000];
	static int[] value = new int[10000];
	
	static int[][] r = new int[10000][2];
	
	static int m;
	static int check(int ret, int r1, int r2, int k) {
		if (r1 == -1 || r2 == -1) {
			return ret;
		}
		int v = r1 + r2 + k;
		if (ret == -1) return v;
		return Math.min(ret, v);
	}
	static int suan(int n, int v) {
		if (n >= (m - 1 ) / 2) {
			return value[n] == v ? 0 : -1;
		}
		if (r[n][v] != -2) {
			return r[n][v]; 
		}
		int n1 = n * 2 + 1;
		int n2 = n * 2 + 2;
		
		int r11 = suan(n1, 1);
		int r10 = suan(n1, 0);
		int r21 = suan(n2, 1);
		int r20 = suan(n2, 0);
		int ret = -1;
		if (op[n] || change[n]) {
			if (v == 1) {
				ret = check(ret, r11, r21, op[n] ? 0 : 1);
			} else {
				ret = check(ret, r10, r20, op[n] ? 0 : 1);
				ret = check(ret, r10, r21, op[n] ? 0 : 1);
				ret = check(ret, r11, r20, op[n] ? 0 : 1);
			}
		}
		if (!op[n] || change[n]) {
			if (v == 0) {
				ret = check(ret, r10, r20, op[n] ? 1 : 0);
			} else {
				ret = check(ret, r11, r21, op[n] ? 1 : 0);
				ret = check(ret, r10, r21, op[n] ? 1 : 0);
				ret = check(ret, r11, r20, op[n] ? 1 : 0);
			}
		}
		return ret;
	}
	static String suan() throws Exception {
		for (int i = 0; i < 10000; ++i) {
			for (int j = 0; j < 2; ++j) {
				r[i][0] = -2;
				r[i][1] = -2;
			};
		}
		m = s.nextInt();
		int v = s.nextInt();
		for (int i = 0; i < (m - 1 ) / 2; ++i) {
			op[i] = 1 == s.nextInt();
			change[i] = 1 == s.nextInt();
		}
		for (int i = 0; i < (m + 1)/2; ++i) {
			value[(m - 1) / 2 + i] = s.nextInt();
		}
		return suan(0, v) < 0 ? "IMPOSSIBLE" : "" + suan(0, v);	
	}
	public static void main(String[] args) throws Exception {
		s = new Scanner(new FileReader("A-small-attempt0.in.txt"));
		int c = s.nextInt();
		for (int i = 1; i <= c; ++i) {
			System.out.println("Case #" + i + ": " + suan());
		}
	}
}
