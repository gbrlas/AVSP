import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemA {
	String PROBLEM_ID = "problemA";
	enum TestType { EXAMPLE, SMALL, LARGE }
	TestType TYPE = TestType.SMALL;
	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch ( TYPE ) {
		case EXAMPLE: result += "example"; break;
		case SMALL:   result += "small"; break;
		case LARGE:   result += "large"; break;
		}
		return result;
	}
	public String getInFileName() { return getFileName() + ".in"; }
	public String getOutFileName() { return getFileName() + ".out"; }
	
	public static void main(String[] args) throws Exception {
		new ProblemA();
	}
	
	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			TeamData[] list = new TeamData[n];
			for (int i = 0; i < list.length; i++) {
				list[i] = new TeamData(scan.next());
			}
			double[] wp = new double[n];
			double[] owp = new double[n];
			double[] oowp = new double[n];
			for ( int i = 0; i < n; i++) {
				wp[i] = list[i].wp();
				double z = 0.0;
				int count = 0;
				for ( int j = 0; j < n; j++) {
					if ( list[i].isOpponent(j) ) {
						count++;
						z += list[j].wp_skip(i);
					}
				}
				owp[i] = z/count;
			}
//			System.out.println("wp " + Arrays.toString(wp));
//			System.out.println("owp" + Arrays.toString(owp));
			for ( int i = 0; i < n; i++) {
				double z = 0.0;
				int count = 0;
				for ( int j = 0; j < n; j++) {
					if ( list[i].isOpponent(j)) {
						count++;
						z += owp[j];
					}
					
				}
				oowp[i] = z/count;
			}
//			System.out.println("oowp " +Arrays.toString(oowp));
		
			
			String resultStr = String.format("Case #%d:\n", test+1);
			// add answer here
			for ( int i = 0; i < n; i++) {
				double rpi = 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i];
				resultStr += String.format("%.9f\n", rpi);
			}
			
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
	
	class TeamData {
		int[] score;
		int totalGames, totalWins;
		public TeamData(String input) {
			int n = input.length();
			score = new int[n];
			totalGames = 0;
			totalWins = 0;
			for ( int i = 0; i < n; i++) {
				char c = input.charAt(i);
				if ( c == '.') score[i] = -1;
				else {
					totalGames++;
					if ( c == '1') {
						score[i] = 1;
						totalWins++;
					}
					if ( c == '0') score[i] = 0;
				}
			}
		}
		public double wp() { return totalWins*1.0/totalGames; }
		public boolean isOpponent(int index) { return score[index] >= 0; }
		public double wp_skip(int skip) {
			if ( score[skip] < 0 ) return wp();
			int m = totalWins - (score[skip] == 1 ? 1 : 0);
			return m*1.0/(totalGames-1);	
		}
	}

	
}
