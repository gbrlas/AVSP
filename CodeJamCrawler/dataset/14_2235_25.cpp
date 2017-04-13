import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
	
	private Scanner in;
	private PrintWriter out;
	
	// DATA
	final int SIZE = 4;
	int line1;
	int[][] matrix1 = new int[SIZE][SIZE];
	int line2;
	int[][] matrix2 = new int[SIZE][SIZE];
	
	private void readData() {
		line1 = in.nextInt();
		for (int i =0; i<SIZE; i++) {
			for (int j =0; j<SIZE; j++) {
				matrix1[i][j] = in.nextInt();
			}
		}
		line2 = in.nextInt();
		for (int i =0; i<SIZE; i++) {
			for (int j =0; j<SIZE; j++) {
				matrix2[i][j] = in.nextInt();
			}
		}
	}
	
	private String solve() {
		Set<Integer> line1Set = new HashSet<Integer>();
		Set<Integer> line2Set = new HashSet<Integer>();
		for (int i =0; i<SIZE; i++) {
			line1Set.add(matrix1[line1-1][i]);
		}
		for (int i =0; i<SIZE; i++) {
			line2Set.add(matrix2[line2-1][i]);
		}
		
		line1Set.retainAll(line2Set);
		
		if (line1Set.isEmpty()) {
			return "Volunteer cheated!";
		}
		if (line1Set.size() > 1) {
			return "Bad magician!";
		}
		return line1Set.iterator().next().toString();
	}
	
	
	public static void main(String[] args) throws FileNotFoundException {
		new A().execute();
	}

	public void execute() throws FileNotFoundException {
		in = new Scanner(new File("A-small-attempt0.in"));
		out = new PrintWriter("A-small-attempt0.out");
		
		int nrlines = in.nextInt();
		for (int i=0; i<nrlines; i++) {
			readData();
			String result = solve();
			out.println("Case #" + (i+1) + ": " + result);		
		}
			
		
        in.close();
        out.close();
	}

}