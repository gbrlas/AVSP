package org.enginmanap.google.codejam.question1;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;

public class PredictCard {
	static class PredictTrick {
		public int[][] firstTry = new int[4][4];
		public int firstAnswer;
		public int[][] secondTry = new int[4][4];;
		public int secondAnswer;
	}

	public static void main(String[] args) {
		int numberOfTestCases = 0;

		InputStream fis = null;
		BufferedReader br = null;
		String line;

		try {
			/*
			fis = new FileInputStream("./src/input");
			br = new BufferedReader(new InputStreamReader(fis,
					Charset.forName("UTF-8")));
			line = br.readLine();
			*/
			br = new BufferedReader(new InputStreamReader(System.in));
			if((line =br.readLine()) == null ){
				System.out.println("line could not be read");
			} else 
			 {
				numberOfTestCases = Integer.parseInt(line);
			 }
			//System.out.println("total cases:" + numberOfTestCases);
			List<PredictTrick> testCasesList = new ArrayList<PredictCard.PredictTrick>(numberOfTestCases);
			for (int i = 0; i < numberOfTestCases; i++) {
				// we can assume there will be 1 + 4 + 1 + 4 = 10 lines per test
				// case
				PredictTrick currentTrick = new PredictTrick();
				testCasesList.add(currentTrick);
				// first read the answer 1;
				if ((line = br.readLine()) == null) {
					System.out.println("line could not be read");
					System.exit(1);
				} else {
					testCasesList.get(i).firstAnswer = Integer.parseInt(line);
					
				}
				// second read 4 lines for cards
				for (int j = 0; j < 4; j++) {
					if ((line = br.readLine()) == null) {
						System.out.println("line could not be read");
						System.exit(1);
					} else {
						String[] tempStringArray;
						tempStringArray = line.split(" ");						
						for (int k = 0; k < 4; k++) {
							currentTrick.firstTry[j][k] = Integer.parseInt(tempStringArray[k]);
						}
					}
				}
				// third read the answer 2;
				if ((line = br.readLine()) == null) {
					System.out.println("line could not be read");
					System.exit(1);
				} else {
					testCasesList.get(i).secondAnswer = Integer.parseInt(line);
				}
				// fourth and last, read 4 lines for cards
				for (int j = 0; j < 4; j++) {
					if ((line = br.readLine()) == null) {
						System.out.println("line could not be read");
						System.exit(1);
					} else {
						String[] tempStringArray;
						tempStringArray = line.split(" ");
						
						for (int k = 0; k < 4; k++) {
							currentTrick.secondTry[j][k] = Integer.parseInt(tempStringArray[k]);
						}
					}
				}

				//now we have all the data we need for one trick, lets calculate
				int firsTryNumbersLine[] = new int[4];
				int secondTryNumbersLine[] = new int[4];
				System.arraycopy(currentTrick.firstTry[(currentTrick.firstAnswer -1)], 0, firsTryNumbersLine, 0, 4); // the -1 is because selected rows starts from 1
				System.arraycopy(currentTrick.secondTry[(currentTrick.secondAnswer -1)], 0, secondTryNumbersLine, 0, 4);
				for(int k=0; k < 4; k++){
					//System.out.println("firstTry[" +k+ "] = " + currentTrick.firstTry[currentTrick.firstAnswer][k]);
				}
				int possibleAnswer = 0;
				boolean multipleAnswers = false;
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) {
						//System.out.println("compairing firstTry[" + j +"]= " + firsTryNumbersLine[j] + ", secondTry[" + k +"]= " + secondTryNumbersLine[k] );
						if(firsTryNumbersLine[j] == secondTryNumbersLine[k]){
							//System.out.println("same value found with j=" + j +" k=" + k);
							
							if(possibleAnswer != 0){
								multipleAnswers = true;
							} else {
								possibleAnswer = firsTryNumbersLine[j];
							}
						}
					}
				}
				if(multipleAnswers && possibleAnswer != 0){
					System.out.println("Case #" + (i+1) + ": Bad magician!");
				} else if (possibleAnswer == 0) {
					System.out.println("Case #" + (i+1) + ": Volunteer cheated!");
				} else {
					System.out.println("Case #" + (i+1) + ": " + possibleAnswer);
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			System.out.println("file not found exception");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("generic io exception");
			e.printStackTrace();
		} finally {
			// Done with the file

			br = null;
			fis = null;
		}
	}

}
