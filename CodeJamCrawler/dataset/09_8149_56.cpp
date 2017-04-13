import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class DecisionTree {
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		
		for (int n=0;n<N;n++) {
			st = new StringTokenizer(in.readLine());
			int L = Integer.parseInt(st.nextToken());
			String treestr = "";
			while (L-->0) treestr += in.readLine();
			treestr = treestr.replaceAll("\\(", " ( ").replaceAll("\\)", " ) ");
			Tree root = new Tree(new StringTokenizer(treestr));
			System.err.println(root);
			
			st = new StringTokenizer(in.readLine());
			int A = Integer.parseInt(st.nextToken());
			System.out.println("Case #"+(n+1)+":");
			while (A-->0) {
				st = new StringTokenizer(in.readLine());
				String animal = st.nextToken();
				int numfeats = Integer.parseInt(st.nextToken());
				TreeSet<String> feats = new TreeSet<String>();
				while (numfeats-->0) feats.add(st.nextToken());
				System.out.printf("%.7f\n", root.search(feats));
			}
		}
	}

}

class Tree {
	String feature;
	double weight;
	Tree ltree, rtree;
	
	public Tree(StringTokenizer st) {
		String curToken;
		while ((curToken = st.nextToken().trim()).equals("("));
		weight = Double.parseDouble(curToken);
		if (!(curToken=st.nextToken()).equals(")")) {
			feature = curToken;
			ltree = new Tree(st);
			rtree = new Tree(st);
		}
		if (st.hasMoreTokens()) st.nextToken();
	}
	
	public String toString() {
		String out = "( "+weight;
		if (feature != null) {
			out += " " + feature + " " + ltree + " " + rtree; 
		}
		return out + " )";
	}
	
	public double search(TreeSet<String> feats) {
		if (feature == null) return weight;
		if (feats.contains(feature)) {
			return weight*ltree.search(feats);
		} else {
			return weight*rtree.search(feats);
		}
	}
}
