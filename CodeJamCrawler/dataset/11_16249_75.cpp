import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class QB {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int t = Integer.parseInt(r.readLine());
		Magicka mag;
		String s;
		for (int i = 0; i < t; i++) {
			s = r.readLine();
			mag = new Magicka(s);
			mag.invoke();
			pw.println("Case #" + (i + 1) + ": " + mag.toString());
		}
		pw.flush();
	}
}

class Magicka {
	private int c;
	private int d;
	private HashMap<String, String> combine;
	private HashSet<String> opposed;
	private String base;
	private ArrayList<String> elements;
	private HashMap<String, Integer> baseElements;

	public Magicka(String s) {
		super();
		StringTokenizer st = new StringTokenizer(s, " ");
		c = Integer.parseInt(st.nextToken());
		combine = new HashMap<String, String>();
		String s1, s2;
		for (int i = 0; i < c; i++) {
			s1 = st.nextToken();
			s2 = s1.substring(2);
			s1 = s1.substring(0, 2);
			combine.put(s1, s2);
			s1 = new StringBuilder(s1).reverse().toString();
			combine.put(s1, s2);
		}
		opposed = new HashSet<String>();
		d = Integer.parseInt(st.nextToken());
		for (int i = 0; i < d; i++) {
			s1 = st.nextToken();
			opposed.add(s1);
			s1 = new StringBuilder(s1).reverse().toString();
			opposed.add(s1);
		}
		st.nextToken();
		base = st.nextToken();
		elements = new ArrayList<String>();
		baseElements = new HashMap<String, Integer>();
	}

	public void invoke() {
		int size, n;
		String s1, s2, s3;
		for (int i = 0; i < base.length(); i++) {
			s1 = base.substring(i, i + 1);
			size = elements.size();
			if (size > 0) {
				s2 = elements.get(size - 1);
				s3 = s1 + s2;
				if (combine.containsKey(s3)) {
					elements.remove(size - 1);
					n = baseElements.get(s2) - 1;
					if (n > 0) {
						baseElements.put(s2, n);
					} else {
						baseElements.remove(s2);
					}
					elements.add(combine.get(s3));
					continue;
				} else {
					if (isOpposed(s1)) {
						elements = new ArrayList<String>();
						baseElements = new HashMap<String, Integer>();
						continue;
					}
				}
			}
			elements.add(s1);
			if (baseElements.containsKey(s1)) {
				n = baseElements.get(s1) + 1;
			} else {
				n = 1;
			}
			baseElements.put(s1, n);
		}
	}

	private boolean isOpposed(String s) {
		for (String ss : baseElements.keySet()) {
			if (opposed.contains(s + ss)) {
				return true;
			}
		}
		return false;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		int size = elements.size();
		if (size > 0) {
			sb.append(elements.get(0));
			for (int i = 1; i < size; i++) {
				sb.append(", " + elements.get(i));
			}
		}
		sb.append("]");
		return sb.toString();
	}
}
