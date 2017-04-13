import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

import static java.lang.String.format;
import static java.lang.Math.*;


public class ProblemA {
//	final static String testType = "test";
//		final static String testType = "small";
		final static String testType = "large";
	static BufferedReader infile;
	static PrintWriter outfile;

	public static void main(String[] args) throws Exception {
		String inFileName = "input_" + testType + "_ProblemA.txt";
		String outFileName = "output_" + testType + "_ProblemA.txt";
		infile = new BufferedReader(new FileReader(inFileName));
		outfile = new PrintWriter(new BufferedWriter(
				new FileWriter(outFileName)));
		new ProblemA();
	}

	public void log(String s) {
		System.out.print(s);
		outfile.print(s);
	}

	public ProblemA() throws Exception {
		Scanner scan = new Scanner(infile);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			log(format("Case #%d:\n", test + 1));
			int lines = scan.nextInt();
			scan.nextLine();
			String thing = "";
			for ( int i = 0; i < lines; i++) thing += " "+scan.nextLine()+" ";
			Tree parser = new Tree(thing.trim());
			int animals = scan.nextInt();
			for ( int i = 0; i < animals; i++) {
				scan.next();
				int features = scan.nextInt();
				HashSet<String> properties = new HashSet<String>();
				for ( int j = 0; j < features; j++) properties.add(scan.next());
				double result = parser.traverse(properties);
				log(format("%.8f\n", result));
			}
		}
		outfile.close();
	}
	
	public class Tree {
		double weight;
		Tree first, second;
		String feature;
		boolean hasFeature;
		public Tree(String s) {
			s = s.trim();
			s = s.substring(1, s.length()-1).trim();
			Scanner scan = new Scanner(s);
			weight = scan.nextDouble();
			if ( scan.hasNext()) {
				feature = scan.next();
				String rest = scan.nextLine().trim();
				int count = 1;
				int index = 1;
				while ( count != 0 ) {
					char c = rest.charAt(index);
					if ( c == '(') count++;
					if ( c == ')') count--;
					index++;
				}
				first = new Tree(rest.substring(0,index).trim());
				second = new Tree(rest.substring(index).trim());
				hasFeature = true;
			}
			else hasFeature = false;
		}
		public double traverse(HashSet<String> properties) {
			double result = weight;
			if ( hasFeature ) {
				if ( properties.contains(feature) ) result *= first.traverse(properties);
				else result *= second.traverse(properties);
			} 
			return result;
		}
	}
}
