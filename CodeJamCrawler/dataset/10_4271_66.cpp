import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {

	final static String FNAME = "B-small-attempt0";
	final static BigInteger bZero = new BigInteger("0");

	public StringTokenizer in;

	public PrintWriter out;

	void open() throws IOException {
		BufferedReader b = new BufferedReader( new FileReader( new File( FNAME + ".in" )));
		String line = b.readLine();
		String res = " ";
		while (line != null) {
			line = line.trim();
			res += line + " "; 
			line = b.readLine();
		}
		
		in = new StringTokenizer(res);
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(in.nextToken());
	}
	
	BigInteger nextBInt() throws IOException {
		return new BigInteger(in.nextToken());
	}
	
	BigInteger gcd (BigInteger a, BigInteger b) {
		if (a.equals(bZero)) {
			return b;
		}
		b = b.remainder(a);
		return gcd(b, a);
	}

	void run() throws IOException {
		int tn = nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			int n = nextInt();
			BigInteger [] b = new BigInteger[n];
			for (int i = 0; i < n; ++i) {
				b[i] = nextBInt();
			}
			Arrays.sort(b);
			BigInteger res = bZero;
			for (int i = 0; i < b.length - 1; ++i) {
				res = gcd(res, b[i + 1].subtract(b[i])); 
			}
			BigInteger prev = b[0].remainder(res);
			if (!prev.equals(bZero)) {
				prev = res.subtract(prev);
			}
			
			out.println( "Case #" + test + ": " + prev.toString());
		}
	}

	public static void main( String[] args ) throws IOException {
		new Thread() {

			public void run() {
				try {
					Main solution = new Main();
					solution.open();
					solution.run();
					solution.close();
				} catch ( Exception e ) {
					throw new RuntimeException( e );
				}
			}
		}.start();
	}
}
