package codejam2010.round1;
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    private static Scanner sc;
    private static PrintWriter pw;
    private static int test;

    // change to your local folder
    private static final String path = "files/codejam2010/round1/";

    // change by question
    private static final String question = "A-small-attempt0";

    public static void main(String[] args) {
        try {
            File in = new File(path + question + ".in");
            File out = new File(path + question + ".out");

            sc = new Scanner(in);
            pw = new PrintWriter(out);

            // solve
            int T = sc.nextInt();
            for (test = 1; test <= T; test++) {
                new A().solve();
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (sc != null) {
                try {
                    sc.close();
                } catch (Exception e) {
                }
            }
            if (pw != null) {
                try {
                    pw.close();
                } catch (Exception e) {
                }
            }
        }
    }

    public void solve() {
        //        int R = sc.nextInt();
        //        int k = sc.nextInt();
        //        int N = sc.nextInt();
        //        
        //        int[] groups = new int[N];
        //        for (int i = 0; i < N; i++) {
        //            groups[i] = sc.nextInt();
        //        }        
    	
    	int N = sc.nextInt();
    	
    	int crossCount = 0;
    	int[][] lines = new int[N][2];
    	for (int n = 0; n < N; n++) {
    		lines[n][0] = sc.nextInt();
    		lines[n][1] = sc.nextInt();
    		
    		for (int lineNum = 0; lineNum < n; lineNum++) {
    			if (isCross(0, lines[lineNum][0], 1, lines[lineNum][1], 0, lines[n][0], 1, lines[n][1]))
    				crossCount++;
    		}
    	}

        String resultStr = String.format("Case #%d: %d\n", test, crossCount);
        pw.print(resultStr);
        System.out.print(resultStr);
    }
    
    private boolean isCross(int x1, int y1, int x2, int y2
    		, int x3, int y3, int x4, int y4) {
    	int dx1 = x2 - x1;
    	int dx2 = x3 - x4;
    	
    	if(dx1 == 0 || dx2 == 0) return false;
    	
    	double m1 = (y2 - y1) / dx1;
    	double m2 = (y3 - y4) / dx2;
    	
    	double x = (-m2 * x4 + y4 + m1 * x1 - y1) / (m1 - m2);
    	double y = m1 * (x - x1) + y1;
    	
    	return x > 0 && y > 0;
    }
}
