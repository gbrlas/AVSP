package com.codeJam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;

public class CookieClicker {
	static StringBuffer output = new StringBuffer();
	static DecimalFormat df;

	public static void main(String[] args) {
		String inputFile = "E:\\B-small-attempt0.in";
		parseInputFile(inputFile);
		writeOutputToFile("E:\\codeJamBOutput-small.txt");
	}

	private static void parseInputFile(String path) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(path));
			int noOfTests = Integer.parseInt(br.readLine());
			for (int i = 0; i < noOfTests; i++) {
				executeTest(br, i + 1);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void executeTest(BufferedReader br, int testNo) {
		try {
			String inputs[] = br.readLine().split(" ");
			Double c = Double.parseDouble(inputs[0]);
			Double f = Double.parseDouble(inputs[1]);
			Double x = Double.parseDouble(inputs[2]);

			Double timeSpent = 0.0;
			Double currentSpeed = 2.0;
			String testOutput = "";
			if (x <= c) {
				timeSpent = x / currentSpeed;
				testOutput = "Case #" + testNo + ": " +  formatWithPrecision(timeSpent, 7);
			} else {
				Double timeWithCurrentSpeed = 0.0;
				Double totalTimeAfterBuyingFarm = 0.0;
				do {
					timeWithCurrentSpeed = x / currentSpeed;

					Double timeAfterBuyingFarm = x / (currentSpeed + f);
					Double timeTobuyFarm = c / currentSpeed;
					totalTimeAfterBuyingFarm = timeAfterBuyingFarm
							+ timeTobuyFarm;

					if (timeWithCurrentSpeed > totalTimeAfterBuyingFarm) {
						timeSpent += timeTobuyFarm;
						currentSpeed += f;
					} else {
						timeSpent += timeWithCurrentSpeed;
					}
				} while (timeWithCurrentSpeed > totalTimeAfterBuyingFarm);

				testOutput = "Case #" + testNo + ": " + formatWithPrecision(timeSpent, 7);
			}
			System.out.println(testOutput);
			output.append(testOutput).append("\r\n");
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	private static String formatWithPrecision(double value, Integer precision) {
		String val = null;

		if (precision != null) {
			DecimalFormat decimalFormat = new DecimalFormat();
			decimalFormat.setGroupingUsed(false);
			decimalFormat.setMaximumFractionDigits(precision);
			decimalFormat.setMinimumFractionDigits(7);
			try {
				val = decimalFormat.format(value);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

		return val;
	}

	public static void writeOutputToFile(String path) {
		try {
			File file = new File(path);

			// if file doesnt exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(output.toString());
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
