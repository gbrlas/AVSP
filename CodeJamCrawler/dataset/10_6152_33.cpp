import java.io.File;
import java.io.IOException;
import java.util.BitSet;
import java.util.Iterator;

import com.google.common.base.Charsets;
import com.google.common.base.Splitter;
import com.google.common.io.Files;
import com.google.common.io.LineProcessor;

/*
 Guava code is available at http://repo1.maven.org/maven2/com/google/guava/guava/r03/guava-r03.jar
 */

public class SnapperChain implements LineProcessor<Void> {

	public static void main( String[] args ) throws IOException {
		Files.readLines(new File(args[0]), Charsets.US_ASCII, new SnapperChain());
	}

	private long caseNumber = -1L;

	public boolean processLine(final String line) throws IOException {
		if (++caseNumber > 0) {
			Iterator<String> split = Splitter.on(' ').split(line).iterator();
			int n = Integer.parseInt(split.next());
			int k = Integer.parseInt(split.next());
			output(computeResult(n, k));
		}
		return true;
	}

	boolean computeResult(final int n, final int k) {
		final int bits = (1 << n) - 1;
		return bits == (bits & k);
	}

	public Void getResult() {
		return null;
	}

	private void output(boolean result) {
		System.out.format("Case #%s: %s%n", String.valueOf(caseNumber), (result ? "ON" : "OFF"));
	}
}
