import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class MainProgram {

	static BufferedReader in = null;
	static int[][] A;
	static int M, N;
	static boolean isPossible = true;;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		in = new BufferedReader(new FileReader("/Users/himanshugupta/workspace/practice/Treasure/input.txt")); 
		int N = Integer.parseInt(in.readLine());
		for (int i=0; i<N; i++){
			readInput();
			System.out.println("Case #"+(i+1)+": "+getOutput());
		}
		in.close();
	}
	
	public static void readInput() throws IOException{
		String[] str = in.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		A = new int[N][M];
		for (int i=0; i<N; i++){
			str = in.readLine().split(" ");
			for (int j=0; j<M; j++){
				A[i][j] = Integer.parseInt(str[j]);
				if (A[i][j] > 100 || A[i][j] < 1)
					isPossible = false;
			}
		}
	}
	
	public static String getOutput(){
		if (!isPossible)
			return "NO";
		int max = -1;
		char[][] C = new char[N][M];
		for (int i=0; i<N; i++){
			max = -1;
			for (int j=0; j<M; j++){
				max = (A[i][j] > max) ? A[i][j] : max;
			}
			for (int j=0; j<M; j++){
				C[i][j] = (A[i][j] == max) ? 'H' : 'V';
			}
		}
		for (int i=0; i<M; i++){
			max = -1;
			for (int j=0; j<N; j++){
				max = (A[j][i] > max) ? A[j][i] : max;
			}
			for (int j=0; j<N; j++){
				char c = (A[j][i] == max) ? 'V' : 'H';
				if (c == 'H' && C[j][i] != 'H')
					return "NO";
			}
		}
		
		return "YES";
	}

}
