import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class QR1 {
	private String[] in;
	private int numCases;
	private String[] out;
	
	public QR1() {
		String inFilename = "A-small-attempt0.in";
		readFile(inFilename);
		numCases = new Integer(in[0]);
		out = new String[numCases];
		calculateResult();
		String outFilename = "A-small-attempt0.out";
		writeOut(outFilename);
	}
	
	public void calculateResult() {
		for(int c = 1; c <= numCases; c++) {
			String ins = in[c];
			String os = new String();
			for(int pos = 0; pos < ins.length(); pos++) {
				char ch = ins.charAt(pos);
				switch(ch) {
				case 'a':
					os += 'y';
					break;
				case 'b':
					os += 'h';
					break;
				case 'c':
					os += 'e';
					break;
				case 'd':
					os += 's';
					break;
				case 'e':
					os += 'o';
					break;
				case 'f':
					os += 'c';
					break;
				case 'g':
					os += 'v';
					break;
				case 'h':
					os += 'x';
					break;
				case 'i':
					os += 'd';
					break;
				case 'j':
					os += 'u';
					break;
				case 'k':
					os += 'i';
					break;
				case 'l':
					os += 'g';
					break;
				case 'm':
					os += 'l';
					break;
				case 'n':
					os += 'b';
					break;
				case 'o':
					os += 'k';
					break;
				case 'p':
					os += 'r';
					break;
				case 'q':
					os += 'z';
					break;
				case 'r':
					os += 't';
					break;
				case 's':
					os += 'n';
					break;
				case 't':
					os += 'w';
					break;
				case 'u':
					os += 'j';
					break;
				case 'v':
					os += 'p';
					break;
				case 'w':
					os += 'f';
					break;
				case 'x':
					os += 'm';
					break;
				case 'y':
					os += 'a';
					break;
				case 'z':
					os += 'q';
					break;
				default:
					os += ch;
				}
			}
			out[c-1] = os;
		}
	}
	
	public void readFile(String filename) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			String cl;
			ArrayList<String> inal = new ArrayList<String>();
			while((cl = br.readLine()) != null) {
				inal.add(cl);
			}
			in = inal.toArray(new String[0]);
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
			System.out.print(in[i]);
			System.out.print(" ");
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
