import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			FileReader fr = new FileReader(args[0]);
			TestData data = new TestData(fr);
			fr.close();
			List<TestCase> testcases = data.getTestCases();
			for (int i=0; i<testcases.size(); i++) {
				PatternMatcher matcher = new PatternMatcher(testcases.get(i));
				int count = matcher.getWordsMatched(data.getWords());
				System.out.format("Case #%d: %d\n", (i+1),count);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
