import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	final static String filein = "input4.in";
	final static String fileout = "output4.txt";
	
	public void solve() throws Exception {
		Scanner s1 = new Scanner(new File("input4.in"));
		int tn = Integer.parseInt(s1.nextLine());
		for (int test = 1; test <= tn; test++) {
			int searchEngines = Integer.parseInt(s1.nextLine());
			String[] names = new String[searchEngines];
			int[] occur = new int[searchEngines];
			
			for(int i = 0; i < searchEngines; i++)
				names[i] = s1.nextLine();
					
			
			HashSet s2 = new HashSet();
			int queries = Integer.parseInt(s1.nextLine());
			int switches = 0;
			for(int i = 0; i < queries; i++){
				String query = s1.nextLine();
				s2.add(query);
				if(s2.size() == searchEngines){
					switches++;
					s2.clear();
					s2.add(query);
				}
			}
			
			out.write("Case #" + test + ": " + switches);
			out.write("\n");
		}
	}
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}
	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c = in.read();
		while (c <= ' ' && c >= 0) {
			c = in.read();
		}
		if (c < 0) return "";
		while (c > ' ') {
			b.append((char)c);
			c = in.read();
		}
		return b.toString();
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(filein));
			out = new BufferedWriter(new FileWriter(fileout));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

}
