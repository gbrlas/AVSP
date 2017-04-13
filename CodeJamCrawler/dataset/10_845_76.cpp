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
				Snappers snappers = new Snappers(testcases.get(i));
				boolean state = snappers.getLightState();
				System.out.format("Case #%d: %s\n", (i+1),(state ? "ON" : "OFF"));
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
