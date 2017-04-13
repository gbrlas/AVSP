import java.io.*;
import java.util.*;

public class sol_vv{

	int _ = 0;
	
	boolean[][] u = new boolean[15][26];
	int d; int l;
	String[] str;

	public int ok(String s){
		for(int i = 0;i<l;i++)
			Arrays.fill(u[i],false);
		int p = 0;
		for(int i = 0;i<l;i++){
			if (s.charAt(p)!='('){
				u[i][s.charAt(p++)-'a'] = true;
			} else {
				p++;
				while (s.charAt(p)!=')'){
					u[i][s.charAt(p++)-'a'] = true;
				}
				p++;
			}
		}
		int cc = 0;
		for(int i = 0;i<d;i++){
			boolean ok = true;
			for(int j = 0;j<l;j++){
				if (!u[j][str[i].charAt(j)-'a']){
					ok = false; break;
				}
			}
			if (ok) cc++;
		}
		return cc;
	}

	BufferedReader in;
	PrintWriter out;

	public void run() throws Exception{
		in = new BufferedReader(new FileReader("input.in"));
		out= new PrintWriter(new FileWriter("output.out"));
		String s = in.readLine();
		String[] u = s.split(" ");
		l = Integer.parseInt(u[0]);
		d = Integer.parseInt(u[1]);
		int n = Integer.parseInt(u[2]);
		str = new String[d];
		for(int i = 0;i<d;i++){
			str[i] = in.readLine();
		}
		for(int j = 0;j<n;j++){
			s = in.readLine();
			print(ok(s));
		}
	}

	public void print(int x){
		out.println("Case #"+(++_)+": "+x); 
	}


	public void close(){
		out.close();
	}
	public static void main(String[] args) throws Exception{
		sol_vv a = new sol_vv();
		a.run();
		a.close();
	}
}
