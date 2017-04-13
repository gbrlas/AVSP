package truizlop.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Problem1 {

	public static class TreeNode{
		public double weight;
		public String feature;
		public TreeNode left;
		public TreeNode right;
	}
	
	public static void main(String args[]) throws Exception{
		
		FileReader fin = new FileReader("test.in");
		BufferedReader input = new BufferedReader(fin);
		FileWriter fout = new FileWriter("test.in" + ".out");
		BufferedWriter output = new BufferedWriter(fout);
		
		int numTrees = Integer.parseInt(input.readLine());
		
		for(int i = 0; i < numTrees; i++){
			int numLines = Integer.parseInt(input.readLine());
			StringBuffer buffer = new StringBuffer();
			for(int j = 0; j < numLines; j++){
				buffer.append(input.readLine());
			}
			StringTokenizer tokenizer = new StringTokenizer(buffer.toString(), " ()");
			TreeNode node = readTree(tokenizer);
			
			System.out.println("Case #" + (i+1) + ":");
			int numAnimals = Integer.parseInt(input.readLine());
			for(int j = 0; j < numAnimals; j++){
				tokenizer = new StringTokenizer(input.readLine());
				tokenizer.nextToken(); // Animal
				tokenizer.nextToken(); // num features
				HashMap<String, Object> map = new HashMap<String, Object>();
				while(tokenizer.hasMoreTokens()){
					map.put(tokenizer.nextToken(), null);
				}
				double p = computeProbability(node, map);
				System.out.println(p);
			}
		}
		
		input.close();
		fin.close();
		output.close();
		fout.close();
		
	}
	
	static String nextToken = null;
	
	public static TreeNode readTree(StringTokenizer tokenizer){
		
		TreeNode node = new TreeNode();
		
		if(nextToken == null){
			node.weight = Double.parseDouble(tokenizer.nextToken());
		}else{
			node.weight = Double.parseDouble(nextToken);
			nextToken = null;
		}
		
		if(tokenizer.hasMoreTokens()){
			nextToken = tokenizer.nextToken();
			
			try{
				Double.parseDouble(nextToken);
			}catch(Exception e){
				node.feature = nextToken;
				nextToken = null;
				node.left = readTree(tokenizer);
				node.right = readTree(tokenizer);
			}
		}
		
		return node;
	}
	
	public static double computeProbability(TreeNode node, HashMap<String, Object> map){
		
		double p = 1.0;
		
		while(node != null){
			p *= node.weight;
			if(node.feature != null){
				if(map.containsKey(node.feature)){
					node = node.left;
				}else{
					node = node.right;
				}
			}else{
				break;
			}
		}
		
		return p;
	}
}
