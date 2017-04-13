import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.Vector;


public class FairWarning {
	
	public static BigInteger zero = new BigInteger("0");
	
	public static BigInteger computeGCD(BigInteger a, BigInteger b) {
		while (!b.equals(zero)) {
			BigInteger t = b;
			b = a.mod(b);
			a = t;
		}
		return a;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		int C = 0;
		BufferedReader br = new BufferedReader(new FileReader("C:\\in\\FairWarning.in"));
		C = Integer.parseInt(br.readLine());
		for (int i = 0; i < C; i++) {
			String[] tokens = br.readLine().split(" ");
			int N = Integer.parseInt(tokens[0]);
			BigInteger[] events = new BigInteger[N];
			for (int j = 0; j < N; j++) {
				events[j] = new BigInteger(tokens[j + 1]);
			}
			Arrays.sort(events);
			Vector<BigInteger> timeBeetwenEvents = new Vector<BigInteger>();
			for (int j = N - 1; j > 0; j--) {
				timeBeetwenEvents.add(events[j].subtract(events[j - 1]));
			}
			BigInteger gcd = timeBeetwenEvents.get(0); 
			for (int j = 1; j < timeBeetwenEvents.size(); j++) {
				gcd = computeGCD(gcd, timeBeetwenEvents.get(j));
			}
			BigDecimal lastEvent = new BigDecimal(events[0]);
			
			
			BigDecimal multipler = lastEvent.divide(new BigDecimal(gcd), RoundingMode.CEILING);
			BigDecimal answer = new BigDecimal(gcd).multiply(multipler).subtract(lastEvent);
			System.out.println("Case #" + (i + 1) + ": " + answer);
		}
	}

}
