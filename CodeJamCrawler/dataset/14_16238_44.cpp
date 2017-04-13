import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Cookie {
	
	public static void main(String[] args) throws Exception{
		
		Scanner scanner = new Scanner(new File("B-small-attempt0.in"));		
		int numCases = scanner.nextInt();		
		int caseNum = 1;		
		ArrayList<Double> res = new ArrayList<Double>();
		
		double C;
		double F;
		double X;
		
		while (caseNum <= numCases) {
			C = scanner.nextDouble();
			F = scanner.nextDouble();
			X = scanner.nextDouble();
			
			res.add(recParse(2, C, F, X, 0));
			
			caseNum++;
		}
		
		PrintWriter result = new PrintWriter(new FileWriter("resultB.txt"));
		for (int i = 0; i < res.size() - 1; i++) {
			result.print("Case #" + (i + 1) + ": ");
			result.printf("%1.7f%n", res.get(i));
		}
		result.print("Case #" + (res.size()) + ": ");
		result.printf("%1.7f", res.get(res.size() - 1));
		result.close();
	}

	public static double recParse(double base, double cost, double extra, double target, double time) {
		double noBuy = target / base;
		double buy = cost / base + target / (base + extra);
		
		if (noBuy <= buy) {
			return noBuy + time;
		}
		
		return recParse(base + extra, cost, extra, target, time + cost / base);
	}
	
}
