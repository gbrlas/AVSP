import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class b {

	final static String PROBLEM_NAME = "b";
    final static String WORK_DIR = "D:\\Gdc\\src\\" + "\\";
    
	public static void main(String[] args) {
		try { 
			Scanner sc = new Scanner(new FileReader(WORK_DIR + PROBLEM_NAME + ".in"));
        	PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + PROBLEM_NAME + ".out"));
	        int caseCnt = Integer.parseInt(sc.nextLine());
	        System.out.println(caseCnt);
	        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
	            System.out.println("Processing test case " + (caseNum + 1));
	            pw.print("Case #" + (caseNum + 1) + ": ");
	            solve(sc, pw);
	        }
	        pw.flush();
	        pw.close();
	        sc.close();
		}
		catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	private static void solve(Scanner sc, PrintWriter pw) {
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[][] a = new int[N][M];
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++)
				a[i][j] = sc.nextInt();
		
		int[] b = new int[N];
		int[] c = new int[M];
		for (int i = 0; i < N; i++) {
			b[i] = a[i][0];			
			for (int j = 0; j < M; j++)
				b[i] = Math.max(b[i], a[i][j]);
		}
		
		for (int j = 0; j < M; j++) {
			c[j] = a[0][j];
			for (int i = 0; i < N; i++)
				c[j] = Math.max(c[j], a[i][j]);
		}
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (a[i][j] < b[i] && a[i][j] < c[j]) {
					pw.println("NO");	
					return;
				}
					
		pw.println("YES");		
	}
}
