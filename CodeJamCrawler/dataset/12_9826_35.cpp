package code.jam.quali;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class Googlerese {

	private static final String in = "z q ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	private static final String out = "q z our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	private static final String al = "abcdefghijklmnopqrstuvwxyz";
	private HashMap<Character, Character> trans;
	private int count;
	private String[] lines;

	public static void main(String[] args) throws Exception {
		Googlerese g = new Googlerese();
		g.init();
		g.readFile();
		g.translate();

	}

	private void translate() {

		for (int i = 0; i < count; i++) {
			String line = lines[i];
			StringBuilder ls = new StringBuilder(line);
			StringBuilder result = new StringBuilder();
			for (int j = 0; j < ls.length(); j++) {
				result.append(trans.get(ls.charAt(j)));
			}

			System.out.println("Case #" + (i + 1) + ": " + result.toString());

		}

	}

	private void readFile() {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(new File(
					"D:/Martin/Downloads/test.in")));
			String line = null;
			line = br.readLine();
			count = Integer.valueOf(line.trim());
			lines = new String[count];
			int i = 0;
			while ((line = br.readLine()) != null) {
				lines[i] = line;
				i++;
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (br != null) {
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

	private void init() throws Exception {
		trans = new HashMap<>();
		StringBuilder inS = new StringBuilder(in);
		StringBuilder outS = new StringBuilder(out);
		for (int i = 0; i < inS.length(); i++) {
			// System.out.print(inS.charAt(i));
			char ic = inS.charAt(i);
			char oc = outS.charAt(i);
			Character curc = trans.get(ic);
			if (curc == null)
				trans.put(ic, oc);
			else if (curc != oc)
				throw new Exception("Error");
		}
		StringBuilder als = new StringBuilder(al);

		for (int i = 0; i < als.length(); i++) {
			if (!in.contains(String.valueOf(als.charAt(i))))
				System.out.println("in " + als.charAt(i));
			if (!out.contains(String.valueOf(als.charAt(i))))
				System.out.println("out " + als.charAt(i));

		}
	}

}
