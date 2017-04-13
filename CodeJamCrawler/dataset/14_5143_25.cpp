import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
public class QualifyCookie {

	static double c, f, x, roc, ttb;
	static int nof;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String base="C:\\Users\\Bryan\\Documents\\PROCESSING\\GoogleJam\\src\\";
		String input= base + "B-small-attempt0.in";
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
				
				nof 	 = 0; //Number of Farms

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
		nof = 0;
		/*
		 * Idea is to calculate total time when exactly N farms are used where N =  1 , 2 , 3, ...)
		 * As the number of farms increases, the total time should decrease until a certain N
		 */
		while(totalTime <= bestTime){
			bestTime = totalTime;
			totalTime = 0;
			
			nof++;
			//Buy the appropriate amount of Farms
			for(int y = 0; y < nof; y++){
				totalTime += getTimeTilBuy(y);
			}	
			
			double timeNeeded = x / getRateOfCookies(nof);
			totalTime += timeNeeded;				
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
