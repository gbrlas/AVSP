import java.io.*;
import java.util.*;

public class sol_vv{


	BufferedReader in;
	PrintWriter out;

	int[][] res;
	int M = 10000;

	public void run() throws Exception{
		in = new BufferedReader(new FileReader("input.in"));
		out= new PrintWriter(new FileWriter("output.out"));
		int _ = Integer.parseInt(in.readLine());
		String ss = "welcome to code jam";
		res = new int[1000][ss.length()+1];
		for(int __=0;__<_;__++){
			String s = in.readLine();
			for(int i = 0;i<=s.length();i++)
				Arrays.fill(res[i],0);
			res[0][0] = 1;
			for(int i = 0;i<s.length();i++)
				for(int j=0;j<=ss.length();j++){
					if (j<ss.length() && s.charAt(i)==ss.charAt(j)){
						res[i+1][j+1]+=res[i][j];
						if (res[i+1][j+1]>=M) res[i+1][j+1]-=M;
					} 
					res[i+1][j]+=res[i][j];
					if (res[i+1][j]>=M) res[i+1][j]-=M;
				}
			String r = ""+res[s.length()][ss.length()];
			while (r.length()<4) r = '0'+r;
			out.println("Case #"+(__+1)+": "+r);
		}
	}


	public void close(){
		out.close();
	}
	public static void main(String[] args) throws Exception{
		new Thread() {
			public void run(){
				try{
					sol_vv a = new sol_vv();
					a.run();
					a.close();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
