import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	int n;
	long[] a;

	public int inv(long a, int p){
		long r = 1;
		long rr = a;
		int d = p-2;
		while (d>0){
			if ((d & 1)!=0) r = (r*rr)%p;
			rr = (rr*rr) %p;
			d = d/2;;
		}
		return (int) r;
	}


	public int check(int p){
		if (n==1) return -1;
		if (a[0]==a[1]) return (int)a[0];
		if (n==2) {
			return -1;
		}
		long dx = (a[1]-a[0]);
		long dy = (a[2]-a[1]);
		if (dx<0) dx+=p;
		if (dy<0) dy+=p;
		long idx = inv(dx,p);
		if ((idx*(long)dx)%p!=1) throw new RuntimeException("Bred");
		long A = ((dy*(long)idx) % p);
		long B = ((a[1]-A*(long)a[0]) % p);
		if (B<0) B+=p;
		for(int i = 1;i<n;i++){
			if ((A*(long)a[i-1]+B)%p!=a[i]) return -1;
		}
		return (int)((A*(long)a[n-1]+B)%p);
	}

	public void solve(){
		int d = in.nextInt();
		n = in.nextInt();
		a = new long[n];
		long max = 0;
		for(int i = 0;i<n;i++){
			a[i] = in.nextInt();
			max = Math.max(a[i],max);
		}
		int dd = 1;
		for(int i = 0;i<d;i++)
			dd*=10;
		boolean[] pp = new boolean[dd];
		int res = -1;
		int cc = 0;
		for(int i=2;i<dd;i++){
			if (!pp[i]){
				//System.out.println(i);
				int j = 2*i;
				while (j<dd){
					pp[j] = true;
					j+=i;
				}
				if (i>max){
					int t = check(i);
					if (t==-1) continue;
					if (cc==0) {
						res = t;
						cc=1;
					} else if (t!=res){
						cc = 2;
						break;
					}
				}
			}
		}
		if (cc!=1) out.println("I don't know.");
		else out.println(res);
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			solve();
		}
	}

	public void close() throws Exception{
		out.close();
	}

	public static void main(String[]  args){
		new Thread(){
			public void run(){
				try{
					Main a = new Main();
					a.run();
					a.close();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
