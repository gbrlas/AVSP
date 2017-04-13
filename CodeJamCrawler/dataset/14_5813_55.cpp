import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		int T;
		int caseNum;
		int N;
		int deceit, normal;
		double[] naomiBlock, kenBlock;
		FileReader file = new FileReader("war_input.txt");
		File outFile = new File("war_output.txt");
		FastScannerSlow fScanner = new FastScannerSlow(file);
		PrintWriter out = new PrintWriter(outFile);

		T = fScanner.nextInt();

		for (caseNum = 1; caseNum <= T; caseNum++) {

			N = fScanner.nextInt();

			naomiBlock = fScanner.nextDoubleArray(N);
			kenBlock = fScanner.nextDoubleArray(N);

			Arrays.sort(naomiBlock);
			Arrays.sort(kenBlock);

			deceit = deceitfulWar(naomiBlock, kenBlock, N);
			normal = normalWar(naomiBlock, kenBlock, N);

			out.println("Case #" + caseNum + ": " + deceit + " " + normal);

		}

		out.flush();
		out.close();

	}

	public static int deceitfulWar(double[] naomiBlock, double[] kenBlock, int N) {

		int i, j;
		int count;
		double naomi;
		double ken;
		boolean marked[];
		boolean found;

		marked = new boolean[N];

		count = 0;

		for (i = 0; i < N; i++) {
			naomi = naomiBlock[i];

			found = false;

			for (j = 0; j <= i; j++) {
				ken = kenBlock[j];

				if (!marked[j] && naomi > ken) {
					marked[j] = true;
					count++;
					found = true;
					break;
				}
			}

			if (!found) {
				for (j = N - 1; j >= 0; j--) {
					if (!marked[j]) {
						marked[j] = true;
						break;
					}
				}
			}
		}

		return count;
	}

	public static int normalWar(double[] naomiBlock, double[] kenBlock, int N) {

		int i, j;
		int count;
		double naomi;
		boolean marked[];

		marked = new boolean[N];

		count = 0;

		for (i = 0; i < N; i++) {
			naomi = naomiBlock[i];

			for (j = 0; j < N; j++) {
				if (marked[j])
					continue;

				if (kenBlock[j] > naomi) {
					marked[j] = true;
					count++;
					break;
				}

			}
		}

		return N - count;
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
	
	double[] nextDoubleArray(int N) {
		int i;
		double [] array;
		
		array = new double[N];
		
		for (i = 0; i < N; i++) {
			array[i] = nextDouble();
		}
		
		return array;
	}
	
	double[][] nextDouble2DArray(int M, int N) {
		int i;
		double [][] array;
		
		array = new double[M][N];
		
		for (i = 0; i < M; i++) {
			array[i] = nextDoubleArray(N);
		}
		
		return array;
	}

}