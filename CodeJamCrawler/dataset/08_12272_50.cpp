import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;


public class A {
	static BufferedReader r;
	
	static int gao() throws Exception {
		int n = Integer.parseInt(r.readLine());
		List<String> s = new ArrayList<String>();
		for (int i = 0; i < n; ++i) {
			s.add(r.readLine());
		}
		
		boolean[] u = new boolean[n];
		int m = Integer.parseInt(r.readLine());
		int c = 0;
		int ret = 0;
		for (int i = 0; i < m; ++i) {
			String ss = r.readLine();
			int k = s.indexOf(ss);
			if (!u[k]) {
				c++;
				u[k] = true;
			}
			if (c == n) {
				ret++;
				c = 1;
				for (int j = 0; j < n; ++j) u[j] = false;
				u[k] = true;
			}
		}
		
		return ret;
		
	}
	static String name = "A-large";
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
