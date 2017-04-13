import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	final static String filein = "input4.in";
	final static String fileout = "output12.txt";
	
	public void solve() throws Exception {
		Scanner s1 = new Scanner(new File("input11.in"));
		int tn = Integer.parseInt(s1.nextLine());
		for (int test = 1; test <= tn; test++) {
			int turnAround = Integer.parseInt(s1.nextLine());
			String[] times = s1.nextLine().split("\\s");
			int NA = Integer.parseInt(times[0]);
			int NB = Integer.parseInt(times[1]);
			ArrayList<Integer> startA = new ArrayList<Integer>(NA+NB);
			ArrayList<Integer> startB = new ArrayList<Integer>(NA+NB);
			ArrayList<Integer> finishA = new ArrayList<Integer>(NA+NB);
			ArrayList<Integer> finishB = new ArrayList<Integer>(NA+NB);
			ArrayList<Integer> findA = new ArrayList<Integer>(NA+NB);
			ArrayList<Integer> findB = new ArrayList<Integer>(NA+NB);
			
			for(int i = 0; i < NA; i++){
				String[] line = s1.nextLine().split("\\s");
				String[] start = line[0].split(":");
				String[] finish = line[1].split(":");
				startA.add(Integer.parseInt(start[0])*60+Integer.parseInt(start[1]));
				finishA.add(Integer.parseInt(finish[0])*60+Integer.parseInt(finish[1])+turnAround);
				findA.add(Integer.parseInt(start[0])*60+Integer.parseInt(start[1]));
			}
			for(int i = 0; i < NB; i++){
				String[] line = s1.nextLine().split("\\s");
				String[] start = line[0].split(":");
				String[] finish = line[1].split(":");
				startB.add(Integer.parseInt(start[0])*60+Integer.parseInt(start[1]));
				finishB.add(Integer.parseInt(finish[0])*60+Integer.parseInt(finish[1])+turnAround);
				findB.add(Integer.parseInt(start[0])*60+Integer.parseInt(start[1]));
			}
			
			Collections.sort(findA);
			Collections.sort(findB);
			
			int A = 0, B = 0;
			int AA = 0, BB = 0;
			for(int i = 0; i <= 24*60+59; i++){
				if(Collections.binarySearch(findA,i) >=0){
					while(Collections.binarySearch(findA,i) >= 0){
						int index = Collections.binarySearch(findA,i);
						A--;
						if(A < 0){
							for(int g = 0; g < finishB.size(); g++)
								if(finishB.get(g) <= i){
									A++;
									finishB.remove(g);
								}
							if(A < 0){
								A++;
								AA++;
							}	
						}
						findA.remove(index);
					}
					
					
			}
			if(Collections.binarySearch(findB,i) >=0){
					while(Collections.binarySearch(findB,i) >= 0){
						int index = Collections.binarySearch(findB,i);
						B--;
						if(B < 0){
							for(int g = 0; g < finishA.size(); g++)
								if(finishA.get(g) <= i){
									B++;
									finishA.remove(g);
								}
							if(B < 0){
								B++;
								BB++;
							}	
						}
						findB.remove(index);
					}
					
					
			}
		}
		out.write("Case #" + test + ": " + AA + " " + BB + "\n");
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
