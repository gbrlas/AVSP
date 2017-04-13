import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class QR3 {
	private String[][] in;
	private int numCases;
	private String[] out;
	
	public QR3() {
		String inFilename = "C-small-attempt0.in";
		readFile(inFilename);
		numCases = new Integer(in[0][0]);
		out = new String[numCases];
		calculateResult();
		String outFilename = "cs0.txt";
		writeOut(outFilename);
	}
	
	public void calculateResult() {
		int arp = 1;
		for(int t = 1; t <= numCases; t++) {
			int best = -1;
			int N = new Integer(in[arp][0]);
			arp++;
			int[] C = new int[N];
			for(int i = 0; i < N; i++) {
				C[i] = new Integer(in[arp][i]);
			}
			
			boolean[] choice = new boolean[N];
			while(true) {
				for(int j = N-1; j >= 0; j--) {
					if(choice[j]) {
						choice[j] = false;
					} else {
						choice[j] = true;
						break;
					}
				}
				
				boolean finished = true;
				for(int j = 0; j < choice.length; j++) {
					if(!choice[j]) {
						finished = false;
					}
				}
				if(finished) break;
				
				
				ArrayList<Integer> b1al = new ArrayList<Integer>();
				ArrayList<Integer> b2al = new ArrayList<Integer>();
				for(int j = 0; j < N; j++) {
					if(choice[j]) {
						b1al.add(new Integer(C[j]));
					} else {
						b2al.add(new Integer(C[j]));
					}
				}
				Integer[] b1 = b1al.toArray(new Integer[0]);
				Integer[] b2 = b2al.toArray(new Integer[0]);
				
				int b1pv = pv(b1);
				int b2pv = pv(b2);
				
				if(b1pv == b2pv) {
					int b1sv = sv(b1);
					int b2sv = sv(b2);
					
					if(b1sv > best) {
						best = b1sv;
					}
					
					if(b2sv > best) {
						best = b2sv;
					}
				}
			}
			
			arp++;
			if(best != -1) {
				out[t-1] = new Integer(best).toString();
			} else {
				out[t-1] = "NO";
			}
		}
	}
	
	public int sv(Integer[] ina) {
		int res = 0;
		for(int i = 0; i < ina.length; i++) {
			int ci = ina[i];
			res += ci;
		}
		return res;
	}
	
	public int pv(Integer[] ina) {
		int res = 0;
		for(int i = 0; i < ina.length; i++) {
			int ci = ina[i];
			res = res ^ ci;
		}
		return res;
	}
	
	public void readFile(String filename) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			String cl;
			ArrayList<String[]> inal = new ArrayList<String[]>();
			while((cl = br.readLine()) != null) {
				String[] cle = cl.split("\\s");
				inal.add(cle);
			}
			in = inal.toArray(new String[0][]);
			br.close();
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void writeOut(String filename) {
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
			for(int i = 0; i < out.length; i++) {
				int caseNum = i + 1;
				String caseTxt = "Case #" + caseNum + ": ";
				if(i > 0) {
					bw.newLine();
				}
				bw.write(caseTxt);
				bw.write(out[i]);
			}
			bw.close();
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void printInArray() {
		for(int i = 0; i < in.length; i++) {
			for(int j = 0; j < in[i].length; j++) {
				System.out.print(in[i][j]);
				System.out.print(" ");
			}
			System.out.print("\n");
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new QR3();
	}

}
