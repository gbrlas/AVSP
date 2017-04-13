import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			TestData data = new TestData(args[0]);
			PrintWriter output = new PrintWriter(args[0]+"-output.txt");
			List<TestCase> testcases = data.getTestCases();
			for (int i=0; i<testcases.size(); i++) {
				DecisionTreeWalker walker = new DecisionTreeWalker(testcases.get(i));
				float[] numbers = walker.getNumbers();
				output.format("Case #%d:\n", (i+1));
				System.out.format("Case #%d:\n", (i+1));
				for (int j=0; j<numbers.length; j++) {
					output.format("%.8f\n", numbers[j]);
					System.out.format("%.8f\n", numbers[j]);					
				}
			}
			output.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
