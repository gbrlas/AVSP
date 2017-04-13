import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class A {
	
	String inputSample = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
	+ " rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
	+ " de kr kd eoya kw aej tysr re ujdr lkgc jv aoz";
	
	String outputSample = "our language is impossible to understand"
	+ " there are twenty six factorial possibilities"
	+ " so it is okay if you want to just give up yeq";
	
	String line;
	
	public A(BufferedReader reader) throws IOException {
		line = reader.readLine();
	}
	
	public char getMapped(char inputChar) {
		if (inputChar == 'q') {
			return 'z';
		}
		if (inputChar == ' ') {
			return ' ';
		}
		int i = inputSample.indexOf(inputChar);
		return outputSample.charAt(i);
	}
	
	public String solve() {

		String output = "";
		for (int i=0; i<line.length(); i++) {
			char toMap = line.charAt(i);
			char mapped = getMapped(toMap);
			output += mapped;
		}
		return output;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile
				+ ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i = 1; i <= nrLines; i++) {
			A b = new A(reader);
			out.println("Case #" + i + ": " + b.solve());
		}
		reader.close();
		out.close();
	}
	
}
