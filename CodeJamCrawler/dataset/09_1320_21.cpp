package gcj2009.round1b.problemA;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test {
	/** Parameter class <br/> stands for each test case */
	public static class Parameter {
		public Node treeRoot;

		public Map<String, List<String>> animalMap;

		public Parameter(Node treeRoot, Map<String, List<String>> animalMap) {
			this.treeRoot = treeRoot;
			this.animalMap = animalMap;
		}
	}


	


	private static double calcProb(double prob, Node node, List<String> features) {
		prob = prob * node.weight;

		if (node.feature == null) {
			// Leaf
			return prob;
		}

		if (features.contains(node.feature)) {
			prob = calcProb(prob, node.getFirstChild(), features);
		} else {
			prob = calcProb(prob, node.getSecondChild(), features);
		}

		return prob;

	}

	private static List<Parameter> readParams(String inputFile)
			throws IOException {
		BufferedReader br = null;

		int nCases = 0;
		try {
			FileInputStream fis = new FileInputStream(inputFile);
			InputStreamReader isr = new InputStreamReader(fis);

			br = new BufferedReader(isr);

			String line;

			line = br.readLine().trim();
			nCases = Integer.parseInt(line);

			List<Parameter> parameters = new ArrayList<Parameter>();

			for (int i = 0; i < nCases; i++) {

				// Parse decision tree
				line = br.readLine().trim();
				int nTreeLines = Integer.parseInt(line);

				StringBuffer sb = new StringBuffer();
				for (int j = 0; j < nTreeLines; j++) {
					line = br.readLine().trim();

					sb.append(line);
				}

				String treeStr = sb.toString();
				Node root = parseTreeStr(treeStr);

				// Parse domain a
				line = br.readLine().trim();
				int nAnimals = Integer.parseInt(line);

				Map<String, List<String>> animalMap = new LinkedHashMap<String, List<String>>();
				for (int j = 0; j < nAnimals; j++) {
					line = br.readLine().trim();
					String[] tokens = line.split(" ");

					String animal = tokens[0];

					int nFeatures = Integer.parseInt(tokens[1]);

					List<String> features = new ArrayList<String>();

					for (int k = 0; k < nFeatures; k++) {
						features.add(tokens[2 + k]);
						System.out.println(animal + "  : " + tokens[2 + k]);
					}

					animalMap.put(animal, features);
				}

				Parameter parameter = new Parameter(root, animalMap);

				parameters.add(parameter);

			}

			return parameters;

		} finally {
			br.close();
		}
	}

	/**
	 * Parse input decision tree
	 * 
	 * @param treeStr
	 */
	private static Node parseTreeStr(String treeStr) {

		// Tokenize

		Pattern pattern = Pattern
				.compile("([0-1]+\\.*[0-9]*)|([a-z]+)|\\(|\\)");
		Matcher matcher = pattern.matcher(treeStr);
		List<String> tokens = new ArrayList<String>();
		while (matcher.find()) {
			tokens.add(matcher.group(0));
		}

		// Parse
		Node root = parseTreeStrInner(tokens);

		// Confirm
		root.dump("  ");
		return root;
	}

	private static Node parseTreeStrInner(List<String> tokens) {

		double weight;
		String feature;

		// "("
		String token;
		token = tokens.get(0);
		tokens.remove(0);
		System.out.println(token + "   " + tokens);

		// Wegiht
		token = tokens.get(0);
		tokens.remove(0);
		weight = Double.parseDouble(token);
		System.out.println(token + "   " + tokens);

		// Feature or "(" expected
		token = tokens.get(0);
		tokens.remove(0);
		System.out.println(token + "   " + tokens);
		Node node;
		if (token.equals(")")) {
			// Leaf
			node = new Node(weight);
		} else {
			feature = token;
			node = new Node(weight, feature);

			Node firstChild = parseTreeStrInner(tokens);
			Node secondChild = parseTreeStrInner(tokens);

			// ")" expected
			token = tokens.get(0);
			tokens.remove(0);
			if (!token.equals(")")) {
				new RuntimeException(") expected");
			}

			node.addChild(firstChild);
			node.addChild(secondChild);

		}
		return node;
	}


	public static void main(String[] args) throws Exception {

		if (args.length != 2) {
			System.err.println("Specify input file name.");
			System.err.println("Specify output file name.");
			System.exit(0);
		}

		String inputFileName = args[0];
		String outputFileName = args[1];

		// read parameters
		List<Parameter> parameters = readParams(inputFileName);

		// preparet output writer

		FileOutputStream fos = new FileOutputStream(outputFileName);
		OutputStreamWriter osw = new OutputStreamWriter(fos, "UTF-8");
		BufferedWriter bw = new BufferedWriter(osw);

		
		try {
			// Solve
			int count = 1;
			for (Parameter parameter : parameters) {
				bw.write("Case #" + count + "\n");

				Node root = parameter.treeRoot;
				Map<String, List<String>> animalMap = parameter.animalMap;

				for (String animal : animalMap.keySet()) {
					// initial probability
					double prob = 1.0;

					List<String> features = animalMap.get(animal);
					prob = calcProb(prob, root, features);
					bw.write(String.format("%1.7f\n", prob));

				}
				count++;

			}

		} finally {
			bw.close();
		}
	}

}
