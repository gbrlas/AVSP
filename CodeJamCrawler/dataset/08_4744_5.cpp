import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * <h3>Problem</h3>
 * 
 * The urban legend goes that if you go to the Google homepage and search for
 * "Google", the universe will implode. We have a secret to share... It is true!
 * Please don't try it, or tell anyone. All right, maybe not. We are just
 * kidding.
 * 
 * The same is not true for a universe far far away. In that universe, if you
 * search on any search engine for that search engine's name, the universe does
 * implode!
 * 
 * To combat this, people came up with an interesting solution. All queries are
 * pooled together. They are passed to a central system that decides which query
 * goes to which search engine. The central system sends a series of queries to
 * one search engine, and can switch to another at any time. Queries must be
 * processed in the order they're received. The central system must never send a
 * query to a search engine whose name matches the query. In order to reduce
 * costs, the number of switches should be minimized.
 * 
 * Your task is to tell us how many times the central system will have to switch
 * between search engines, assuming that we program it optimally.
 * 
 * <h3>Input</h3>
 * 
 * The first line of the input file contains the number of cases, N. N test
 * cases follow.
 * 
 * Each case starts with the number S -- the number of search engines. The next
 * S lines each contain the name of a search engine. Each search engine name is
 * no more than one hundred characters long and contains only uppercase letters,
 * lowercase letters, spaces, and numbers. There will not be two search engines
 * with the same name.
 * 
 * The following line contains a number Q -- the number of incoming queries. The
 * next Q lines will each contain a query. Each query will be the name of a
 * search engine in the case.
 * 
 * <h3>Output</h3>
 * 
 * For each input case, you should output:
 * 
 * <code>Case #X: Y</code>
 * 
 * where X is the number of the test case and Y is the number of search engine
 * switches. Do not count the initial choice of a search engine as a switch.
 * 
 * @author Thiago Braga
 */
public class SavingTheUniverse {

	/**
	 * Main method: reads the input file and computes the output file.
	 * 
	 * @param args
	 *            [inputFile, outputFile]
	 */
	public static void main(String[] args) {
		if (args.length == 2) {
			try {
				final BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
				final PrintStream output = new PrintStream(new FileOutputStream(args[1]));

				// Reads the number of test cases
				String line = input.readLine();
				int n = Integer.valueOf(line);
				
				for (int testCase = 1; testCase <= n; testCase++) {
					// Reads the number of search engines.
					line = input.readLine();
					int s = Integer.valueOf(line);

					// Reads each search engine
					String[] searchEngine = new String[s];
					for (int i = 0; i < s; i++) {
						searchEngine[i] = input.readLine();
					}
					Set<String> availableSearchEngines = new HashSet<String>(Arrays.asList(searchEngine));
					
					// Number of search engine switches
					int switches = 0;
					
					//Reads the number of incoming queries
					line = input.readLine();
					int q = Integer.valueOf(line);
					
					// Reads each incoming queries, computing the number of search engine switches
					for (int i = 0; i < q; i++) {
						String querie = input.readLine();
						availableSearchEngines.remove(querie);
						if (availableSearchEngines.isEmpty()) {
							System.out.printf("Case #%d: Using %s until query #%d.\n", testCase, querie, i - 1);
							availableSearchEngines = new HashSet<String>(Arrays.asList(searchEngine));
							availableSearchEngines.remove(querie);
							switches++;
						}
					}
					System.out.printf("Case #%d: Using one of %s until the end.\n", testCase, availableSearchEngines);
					output.printf("Case #%d: %s\n", testCase, switches);
				}

				input.close();
				output.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			System.exit(0);
		} else {
			System.err.println("SavingTheUniverse inputFile outputFile");
			System.exit(-1);
		}
	}

}