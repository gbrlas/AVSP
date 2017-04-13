import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class QR1 {
	private String[][] in;
	private int numCases;
	private String[] out;
	
	public QR1() {
		String inFilename = "A-small-attempt0.in";
		readFile(inFilename);
		numCases = new Integer(in[0][0]);
		out = new String[numCases];
		calculateResult();
		String outFilename = "out.txt";
		writeOut(outFilename);
	}
	
	public void calculateResult() {
		for(int c = 1; c <= numCases; c++) {
			int op = 1;
			int bp = 1;
			int ns = 0;
			int arp = 1;
			
			while(arp < in[c].length) {
				boolean of = false;
				boolean bf = false;
				boolean o1st = false;
				int bg = -1;
				int og = -1;
				for(int i = arp; (i < in[c].length && !(of && bf)); i+=2) {
					String bot = in[c][i];
					
					if(!of && bot.equals("O")) {
						og = new Integer(in[c][i+1]);
						of = true;
						if(i == arp) {
							o1st = true;
						}
					}
					
					if(!bf && bot.equals("B")) {
						bg = new Integer(in[c][i+1]);
						bf = true;
						if(i == arp) {
							o1st = false;
						}
					}
				}
				
				if(o1st) {
					int sn = Math.abs(op-og)+1;
					ns += sn;
					op = og;
					if(bf) {
						int snb = Math.abs(bp-bg);
						if(snb <= sn) {
							bp = bg;
						} else if (bg < bp) {
							bp -= sn;
						} else {
							bp += sn;
						}
					}
				} else {
					int sn = Math.abs(bp-bg)+1;
					ns += sn;
					bp = bg;
					if(of) {
						int sno = Math.abs(op-og);
						if(sno <= sn) {
							op = og;
						} else if (og < op) {
							op -= sn;
						} else {
							op += sn;
						}
					}
				}
				
				arp+=2;
			}
			
			out[c-1] = new Integer(ns).toString();
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
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
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
		new QR1();
	}

}
