import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ProblemC {

	private static final String INPUT = "d:/c-large.in";

	private static final String OUTPUT = "d:/c.out";

	private static int readInt(BufferedReader reader) throws IOException {
		return Integer.parseInt(reader.readLine());
	}

	private static int[] readInts(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		String[] tokens = line.split(" ");
		int[] result = new int[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			result[i] = Integer.parseInt(tokens[i]);
		}
		return result;
	}
	
	private static class Pair {
		int begin;
		int end;
		int v;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				new FileInputStream(INPUT)));
		PrintWriter writer = new PrintWriter(new OutputStreamWriter(
				new FileOutputStream(OUTPUT)));
		int t = readInt(reader);
		for (int i = 0; i < t; i++) {
			int[] tmp = readInts(reader);
			System.out.println(i);
			int R = tmp[0];
			int k = tmp[1];
			int N = tmp[2];
			int[] g = readInts(reader);
			List<Pair> pairs = new ArrayList<Pair>();
			int ptr = 0;
			int shift = -1;
			while (true) {
				System.out.println(pairs.size());
				int begin = ptr, v = 0, count = 0;
				while (v + g[ptr] <= k && count < N) {
					v += g[ptr];
					ptr++;
					count++;
					if (ptr >= N)
						ptr = 0;
					
				}
				Pair pair = new Pair();
				pair.begin = begin;
				pair.end = ptr;
				pair.v = v;
				int q = -1;
				for (int j = 0; j < pairs.size(); j++) {
					Pair rp = pairs.get(j);
					if (rp.begin == pair.begin && rp.end == pair.end) {
						q = j;
					}
				}
				if (q == -1) {
					pairs.add(pair);
				} else {
					shift = q;
					break;
				}
			}
			R = R - shift;
			long total = 0;
			for (int j = 0; j < shift; j++) {
				total += pairs.get(j).v;
			}
			
			List<Pair> w = new ArrayList<Pair>();
			long round = 0;
			for (int j = shift; j < pairs.size(); j++) {
				w.add(pairs.get(j));
				round += pairs.get(j).v;
			}
			
			int m = w.size();
			total += round * (R / m);
			int x = R % m;
			for (int j = 0; j < x; j++) {
				total += w.get(j).v;
			}
			writer.println("Case #" + (i + 1) + ": " + total);
		}
		writer.close();
		reader.close();
	}
}
