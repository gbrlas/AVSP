import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class D {
	
	static class Pair<A, B> {
		A a;
		B b;
		int steps = 0;
		public Pair(A a1, B b1) {
			a = a1;
			b = b1;
		}
		
		public String toString() {
			return "(" + a + ", " + b + ")";
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("D.in"));
		PrintWriter pw = new PrintWriter("D.out");
		int T = sc.nextInt();
		for (int test=1; test<=T; test++) {
			pw.print("Case #"+test+": ");
			
			
			int p = sc.nextInt();
			int w = sc.nextInt();
			
			boolean[] inq = new boolean[p];
			Vector<Integer>[] h = new Vector[p];
			for (int i=0; i<p; i++) {
				h[i] = new Vector<Integer>();
				h[i].add(i);
			}
			
			sc.nextLine();
			String l = sc.nextLine();
			StringTokenizer st = new StringTokenizer(l, ", ");
			for (int i=0; i<w; i++) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				
				h[x].add(y);
				h[y].add(x);
//				System.out.println(x + " " + y);
			}
			
			int[] mins = new int[p];
			for (int i=0; i<p; i++) {
				mins[i] = 100000;
			}
			ArrayList<Pair<Integer, HashSet<Integer>>> q = new ArrayList<Pair<Integer, HashSet<Integer>>>(); 
			q.add(new Pair<Integer, HashSet<Integer>>(0, new HashSet(h[0])));
			inq[0] = true;
			mins[0] = 0;
			
			int lgmin = 100000;
			int thrmax = -1;
			
			while (q.size() > 0) {
				Pair<Integer, HashSet<Integer>> pair = q.remove(0);
				
				int steps = pair.steps;
				for (Integer vecin: pair.b) {
					if (vecin == 1) {
						if (steps > lgmin) {
							continue;
						}
						else {
							if (steps < lgmin) {
								lgmin = steps;
								thrmax = pair.b.size();
							}
							else if (steps == lgmin) {
								if (thrmax < pair.b.size()) {
									thrmax = pair.b.size();
								}
							}
							
						}
					}
					else {
						//if (inq[vecin]) continue;
						if (mins[vecin] >= steps+1) {
							mins[vecin] = steps+1;
							
							HashSet<Integer> hs = new HashSet<Integer>(h[vecin]);
							hs.addAll(pair.b);
							Pair p2 = new Pair<Integer, HashSet<Integer>>(vecin, hs);
							p2.steps = steps+1;
							
							q.add(p2);
						}
					}
				}
			}
			
			pw.println(lgmin + " " + (thrmax - lgmin - 1));
		}
		pw.close();
	}
}
