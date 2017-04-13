import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	final static String filein = "input2.in";
	final static String fileout = "output1.txt";
	
	
	
	public void solve() throws Exception {
		
		Scanner s1 = new Scanner(new File("input2.in"));
		int tn = iread();
		for (int test = 1; test <= tn; test++) {
		int num = iread();
		ArrayList<Integer> posX = new ArrayList<Integer>();
		ArrayList<Integer> negX = new ArrayList<Integer>();
		ArrayList<Integer> posY = new ArrayList<Integer>();	
		ArrayList<Integer> negY = new ArrayList<Integer>();
		for(int i = 0; i < num; i++){
			int g = iread();
			if(g < 0)
				negX.add(g);
			else
				posX.add(g);	
		}
		for(int i = 0; i < num; i++){
			int g = iread();
			if(g < 0)
				negY.add(g);
			else
				posY.add(g);
		}
		Collections.sort(posX);
		Collections.sort(posY);
		Collections.sort(negX);
		Collections.sort(negY);			
		int ret = 0;
		
		for(int i = 0; i < negX.size(); i++){
			if(posY.size()>0){
			ret += negX.get(i)*posY.get(posY.size()-1);
			posY.remove(posY.size()-1);
			}
			else{
				ret += negX.get(i)*negY.get(negY.size()-1);
				negY.remove(negY.size()-1);	
				
			}		
				
		}
		for(int i = posX.size()-1; i >= 0; i--){
			if(negY.size()>0){
			ret += posX.get(i)*negY.get(0);
			negY.remove(0);
			}
			else{
				ret += posX.get(i)*posY.get(0);
				posY.remove(0);	
				
			}		
				
		}
			
			
			
		out.write("Case #" + test + ": " + ret + "\n");
		
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
