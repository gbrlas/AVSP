package gcj.qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.PrintWriter;

public class Main {
//	private static final GoogleRunnable runner = new SavingTheUniverse();
	private static final GoogleRunnable runner = new TrainTimetable();
	
	public static void main(String[] args) throws IOException {
		if (args.length == 0) {
			throw new IllegalArgumentException("Missing input");
		}
		String inputName = args[0];
		FileReader inputReader = new FileReader(inputName);
		String outputName = inputName.replace(".in", ".out");
		PrintWriter outWriter = new PrintWriter(new FileWriter(outputName));
		try {
			LineNumberReader r = new LineNumberReader(new BufferedReader(inputReader));
			try {
				int numCases = Integer.parseInt(r.readLine());
				for (int i = 0; i < numCases; i++) {
					String res = "Case #" + (i + 1) + ": " + runner.solveOneTask(r);
					System.out.println(res);
					outWriter.println(res);
				}
			} catch (IOException e) {
				System.err.println(args[0] + ": " + e);
			} finally {
				r.close();
			}
		} finally {
			outWriter.close();
		}
	}
}
