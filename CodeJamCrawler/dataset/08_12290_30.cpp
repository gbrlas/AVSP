import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.TreeSet;


public class C {
	static BufferedReader r;
	static long[] b;
	static long[] c;
	static long get(String s, int k) throws Exception {
		return (long) (s.charAt(k) - '0');
	}
	static long suan(String s, int k) throws Exception {
		
		long r = 0;
		long x = get(s, 0);
		int n = s.length();
		int last = 1;
		for (int i = 1; i < n; ++i) {
			int y = k %3;
			k /= 3;
			if (y == 0) {
				x = x * 10 + get(s,i);
			} else if (y == 1) {
				r += last * x;
				x = get(s,i);
				last = 1;
			} else {
				r += last * x;
				x = get(s,i);
				last = -1;
			}
		}
		r += last * x;
		
		return r;
		
	}
	static long gao() throws Exception {
		String s = r.readLine();
		int n = s.length();
		int nn = 1;
		for (int i = 0; i < n-1; ++i) {
			nn*=3;
		}
		long ret = 0;
		for (int i = 0; i < nn; ++i) {
			
			long k = suan(s, i);
			//System.out.println(i + " " + k);
			
			if (k % 2 == 0 || k % 3 == 0 ||k % 5 == 0 ||k % 7 == 0) {
				ret ++;
			}
		}
		
		return ret;
	}
	static String name = "B-small-attempt1";
	static FileWriter w;
	public static void main(String[] args) throws Exception {
		r = new BufferedReader(new FileReader(name + ".in"));
		w = new FileWriter(name + ".out");
		
		int z = Integer.parseInt(r.readLine());
		for (int i = 0; i < z; ++i) {
			write("Case #" + (i + 1) + ": " + gao());
		}
		r.close();
		w.close();
		
	}
	static void write(Object o) throws Exception {
		String s = String.valueOf(o);
		System.out.println(s);
		w.write(s + "\n");
	}
}
