import java.util.*;
import java.io.*;
import java.math.*;

class A {
    static Scanner scanner;

    public static void main(String args[]) {
	scanner = new Scanner(System.in);

	int cases = scanner.nextInt();

	for (int i=0; i<cases; i++) {
	    String ans = single();
	    System.out.printf("Case #%d: %s\n", i+1, ans);
	}
    }

    static BigInteger gcd(BigInteger a, BigInteger b) {
	BigInteger c;

	while (!b.equals(BigInteger.ZERO)) {
	    c = a.remainder(b);
	    a = b;
	    b = c;
	}

	return a;
    }

    static String single() {
	int N;
	N = scanner.nextInt();
	String tn;
	BigInteger[] T = new BigInteger[N];
	BigInteger[] D = new BigInteger[N-1];

	for (int i=0; i<N; i++) {
	    tn = scanner.next();
	    T[i] = new BigInteger(tn);
	}

	Arrays.sort(T, new Cmp());

	for (int i=0; i<N-1; i++) {
	    D[i] = T[i+1].subtract(T[i]);
	}

	Arrays.sort(D, new Cmp());

	BigInteger m = D[N-2];

	for (int i=N-3; i>=0; i--) {
	    m = gcd(m, D[i]);
	}

	if (m.equals(BigInteger.ZERO)) return "0";
	return m.subtract(T[0].remainder(m)).remainder(m).toString();
    }
}

class Cmp implements Comparator {
    public int compare(Object a, Object b) {
	return ((BigInteger)a).compareTo((BigInteger)b);
    }    
}