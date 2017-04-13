import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class One {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter("output.in");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int i = 1; i <= t; ++i) {
			//Taking the first input
			int input1 = Integer.parseInt(br.readLine());
			int arr1[][] = new int[4][4];
			
			for (int j = 0; j < 4; ++j) {
				String tmp[] = br.readLine().split("\\s");
				for (int k = 0; k < 4; ++k) 
					arr1[j][k] = Integer.parseInt(tmp[k]);
			}
			
			//Taking the second input
			int input2 = Integer.parseInt(br.readLine());
			int arr2[][] = new int[4][4];
			
			for (int j = 0; j < 4; ++j) {
				String tmp[] = br.readLine().split("\\s");
				for (int k = 0; k < 4; ++k) 
					arr2[j][k] = Integer.parseInt(tmp[k]);
			}
			
			String result = solve(input1, arr1, input2, arr2);
			pw.println("Case #" + i +": " + result);
		}
		pw.close();

	}
	
	public static String solve(int input1, int[][] arr1, 
									int input2, int[][] arr2) {
		String result = null;
		List<Integer> tmp = new ArrayList<Integer>();
		
		for (int i = 0; i < 4; ++i) 
			tmp.add(arr1[input1-1][i]);
		
		int count = 0;
		Integer resultVal = -1;
		for (int i = 0; i < 4; ++i) { 
			if (tmp.contains(arr2[input2-1][i])) {
				++count;
				resultVal = arr2[input2 - 1][i];
			}
		}
		
		switch (count) {
		case 0:
			result = "Volunteer cheated!";
			break;
		case 1:
			result = resultVal.toString();
			break;
		default:
			result = "Bad magician!";
		}
	
		return result;
	}
	
}
