import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class A {
	
	public static int minimumSequence(String sequence) {
		StringTokenizer strTokenizer = new StringTokenizer(sequence, " ");
		String strSteps = strTokenizer.nextToken();
		Queue<Integer> o = new LinkedList<Integer>();
		Queue<Integer> b = new LinkedList<Integer>();
		int result = 0;
		
		int oPos = 1;
		int bPos = 1;
		int oTime = 0; // the time spent from the last O command
		int bTime = 0; // the time spent from the last B command
	
		int steps = Integer.parseInt(strSteps);
		for(int i = 0; i< steps; i++) {
			String robot = strTokenizer.nextToken();
			String strButton = strTokenizer.nextToken();
			int button = Integer.parseInt(strButton);
			
			if ("O".equals(robot)) {
				int moves = Math.max(Math.abs(oPos - button) - oTime, 0);
				oTime = 0;
				bTime += moves + 1;
				oPos = button;
				result += moves + 1; // 1 is for action
			} else {
				int moves = Math.max(Math.abs(bPos - button) - bTime, 0);
				bTime = 0;
				oTime += moves + 1;
				bPos = button;
				result += moves + 1; // 1 is for action
			}
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile + ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i=1;i<=nrLines; i++ ) {
			String line = reader.readLine();
			int moves = minimumSequence(line);
			out.println("Case #" + i + ": " + moves);
		}
		reader.close();
		out.close();

	}

}
