import java.util.*;
import java.io.*;

public class Main{
	
	public void run() throws Exception{
		BufferedReader in = new BufferedReader(new FileReader(new File("input.txt")));
		PrintWriter out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = Integer.parseInt(in.readLine());
		for(int __=0;__<_;__++){
			int n = Integer.parseInt(in.readLine());
			HashMap<String,Integer> h = new HashMap<String,Integer>();
			for(int i = 0;i<n;i++){
				h.put(in.readLine(),i);
			}
			int m = Integer.parseInt(in.readLine());
			int[] u = new int[m];
			for(int i = 0;i<m;i++){
				String s = in.readLine();
				if (h.containsKey(s)){
					u[i] = h.get(s);
				} else u[i] = -1;
			}
			int[][] res = new int[m+1][n];
			for(int i = 0;i<m;i++){
				int min = 1000000000;
				for(int j = 0;j<n;j++)
					if (min>res[i][j]) min = res[i][j];
				for(int j = 0;j<n;j++){
					if (u[i]==j) res[i+1][j] = 1000000000;
					else res[i+1][j] = Math.min(res[i][j],min+1);
				}
			}
			int min = 1000000000;
			for(int j = 0;j<n;j++)
				if (min>res[m][j]) min = res[m][j];
			out.println("Case #"+(__+1)+": "+min);
		}
		out.close();
	}
	public static void main(String[] args) throws Exception{
		new Main().run();
	}
}