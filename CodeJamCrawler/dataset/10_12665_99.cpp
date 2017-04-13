import java.io.*;
import java.math.*;
import java.util.*;

public class CodeJam {
	public static void main(String[] args) throws IOException {
			System.setIn(new FileInputStream(new File(
					"C:/Users/Tyler Sun/Documents/CodeJam/CodeJam/Qual/input.txt")));
			PrintStream ps = new PrintStream(new File(
					"C:/Users/Tyler Sun/Documents/CodeJam/CodeJam/Qual/output.txt"));
			System.setOut(ps);
			new CodeJam().runit();
			ps.flush();
			ps.close();
			return;
	}

	BufferedReader in;
	private StringTokenizer st;
	PrintWriter out;

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}


	void runCase(int caseNum) throws IOException {
		int N = nextInt();
		List<BigInteger> ts = new ArrayList<BigInteger>();
		Set<BigInteger> mark = new HashSet<BigInteger>();
		
		for (int i = 0; i < N; ++i) {
			String s = next();
			BigInteger n = new BigInteger(s);
			if (mark.contains(n))
				continue;
			mark.add(n);
			ts.add(n);
			//out.println(n.toString());
		}
		
		
		
		BigInteger rr = BigInteger.valueOf(0);
		if (ts.size() >= 2) {
			BigInteger m = ts.get(0).subtract(ts.get(1)).abs();
			for (int i = 0; i < ts.size(); ++i) {
				//out.println(m.toString());
				for (int j = i + 1; j < ts.size(); ++j) {
					m = m.gcd(ts.get(i).subtract(ts.get(j)).abs());
				}
				
			}
			//out.println(m.toString());
			rr = m.subtract(ts.get(0).mod(m));
			if (rr.equals(m))
				rr = BigInteger.valueOf(0);
//			for (int i = 0; i < ts.size(); ++i) {
//				BigInteger mm = ts.get(i).mod(m);
//				if (rr.compareTo(m.subtract(mm)) < 0) {
//					rr = m.subtract(mm);
//				}
//			}
		}		
		out.print("Case #");
		out.print(caseNum);
		out.print(": ");
		out.println(rr.toString());
	}

	void runit() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		st = new StringTokenizer("");

		int N = nextInt();
		for (int i = 0; i < N; i++) {
			runCase(i + 1);
		}

		out.flush();
	}

}
