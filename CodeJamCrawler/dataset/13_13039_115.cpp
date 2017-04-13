import java.util.*;
import java.io.*;

public class ProblemC {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "C-large-1.in";
	private static final String OUT_FILE = "output_c.txt";
	
	private static final int MAX_ROOT_DIGITS = 7;

	private static long fnsCounter = 0;
	private static TreeMap<Long, Long> fnsToIndex = new TreeMap<Long, Long>();
	
	public static void main(String[] args) {
		Scanner sc = null;
		BufferedWriter out = null;

		try {
			sc = new Scanner(new File(IN_DIR + "/" + IN_FILE));
			out = new BufferedWriter(new FileWriter(OUT_DIR + "/" + OUT_FILE));
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		preComputeFns(MAX_ROOT_DIGITS);
		
/*		for (Map.Entry<Long, Long> entry: fnsToIndex.entrySet()) {
			System.out.println(entry.getKey() + " : " + entry.getValue());
		} */
		
		int numTests = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < numTests; i++) {
			try {
				handleTest(sc, out, i+1);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		// clean up
		try {
			sc.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void preComputeFns(int maxRootDigits) {
		for (int digs = 1; digs <= maxRootDigits; digs++) {
			if (digs % 2 == 0) {
				int half = digs / 2;
				long start = longExp(10, half - 1);
				long end = start * 10 - 1;
				for (long next = start; next <= end; next++) {
					String leftHalf = Long.toString(next);
					char[] rightHalfArr = new char[half];
					for (int i = 0; i < half; i++) {
						rightHalfArr[i] = leftHalf.charAt(half - 1 - i);
					}
					String strNum = leftHalf + new String(rightHalfArr);
					long longSq = longExp(Long.parseLong(strNum), 2);
					if (isPalindrome(longSq)) {
						fnsToIndex.put(longSq, fnsCounter++);
						//System.out.println("fns: " + longSq);
					}
				}
			} else if (digs == 1) {
				for (long i = 1; i <= 9; i++) {
					long longSq = longExp(i, 2);
					if (isPalindrome(longSq)) {
						fnsToIndex.put(longSq, fnsCounter++);
						//System.out.println("fns: " + longSq);
					}
				}
			} else {
				int half = digs / 2;
				long start = longExp(10, half - 1);
				long end = start * 10 - 1;
				for (long next = start; next <= end; next++) {
					String leftHalf = Long.toString(next);
					char[] rightHalfArr = new char[half + 1];
					for (int i = 1; i <= half; i++) {
						rightHalfArr[i] = leftHalf.charAt(half - i);
					}
					for (char mid = '0'; mid <= '9'; mid++) {
						rightHalfArr[0] = mid;
						String strNum = leftHalf + new String(rightHalfArr);
						long longSq = longExp(Long.parseLong(strNum), 2);
						if (isPalindrome(longSq)) {
							fnsToIndex.put(longSq, fnsCounter++);
							//System.out.println("fns: " + longSq);
						}
					}
				}
			}
		}
	}

	private static void handleTest(Scanner sc, BufferedWriter out, int caseNum) throws IOException {
		long left = sc.nextLong();
		long right = sc.nextLong();
		
		Map.Entry<Long, Long> lEntry = fnsToIndex.ceilingEntry(left);
		if (lEntry == null) {
			out.write("Case #" + caseNum + ": 0\n");
			return;
		}
		Map.Entry<Long, Long> rEntry = fnsToIndex.floorEntry(right);
		if (rEntry == null) {
			out.write("Case #" + caseNum + ": 0\n");
			return;
		}
		
		long result = rEntry.getValue() - lEntry.getValue() + 1;
		out.write("Case #" + caseNum + ": " + result + '\n');
	}
	
	private static long longExp(long num, int pow) {
		long result = 1;
		// optimize
		for (int i = 0; i < pow; i++) {
			result *= num;
		}
		
		return result;
	}
	
	private static boolean isPalindrome(long longSq) {
		String str = Long.toString(longSq);
		int len = str.length();
		int hlen = len/2;
		for (int i = 0; i < hlen; i++) {
			if (str.charAt(i) != str.charAt(len - 1 - i)) {
				return false;
			}
		}

		return true;
	}
}
