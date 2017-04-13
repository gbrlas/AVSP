package com.main;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class CookieClicker {
	public static void main(String... args) {
		BufferedReader br = null;
		BufferedWriter bw = null;
	
		String temp[] = null;
		Double farm;
		Double cookiesPerSec;
		Double result;
		Double sec = 0.0;
		int multiplier = 1;
		try {

			br = new BufferedReader(new FileReader(System.getProperty("user.home") + "\\B-small-attempt5.in"));

			bw = new BufferedWriter(new FileWriter(System.getProperty("user.home") + "\\B-small-attempt5.out"));
			PrintWriter fileOut = new PrintWriter(bw);
			
			long numberInp = Integer.parseInt(br.readLine());

			for (int index = 1; index <= numberInp; index++) {
				multiplier = 1;
				sec = 0.0;
				temp = br.readLine().split(" ");
				farm = Double.parseDouble(temp[0]);
				cookiesPerSec = Double.parseDouble(temp[1]);
				result = Double.parseDouble(temp[2]);
				
				if (farm >= result) {
					sec = result/2;
					fileOut.println("Case #"+index+": "+new BigDecimal(sec).setScale(7, RoundingMode.HALF_UP));
				} else {
					
					if ((farm/(2)+(result/(2+cookiesPerSec))) < result/(2)) {
						sec = sec + new BigDecimal(farm/2).setScale(7,  RoundingMode.HALF_UP).doubleValue();
						while ((farm/(2+multiplier*cookiesPerSec)+(result/(2+multiplier*cookiesPerSec+cookiesPerSec))) < result/(2+multiplier*cookiesPerSec)) {
							sec = sec + farm/(2+multiplier*cookiesPerSec);
							multiplier++;
						}
						sec = sec + new BigDecimal(result/(2+multiplier*cookiesPerSec)).setScale(7,  RoundingMode.HALF_UP).doubleValue();
						fileOut.println("Case #"+index+": "+new BigDecimal(sec).setScale(7,  RoundingMode.HALF_UP));
					} else {
						sec = result/2;
						fileOut.println("Case #"+index+": "+new BigDecimal(sec).setScale(7,  RoundingMode.HALF_UP));
					}
				}
							
			}
			fileOut.flush();
			bw.flush();
			fileOut.close();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
				bw.close();
				
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

}
