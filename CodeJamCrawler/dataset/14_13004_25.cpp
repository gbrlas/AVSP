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
		String inFilename = "B-large.in";
		readFile(inFilename);
		numCases = new Integer(in[0][0]);
		out = new String[numCases];
		calculateResult();
		String outFilename = "B-large.out";
		writeOut(outFilename);
	}
	
	public void calculateResult() {
		int arp = 1;
		for(int c = 0; c < numCases; c++) {
			double C = new Double(in[arp][0]);
			double F = new Double(in[arp][1]);
			double X = new Double(in[arp][2]);
			
			out[c] = calcTime(C, F, X);
			arp++;
		}
	}
	
	public String calcTime(double C, double F, double X) {
		double roi = C/F;
		
		double prod = 2;
		double time = 0;
		
		while(true) {
			double ttc = C/prod;
			time += ttc;
			double ttx = (X-C)/prod;
			if(roi < ttx) {
				prod+=F;
			} else {
				time += ttx;
				return (new Double(time)).toString();
			}
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
