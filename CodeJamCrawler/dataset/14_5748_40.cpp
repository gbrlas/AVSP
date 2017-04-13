import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
	    int n = in.nextInt();
	    int xx = in.nextInt();
	    int[] l1 = in.nextIntArray(n);
	    Arrays.sort(l1);
		boolean[] used = new boolean[n];
	    int ptr = l1.length - 1;
	    int ans = 0;
	    for (int i=  0 ; i < l1.length; i++){
		    if (used[i]) continue;
		    for (;ptr >= 0; ptr--){
			    if (used[ptr]) continue;
			    if (l1[ptr] + l1[i] <= xx){
				    used[ptr] = true;
				    break;
			    }
		    }
		    used[i] = true;
		    ans++;

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

