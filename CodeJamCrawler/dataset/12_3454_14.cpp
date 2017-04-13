import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Solver {
	
	public String hasDiamond(int[][] path){
		for (int k=0; k<path.length; k++){
			for(int i=0; i<path.length; i++){
				for(int j=1; j<path.length; j++){
					if(path[i][k] > 0 && path[k][j] > 0){
						path[i][j] += 1;
					}
					if(path[i][j] > 1) return "Yes";
				}
			}
		}
		/*for(int i = 0; i<path.length; i++){
			for (int j=0; j<path.length; j++){
				System.out.print(path[i][j]+" ");
			}
			System.out.println();
		}*/
		return "No";
	}
	
	public void solve(){
		try{
		System.setIn(new FileInputStream(new File("in.in")));
		System.setOut(new PrintStream(new File("out.txt")));
		} catch (FileNotFoundException e){}
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		for(int tc=1; tc<=t; tc++){
			int N = scanner.nextInt();
			int [][] path = new int[N][N];
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					path[i][j] = 0;
				}
			}
			for(int i=0; i<N; i++){
				int M = scanner.nextInt();
				for (int j =0; j<M; j++){
					int Mi = scanner.nextInt();
					path[i][Mi-1] = 1;
				}
			}
			System.out.println("Case #"+tc+": "+hasDiamond(path));
		}
	}
	
	public static void main(String[] args) {
		new Solver().solve();
	}

}
