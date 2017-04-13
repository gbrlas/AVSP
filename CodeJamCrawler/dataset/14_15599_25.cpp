package com.codeJam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class MagicTrick {
	static StringBuffer output = new StringBuffer();

	public static void main(String[] args) {
		String inputFile = "E:\\A-small-attempt0.in";
		parseInputFile(inputFile);
		writeOutputToFile("E:\\codeJamAOutput.txt");
	}

	private static void parseInputFile(String path) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(path));
			int noOfTests = Integer.parseInt(br.readLine());
			for (int i = 0; i < noOfTests; i++) {
				validateTrick(br, i + 1);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void validateTrick(BufferedReader br, int testNo) {
		try {
			// read first Row input and parse corresponding cards
			int row1 = Integer.parseInt(br.readLine());
			String row1CardArr[] = getCardsAtGivenRow(br, row1);

			// read Second Row input and parse corresponding cards
			int row2 = Integer.parseInt(br.readLine());
			String row2CardArr[] = getCardsAtGivenRow(br, row2);

			// Find cards matching from two inputs
			List<String> result = findCard(row1CardArr, row2CardArr);
			String outputCard = "";
			if (result.size() == 0) {
				outputCard = "Case #" + testNo + ": Volunteer cheated!";
			} else if (result.size() == 1) {
				outputCard = "Case #" + testNo + ": " + result.get(0);
			} else if (result.size() > 1) {
				outputCard = "Case #" + testNo + ": Bad magician!";
			}
			System.out.println(outputCard);
			output.append(outputCard).append("\r\n");

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static String[] getCardsAtGivenRow(BufferedReader br, int row) {
		String cardArr[] = new String[4];
		try {
			for (int j = 0; j < 4; j++) {
				String cards = br.readLine();
				if (row == j + 1) {
					cardArr = cards.split(" ");
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return cardArr;
	}

	private static List<String> findCard(String[] row1CardArr,
			String[] row2CardArr) {
		List<String> results = new ArrayList<String>();

		// find all common cards and return back to check output
		HashSet<String> map = new HashSet<String>();
		for (String card : row1CardArr) {
			map.add(card);
		}
		for (String card : row2CardArr) {
			if (map.contains(card)) {
				results.add(card);
			}
		}
		return results;
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
