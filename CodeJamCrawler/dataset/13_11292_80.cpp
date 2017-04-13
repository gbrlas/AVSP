import java.util.*;
import java.io.*;

public class a {

	final static String PROBLEM_NAME = "a";
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
	            new a().solve(sc, pw);
	        }
	        pw.flush();
	        pw.close();
	        sc.close();
		}
		catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	private void solve(Scanner sc, PrintWriter pw) {
		int N = 4;
        int xT = -1;
        int yT = -1;
        int num = 0;
        
		int[][] a = new int[4][4];
        for (int i = 0; i < N; i++) {
        	String s = sc.nextLine();
        	for (int j = 0; j < 4; j++) {
        		switch (s.charAt(j)) {
        			case 'X': 
        				a[i][j] = -1;
        				break;
        			case 'O':
        				a[i][j] = 1;
        				break;
        			case 'T':
        				xT = i;
        				yT = j;
        				break;
        			case '.':
        				a[i][j] = 0;
        				num++;
        				break;
        		}
        	}        		
        }
       if (sc.hasNext()) sc.nextLine();               
        	
        //check X win
        if (xT != -1)
        	a[xT][yT] = -1;
        
        if (a[0][0] + a[0][1] + a[0][2] + a[0][3] == -4) {
        	pw.println("X won");
        	return ;
        }
        if (a[1][0] + a[1][1] + a[1][2] + a[1][3] == -4) {
        	pw.println("X won");
        	return;
        }
        if (a[2][0] + a[2][1] + a[2][2] + a[2][3] == -4) {
        	pw.println("X won");
        	return;
        }
        if (a[3][0] + a[3][1] + a[3][2] + a[3][3] == -4) {
        	pw.println("X won");
        	return;
        }
        
        if (a[0][0] + a[1][0] + a[2][0] + a[3][0] == -4) {
        	pw.println("X won");
        	return;
        }
        if (a[0][1] + a[1][1] + a[2][1] + a[3][1] == -4) {
        	pw.println("X won");
        	return;
        }
        if (a[0][2] + a[1][2] + a[2][2] + a[3][2] == -4) {
        	pw.println("X won");
        	return;
        }
        if (a[0][3] + a[1][3] + a[2][3] + a[3][3] == -4) {
        	pw.println("X won");
        	return;
        }
        
        if (a[0][0] + a[1][1] + a[2][2] + a[3][3] == -4) {
        	pw.println("X won");
        	return;
        }
        if (a[0][3] + a[1][2] + a[2][1] + a[3][0] == -4) {
        	pw.println("X won");
        	return;
        }
        
        //check O win
        if (xT != -1)
        	a[xT][yT] = 1;
        
        if (a[0][0] + a[0][1] + a[0][2] + a[0][3] == 4) {
        	pw.println("O won");
        	return;
        }
        if (a[1][0] + a[1][1] + a[1][2] + a[1][3] == 4) {
        	pw.println("O won");
        	return;
        }
        if (a[2][0] + a[2][1] + a[2][2] + a[2][3] == 4) {
        	pw.println("O won");
        	return;
        }
        if (a[3][0] + a[3][1] + a[3][2] + a[3][3] == 4) {
        	pw.println("O won");
        	return;
        }
        
        if (a[0][0] + a[1][0] + a[2][0] + a[3][0] == 4) {
        	pw.println("O won");
        	return;
        }
        if (a[0][1] + a[1][1] + a[2][1] + a[3][1] == 4) {
        	pw.println("O won");
        	return;
        }
        if (a[0][2] + a[1][2] + a[2][2] + a[3][2] == 4) {
        	pw.println("O won");
        	return;
        }
        if (a[0][3] + a[1][3] + a[2][3] + a[3][3] == 4) {
        	pw.println("O won");
        	return;
        }
        
        if (a[0][0] + a[1][1] + a[2][2] + a[3][3] == 4) {
        	pw.println("O won");
        	return;
        }
        if (a[0][3] + a[1][2] + a[2][1] + a[3][0] == 4) {
        	pw.println("O won");
        	return;
        }
        
        //draw or not end
        if (num == 0)
        	pw.println("Draw");
        else
        	pw.println("Game has not completed");
	}
}
