import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ArbitraySubstrings {

	//private static BigInteger recursionCount = new BigInteger("0");
//	private static int overflowCount = 0;

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {

		System.out.println(Arrays.toString(args));
		String inputFileName = args[0];
		String outputFileName = args[1];

		Scanner scanner = new Scanner(new File(inputFileName));

		FileWriter fileWriter = new FileWriter(new File(outputFileName));
		BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
		PrintWriter printWriter = new PrintWriter(bufferedWriter);

		int nTestCases = scanner.nextInt();
		scanner.nextLine();
		System.out.println("# of Test Cases:" + nTestCases);

		String testCase = null;
		String cappedCount = null;
		for (int k = 0; k < nTestCases; k++) {
			//recursionCount = new BigInteger("0");
			testCase = scanner.nextLine();
			System.out.println("Test Case:" + testCase);
			// int count = countArbitrarySubstrings(testCase,"welcome to code jam", 0);
			int count = countArbitrarySubstrings(testCase, "welcome to code jam");
			// int count = countArbitrarySubstrings(testCase, "wel");
			cappedCount = formatCountArbitrarySubstrings(count);
			//System.out.println("recursionCount:" + recursionCount);
			System.out.println("Case #" + (k + 1) + ": " + cappedCount);
			printWriter.println("Case #" + (k + 1) + ": " + cappedCount);
		}

		printWriter.close();

	}

	// private static int countArbitrarySubstrings(String testCase, String
	// target, int count) {
	//
	// recursionCount = recursionCount.add(new BigInteger("1"));
	//
	// int module = 0;
	// if ((module = recursionCount.mod(new BigInteger("100000")).intValue()) ==
	// 0 && recursionCount.intValue() != 0) {
	// System.out.println(recursionCount);
	// } else {
	// // System.out.println(recursionCount + " - " + target);
	// }
	//
	// if (target.length() > 0) {
	// if (testCase.length() > 0) {
	//
	// int pointer = testCase.indexOf(target.charAt(0));
	// while (pointer != -1) {
	//							
	// count = countArbitrarySubstrings(testCase.substring(pointer + 1),
	// target.substring(1), count);
	// pointer = testCase.indexOf(target.charAt(0),pointer + 1);
	//					
	// }
	//
	// }
	// } else {
	//			
	// count = rollingIncrement(count, 10000);
	//
	// }
	//
	// return count;
	//
	// }

	private static int countArbitrarySubstrings(String testCase, String target) throws Exception {
		
//		HashMap<String,String> ocurrencies = new HashMap<String,String>();

		int count = 0;
		int targetLength = target.length();
		int[] pointerTargetTestCase = new int[targetLength];

		int pointerTarget = 0;
		int pointerTestCase = 0;

		while (pointerTarget != -1) {
			
			//System.out.println("pointerTarget: " + pointerTarget);

			pointerTargetTestCase[pointerTarget] = testCase.indexOf(target.charAt(pointerTarget), pointerTestCase);

			while (pointerTarget < targetLength && pointerTargetTestCase[pointerTarget] != -1) {
				
				pointerTestCase = pointerTargetTestCase[pointerTarget] + 1;
				pointerTarget++;
				if (pointerTarget < targetLength) {
					pointerTargetTestCase[pointerTarget] = testCase.indexOf(target.charAt(pointerTarget), pointerTestCase);
				}

			}

			pointerTarget--;

			if (pointerTarget == targetLength - 1) {
//				String key = ocurrencies.put(Arrays.toString(pointerTargetTestCase),"");
//				if(key != null) {
//					throw new Exception("Duplicated String");
//				}
				count = rollingIncrement(count, 10000);
			} else {
				if (pointerTarget > -1) {
					pointerTestCase = pointerTargetTestCase[pointerTarget] + 1;
				}
			}


		}
		
		//System.out.println("pointerTarget: " + pointerTarget);

		return count;

	}

	private static int rollingIncrement(int count, int overflow) {
		if (count < overflow) {
			count++;
		} else {
//			overflowCount++;
//			System.out.println("overflowCount: " + overflowCount);
			count = 0;
		}

		return count;
	}

	private static String formatCountArbitrarySubstrings(int count) {

		return String.format("%04d", count);

	}

}
