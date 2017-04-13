import java.io.BufferedReader;
import java.io.FileReader;


public class MainProgram {

	
	static BufferedReader in = null;
	static String[] possibleNumbers, possibleNumbers2;
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("/Users/himanshugupta/workspace/practice/MagicTrick/A-small-attempt0.in")); 
		int T = Integer.parseInt(in.readLine());
		for (int i=0; i<T; i++){
			int row1 = Integer.parseInt(in.readLine());
			for (int j=1; j<row1; j++){
				in.readLine();
			}
			String row = in.readLine();
			possibleNumbers = row.split(" ");
			for (int j=row1; j<4; j++){
				in.readLine();
			}
			int row2 = Integer.parseInt(in.readLine());
			for (int j=1; j<row2; j++){
				in.readLine();
			}
			row = in.readLine();
			possibleNumbers2 = row.split(" ");
			for (int j=row2; j<4; j++){
				in.readLine();
			} 
			System.out.println("Case #"+(i+1)+": "+getOutput());
		}
		in.close();
	}

	private static String getOutput() {
		String possibleNumber = "";
		int matchingNumbers = 0;
		for (String str1 : possibleNumbers){
			for (String str2 : possibleNumbers2){
				if (str1.equals(str2)){
					possibleNumber = str1;
					matchingNumbers++;
				}
			}
		}
		if (matchingNumbers == 0)
			return "Volunteer cheated!";
		else if (matchingNumbers > 1)
			return "Bad magician!";
		else
			return possibleNumber;
	}

	private static String readInput() throws Exception {
		return in.readLine();
	}
	
}
