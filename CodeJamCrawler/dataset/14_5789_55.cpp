import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		int T;
		int i, j, k;
		int[][] arr;
		int ans;
		int count;
		int row;
		HashSet<Integer> hashSet = new HashSet<>();
		FastScannerSlow fastScanner = new FastScannerSlow();
		PrintWriter out = new PrintWriter(System.out);

		T = fastScanner.nextInt();

		for (j = 1; j <= T; j++) {
			count = 0;
			row = fastScanner.nextInt() - 1;
			arr = fastScanner.nextInt2DArray(4, 4);
			hashSet.clear();

			for (i = 0; i < 4; i++) {
				hashSet.add(arr[row][i]);
			}

			row = fastScanner.nextInt() - 1;
			arr = fastScanner.nextInt2DArray(4, 4);

			ans = -1;

			for (i = 0; i < 4; i++) {
				k = arr[row][i];

				if (hashSet.contains(k)) {
					ans = k;
					count++;
				}
			}

			if (count == 0) {
				out.println("Case #" + j + ": Volunteer cheated!");
			} else if (count == 1) {
				out.println("Case #" + j + ": " + ans);
			} else {
				out.println("Case #" + j + ": Bad magician!");
			}

		}

		out.flush();
		out.close();
	}
}

class FastScannerSlow {

	BufferedReader br;
	StringTokenizer st;

	public FastScannerSlow() {
		br = new BufferedReader(new InputStreamReader(System.in));
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