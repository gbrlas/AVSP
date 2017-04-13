import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	int M = 10007;
	
	public class Pair implements Comparable<Pair>{
		int x; int y;
		
		Pair(int _x, int _y){
			x = _x; y = _y;
		}
		
		public int compareTo(Pair p){
			if (x!=p.x) return x-p.x;
			return y-p.y;
		}
	}
	
	int[] e;
	int[] inv;
		
	public int c(int n, int k){
		if (n<M) return ((e[n]*inv[e[k]])%M)*inv[e[n-k]]%M;
		int t = n/M-k/M-(n-k)/M;
		if (t>0) return 0;
		int res = (((((c(n/M,k/M)*e[n % M])%M)*inv[e[k%M]])%M) * inv[e[(n-k)%M]])%M;
		return res; 
	}
	
	public int sol(int w, int h){
		if (w<0) return 0;
		if (h<0) return 0;
		int x; int y;
		if (2*w<h) return 0;
		if ((2*w-h)%3!=0) return 0;
		if (2*h<w) return 0;
		if ((2*h-w)%3!=0) return 0;
		x = (2*w-h)/3;
		y = (2*h-w)/3;
		return c(x+y,x);
	}
	
	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		e = new int[M];
		e[0] = 1;
		e[1] = 1;
		for(int i =2;i<M;i++) e[i] = (e[i-1]*i)%M;
		inv  = new int[M];
		inv[0] = 0;
		for(int i = 1;i<M;i++){ 
			for(int j = 0;j<M;j++) if ((i*j)%M==1){
				inv[i] = j; break;
			}
			if (inv[i]==0) System.out.println("AHTUNG");
		}
		int _ = in.nextInt();
		for(int __ = 0;__<_;__++){
			int w = in.nextInt();
			int h = in.nextInt();
			int r = in.nextInt();
			Pair[] p = new Pair[r+2];
			p[0] = new Pair(1,1);
			p[1] = new Pair(w,h);
			
			for(int i = 0;i<r;i++){
				p[i+2] = new Pair(in.nextInt(),in.nextInt());
				if ((p[i+2].x>w) || (p[i+2].y>h)) System.out.println("AH");
			}
			Arrays.sort(p);
			int res = 0;
			for(int ii = 0;ii<(1<<(r+2));ii++){
				if (((ii&1)==0) || (ii & (1<<(r+1)))==0) continue;
				int z = 0;
				for(int i =0;i<(r+2);i++) if ((ii&(1<<i))!=0) z++;
				int d = 1;
				int last = 0;
				for(int i = 1;i<(r+2);i++) if ((ii&(1<<i))!=0){
					d = d * sol(p[i].x-p[last].x,p[i].y-p[last].y) % M;
					last = i;
				}
				if (z % 2==0){
					res +=d;
				} else res-=d;
				if (res<M) res+=M;
				if (res>=M) res-=M;
			}
			out.println("Case #"+(__+1)+": "+res);
		}
		out.close();
	}

	public static void main(String[] args) throws Exception{
		new Main().run();
	}	
}