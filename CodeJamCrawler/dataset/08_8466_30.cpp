import java.io.File;
import java.io.IOException;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import org.apache.commons.io.FileUtils;

public class CJ2008Round1A_A {

	public String resolv() {
		long res = 0;
		int size = Integer.valueOf(input.get(pos++));
		String vet1 = input.get(pos++);
		String vet2 = input.get(pos++);

		StringTokenizer t1 = new StringTokenizer(vet1);
		List<Long> v1 = new ArrayList<Long>();
		while (t1.hasMoreElements()) {
			v1.add(new Long(t1.nextToken()));
		}
		Collections.sort(v1);

		StringTokenizer t2 = new StringTokenizer(vet2);
		List<Long> v2 = new ArrayList<Long>();
		while (t2.hasMoreElements()) {
			v2.add(new Long(t2.nextToken()));
		}
		Collections.sort(v2);

		for (int i = 0; i < size; i++) {
			res += v1.get(i) * v2.get(size - i - 1);
		}
		return String.valueOf(res);
	}

	// * prepared stuff ----------------------------------------------
	public String solve() {
		String result = "";
		long cases = Long.valueOf(input.get(pos++));
		for (long i = 0; i < cases; i++) {
			result += "Case #" + (i + 1) + ": " + resolv() + "\n";
		}
		return result;
	}

	List<String> input;

	int pos = 0;

	public CJ2008Round1A_A(List<String> input) {
		this.input = input;
	}

	private static List<String> input(String s) throws URISyntaxException, IOException {
		return FileUtils.readLines(new File(s), null);
	}

	public static void main(String[] args) throws Exception {
		File f = new File("A-large.out");
		String output = new CJ2008Round1A_A(input("A-large.in")).solve();
		FileUtils.writeStringToFile(f, output, null);
	}
}
