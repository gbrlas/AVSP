import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.*;
import java.io.*;
public class C {

	/**
	 * @param args
	 */

	public static long incr(long[] B, int depth, long lastLarge, long[] D){
		if (depth==B.length) {
			if (lastLarge>=0){
				return 1;
			} else {
				return 0;
			}
		}
		//System.out.println(depth);
		if (B[depth] > lastLarge) {
			long result = 0;
			if (D[depth] >=0) {
				result = D[depth] + incr(B,depth+1,lastLarge,D);
			} else {
				D[depth] = incr(B,depth+1,B[depth],D)%1000000007l;
				result = D[depth] + incr(B,depth+1,lastLarge,D);
				
			}
			
			
			return result%1000000007l;
		}
		long result = incr(B,depth+1,lastLarge,D);

		return result%1000000007l;
		
		
		
		
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			BufferedReader br = new BufferedReader(new FileReader("c3.in"));

			PrintWriter pw = new PrintWriter(new FileWriter("c_output.txt"));
			String s;
			int num = Integer.parseInt(br.readLine());
			

			for (int i=0; i<num; i++) {
				s = br.readLine();
				StringTokenizer token = new StringTokenizer(s);
				int n = Integer.parseInt(token.nextToken());
				int m = Integer.parseInt(token.nextToken());
				long x = Integer.parseInt(token.nextToken());
				long y = Integer.parseInt(token.nextToken());
				long z = Integer.parseInt(token.nextToken());
				long A[] = new long[m];
				long B[] = new long[n];
				for (int j=0; j<m; j++) {
					A[j] = Integer.parseInt(br.readLine());
				
				}
				for (long j=0; j<n; j++) {
					B[(int)j] = A[(int)(j%m)];
					A[(int)(j%m)] = (x*A[(int)(j%m)]+y*(j+1))%z;
				}
				/*
				for (int j=0; j<n; j++) {
					System.out.println(B[j]);
				}
				*/
				long C[] = new long [n];
				for (int j=0; j<n; j++) {
					C[j] = B[j];
				}
				Arrays.sort(C);
				boolean same = true;
				for (int j=0; j<n; j++) {
					if (C[j]!=B[j]) {
						same = false;
						j=n;
					}
				}
				long result = 0;
				if (false && same) {
					result = (long)Math.pow(2,C.length)-1;
				} else {
					long D[] = new long[n];
					for (int j=0;j<n;j++) {
						D[j] = -1;
					}
					result = incr(B,0,-1,D);
				}
				System.out.println("Case #"+(i+1)+": "+result);
				pw.println("Case #"+(i+1)+": "+result);
			}
			pw.close();
		} catch (IOException e) {
			System.out.println("io error");
		}
	}

}
