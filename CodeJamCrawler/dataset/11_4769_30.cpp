import java.util.Scanner;

public class A {
	static class R {
		int p = 1;
		int t = 0;
	}

	public static void main(String[] args) {
//		String f = "A-small-attempt1";
//		System.setIn(A.class.getResourceAsStream(f+".in"));
//		System.setOut(new PrintStream(new File(f+".out")));
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=1; i<=T; i++) {
			R o = new R(),b = new R(); int s = 0;
			int N = in.nextInt();
			for(int j = 1; j<=N; j++) {
				String c = in.next("[O|B]");
				int p = in.nextInt();
				int d;
				if( c.equals("O")) {
					d=Math.abs(p-o.p)>b.t?Math.abs(p-o.p)+1-b.t:1;
					o.t+=d; s+=d;
					o.p=p; b.t=0;
				} else {
					d=Math.abs(p-b.p)>o.t?Math.abs(p-b.p)+1-o.t:1;
					b.t+=d; s+=d;
					b.p=p; o.t=0; 
				}
			}
			System.out.println("Case #"+i+": "+s);
		}
	}
}


