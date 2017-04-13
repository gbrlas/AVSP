import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class C {

	public static String splitCandies(int nrCandies, String strCandies) {
		int result = 0; //xor sum result. if this is 0 then the values can be split.
		int minim = Integer.MAX_VALUE;  // the minimum of the values
		int sum = 0;
		StringTokenizer strTokenizer = new StringTokenizer(strCandies, " ");
		for(int i=0; i<nrCandies; i++) {
			String strCandy = strTokenizer.nextToken();
			int candy = Integer.parseInt(strCandy);
			result ^= candy;
			sum += candy;
			if (minim > candy) {
				minim = candy;
			}
		}
		if (result == 0) {
			if (sum == 0) {
				return "0";
			}
			return Integer.toString(sum - minim);
		} else {
			return "NO";
		}
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile + ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i=1;i<=nrLines; i++ ) {
			String nrCandies = reader.readLine();
			String candies = reader.readLine();
			String result = splitCandies(Integer.parseInt(nrCandies), candies);
			out.println("Case #" + i + ": " + result);
		}
		reader.close();
		out.close();
	}

}
