package com.codejam.zero;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import com.codejam.utility.StringManipulation;

public class ThemePark {

	/**
	 * Google Code Jam 2010.
	 * ThemePark program.
	 * File Execution as -->>java com.codejam.zero.ThemePark /Users/v/codejam/f1.in
	 * f1.in is the name of the input file from google.
	 * @param args
	 */
	public static void main(String[] args) {
		//
		System.out.println("----------------START------------");
		StringManipulation strMan = null;
		Long totalCases = null;//Total test cases in the input file.
		Long currentTestIteration = new Long(0);//For indicating the test case, program is into
		
		Long positionPointer = null;
		Long totalPeople = null;
		Long availablePeople = null;
		Map<Long,Long> currencyMap = null;//Holds total Euros earned. 
		Long grandTotal = null;//Holds total euros as counting progresses.
		System.out.println("File :: " + args[0]);
		try {
			strMan = new StringManipulation();
			strMan.createFileRef(args[0]);
			strMan.createFileReader(strMan.getNewFile());
			strMan.createBufferedReader(strMan.getNewFR());
			
			System.out.println("----------------");
			totalCases = Long.parseLong(strMan.getRow());
			System.out.println("Total Cases to be solved : " + totalCases);
			
			if(totalCases.longValue() > 0)
				currencyMap = new HashMap<Long,Long>(totalCases.intValue());
			
			while(totalCases.longValue() != 0) {
				grandTotal = new Long(0);
				currentTestIteration++;
				System.out.println("TEST CASE --------" + currentTestIteration);
				
				strMan.intializeLimits(strMan.getRow());
				System.out.println("Max rounds>>" + strMan.getMaxRounds()+ " " + "people>>" + strMan.getMaxPeople() + " "+ "groups>>" + strMan.getMaxGroups());
				
				if(strMan.getMaxGroups() > 0)
					strMan.intializeGroups(strMan.getRow(),strMan.getMaxGroups());
				else if(strMan.getMaxGroups() <= 0)
					strMan.intializeGroups(strMan.getRow(),new Long(0));//Initialize List to 0.
				
				System.out.print("Group elements >>");
				if(null != strMan.getMaxGroupsElem() && !(strMan.getMaxGroupsElem().isEmpty())) {
					for(Long g : strMan.getMaxGroupsElem())
						System.out.print(g+" ");
					System.out.println("");
				}
				
				Long currentRound = new Long(1);
				Long currentGroup = new Long(1);
				positionPointer = new Long(1);
				totalPeople = new Long(0);
				if(strMan.getMaxRounds() > 0) {
					while(currentRound <= strMan.getMaxRounds()) {
						totalPeople = new Long(0);
						currentGroup = new Long(1);
						//System.out.println("Round ::" + currentRound + " " + "Total People ::" + totalPeople);
						if(strMan.getMaxGroups() > 0) {
							
							while((totalPeople < strMan.getMaxPeople())) {
								currentGroup++;
								if(positionPointer <= strMan.getMaxGroups()) {
									availablePeople = strMan.getMaxGroupsElem().get((positionPointer.intValue() - 1));
									if((totalPeople + availablePeople) > 0) {
										if((totalPeople + availablePeople) <= strMan.getMaxPeople()) {
											totalPeople += availablePeople;
											positionPointer++;
										} else {
											break;
										}
									}
								} else if(positionPointer > strMan.getMaxGroups()) {
									positionPointer = new Long(1);
									if((currentGroup > strMan.getMaxGroups())) break;
									if(strMan.getMaxGroups() == 1) {
										break;//Group of only 1 person.
									}
									availablePeople = strMan.getMaxGroupsElem().get((positionPointer.intValue() - 1));
									if((totalPeople + availablePeople) > 0) {
										if((totalPeople + availablePeople) <= strMan.getMaxPeople()) {
											totalPeople += availablePeople;
											positionPointer++;
										} else {
											break;
										}
									} else if((totalPeople + availablePeople) <= 0) {
										totalPeople = new Long(0);
										System.out.println("No one to occupy roller (Invalid group element) ::"+totalPeople);//Group has zero elements.
										break;
									}
								}
								if((currentGroup > strMan.getMaxGroups())) { 
									positionPointer = new Long(1); 
									break;
								}
							}
							
						} else {
							System.out.println("Invalid group ::"+strMan.getMaxGroups());
						}
						grandTotal += totalPeople;
						System.out.println("Round ::" + currentRound + " " + "Total People ::" + totalPeople);
						currentRound++;
					}
				} else {
					grandTotal += totalPeople;
					System.out.println("Roller will not start, as total rounds to be done is  ::"+strMan.getMaxRounds());
					System.out.println("Round :: 0 " + " " + "Total People ::" + totalPeople);
				}
				System.out.println("Case #" + currentTestIteration + ": "+grandTotal);
				currencyMap.put(currentTestIteration, grandTotal);
				totalCases--;
			}
			System.out.println("----------------RESULT---------");
			currentTestIteration = new Long(1);
			if(null != currencyMap && !currencyMap.isEmpty()) {
				
				//Write in the output file.
				strMan.writeFile(currencyMap,".", "outfile.in");
				
				//Display on console
				while(currentTestIteration <= currencyMap.size()) {
					System.out.println("Case #" + currentTestIteration + ": " + currencyMap.get(currentTestIteration));
					currentTestIteration++;
				}
			}
			System.out.println("----------------END------------");
		} catch (FileNotFoundException fne) {
			System.out.println("File not found :: " + fne.getMessage());
		} catch (IOException ie) {
			System.out.println("I/O error :: " + ie.getMessage());
		} catch (Exception e) {
			System.out.println("General error :: " + e.getMessage());
		}finally {
			availablePeople = null;
			strMan.getMaxGroupsElem().clear();
			strMan.setMaxGroupsElem(null);
			strMan = null;
		}
	}
}
