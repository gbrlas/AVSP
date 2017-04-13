import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class DeceitfulWarLarge {
	
	public static void main(String[] args) throws Exception{
		Scanner scanner = new Scanner(new File("D-large.in"));		
		int numCases = scanner.nextInt();		
		int caseNum = 1;		
		ArrayList<Integer> resw = new ArrayList<Integer>();
		ArrayList<Integer> resdw = new ArrayList<Integer>();
		
		int blocks;
		ArrayList<Double> n;
		ArrayList<Double> k;
		
		while (caseNum <= numCases) {
			blocks = scanner.nextInt();
			n = new ArrayList<Double>();
			k = new ArrayList<Double>();
			
			for (int i = 0; i < blocks; i++) {
				n.add(scanner.nextDouble());
			}
			for (int i = 0; i < blocks; i++) {
				k.add(scanner.nextDouble());
			}
			
			n = quicksort(n);
			k = quicksort(k);
			
			System.out.println(n);
			System.out.println(k);

			System.out.println(recParseDW(n, k, 0));
			System.out.println(blocks - recParseDW(k, n, 0));
			
			resw.add(blocks - recParseDW(k, n, 0));
			resdw.add(recParseDW(n, k, 0));
			
			caseNum++;
		}
		
		PrintWriter result = new PrintWriter(new FileWriter("ResultCLarge.txt"));
		for (int i = 0; i < resw.size() - 1; i++) {
			result.println("Case #" + (i + 1) + ": " + resdw.get(i) + " " + resw.get(i));
		}
		result.print("Case #" + (resw.size()) + ": " + resdw.get(resw.size() - 1) + " " + resw.get(resdw.size() - 1));
		result.close();
	}
	
	public static int recParseDW(ArrayList<Double> n, ArrayList<Double> k, int score) {
		ArrayList<Double> copyn = new ArrayList<Double>();
		for (Double num:n) {
			copyn.add(num);
		}
		ArrayList<Double> copyk = new ArrayList<Double>();
		for (Double num:k) {
			copyk.add(num);
		}
		
		if (copyn.size() == 0) {
			return score;
		}
		
		int ind = contGr(copyn, k.get(0));
		
		if (ind == -1) {
			return score;
		}
		
		copyn.remove(ind);
		copyk.remove(0);
		
		return recParseDW(copyn, copyk, score + 1);
	}

	public static int contGr(ArrayList<Double> naomi, double ken) {
		if (ken > naomi.get(naomi.size() - 1)) {
			return -1;
		}
		int ind = 0;
		while (naomi.get(ind) < ken) {
			ind++;
		}
		return ind;
	}
	
	public static ArrayList<Double> quicksort(ArrayList<Double> list) {
		if (list.size() <= 1) {
			return list;
		}
		
		int pivot = (int)(list.size() * Math.random());
		double pivVal = list.get(pivot);
		
		ArrayList<Double> lower = new ArrayList<Double>();
		ArrayList<Double> higher = new ArrayList<Double>();
		
		for (int i = 0; i < list.size(); i++) {
			if (i == pivot) {
				continue;
			}
			if (list.get(i) <= pivVal) {
				lower.add(list.get(i));
			} else {
				higher.add(list.get(i));
			}
		}
		
		return concatenate(quicksort(lower), list.get(pivot), quicksort(higher));
	}
	
	public static ArrayList<Double> concatenate(ArrayList<Double> lower, double pivot, ArrayList<Double> higher) {
		lower.add(pivot);
		for (Double num:higher) {
			lower.add(num);
		}
		return lower;
	}
}
