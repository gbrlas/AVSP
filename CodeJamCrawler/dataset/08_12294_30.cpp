import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.TreeSet;


public class B {
	static BufferedReader r;
	static long[] b;
	static long[] c;
	static long gao() throws Exception {
		String[] xx = r.readLine().split("\\s");
		int n = Integer.parseInt(xx[0]);
		int m = Integer.parseInt(xx[1]);
		long X = Integer.parseInt(xx[2]);
		long Y = Integer.parseInt(xx[3]);
		long Z = Integer.parseInt(xx[4]);
		long[] a = new long[m];
		for (int i = 0; i < m; ++i) {
			a[i] = Long.parseLong(r.readLine());
		}
		b = new long[n];
		c = new long[n];
		for (int i = 0; i < n; ++i) {
			b[i] = a[i % m];
			a[i % m] = (X * a[i % m] + Y * (i + 1)) % Z;
		}
		long ret = 0;
		for (int i = 0; i < n; ++i) {
			c[i] = 1;
			for (int j = 0; j < i; ++j) if (b[i] > b[j]){
				c[i] = (c[i] + c[j]) % 1000000007l;
			}
			ret = (ret + c[i]) % 1000000007l;
			
		}
		return ret;
	}
	static String name = "C-small-attempt0";
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
