package hu.wildhemp.codejam.universe;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Universe {

	private int caseNum;
	private List<String>[] searchEngines;
	private List<String>[] searchStrings;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Universe univ = new Universe();
		univ.start();
	}
	
	public void start() {
		try {
			readInput("A-small-attempt0.in");
			System.setOut(new PrintStream("A-small-attempt0.out"));
			
			for (int caseIdx = 0; caseIdx < caseNum; caseIdx ++) {
				List<String> actualEngines = searchEngines[caseIdx];
				List<String> actualSearches = searchStrings[caseIdx];
		
				int changeCount = 0;
				List<String> searchList = actualSearches;
				int furtherElement = -1;
				while ((furtherElement = getFurtherFirstElement(searchList, actualEngines)) != Integer.MAX_VALUE) {
					changeCount ++;
					
					searchList = searchList.subList(furtherElement, searchList.size());
				}
				
				System.out.println("Case #" + (caseIdx + 1) + ": " + changeCount);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private int getFurtherFirstElement(List<String> searchList, List<String> actualEngines) {
		if (searchList.isEmpty()) {
			return Integer.MAX_VALUE;
		}
		
		int[] firstElements = new int[actualEngines.size()];
		Arrays.fill(firstElements, Integer.MAX_VALUE);
		
		for (int strIdx = 0; strIdx < searchList.size(); strIdx ++) {
			String str = searchList.get(strIdx);
			
			int engineIdx = actualEngines.indexOf(str);
			
			if (firstElements[engineIdx] == Integer.MAX_VALUE) {
				firstElements[engineIdx] = strIdx;
			}
		}
		
		int maxIdx = 0;
		for (int idx = 0; idx < firstElements.length; idx ++) {
			if (firstElements[idx] == Integer.MAX_VALUE) {
				return Integer.MAX_VALUE;
			} else if (firstElements[idx] > maxIdx) {
				maxIdx = firstElements[idx];
			}
		}
		
		return maxIdx;
	}
	
	private void readInput(String fileName) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(fileName)));

		caseNum = Integer.parseInt(reader.readLine());
		
		searchEngines = new ArrayList[caseNum];
		searchStrings = new ArrayList[caseNum];
		
		for (int idx =0; idx < caseNum; idx ++) {
			int engineNum = Integer.parseInt(reader.readLine());
			searchEngines[idx] = new ArrayList<String>(engineNum);
			
			for (int engineIdx = 0; engineIdx < engineNum; engineIdx ++) {
				searchEngines[idx].add(reader.readLine());
			}
			
			int searchNum = Integer.parseInt(reader.readLine());
			searchStrings[idx] = new ArrayList<String>(searchNum);
			
			for (int searchIdx = 0; searchIdx < searchNum; searchIdx ++) {
				searchStrings[idx].add(reader.readLine());
			}
		}
	}

}
