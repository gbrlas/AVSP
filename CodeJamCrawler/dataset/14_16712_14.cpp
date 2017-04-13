package org.enginmanap.google.codejam.question2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CalculateNeededTime {

	//C is farm cost
	//F is farm production per second
	//X is game over
	// 2 cookie for second as base
	
	static double farmCost;
	static double farmProduction;
	static double endGameCount;
	static double BASE_PRODUCTION = 2.0;


	static double playCookieClicker(double totalCookies, double neededCookies, double production, double totalSeconds){

		//the time with base production:
		double timeNeededForFinish;
		timeNeededForFinish = endGameCount / production;
		//the base time needed.
		double timeNeededForFarm = farmCost / production;
		//is buying a farm makes sense?
		double farmWorkingTime = timeNeededForFinish - timeNeededForFarm;
		if(farmWorkingTime * farmProduction > farmCost){ // if equals, won't bother.
			//farm must be bought calculate values for the purchase second
			totalCookies = totalCookies + timeNeededForFarm * production - farmCost;
			totalSeconds = totalSeconds + timeNeededForFarm;
			production = production + farmProduction;
			//keep playing from that point
			return playCookieClicker(totalCookies, neededCookies, production, totalSeconds);
		} else {
			//the game is over
			return (totalSeconds + timeNeededForFinish);
		}
	}
	
	static String readLineFromConsole(BufferedReader br){
		String line;
		try {
			if((line =br.readLine()) == null ){
				System.out.println("line could not be read");
				System.exit(1);
				return null;
			} else 
			 {
				return line;
			 }
		} catch (IOException e) {
			System.out.println("Generic io problem");
			e.printStackTrace();
		}
		return null;
	}
	
	
	public static void main(String[] args) {
		int numberOfTestCases = 0;
		BufferedReader br = null;
		String currentLine;
		
		br = new BufferedReader(new InputStreamReader(System.in));
		
		currentLine = readLineFromConsole(br);
		
		numberOfTestCases = Integer.parseInt(currentLine);
		for (int i = 0; i < numberOfTestCases; i++) {
			//for each test case


			
			currentLine = readLineFromConsole(br);
			//there will be 3 values, seperated by space
			String[] gameValues = currentLine.split(" ");
			//the input is like 500.0, and output is requested to be precise to 10^-6, to start with it
			
			farmCost = Float.parseFloat(gameValues[0]);
			farmProduction = Float.parseFloat(gameValues[1]);
			endGameCount = Float.parseFloat(gameValues[2]);
			double totalSeconds;
			totalSeconds = playCookieClicker(0, endGameCount, BASE_PRODUCTION, 0); //first 0 is total cookies, second is total seconds..
			System.out.print("Case #" + (i+1) +": ");
			System.out.printf("%.7f", totalSeconds);
			System.out.println("");			
			
		}
	}

}
