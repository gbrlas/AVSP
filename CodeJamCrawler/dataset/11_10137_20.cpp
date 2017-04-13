import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class R1B1 {
	private String[][] in;
	private int numCases;
	private String[] out;
	
	public R1B1() {
		String inFilename = "A-large.in";
		readFile(inFilename);
		numCases = new Integer(in[0][0]);
		out = new String[numCases];
		calculateResult();
		//String outFilename = "out.txt";
		//writeOut(outFilename);
	}
	
	public void calculateResult() {
		try{
		String filename = "A-large.out";
		BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
		
		int arp = 1;
		for(int c = 0; c < numCases; c++) {
			String caseTxt = "Case #" + (c+1) + ": ";
			if(c > 0) {
				bw.newLine();
			}
			bw.write(caseTxt);
			
			int N = new Integer(in[arp][0]);
			arp++;
			int[][] t = new int[N][N];
			for(int n = 0; n < N; n++) {
				String row = in[arp][0];
				for(int i = 0; i < N; i++) {
					char ch = row.charAt(i);
					if(ch == '.') {
						t[n][i] = -1;
					} else if (ch == '0') {
						t[n][i] = 0;
					} else if (ch == '1'){
						t[n][i] = 1;
					}
				}
				arp++;
			}
			
			double[] wp = new double[N];
			int[] twon = new int[N];
			int[] tplayed = new int[N];
			for(int n = 0; n < N; n++) {
				int won = 0;
				int played = 0;
				for(int i = 0; i < N; i++) {
					if(t[n][i] == 1) {
						won++;
						played++;
					} else if (t[n][i] == 0) {
						played++;
					}
				}
				
				wp[n] = ((double)won)/((double)played);
				twon[n] = won;
				tplayed[n] = played;
			}
			
			double[] owp = new double[N];
			for(int n = 0; n < N; n++) {
				double wposum = 0;
				int numo = 0;
				for(int o = 0; o < N; o++) {
					if(n!=o) {
						if(t[o][n] != -1) {
							int won, played;
							if(t[o][n] == 0) {
								won = twon[o];
								played = tplayed[o]-1;
							} else {
								won = twon[o]-1;
								played = tplayed[o]-1;
							}
							double wpo = ((double)won)/((double)played);
							wposum += wpo;
							numo++;
						} else {
							//wposum += wp[o];
						}
					}
				}
				owp[n] = wposum / ((double)(numo));
			}
			
			double[] oowp = new double[N];
			for(int n = 0; n < N; n++) {
				double owpsum = 0;
				int numo = 0;
				for(int o = 0; o < N; o++) {
					if(t[o][n]!=-1) {
						owpsum += owp[o];
						numo++;
					}
				}
				
				oowp[n] = owpsum / ((double)(numo));
			}
			
			double[] rpi = new double[N];
			for(int n = 0; n < N; n++) {
				rpi[n] = (0.25*wp[n])+(0.5*owp[n])+(0.25*oowp[n]);
				bw.newLine();
				bw.write(new Double(rpi[n]).toString());
			}
		}
		bw.close();
	} catch(IOException e) {
		System.err.println(e);
	}
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
		new R1B1();
	}

}
