import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Main {
	
	public static Scanner in;
	public static PrintWriter out;
	
	public static void main(String[] args) throws FileNotFoundException {
		boolean sample = false;
		String input = "D-large.in";
		String output = "D-large-output.txt";
		if(sample){
			input = "sample.in";
			output = "sample.out";
		}
		
		in = new Scanner(new File(input));
		out  = new PrintWriter(new File(output));
		
		int t = in.nextInt();
		for(int c = 1; c <= t; c++){
			solve(c);
		}
		
		
		in.close();
		out.close();
	}
	
	
	public static void solve(int t){
		int n = in.nextInt();
		ArrayList<Double> naomi = new ArrayList<Double>();
		ArrayList<Double> ken = new ArrayList<Double>();
		
		for(int i = 0; i < n; i++){
			naomi.add(in.nextDouble());
		}
		
		for(int i = 0; i < n; i++){
			ken.add(in.nextDouble());
		}
		
		Collections.sort(naomi);
		Collections.sort(ken);
		
		
		
		int dans = deceitfulWar((ArrayList<Double>)naomi.clone(), (ArrayList<Double>)ken.clone());
		
		int wans = war(naomi, ken);
		
		System.out.printf("Case #%d: %d %d\n",t, dans, wans );
		out.printf("Case #%d: %d %d\n",t, dans, wans );
		
	}
	
	public static int war(ArrayList<Double> naomi, ArrayList<Double> ken){
		int wins = 0;
		
		for(int i = 0; i < naomi.size(); i++){
			Double n = naomi.get(i);
			
			boolean kenWon = false;
			for(int j = 0; j < ken.size() && !kenWon; j++){
				Double k = ken.get(j);
				
				if(k > n){
					kenWon = true;
					ken.remove(j);
				}
			}
			
			if(!kenWon){
				wins++;
				ken.remove(0);
			}
			
		}
		return wins;
	}
	
	public static int deceitfulWar(ArrayList<Double> naomi, ArrayList<Double> ken){
		int wins = 0;
		
		for(int i = 0; i < naomi.size(); i++){
			Double n = naomi.get(i);
			
			if(n > ken.get(0)){
				wins++;
				ken.remove(0);
			}
			else{
				ken.remove(ken.size() -1 );
			}
			
			
		}
		
		
		return wins;
	}
}
