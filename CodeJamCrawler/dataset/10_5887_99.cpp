import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int tn = in.nextInt();
		for(int tt = 0; tt<tn;tt++){
			int r = in.nextInt();
			int k = in.nextInt();
			int n = in.nextInt();
			int[] a = new int[2*n];
			for(int i = 0;i<n;i++){
				a[i] = in.nextInt();
				a[i+n] = a[i];
			}
			int[] next = new int[n];
			int[] cost = new int[n];
			for(int i = 0;i<n;i++){
				int j;
				int s = 0;

				for(j = i;j<i+n;j++){
					if (a[j]+s>k) break;
					s+=a[j];
				}
				if (j>=n) j-=n;
				next[i] = j;
				cost[i] = s;
			}
			int first = 0;
			long sum = 0;
			for(int i=0;i<r;i++){
				sum+=cost[first];
				first = next[first];
			}
			out.println("Case #"+(tt+1)+": "+sum);
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
