import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;

public class Main {

	/**
	 * @param args
	 */
	
	
	static BigInteger gcd(BigInteger a, BigInteger b){
		if (a.compareTo(b) < 0){
			BigInteger temp = b;
			b = a;
			a = temp;
		}
		while (!b.equals(BigInteger.ZERO)){
			BigInteger temp = b;
			b = a.mod(b);
			a = temp;
		}
		return a;			
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger[] ts = new BigInteger[1001];
		BigInteger[] intevals = new BigInteger[1001];
        int c = in.nextInt();
        for(int i = 1; i <= c; ++i){
        	int N = in.nextInt();
        	for(int j = 0; j < N; ++j)
        		ts[j] = in.nextBigInteger();
        	Arrays.sort(ts, 0, N);
        	for(int j = 0; j < N-1; ++j)
        		intevals[j] = ts[j+1].subtract(ts[j]);
        	for (int j = N-3; j >=0; --j)
        		intevals[j] = gcd(intevals[j], intevals[j+1]);
        	BigInteger res = ts[0].mod(intevals[0]).equals(BigInteger.ZERO)  ? BigInteger.ZERO: 
        		ts[0].divide(intevals[0]).add(BigInteger.ONE).multiply(intevals[0]).subtract(ts[0]);
        	System.out.println("Case #" + Integer.toString(i)+ ": " + res.toString());
        }
	}

}
