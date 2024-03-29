package gcj.y2009.round1;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Problem1 {

	private Pattern pattern;

	public static class Parameter {
		public int l;
		public int d;
		public int n;

		public String[] words;
		public String[] patterns;

		public Parameter(int l, int d, int n, String[] words, String[] patterns) {
			this.l = l;
			this.d = d;
			this.n = n;
			this.words = words;
			this.patterns = patterns;
		}

	}

	public Parameter parseInput(String fileName, String encoding)
			throws Exception {

		BufferedReader br = null;

		InputStreamReader isr = null;
		FileInputStream fis = null;

		fis = new FileInputStream(fileName);
		isr = new InputStreamReader(fis, encoding);
		br = new BufferedReader(isr);

		int cnt = 0;
		int l = -1;
		int d = -1;
		int n = -1;
		String[] words = null;
		String[] patterns = null;

		String line;
		while ((line = br.readLine()) != null) {
			line = line.trim();

			if ("".equals(line)) {
				continue;
			}

			// Basic parameters
			if (cnt == 0) {
				// length of tokens
				l = Integer.parseInt(line.split(" ")[0]);
				// number of words
				d = Integer.parseInt(line.split(" ")[1]);
				// number of patterns
				n = Integer.parseInt(line.split(" ")[2]);

				words = new String[d];
				patterns = new String[n];
			}
			// words
			if ((cnt > 0) && (cnt <= d)) {
				words[cnt - 1] = line;
			}

			if (cnt > d) {

				line = line.replace('(', '[');
				line = line.replace(')', ']');
				patterns[cnt - d - 1] = line;
			}

			cnt++;
		}

		return new Parameter(l, d, n, words, patterns);

	}

	public void inspect(Parameter parameter) {
		for (int i = 0; i < parameter.n; i++) {

			this.pattern = Pattern.compile(parameter.patterns[i]);

			int cnt = 0;
			for (int j = 0; j < parameter.d; j++) {
				String word = parameter.words[j];
				Matcher matcher = pattern.matcher(word);
				if (matcher.matches()) {
					cnt++;
				}
			}
			System.out.println("Case #"+(i+1)+": "+cnt);
		}

	}

	public static void main(String[] args) throws Exception {

		if (args.length != 1) {
			System.out.println("Specify input");
			System.exit(1);
		}

		String file = args[0];

		Problem1 p1 = new Problem1();

		Parameter parameter = p1.parseInput(file, "utf-8");

		p1.inspect(parameter);
	}
}
