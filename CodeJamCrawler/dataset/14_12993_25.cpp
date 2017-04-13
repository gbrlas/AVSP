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
		String inFilename = "A-small-attempt1.in";
		readFile(inFilename);
		numCases = new Integer(in[0][0]);
		out = new String[numCases];
		calculateResult();
		String outFilename = "A-small-attempt1.out";
		writeOut(outFilename);
	}
	
	public void calculateResult() {
		int arp = 1;
		for(int c = 0; c < numCases; c++) {
			int row1 = new Integer(in[arp][0]);
			int[] n1 = new int[4];
			for(int i = 0; i < 4; i++) {
				n1[i] = new Integer(in[arp+row1][i]);
			}
			arp+=5;
			
			int row2 = new Integer(in[arp][0]);
			int[] n2 = new int[4];
			for(int i = 0; i < 4; i++) {
				n2[i] = new Integer(in[arp+row2][i]);
			}
			arp+=5;
			
			out[c] = checkRows(n1, n2);

		}
	}
	
	public String checkRows(int[] r1, int[] r2) {
		int sol = -1;
		for(int i = 0; i < 4; i++) {
			int n = r1[i];
			for(int j = 0; j < 4; j++) {
				int m = r2[j];
				if(n == m) {
					if(sol != -1) {
						return "Bad magician!";
					} else {
						sol = n;
					}
				}
			}
		}
		
		if(sol == -1) {
			return "Volunteer cheated!";
		} else {
			return (new Integer(sol)).toString();
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
		new QR1();
	}

}
