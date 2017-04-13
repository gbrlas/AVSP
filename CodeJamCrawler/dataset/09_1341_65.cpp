package gcj2009.round1c.problemA;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solver {

	/** Parameter class */
	public static class Case {
		public List<Character> chars;

		public Map<Character, Integer> charToCount;

		public Case(List<Character> chars, Map<Character, Integer> charToCount) {
			this.chars = chars;
			this.charToCount = charToCount;
		}
	}

	/** Fields */
	private BufferedReader br;

	private BufferedWriter bw;

	private List<Case> cases = new ArrayList<Case>();

	/** Constructor */
	public Solver(BufferedReader reader, BufferedWriter writer) {
		br = reader;
		bw = writer;
	}

	/** Parse parameter */
	public void readParams() throws IOException {
		String line;
		line = br.readLine().trim();

		int nCases = Integer.parseInt(line);

		for (int i = 0; i < nCases; i++) {
			line = br.readLine().trim();

			// Count number of characters
			Map<Character, Integer> charToCount = new HashMap<Character, Integer>();
			List<Character> chars = new ArrayList<Character>();

			for (int j = 0; j < line.length(); j++) {

				Character c = line.charAt(j);
				chars.add(c);
				if (!charToCount.containsKey(c)) {
					charToCount.put(c, 1);
					continue;
				}
				Integer cnt = Integer.valueOf(charToCount.get(c) + 1);
				charToCount.put(c, cnt);
			}

			Case c = new Case(chars, charToCount);

			cases.add(c);
		}
	}

	/**
	 * solve
	 * 
	 * @throws IOException
	 */
	public void solve() throws IOException {
		int caseNum = 1;
		for (Case c : this.cases) {
			// 
			int min_base = c.charToCount.size();
			// no unary
			if (min_base < 2) {
				min_base = 2;
			}

			List<Integer> remained = new ArrayList<Integer>();
			for (int i = 0; i < min_base; i++) {
				if (i == 1) {
					continue;
				}
				remained.add(Integer.valueOf(i));
			}

			List<Integer> digits = new ArrayList<Integer>();
			Map<Character, Integer> charToDigitMap = new HashMap<Character, Integer>();

			// Resolve first digit
			Character first = c.chars.get(0);
			charToDigitMap.put(first, Integer.valueOf(1));

			System.out.println(c.chars);

			for (int i = 0, size = c.chars.size(); i < size; i++) {

				Character current = c.chars.get(i);
				System.out.println(current);

				// Resolve what digit does "current" stand for
				Integer digit;
				if (!charToDigitMap.containsKey(current)) {
					digit = remained.get(0);
					remained.remove(0);
					charToDigitMap.put(current, digit);
				} else {
					digit = charToDigitMap.get(current);
				}
				digits.add(digit);

			}
			System.out.println("Base is " + min_base + "  : " + digits);

			BigDecimal timeBeforeWar = new BigDecimal(0);

			BigDecimal base = new BigDecimal(min_base);
			for (Integer digit : digits) {
				timeBeforeWar = timeBeforeWar.multiply(base);
				timeBeforeWar = timeBeforeWar.add(BigDecimal.valueOf(digit));
			}
			System.out.print(String.format("Case #%d: %s\n", caseNum,
					timeBeforeWar.toString()));

			bw.write(String.format("Case #%d: %s\n", caseNum, timeBeforeWar
					.toString()));
			caseNum++;
		}
	}

	public static void main(String[] args) throws Exception {

		List<Integer> list = new ArrayList<Integer>();
		list.add(6);
		list.add(6);
		list.add(3);
		list.add(3);
		list.add(1);
		list.add(0);

		System.out.println("-----------");
		System.out.println(list);
		System.out.println("-----------");

		if (args.length != 2) {
			System.err.println("Specify input file name.");
			System.err.println("Specify output file name.");
			System.exit(0);
		}

		String inputFileName = args[0];
		String outputFileName = args[1];

		BufferedReader br = null;
		BufferedWriter bw = null;
		try {
			// Prepare reader
			br = new BufferedReader(new InputStreamReader(new FileInputStream(
					inputFileName)));

			// Prepare writer
			bw = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream(outputFileName), "UTF-8"));

			Solver sol = new Solver(br, bw);

			// Read and parse parameter
			sol.readParams();

			sol.solve();
			/**
			 * 
			 */
		} finally {
			if (br != null)
				br.close();
			if (bw != null)
				bw.close();
		}

	}
}
