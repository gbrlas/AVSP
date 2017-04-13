import java.util.*;
import java.io.*;

public class A {
	void solve() {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			int X = sc.nextInt();
			int S = sc.nextInt();
			int R = sc.nextInt();
			R-=S;
			double t = sc.nextInt();
			int N = sc.nextInt();
			double[] distances = new double[200];
			distances[S] = X;
			for (int i=0;i<N;i++){
				int B = sc.nextInt();
				int E = sc.nextInt();
				int w = sc.nextInt();
				distances[w+S] += E-B;
				distances[S] -= E-B;
			}
			double time = 0;
			for (int i=1; i<200; i++){
				//System.out.print(i + " - "+distances[i]+"\n");
				if (distances[i] >0) {
					if (t>=distances[i]/(i+R)) {
						t -= distances[i]/(i+R);
						time += distances[i]/(i+R);
						
					} else if(t>0) {
						time += t;
						time += (distances[i]-t*(i+R))/i;
						t = 0;
						
					} else {
						
						time += distances[i]/i;
					}
					
				}
			}
			
			System.out.print(time + "\n");
		}
	}

	public static void main(String[] args) {
		new A().solve();
	}
}
