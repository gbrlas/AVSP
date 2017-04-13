import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Main {

	private static final String PHRASE = "welcome to code jam";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			FileReader fr = new FileReader(args[0]);
			TestData testdata = new TestData(fr);
			String[] testcases = testdata.getTestCases();
			for (int i=0; i<testcases.length; i++) {
				PhraseCounter counter = new PhraseCounter(PHRASE, testcases[i]);
				long totalcount = counter.getTotalCount();
				int fordigits = (int)(totalcount % 10000);
				System.out.format("Case #%d: %04d\n", (i+1),fordigits);
			}
			fr.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
