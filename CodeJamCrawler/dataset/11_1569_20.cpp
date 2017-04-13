import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class A {
	
	public char[][] input = null;
	
	// wining procesntage except team from column
	public double POINTS[] = null;
	public double PLAYED[] = null;
	public double OWP[] = null;
	public double OOWP[] = null;
	
	int n = 0;
	
	public A(BufferedReader reader) throws NumberFormatException, IOException {
		n = Integer.parseInt(reader.readLine());
		input = new char[n][n];
		for(int i = 0; i<n; i++) {
			String line = reader.readLine();
			for(int j = 0; j<n; j++) {
				input[i][j] = line.charAt(j);
			}
		}

	}
	
	public String print(double[] a) {
		String result = "";
		for (int i = 0; i<n; i++) {
			result += a[i] +  " ";
		}
		return result;
	}
	
	public double[] solve() {
		double[] result = new double[n];
		POINTS = new double[n];
		PLAYED = new double[n];
		OWP = new double[n];
		OOWP = new double[n];
		for (int i = 0; i< n; i++) {
			POINTS[i] = 0;
			PLAYED[i] = 0;
			for (int j=0; j<n;j++) {
				if (input[i][j] == '.') {
					continue;
				}
				POINTS[i] += Integer.parseInt("" + input[i][j]);
				PLAYED[i] += 1;
			}
		}
		
		System.out.println("PLAYED " + print(PLAYED));
		System.out.println("POINTS " + print(POINTS));
		
		for (int i = 0; i< n; i++) {
			double SUM = 0;
			double z = 0;
			for (int j=0; j<n; j++) {
				if (input[i][j] == '.') {
					continue;
				}
				SUM += (POINTS[j] - Integer.parseInt(""+input[j][i]))/ (double)(PLAYED[j]-1);
				z = z +1;
			}
			OWP[i] = SUM/z;
		}
		System.out.println("OWP " + print(OWP));
		
		for (int i = 0; i<n; i++) {
			OOWP[i] = 0;
			double SUM = 0;
			double z = 0;
			for (int j=0; j<n; j++) {
				if (input[i][j] == '.') {
					continue;
				}
				SUM += OWP[j];
				z = z + 1;
			}
			OOWP[i] = SUM/z;
		}
		
		for (int i = 0; i<n; i++) {
			result[i] = 0.25 * (POINTS[i]/PLAYED[i]) + 0.5 * OWP[i] + 0.25 * OOWP[i];
		}
		return result;
		
	}
	
	
	
	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile + ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i=1;i<=nrLines; i++ ) {
			A a = new A(reader);
			double[] result = a.solve();
			out.println("Case #" + i + ":");
			for (int j = 0; j<a.n; j++) {
				out.println(result[j]);
			}
//			String ok = possible(line)?"Possible":"Broken";
//			out.println("Case #" + i + ": " + ok);
		}
		reader.close();
		out.close();

	}

}
