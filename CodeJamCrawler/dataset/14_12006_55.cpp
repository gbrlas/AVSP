import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	
	public static Scanner in;
	public static PrintWriter out;
	
	public static void main(String[] args) throws FileNotFoundException {
		boolean sample = false;
		String input = "B-large.in";
		String output = "B-large-output.txt";
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
		double c = in.nextDouble();
		double f = in.nextDouble();
		double x = in.nextDouble();
		
		double rate = 2;
		double time = 0;
		
		
		while(x / rate > c / rate + x / (rate + f) ){
			time += c / rate;
			rate += f;
			
			
		}
		
		time += x / rate;
		
		System.out.printf("Case #%d: %.7f\n", t, time);
		out.printf("Case #%d: %.7f\n", t, time);
	}
}
