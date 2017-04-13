import java.io.File;
import java.io.IOException;
import java.math.BigDecimal;
import java.net.URISyntaxException;
import java.text.DecimalFormat;
import java.util.List;

import org.apache.commons.io.FileUtils;
import org.apache.commons.lang.StringUtils;

public class CJ2008Round1A_C {
	DecimalFormat d = new DecimalFormat(
			"00.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

	static BigDecimal tresmaisraizcinco;
	static {
		BigSquareRoot sr = new BigSquareRoot();
		sr.setScale(1000);
		BigDecimal tres = new BigDecimal(3);
		tresmaisraizcinco = tres.add(sr.get(new BigDecimal(5)));
	}

	public String resolv() {
		int n = Integer.valueOf(input.get(pos++));

		String s = d.format(tresmaisraizcinco.pow(n));
		System.out.println(s);
		String s2 = StringUtils.substringBefore(s, ".");
		return StringUtils.leftPad(StringUtils.right(s2, 3), 3, "0");
	}

	// * prepared stuff ----------------------------------------------
	public String solve() {
		String result = "";
		int cases = Integer.valueOf(input.get(pos++));
		for (int i = 0; i < cases; i++) {
			result += "Case #" + (i + 1) + ": " + resolv() + "\n";
		}
		return result;
	}

	List<String> input;

	int pos = 0;

	public CJ2008Round1A_C(List<String> input) {
		this.input = input;
	}

	private static List<String> input(String s) throws URISyntaxException, IOException {
		return FileUtils.readLines(new File(s), null);
	}

	public static void main(String[] args) throws Exception {
		File f = new File("C-small.out");
		String output = new CJ2008Round1A_C(input("C-small.in")).solve();
		FileUtils.writeStringToFile(f, output, null);
	}

}
