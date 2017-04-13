import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class ProblemB {

	public static double C;
	public static double F;
	public static double X;

	public static void solve(BufferedReader reader, PrintStream writer)
			throws NumberFormatException, IOException {
		int testCaseCount = Integer.valueOf(reader.readLine());
		int globalCount = 1;

		for (int i = 0; i < testCaseCount; i++) {
			String gameLine = reader.readLine();
			String[] gameParams = gameLine.split(" ");

			// set params
			if (3 != gameParams.length) {
				System.out.println("Invalid format");
				System.exit(-1);
			}

			C = Double.valueOf(gameParams[0]);
			F = Double.valueOf(gameParams[1]);
			X = Double.valueOf(gameParams[2]);

			double R = 2.0;
			double A = ((R + F) * C) / F;
			double T = 0.0;

			double remain = X;
			while (X >= A) {
				
				T += C / R;
				R += F;
				A = ((R + F) * C) / F;
			}

			T += X / R;
			writer.println("Case #" + globalCount++ + ": " + T);
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		if (1 != args.length) {
			System.exit(0);
		}

		String filename = args[0];

		BufferedReader reader = new BufferedReader(new FileReader(filename));
		PrintStream writer = new PrintStream(args[0] + ".output");

		solve(reader, writer);

		reader.close();
		writer.close();
	}
}
