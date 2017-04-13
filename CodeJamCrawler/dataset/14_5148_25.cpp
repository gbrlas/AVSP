import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
public class QualifyCookie {

	static double c, f, x, roc, ttb;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String base="C:\\Users\\Bryan\\Documents\\PROCESSING\\GoogleJam\\src\\";
		String input= base + "B-large.in";
		String output=base + "outcookies.txt";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);
			int t = 0;

			t = sc.nextInt();
			//For each Test Case 
			for(int i = 0; i < t; i++){
				sc.nextLine();
				c = sc.nextDouble(); //Cost of Farm
				f = sc.nextDouble(); //Rate of Cookies per Farm
				x = sc.nextDouble(); //Total Amount Needed

				double bestTime = calculateBestTime();
				
				//Print the answer
				pw.print("Case #" + (i+1) + ": ");
				pw.println(bestTime);

				pw.println();

			}

			pw.println();
			pw.flush();
			pw.close();
			sc.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}


	}

	private static double calculateBestTime() {
		if (x < c)
			return x/2;
		double totalTime = x/2;
		double bestTime = totalTime;
		double farmTime = 0.0; 		//accumulated time spent on Farming
		int nof = 0; 				//Number of Farms
		/*
		 * Idea is to calculate total time when exactly N farms are used where N =  1 , 2 , 3, ...)
		 * As the number of farms increases, the total time should decrease until a certain N
		 * 
		 * For Large, keep track of time spent on farming as opposed to calculating it each loop
		 */
		while(totalTime <= bestTime){
			bestTime = totalTime;
			//How much time have we spent on getting new farms?
			farmTime += getTimeTilBuy(nof);
			nof++;
			
			double timeNeeded = x / getRateOfCookies(nof);
			totalTime = farmTime + timeNeeded;				
		}

		return bestTime;

	}

	public static double getRateOfCookies(int farms){
		return (f*farms) + 2;
	}
	public static double getTimeTilBuy(int farms){
		return c/getRateOfCookies(farms);
	}
	
	//All the best programming gets done at 4 in the morning.

}
