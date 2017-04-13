import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class DeceitfulWar {

	private static String inputDir = "C:\\CodeJam2014\\Input\\";
	private static String outputDir = "C:\\CodeJam2014\\Output\\";

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(inputDir + "D-large.in")));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputDir + "DeceitfulWarOutput.txt")));
		int testCases = Integer.parseInt(in.readLine().trim());
		for (int i = 0; i < testCases; i++) {
			in.readLine();
			List<Double> nBlockWts = new ArrayList<>();
			List<Double> kBlockWts = new ArrayList<>();
			for (String wt : in.readLine().trim().split("\\s")) {
				nBlockWts.add(Double.parseDouble(wt));
			}
			for (String wt : in.readLine().trim().split("\\s")) {
				kBlockWts.add(Double.parseDouble(wt));
			}
			out.write("Case #" + (i + 1) + ": " + getWarResult(new ArrayList<>(nBlockWts), new ArrayList<>(kBlockWts), true) + " " + getWarResult(new ArrayList<>(nBlockWts), new ArrayList<>(kBlockWts), false));
			if (i != testCases - 1) {
				out.newLine();
			}
		}
		in.close();
		out.close();
	}

	private static int getWarResult(List<Double> nBlockWts, List<Double> kBlockWts, boolean isDeceifulWar) {
		Collections.sort(nBlockWts);
		Collections.sort(kBlockWts);
		int points = 0;
		if (isDeceifulWar) {
			while (nBlockWts.size() > 0) {
				if (nBlockWts.get(0) > kBlockWts.get(0)) {
					points++;
					kBlockWts.remove(0);
				} else {
					kBlockWts.remove(kBlockWts.size() - 1);
				}
				nBlockWts.remove(0);
			}
		} else {
			Collections.reverse(nBlockWts);
			for (Double n : nBlockWts) {
				points += (canGetWarPoint(n, kBlockWts) ? 1 : 0);
			}
		}
		return points;
	}

	private static boolean canGetWarPoint(Double n, List<Double> kBlockWts) {
		boolean result = true;
		int i = 0;
		while (i < kBlockWts.size()) {
			if (n < kBlockWts.get(i)) {
				result = false;
				break;
			}
			i++;
		}
		kBlockWts.remove(result ? 0 : i);
		return result;
	}
}
