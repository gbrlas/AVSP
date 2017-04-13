import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class p1 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		P[]eo=new P[M];
		R[]v=new R[2*M];
		long ic = 0;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int e = Integer.parseInt(st.nextToken());
			int o = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			eo[i]=new P(e,o,p,N);
			v[2*i]=new R(e,p,true,i);
			v[2*i+1]=new R(o,p,false,i);
		}
		for(int i=0;i<M;i++) {
			ic += eo[i].c();
		}
		Arrays.sort(v);
		TreeSet<R>h=new TreeSet<R>();
		long minv = 0;
		for(int i=0;i<v.length;i++) {
			if(v[i].st) {
				h.add(v[i]);
			}
			else {
				int tex = v[i].p;
				while(tex > 0) {
					R lv = h.pollLast();
					int tt = Math.min(lv.p, tex);
					tex-=tt;
					lv.p-=tt;
					if(lv.p > 0) {
						h.add(lv);
					}
					minv += c(N,v[i].e,lv.e,tt);
				}
			}
		}
		
		return (ic-minv)+"";
	}

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine());
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
	private static final class R implements Comparable<R> {
		int e,p,i;
		boolean st;
		public R(int e, int p, boolean st, int i) {
			super();
			this.e = e;
			this.p = p;
			this.st = st;
			this.i = i;
		}
		@Override
		public int compareTo(R arg0) {
			if(e - arg0.e == 0) {
				if(st && !arg0.st) return -1;
				else if(!st && arg0.st) return 1;
				else return i - arg0.i;
			}
			return e - arg0.e;
		}
	}
	
	public static long c(int n, int o, int e, int p) {
		long l = o - e;
		long v = (2L*l*n - l*l + l)/2;
		return p*v;
	}
	
	private static final class P {
		int e,o,p;
		int n;

		public P(int e, int o, int p, int n) {
			super();
			this.e = e;
			this.o = o;
			this.p = p;
			this.n = n;
		}

		public long c() {
			long l = o - e;
			long v = (2L*l*n - l*l + l)/2;
			return p*v;
		}
	}
}