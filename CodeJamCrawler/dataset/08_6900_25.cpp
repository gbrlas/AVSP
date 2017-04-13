import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemA {
	public static void main(String[] args) throws Exception {
		new ProblemA();
	}

	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input-a.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-A.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			M = scan.nextInt();
			int V = scan.nextInt();
			type = new int[M+1];
			change = new boolean[M+1];
			for ( int i = 1; i <= (M-1)/2; i++) {
				type[i] = scan.nextInt();
				int z = scan.nextInt();
				change[i] = z==1;
			}
			value = new int[M+1];
			for ( int i = (M-1)/2+1; i <= M; i++) {
				type[i] = 2;
				value[i] = scan.nextInt();
			}
//			System.out.println("value " +Arrays.toString(value));
//			System.out.println("type " +Arrays.toString(type));
			memo = new int[2][M+1];
			for ( int[] a: memo ) Arrays.fill(a, -1);
			for ( int i = M; i >= 1; i--) {
				go(i,0);
				go(i,1);
			}
			String answer = String.format("Case #%d: ",test + 1 );
			if ( memo[V][1] == INF ) answer += "IMPOSSIBLE\n";
			else answer += memo[V][1] +"\n";
			System.out.print(answer);
			out.printf(answer);
		}
		out.close();
	}
	
	public int go(int index, int v) {
		if ( memo[v][index] >= 0) return memo[v][index];
		if ( type[index] == 2 )
			return memo[v][index] = v == value[index] ? 0 : INF;
		int result = INF;
		for ( int a = 0; a <= 1; a++)
			for ( int b = 0; b <=1; b++) {
				// and
				int z = go(2*index,a) + go(2*index+1, b);
				int extra;
				if ( (a & b) == v ) {
					extra = type[index] == 1 ? 0 : 1;
					if ( type[index] == 0 && !change[index]) extra = INF;
					if ( z + extra < result ) result = z+extra;
				}
				if ( (a | b) == v) {
					extra = type[index] == 0 ? 0 : 1;
					if ( type[index] == 1 && !change[index]) extra = INF;
					if ( z + extra < result ) result = z+extra;
				}
			}
		return memo[v][index] = result;
	}
	
	
	int INF = 1000000;
	int M;
	int[] type;
	int[] value;
	boolean[] change;
	int[][] memo;
	
}
