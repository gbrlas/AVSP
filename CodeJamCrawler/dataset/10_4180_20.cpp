package codejam2010.qualification;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigInteger;

public class SnapperChain {

	public static void main(String[] args) throws Exception {
		InputFile input = new InputFile(new BufferedReader(new InputStreamReader(System.in)));
		int T = input.nextInt();
		for (int testCase=1; testCase<=T; testCase++) {
			int n = input.nextInt();
			int k = input.nextInt();
			
//			System.out.println("Initial:");
			BigInteger switchState = BigInteger.ZERO;
//			System.out.printf("\tSwitch state: %s\n", pad(switchState.longValue(), n));
			BigInteger powerState = BigInteger.ONE;
//			System.out.printf("\tPower state:  %s\n", pad(powerState.longValue(), n));
			boolean on = false;
//			System.out.printf("\tLight state:  %s\n", on);
			
			for (int snap=1; snap<=k; snap++) {
//				System.out.printf("After snap %d:\n", snap);
				switchState = switchState.xor(powerState);
//				System.out.printf("\tSwitch state: %s\n", pad(switchState.longValue(), n));
				int lowestClearBit = switchState.not().getLowestSetBit();
//				System.out.printf("\tlowest clear bit: %d\n", lowestClearBit);
				powerState = BigInteger.valueOf((1<<(lowestClearBit+1))-1).or(BigInteger.ONE);
//				System.out.printf("\tPower state:  %s\n", pad(powerState.longValue(), n));
				on = powerState.testBit(n-1) && switchState.testBit(n-1);
//				System.out.printf("\tLight state:  %s\n", on);
			}
			
			System.out.printf("Case #%d: %s\n", testCase, (on ? "ON" : "OFF"));
		}
	}
	
	private static String pad(long n, int len) {
		StringBuilder sb = new StringBuilder(Long.toString(n, 2));
		while (sb.length() < len) {
			sb.insert(0, '0');
		}
		return sb.toString();
	}
	
	static class InputFile {
		
		private StreamTokenizer st;
		
		public InputFile(Reader r) {
			st = new StreamTokenizer(r);
		}
		
		public int nextInt() throws IOException {
			st.nextToken();
			return (int) st.nval;
		}
	}
	
}
