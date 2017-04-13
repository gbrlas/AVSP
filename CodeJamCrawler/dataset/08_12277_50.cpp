import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;


public class B {
	static BufferedReader r;
	
	static String gao() throws Exception {
		int n = Integer.parseInt(r.readLine());
		String ss = r.readLine();
		int na = Integer.parseInt(ss.split("\\s")[0]);
		int nb = Integer.parseInt(ss.split("\\s")[1]);
		List<Integer> la = new ArrayList<Integer>();
		List<Integer> lb = new ArrayList<Integer>();
		for (int i = 0; i < na; ++i) {
			ss = r.readLine();
			int x = Integer.parseInt(ss.substring(0, 2)) * 60 + Integer.parseInt(ss.substring(3, 5));
			int y = Integer.parseInt(ss.substring(6, 8)) * 60 + Integer.parseInt(ss.substring(9, 11));
			la.add(x * 10000 + y);
		}
		for (int i = 0; i < nb; ++i) {
			ss = r.readLine();
			int x = Integer.parseInt(ss.substring(0, 2)) * 60 + Integer.parseInt(ss.substring(3, 5));
			int y = Integer.parseInt(ss.substring(6, 8)) * 60 + Integer.parseInt(ss.substring(9, 11));
			lb.add(x * 10000 + y);
		}
		if (la.size() == 0) la.add(Integer.MAX_VALUE);
		if (lb.size() == 0) lb.add(Integer.MAX_VALUE);
		int ra = 0;
		int rb = 0;
		for (;;) {
			Collections.sort(la);
			Collections.sort(lb);
			if (la.get(0) == Integer.MAX_VALUE && lb.get(0) == Integer.MAX_VALUE) break;
			boolean fromA;
			int t;
			if (la.get(0) < lb.get(0)) {
				ra++;
				fromA = true;
				t = la.get(0);
				la.set(0, Integer.MAX_VALUE);
			} else {
				rb++;
				fromA = false;
				t = lb.get(0);
				lb.set(0, Integer.MAX_VALUE);
			}
			for (;;) {
				int ts = t / 10000;
				int te = t % 10000;
				List<Integer> l = fromA ? lb : la;
				fromA = !fromA;
				boolean ok = false;
				for (int i = 0; i < l.size(); ++i) if (l.get(i) != Integer.MAX_VALUE) {
					int tt = l.get(i);
					int tts = tt / 10000;
					int tte = tt % 10000;
					if (te + n <= tts) {
						t = tt;
						l.set(i, Integer.MAX_VALUE);
						ok = true;
						break;
					}
				}
				if (!ok) break;
			}
		}
		
		return ra + " " + rb;
		
	}
	static String name = "B-small-attempt0";
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
