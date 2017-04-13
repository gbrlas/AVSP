package com.util;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class GoogleCookie {
	static double costForFarm = 0;
	static double cookieIncrementRate = 0;
	static double cookieToEarn = 0;
	static final double fixedCookieRate = 2;
	static int caseNo = 1;
	private static Map<Integer, Double> resultList = new HashMap<Integer, Double>();
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = null;
		int testCount = -1;		
		String input[];
		while((in=br.readLine())!=null){
			if(testCount == -1){
				testCount = Integer.parseInt(in);
			}  else {
				input = in.split(" ");
				costForFarm = Double.parseDouble(input[0]);
				cookieIncrementRate = Double.parseDouble(input[1]);
				cookieToEarn = Double.parseDouble(input[2]);
				
				double totalTimeWithBaseRate = cookieToEarn/fixedCookieRate;
				double timeToGetTheFarmWithBaseRate = costForFarm/fixedCookieRate;				
				double timeWithIncrementRate = cookieToEarn/(fixedCookieRate+cookieIncrementRate);				
				double totalTimeWithIncrementRate = timeToGetTheFarmWithBaseRate+timeWithIncrementRate;
				if(totalTimeWithBaseRate <= totalTimeWithIncrementRate){
					resultList.put(caseNo, totalTimeWithBaseRate);
				} else{
					totalTimeWithIncrementRate = timeToGetTheFarmWithBaseRate+findOptimumTime(fixedCookieRate+cookieIncrementRate);					
					resultList.put(caseNo, totalTimeWithIncrementRate);
				}
				
				caseNo++;
				if(testCount < caseNo){
					break;
				}

			}

		}
		
		for(int i=1; i< caseNo; i++){
			System.out.printf("Case #%d: %.7f\n",i,resultList.get(i));
		}

	}
	
	private static double findOptimumTime(double newCookieIncrementRate) {
		double totalTimeWithBaseRate = cookieToEarn/newCookieIncrementRate;
		double timeToGetTheFarmWithBaseRate = costForFarm/newCookieIncrementRate;				
		double timeWithIncrementRate = cookieToEarn/(cookieIncrementRate+newCookieIncrementRate);				
		double totalTimeWithIncrementRate = timeToGetTheFarmWithBaseRate+timeWithIncrementRate;
		if(totalTimeWithBaseRate <= totalTimeWithIncrementRate){			
			return totalTimeWithBaseRate;
		} else{			
			return timeToGetTheFarmWithBaseRate+findOptimumTime(cookieIncrementRate+newCookieIncrementRate);
		}
	}

}
