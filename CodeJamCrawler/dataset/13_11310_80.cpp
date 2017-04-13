import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class c {

	final static String PROBLEM_NAME = "c";
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
		int A = sc.nextInt();
		int B = sc.nextInt();
		
		//small case
		ArrayList<Integer> fs = new ArrayList<Integer>();
		fs.add(1);
		fs.add(4);
		fs.add(9);
		fs.add(121);
		fs.add(484);
		
		int cnt = 0;
		for (int i : fs)
			if (i >= A && i <= B) cnt++;
		
		pw.println(cnt);
	}
	
	
}
