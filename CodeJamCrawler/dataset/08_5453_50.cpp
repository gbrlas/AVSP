import java.util.*;
import java.io.*;

public class Main2{
	
	int gett(String s){
		String[] ss = s.split(":");
		int t = 60*Integer.parseInt(ss[0])+Integer.parseInt(ss[1]);
		//System.out.println(t);
		return t;
	}
	
	public void run() throws Exception{
		BufferedReader in = new BufferedReader(new FileReader(new File("input.txt")));
		PrintWriter out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = Integer.parseInt(in.readLine());
		for(int __=0;__<_;__++){
			int u = Integer.parseInt(in.readLine());
			String[] ss = in.readLine().split(" ");
			int n = Integer.parseInt(ss[0]);
			int m = Integer.parseInt(ss[1]);
			int[] x1 = new int[n];
			int[] y1 = new int[n];
			int[] x2 = new int[m];
			int[] y2 = new int[m];
			for(int i = 0;i<n;i++){
				String s = in.readLine();
				ss = s.split(" ");
				x1[i] = gett(ss[0]);
				y1[i] = gett(ss[1])+u;
			}
			for(int i = 0;i<m;i++){
				String s = in.readLine();
				ss = s.split(" ");
				x2[i] = gett(ss[0]);
				y2[i] = gett(ss[1])+u;
			}
			Arrays.sort(x1); Arrays.sort(x2);
			Arrays.sort(y1); Arrays.sort(y2);
			int c1 = n;
			int p = 0;
			for(int i = 0; i<n;i++)
				if (p<m && y2[p]<=x1[i]){
					c1--; p++;
				} 
			int c2 = m;
			p = 0;
			for(int i = 0; i<m;i++)
				if (p<n && y1[p]<=x2[i]){
					c2--; p++;
				} 
			out.println("Case #"+(__+1)+": "+c1+" "+c2);
		}
		out.close();
	}
	public static void main(String[] args) throws Exception{
		new Main2().run();
	}
}