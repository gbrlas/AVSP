import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class PartEif {

	private static String inputDir = "C:\\CodeJam2014\\Input\\";
	private static String outputDir = "C:\\CodeJam2014\\Output\\";

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(inputDir + "A-small-attempt0.in")));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputDir + "PartEifOutput.txt")));
		int testCases = Integer.parseInt(in.readLine().trim());
		for (int i = 0; i < testCases; i++) {
			String[] s = in.readLine().trim().split("/");
			long p = Long.parseLong(s[0]);
			long q = Long.parseLong(s[1]);
			long d = gcf(p, q);
			p = p / d;
			q = q / d;
			int g = -1;
			while (g < 40) {
				g++;
				if (p >= q) {
					break;
				} else {
					p = p * 2L;
				}
				d = gcf(p, q);
				p = p / d;
				q = q / d;
			}
			if (p < q) {
				g = -1;
			} else if (p > q) {
				p = p - q;
				while (p % 2 == 0 && q % 2 == 0) {
					p = p / 2;
					q = q / 2;
				}
				if (q % 2 == 0) {
					int l = 0;
					while (Math.pow(2, l) != q && l < 40) {
						l++;
					}
					if (Math.pow(2, l) != q) {
						g = -1;
					}
				} else {
					g = -1;
				}
			}
			out.write("Case #" + (i + 1) + ": " + (g == -1 ? "impossible" : g));
			if (i != testCases - 1) {
				out.newLine();
			}
		}
		in.close();
		out.close();
	}

	public static long gcf(long a, long b) {
		if (b == 0)
			return a;
		else
			return (gcf(b, a % b));
	}
}
