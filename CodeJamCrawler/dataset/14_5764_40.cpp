import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Sheng Cao
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
	    int best = Integer.MAX_VALUE;
	    int n = in.nextInt();
	    int[] l1 = in.nextIntArray(n);
//	    DebugZ.print(l1);
	    int[] sorted = ArrayZ.sortUnique(l1);
	    for (int i = 0 ; i < l1.length; i++){
		    l1[i] = Arrays.binarySearch(sorted, l1[i]);
	    }
//	    DebugZ.print(l1);

	    int ans = 0;
	    for (int i = 0 ; i < n; i++){
		    int left = 0;
		    int right = 0;
		    boolean encountered = false;
		    for (int e : l1){
			    if (e > i){
				    if (!encountered) left++;
				    else right++;
			    }
			    if (e == i){
				    encountered = true;
			    }
		    }
		    ans += Math.min(left, right);
	    }

	    out.printLine("Case #" + testNumber + ": " + ans);
    }
}

class InputReader {
	private BufferedReader in = null;
	private StringTokenizer st = null;

	public InputReader(InputStream usingStream) {
		in = new BufferedReader(new InputStreamReader(usingStream));

	}
	public String next(){
		for (;st == null || !st.hasMoreTokens();){
			String currentLine = null;
			try {
				currentLine = in.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (currentLine == null) return null;
			st = new StringTokenizer(currentLine);
		}
		return st.nextToken();
	}
	public int nextInt(){
		return Integer.parseInt(next());
	}

	public int[] nextIntArray(int len){
		int[] fin = new int[len];
		for (int i = 0 ; i < len; i++){
			fin[i] = nextInt();
		}
		return fin;
	}
}

class OutputWriter {
	private PrintWriter usingPrintWriter = null;

	public OutputWriter(OutputStream usingStream){
		usingPrintWriter = new PrintWriter(usingStream);
	}
	public OutputWriter(Writer usingWriter){
		usingPrintWriter = new PrintWriter(usingWriter);
	}

	public void printLine(Object... l1){
		for (int i = 0;i < l1.length; i++){
			if (i != 0) usingPrintWriter.print(" ");
			usingPrintWriter.print(l1[i]);
		}
		usingPrintWriter.println();
	}
	public void flush(){
		usingPrintWriter.flush();
	}
	public void close(){
		flush();
		usingPrintWriter.close();
	}
}

class ArrayZ {
	public static int[] sortUnique(int[] l1) {
		int[] copy = l1.clone();
		Arrays.sort(copy);
		int size = 0;
		for (int i = 0; i < copy.length; i++) {
			if (i == 0 || copy[i] != copy[i - 1]) {
				copy[size++] = copy[i];
			}
		}
		return Arrays.copyOf(copy, size);
	}
}

