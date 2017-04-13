package cw.codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

class Lang_A {
	static Map<Character, Character> staticMapping = new LinkedHashMap<>();
	static {
		staticMapping.put('a', 'y');
		staticMapping.put('z', 'q');

		// error?
		staticMapping.put('o', 'k');
		
		// discovered missing
		staticMapping.put('q', 'z');

		// given
		staticMapping.put('f', 'c');
		staticMapping.put('g', 'v');
		staticMapping.put(' ', ' ');
		staticMapping.put('d', 's');
		staticMapping.put('e', 'o');
		staticMapping.put('b', 'h');
		staticMapping.put('c', 'e');
		staticMapping.put('n', 'b');
		staticMapping.put('l', 'g');
		staticMapping.put('m', 'l');
		staticMapping.put('j', 'u');
		staticMapping.put('k', 'i');
		staticMapping.put('h', 'x');
		staticMapping.put('i', 'd');
		staticMapping.put('w', 'f');
		staticMapping.put('v', 'p');
		staticMapping.put('u', 'j');
		staticMapping.put('t', 'w');
		staticMapping.put('s', 'n');
		staticMapping.put('r', 't');
		staticMapping.put('p', 'r');
		staticMapping.put('y', 'a');
		staticMapping.put('x', 'm');
	}

	public static void main(String[] args) {
		File infile = new File(args[0]);
		discoverMappings();
		parseInput(infile);
	}

	static void parseInput(File infile) {
		File outfile = new File(infile.getParent(), "a.lang.out.txt");
		try (Scanner scanner = new Scanner(infile)) {
			try (BufferedWriter bw = new BufferedWriter(new FileWriter(outfile))) {
				int numCases = Integer.parseInt(scanner.nextLine());
				for (int i = 0; i < numCases; i++) {

					String inputline = scanner.nextLine();
					StringBuffer mappedLine = new StringBuffer();
					for (char c : inputline.toCharArray()) {
						mappedLine.append(staticMapping.get(c));
					}
					bw.write(String.format("Case #%d: %s\n", i + 1,
							mappedLine.toString()));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static void discoverMappings() {
		Map<String, String> samples = new HashMap<>();
		samples.put("ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"our language is impossible to understand");
		samples.put("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"there are twenty six factorial possibilities");
		samples.put("de kr kd eoya kw aej tysr re ujdr lkgc jv",
				"so it is okay if you want to just give up");

		// build mapping from example
		for (String srtIn : samples.keySet()) {
			String strOut = samples.get(srtIn);

			for (int i = 0; i < srtIn.length(); i++) {
				char charIn = srtIn.charAt(i);
				char charOut = strOut.charAt(i);
				Character prevChar = staticMapping.put(charIn, charOut);
				if (prevChar != null && prevChar != charOut) {
					System.out.println(String.format("THIS IS BAD: %c, %c, %c", charIn, prevChar, charOut));
				}
			}
		}

		/*
		 * //find missing mapping key for(int i=97; i<123; i++){ char c =
		 * (char)i; if(!staticMapping.containsKey(c)){
		 * System.out.println("found a missing mapping key: " + c); }
		 * 
		 * if(!staticMapping.containsValue(c)){
		 * System.out.println("found a missing mapping value:" + c); } }
		 */
		// format mappings
		for (Entry<Character, Character> entry : staticMapping.entrySet()) {
			System.out.println(String.format("staticMappings.put('%c', '%c');",
					entry.getKey(), entry.getValue()));
		}
		//System.out.println(staticMapping.size());
	}
}
