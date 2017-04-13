package gcj2009.round1c.problemC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solver {

	/** Parameter class */
	public static class Case {
		public int n_p;

		public int n_q;

		// Prisoners to be released
		public List<Integer> ps;

		public Case(int n_p, int n_q, List<Integer> ps) {
			this.n_p = n_p;
			this.n_q = n_q;
			this.ps = ps;

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

			String[] tokens;
			tokens = line.split(" ");

			int n_p = Integer.parseInt(tokens[0]);
			int n_q = Integer.parseInt(tokens[1]);

			line = br.readLine().trim();
			tokens = line.split(" ");

			List<Integer> ps = new ArrayList<Integer>();
			for (int j = 0; j < n_q; j++) {
				
				int pp = Integer.parseInt(tokens[j]);
				ps.add(Integer.valueOf(pp-1)  );
			}
			Collections.sort(ps);

			Case c = new Case(n_p, n_q, ps);
			cases.add(c);
		}
	}

	/** solve 
	 * @throws IOException */
	public void solve() throws IOException {
		int nCase = 0;
		for (Case case_ : this.cases) {
			nCase++;
			int n_p = case_.n_p;
			int n_q = case_.n_q;

			// Very Vey Simple Solution

			List<List<Integer>> candidates = permGenInner(case_.ps);

			long min = -1;
			for (List<Integer> candidate : candidates) {
				List<Boolean> room = new ArrayList<Boolean>();

				// Init
				for (int i = 0; i < n_p; i++) {
					room.add(Boolean.TRUE);
				}
				System.out.println("Can" + candidate);

				long sum = 0;
				for (Integer release : candidate) {
					sum = sum + this.calcBribe(room, release);
					System.out.println("   Sum : " + sum);
					room.set(release, Boolean.FALSE);
				}

				if (min == -1) {
					min = sum;
				}

				if (min > sum) {
					min = sum;
				}
			}

			String outStr = String.format("Case #%d: %d\n", nCase, min);
			System.out.println(outStr);
			bw.write(outStr);
		}
	}

	private long calcBribe(List<Boolean> room, int release) {
		int nRooms = room.size();
		long sum = 0;
		for (int i = release + 1; i < nRooms; i++ ){
			if (room.get(i).equals(Boolean.FALSE)) {
				// empty
				break;
			}
			sum++;
		}
		System.out.println("S"+sum +"  " + nRooms);
		for (int i = release - 1; i >= 0; i-- ){
			if (room.get(i).equals(Boolean.FALSE)) {
				// empty
				break;
			}
			sum++;
		}
		System.out.println("S"+sum);
		
		
		
		return sum;
	}

	public static void main(String[] args) throws Exception {

		List<Integer> list = new ArrayList<Integer>();
		list.add(6);
		list.add(5);
		list.add(4);
		list.add(3);

		System.out.println("-----------");
		System.out.println(list);
		for (List<Integer> comb : permGenInner(list)) {
			System.out.println(comb);
		}

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

	public static <T> List<List<T>> permGenInner(List<T> list) {
		List<List<T>> ret = new ArrayList<List<T>>();

		if (list.size() == 1) {
			ret.add(list);
			return ret;
		}

		for (int i = 0; i < list.size(); i++) {
			// Head
			T head = list.get(i);

			// Tail
			List<T> tail = new ArrayList<T>(list);
			tail.remove(i);

			for (List<T> restResult : permGenInner(tail)) {
				// Insert before
				restResult.add(0, head);
				ret.add(restResult);
			}
		}
		return ret;
	}

}
