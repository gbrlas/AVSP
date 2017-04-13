package com.main;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DecietfulWar {
	public static void main(String... args) {
		BufferedReader br = null;
		BufferedWriter bw = null;
	
		String temp[] = null;
		List<String> naomiWtListOrig = new ArrayList<String>();
		List<String> kenWtListOrig = new ArrayList<String>();
		List<String> kenWtList = new ArrayList<String>();
		List<String> tempList;
		try {

			br = new BufferedReader(new FileReader(System.getProperty("user.home") + "\\test.in"));

			bw = new BufferedWriter(new FileWriter(System.getProperty("user.home") + "\\test.out"));
			PrintWriter fileOut = new PrintWriter(bw);
			
			long numberInp = Integer.parseInt(br.readLine());
			int noOfWts = 0;
			double naomiWt = 0.0;
			double kenWt = 0.0;
			int winNormalWar = 0;
			int winDecietfulWar = 0;
			boolean found = false;
			for (int index = 1; index <= numberInp; index++) {
				winNormalWar = 0;
				winDecietfulWar = 0;
				noOfWts = Integer.parseInt(br.readLine());
				temp = br.readLine().split(" ");
				Arrays.parallelSort(temp);
				naomiWtListOrig = Arrays.asList(temp);
				
				temp = br.readLine().split(" ");
				Arrays.parallelSort(temp);
				kenWtListOrig = Arrays.asList(temp);
				
				//Normal War
				tempList = new ArrayList<String>(kenWtListOrig);
				kenWtList = new ArrayList<String>(kenWtListOrig);
				for (String nWt : naomiWtListOrig) {
					found = false;
					naomiWt = Double.parseDouble(nWt);
					for (String kWt : kenWtList) {
						if (naomiWt < Double.parseDouble(kWt)) {
							found = true;
							tempList.remove(kWt);
							break;
						}
					}
					if (!found) {
						winNormalWar++;
						tempList.remove(0);
					}
					kenWtList = tempList;
				}
				
				//Decietful War
				tempList = new ArrayList<String>(naomiWtListOrig);
				for (String kWt : kenWtListOrig) {
					found = false;
					kenWt = Double.parseDouble(kWt);
					for (String nWt : naomiWtListOrig) {
						if (kenWt < Double.parseDouble(nWt)) {
							found = true;
							tempList.remove(nWt);
							break;
						}
					}
					if (!found) {
						tempList.remove(0);
					} else {
						winDecietfulWar++;
					}
					naomiWtListOrig = tempList;
				}
				System.out.println("Case #"+index+": "+ winDecietfulWar +" "+winNormalWar);						
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
