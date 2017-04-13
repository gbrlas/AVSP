import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.TreeSet;


public class A {
	static BufferedReader r;
	
	static int gao() throws Exception {
		String[] xx = r.readLine().split("\\s");
		int p = Integer.parseInt(xx[0]);
		int k = Integer.parseInt(xx[1]);
		int l = Integer.parseInt(xx[2]);
		xx = r.readLine().split("\\s");
		ArrayList<Integer> s = new ArrayList<Integer>();
		for (int i = 0; i < l; ++i) {
			int j = Integer.parseInt(xx[i]);
			s.add(-j);
		}
		Collections.sort(s);
		int ret = 0;
		int index = 0;
		for (Integer ii : s) {
			int i = -ii;
			ret += ((index / k) + 1) * i;
			index++;
		}
		
		return ret;
		
	}
	static String name = "A-small-attempt0";
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
