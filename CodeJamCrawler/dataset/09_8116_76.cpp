import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class AlienLanguage {

	public static void main(String[] args) throws IOException {
		BufferedReader infile = new BufferedReader(new FileReader("alien_language.in"));
		BufferedWriter outfile = new BufferedWriter(new FileWriter("alien_language.out"));
		
		StringTokenizer st = new StringTokenizer(infile.readLine());
		int L = Integer.parseInt(st.nextToken());
		int D = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		TreeNode root = new TreeNode((char)0);
		for (int i=0; i<D; i++)
			root.insert(infile.readLine());
		//System.out.println(root);

		ArrayList<ArrayList<Character>> poss;
		boolean inParens;
		for (int i=0; i<N; i++) {
			String str = infile.readLine();
			poss = new ArrayList<ArrayList<Character>>();
			inParens = false;
			for (char c : str.toCharArray()) {
				if (c == '(') {
					inParens = true;
					poss.add(new ArrayList<Character>());
				} else if (c == ')') {
					inParens = false;
				} else {
					if (!inParens) poss.add(new ArrayList<Character>());
					poss.get(poss.size()-1).add(c);
				}
			}
			//System.out.println(poss);
			outfile.write("Case #"+(i+1)+": " + root.test(poss) + "\n");
		}
		outfile.close();
	}
}

class TreeNode {
	char c;
	int depth;
	TreeMap<Character, TreeNode> children;
	
	public TreeNode(char c) {
		this(c, 0);
	}
	public TreeNode(char c, int depth) {
		this.c = c;
		this.depth = depth;
		children = new TreeMap<Character, TreeNode>();
	}
	
	public void insert(String str) {
		if (str.length() == 0) return;
		if (!children.containsKey(str.charAt(0))) {
			children.put(str.charAt(0), new TreeNode(str.charAt(0), depth+1));
		}
		children.get(str.charAt(0)).insert(str.substring(1));
	}
	
	public String toString() {
		String out = c+"";
		for (TreeNode child : children.values()) {
			out += "("+child+")";
		}
		return out;
	}

	public int test(ArrayList<ArrayList<Character>> poss) {
		if (depth >= poss.size()) return 1;
		//System.out.println(this + " || " + poss.get(depth));
		int tot = 0;
		for (char c : poss.get(depth)) {
			if (children.containsKey(c)) {
				tot += children.get(c).test(poss);
			}
		}
		return tot;
	}
}