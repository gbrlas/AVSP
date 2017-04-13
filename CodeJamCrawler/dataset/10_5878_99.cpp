import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int tn = in.nextInt();
		for(int tt = 0;tt<tn;tt++){
			int n = in.nextInt();
			BigInteger[] a = new BigInteger[n];
			for(int i = 0;i<n;i++)
				a[i] = new BigInteger(in.next());
			Arrays.sort(a);
			BigInteger t = BigInteger.ZERO;
			for(int i = 0;i<n-1;i++)
				t = t.gcd(a[i+1].subtract(a[i]));
			BigInteger r = a[0].remainder(t);
			if (r.compareTo(BigInteger.ZERO)!=0){
				r = t.subtract(r);
			}
			out.println("Case #"+(tt+1)+": "+r);

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
