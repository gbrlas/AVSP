import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		int T;
		int caseNum;
		double C, F, X;
		double ans;
		FileReader file = new FileReader("cookie_input.txt");
		File outFile = new File("cookie_output.txt");
		FastScannerSlow fScanner = new FastScannerSlow(file);
		PrintWriter out = new PrintWriter(outFile);
//		PrintWriter outConsole = new PrintWriter(System.out);

		T = fScanner.nextInt();

		for (caseNum = 1; caseNum <= T; caseNum++) {

			C = fScanner.nextDouble();
			F = fScanner.nextDouble();
			X = fScanner.nextDouble();

			ans = solve(C, F, X);

			out.println("Case #" + caseNum + ": " + String.format("%.7f", ans));

//			outConsole.println("Case #" + caseNum + ": "
//					+ String.format("%.7f", ans));
		}

		out.flush();
//		outConsole.flush();
		out.close();
//		outConsole.close();
	}

	public static double solve(double C, double F, double X) {
		double minTime;
		double rate;
		double curTime;
		double elapsedTime;

		rate = 2;

		minTime = X / rate;

		curTime = 0;

		if (C >= X)
			return minTime;

		elapsedTime = 0;

		while (true) {

			elapsedTime += C / rate;

			rate += F;

			curTime = elapsedTime + X / rate;

			if (minTime < curTime)
				break;

			minTime = curTime;

		}

		return minTime;

	}
}

class FastScannerSlow {

	BufferedReader br;
	StringTokenizer st;

	public FastScannerSlow() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	public FastScannerSlow(FileReader file) {
		br = new BufferedReader(file);
	}

	String next() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}

	String nextLine() {
		String str = "";
		try {
			str = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return str;
	}

	char[] nextCharArray(int N) {
		int i;
		char[] array;
		String str;

		array = new char[N];

		i = 0;

		str = nextLine();

		for (i = 0; i < N && i < str.length(); i++) {
			array[i] = str.charAt(i);
		}

		return array;
	}

	char[][] nextChar2DArray(int M, int N) {
		int i;
		char[][] array;

		array = new char[M][N];

		i = 0;

		for (i = 0; i < M; i++) {
			array[i] = nextCharArray(N);
		}

		return array;
	}

	int[] nextIntArray(int N) {
		int i;
		int[] array;

		array = new int[N];

		i = 0;

		for (i = 0; i < N; i++) {
			array[i] = nextInt();
		}

		return array;
	}

	int[][] nextInt2DArray(int M, int N) {
		int i;
		int[][] array;

		array = new int[M][N];

		i = 0;

		for (i = 0; i < M; i++) {
			array[i] = nextIntArray(N);
		}

		return array;
	}

	long[] nextLongArray(int N) {
		int i;
		long[] array;

		array = new long[N];

		i = 0;

		for (i = 0; i < N; i++) {
			array[i] = nextLong();
		}

		return array;
	}

	long[][] nextLong2DArray(int M, int N) {
		int i;
		long[][] array;

		array = new long[M][N];

		i = 0;

		for (i = 0; i < M; i++) {
			array[i] = nextLongArray(N);
		}

		return array;
	}

}