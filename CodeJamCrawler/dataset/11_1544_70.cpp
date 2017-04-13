import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	// combines strings <QF, T> and also <FQ, T>
	protected HashMap<String, String> combines;
	// contains <E,R> and <R,E>
	protected HashMap<Character, List<Character>> opposite;

	protected int nrInvoke;
	protected String invoke;

	public B(String line) {
		StringTokenizer tokenizer = new StringTokenizer(line, " ");

		// combines
		combines = new HashMap<String, String>();
		int nrCombines = Integer.parseInt(tokenizer.nextToken());
		for (int i = 0; i < nrCombines; i++) {
			String combine = tokenizer.nextToken();
			combines.put("" + combine.charAt(0) + combine.charAt(1), ""
					+ combine.charAt(2));
			combines.put("" + combine.charAt(1) + combine.charAt(0), ""
					+ combine.charAt(2));
		}

		// opposite
		opposite = new HashMap<Character, List<Character>>();
		int nrOpposite = Integer.parseInt(tokenizer.nextToken());
		for (int i = 0; i < nrOpposite; i++) {
			String strOpposite = tokenizer.nextToken();
			{
				Character key = strOpposite.charAt(0);
				if (!opposite.containsKey(key)) {
					opposite.put(key, new ArrayList<Character>());
				}
				opposite.get(key).add(strOpposite.charAt(1));
			}
			{
				Character key = strOpposite.charAt(1);
				if (!opposite.containsKey(key)) {
					opposite.put(key, new ArrayList<Character>());
				}
				opposite.get(key).add(strOpposite.charAt(0));
			}
		}

		// invoke
		nrInvoke = Integer.parseInt(tokenizer.nextToken());
		if (nrInvoke > 0) {
			invoke = tokenizer.nextToken();
		}

	}

	public String magica() {
		ArrayList<Character> result = new ArrayList<Character>();
		if (nrInvoke <= 0) {
			return result.toString();
		}

		String strResult = recurseMagica("", invoke);
		for (int i = 0; i < strResult.length(); i++) {
			result.add(strResult.charAt(i));
		}

		return result.toString();
	}

	public String combine(String elements) {
		if (elements.length() <= 1) {
			return elements;
		}
		
		Character current = elements.charAt(elements.length() - 1);
		String seq =  "" + elements.charAt(elements.length() - 2) + current;
		if (combines.containsKey(seq)) {
			String result = "";
			if (elements.length() > 2) {
				result = elements.substring(0, elements.length() - 2);
			} else {
				result = "";
			}
			return result + combines.get(seq);
		} else {
			return elements;
		}
	}
	
	public String opposite(String elements) { // get any sequence to replace, 
		// which has the last character in it.
		
		if (elements.length() <= 1) {
			return elements;
		}
		Character current = elements.charAt(elements.length() - 1);
		if (!opposite.containsKey(current)) {
			return elements;
		}
		List<Character> opposites = opposite.get(current);
		Iterator<Character> it = opposites.iterator();
		while (it.hasNext()) {
			Character c = (Character) it.next();
			int i = elements.indexOf(c);
			if (i < 0) {
				continue;
			}
			return "";
		}
		return elements;
	}
	
	public String reduce(String elements) {
		String result = elements;
		String resultTmp = null;
		do {
			resultTmp = result;
			result = combine(resultTmp);
		} while (!resultTmp.equals(result));
		
		resultTmp = result;
		result = opposite(resultTmp);
		
		return result;
	}
	
	public String recurseMagica(String invoked, String toInvoke) {
		if (toInvoke.isEmpty()) {
			return invoked;
		}
		
		Character current = toInvoke.charAt(0);
		
		String result = invoked + current;
		result = reduce(result);
		
		return recurseMagica(result, toInvoke.substring(1));
	}

	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile
				+ ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i = 1; i <= nrLines; i++) {
			String line = reader.readLine();
			String result = new B(line).magica();
			out.println("Case #" + i + ": " + result);
		}
		reader.close();
		out.close();
	}

}
