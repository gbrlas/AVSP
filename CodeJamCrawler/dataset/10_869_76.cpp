import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
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
				FairWarning warning = new FairWarning(testcases.get(i));
				BigInteger slarbosec = warning.getSlarbosecondsNeeded();
				System.out.format("Case #%d: %s\n", (i+1),slarbosec.toString());
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
