package gcj2009.round1c.problemB;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Solver {

	/** Parameter class */
	public static class Case {
		double[][] v;

		double[][] x;

		double[] c_x = new double[3];

		double[] c_v = new double[3];

		int nFlies;

		public Case(int nFlies) {
			this.nFlies = nFlies;
			v = new double[nFlies][3];
			x = new double[nFlies][3];

			// Init center
			for (int i = 0; i < 3; i++) {
				this.c_x[i] = 0.0;
				this.c_v[i] = 0.0;
			}
		}

		public void set(int fly_ind, String[] fields) {

			for (int i = 0; i <= 2; i++) {
				double d = Double.parseDouble(fields[i]);
				this.x[fly_ind][i] = d;
			}

			for (int i = 3; i <= 5; i++) {
				double d = Double.parseDouble(fields[i]);
				this.v[fly_ind][i - 3] = d;
			}

		}

		public void set_senter() {

			for (int j = 0; j <= 2; j++) {
				for (int i = 0; i < this.nFlies; i++) {
					this.c_v[j] = this.c_v[j] + this.v[i][j];
					this.c_x[j] = this.c_x[j] + this.x[i][j];
				}

				this.c_v[j] = this.c_v[j] / ((double) this.nFlies);
				this.c_x[j] = this.c_x[j] / ((double) this.nFlies);

			}
			// print 
			System.out.println("center _ x");
			for (int j = 0; j <= 2; j++) {
				System.out.print(this.c_x[j] + " ");
			}
			System.out.println("\n");
			// print 
			System.out.println("center _ v");
			for (int j = 0; j <= 2; j++) {
				System.out.print(this.c_v[j] + " ");
			}
			System.out.println("\n");
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

			int nFlies = Integer.parseInt(line);

			Case c = new Case(nFlies);

			for (int j = 0; j < nFlies; j++) {
				line = br.readLine().trim();

				String[] fields = line.split(" ");

				if (fields.length != 6) {
					throw new RuntimeException();
				}

				c.set(j, fields);
			}

			c.set_senter();
			cases.add(c);
		}
	}

	/** solve */
	public void solve() throws IOException {
		double err = 1.0e-5;
		int caseNum = 1;
		for (Case c : this.cases) {
			// first order
			double coef_1 = 0.0;
			// 0th order
			double coef_0 = 0.0;

			for (int i = 0; i <= 2; i++) {
				coef_1 = coef_1 + c.c_v[i] * c.c_v[i];
			}
			for (int i = 0; i <= 2; i++) {
				coef_0 = coef_0 + c.c_v[i] * c.c_x[i];
			}

			double d_min_t = 0.0;
			if (coef_1 > err) {
				d_min_t = -coef_0 / coef_1;
			}
			
			
			if (d_min_t < 0) {
				d_min_t = 0.0;
			}
			
			double[] x1 = new double[3];
			for (int i = 0; i < 3; i++) {
				x1[i] = 0.0;
			}

			
			for (int i = 0; i < 3; i++) {
				x1[i] = c.c_x[i] + c.c_v[i] * d_min_t;
			}

			double d = 0.0;
			for (int i = 0; i < 3; i++) {
				d = d + (x1[i] * x1[i]);
			}

			d = Math.sqrt(d);

			String outStr = (String.format("Case #%d: %1.8f %1.8f\n", caseNum,
					d, d_min_t));
			caseNum++;
			System.out.println(outStr);
			bw.write(outStr);

			//			
		}

	}

	public static void main(String[] args) throws Exception {


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
