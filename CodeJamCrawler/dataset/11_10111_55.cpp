import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class QR2 {
	private String[][] in;
	private int numCases;
	private String[] out;
	
	public QR2() {
		String inFilename = "B-small-attempt0.in";
		readFile(inFilename);
		numCases = new Integer(in[0][0]);
		out = new String[numCases];
		calculateResult();
		String outFilename = "bs0.txt";
		writeOut(outFilename);
	}
	
	public void calculateResult() {
		for(int c = 1; c <= numCases; c++) {
			int arp = 0;
						
			int C = new Integer(in[c][arp]);
			char[][] comb = new char[C][3];
			for(int i = 0; i < C; i++) {
				comb[i][0] = in[c][arp+i+1].charAt(0);
				comb[i][1] = in[c][arp+i+1].charAt(1);
				comb[i][2] = in[c][arp+i+1].charAt(2);
			}
			arp += (C+1);
			
			int D = new Integer(in[c][arp]);
			char[][] opp = new char[D][2];
			for(int i = 0; i < D; i++) {
				opp[i][0] = in[c][arp+i+1].charAt(0);
				opp[i][1] = in[c][arp+i+1].charAt(1);
			}
			arp += (D+1);
			
			ArrayList<Character> l = new ArrayList<Character>();
			int N = new Integer(in[c][arp]);
			String inv = in[c][arp+1];
			for(int i = 0; i < N; i++) {
				l.add(inv.charAt(i));
				boolean changed = true;
				while(changed) {
					changed = false;
					if(l.size() >= 2) {
						char c1 = l.get(l.size()-1);
						char c2 = l.get(l.size()-2);
						for(int j = 0; j < comb.length; j++) {
							char co1 = comb[j][0];
							char co2 = comb[j][1];
							if(((c1 == co1) && (c2 == co2)) || ((c1 == co2) && (c2 == co1))) {
								l.remove(l.size()-1);
								l.remove(l.size()-1);
								l.add(comb[j][2]);
								changed = true;
								break;
							}
						}
						
						if(!changed) {
							for(int j = 0; j < opp.length; j++) {
								char oc1 = opp[j][0];
								char oc2 = opp[j][1];
								boolean oc1f = false;
								boolean oc2f = false;
								
								for(int k = 0; k < l.size(); k++) {
									char lc = l.get(k);
									if(oc1 == lc) {
										oc1f = true;
									}
									
									if(oc2 == lc) {
										oc2f = true;
									}
								}
								
								if(oc1f && oc2f) {
									l.clear();
								}
							}
						}
					}
				}
			}
			
			String o = "[";
			for(int i = 0; i < l.size(); i++) {
				if(i > 0) {
					o += ", ";
				}
				
				o += l.get(i);
			}
			o += "]";
			out[c-1] = o;
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
		new QR2();
	}

}
