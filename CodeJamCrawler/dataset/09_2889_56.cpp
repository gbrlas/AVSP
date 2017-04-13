import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Scanner;


public class Q1 {

	static DecimalFormat format;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		format = new DecimalFormat("0.0000000");
		DecimalFormatSymbols sym = new DecimalFormatSymbols();
		sym.setDecimalSeparator('.');
		format.setDecimalFormatSymbols(sym);
		Scanner scn = new Scanner(System.in);
		int cases = scn.nextInt();
		for( int c = 1; c <= cases; c++ ) {
			int treeSize = scn.nextInt();
			scn.nextLine();
			StringBuilder build = new StringBuilder();
			for( int t = 0; t < treeSize; t++ ) {
				build.append(scn.nextLine());
			}
			System.out.println("Case #" + c + ":");
			Tree t = Tree.parse(new Scanner(
					build.toString().replaceAll("\\(", "( ").replaceAll("\\)", " )").replaceAll("\n", " ")));
			int animals = scn.nextInt();
			for(int a = 0; a < animals; a++) {
				String name = scn.next();
				int feats = scn.nextInt();
				String[] fs = new String[feats];
				for(int f = 0; f < feats; f++ ) {
					fs[f] = scn.next();
				}
				double cuteness = t.compute(new Animal(name, fs));
				System.out.println(format.format(cuteness));
			}
		}

	}

}

class Tree {
	double perc;
	String feature;
	Tree yes;
	Tree no;
	
	public Tree() {
		yes = null;
		no = null;
		perc = 0;
	}

	public double compute(Animal animal) {
		if(isLeaf()) {
			return perc;
		}
		
		if(animal.contains(feature)) {
			return perc * yes.compute(animal);
		} else {
			return perc * no.compute(animal);
		}
	}

	private boolean isLeaf() {
		return yes == null || no == null;
	}

	public static Tree parse(Scanner scn) {
		String aux = scn.next();
		String perc = scn.next();
		String name = scn.next();
		Tree root = new Tree();
		if(")".equals(name.trim())) {
		} else {
			root.feature = name;
			root.yes = parse(scn);
			root.no = parse(scn);
			String aux2 = scn.next();
		}
		root.perc = Double.parseDouble(perc);
		return root;
	}
}

class Animal {
	String name;
	String[] features;
	double cute;
	
	public Animal(String name, String[] features) {
		cute = 1;
		this.features = features;
		this.name = name;
	}

	public boolean contains(String feature) {
		for( String f : features ) {
			if( f.trim().equals(feature)) {
				return true;
			}
		}
		return false;
	}
}
