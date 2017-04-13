import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SpeakingInTongues {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		InputStream ips = null;
		try {
			ips = new FileInputStream("sit.txt");
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
		if (ips != null) {
			InputStreamReader ipsr = new InputStreamReader(ips);
			BufferedReader br = new BufferedReader(ipsr);
			String line = null;
			int nbLines = 1;
			boolean firstLine = true;
			List<String> textInGooglerese = new ArrayList<String>();

			try {
				while ((line = br.readLine()) != null && nbLines > 0) {
					if (firstLine) {
						nbLines = Integer.parseInt(line);
						firstLine = false;
					} else {
						textInGooglerese.add(line);
					}
				}

				br.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}

			List<String> textInEnglish = translate(textInGooglerese);

			printText(textInEnglish);
		}

	}

	private static Map<String, String> getConvertMap() {
		Map<String, String> convertMap = new HashMap<String, String>();
		convertMap.put("a", "y");
		convertMap.put("b", "h");
		convertMap.put("c", "e");
		convertMap.put("d", "s");
		convertMap.put("e", "o");
		convertMap.put("f", "c");
		convertMap.put("g", "v");
		convertMap.put("h", "x");
		convertMap.put("i", "d");
		convertMap.put("j", "u");
		convertMap.put("k", "i");
		convertMap.put("l", "g");
		convertMap.put("m", "l");
		convertMap.put("n", "b");
		convertMap.put("o", "k");
		convertMap.put("p", "r");
		convertMap.put("q", "z");
		convertMap.put("r", "t");
		convertMap.put("s", "n");
		convertMap.put("t", "w");
		convertMap.put("u", "j");
		convertMap.put("v", "p");
		convertMap.put("w", "f");
		convertMap.put("x", "m");
		convertMap.put("y", "a");
		convertMap.put("z", "q");
		convertMap.put(" ", " ");
		return convertMap;
	}

	private static void printText(List<String> textInEnglish) {
		int size = textInEnglish.size();
		for (int i = 0; i < size; i++) {
			System.out.println("Case #" + (i+1) + ": " + textInEnglish.get(i));
		}
	}

	private static List<String> translate(List<String> textInGooglerese) {
		List<String> textInEnglish = new ArrayList<String>();
		for (String s : textInGooglerese) {
			textInEnglish.add(translate(s));
		}
		return textInEnglish;
	}

	private static String translate(String s) {
		int stringSize = s.length();
		StringBuffer buf = new StringBuffer(stringSize);
		Map<String, String> convertMap = getConvertMap();
		for (int i = 0; i < stringSize; i++) {
			buf.append(convertMap.get(s.substring(i, i + 1)));
		}
		return buf.toString();
	}

}
