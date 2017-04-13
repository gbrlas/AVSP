
package qualification.allenlanguage;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
	AllenLanguage.java
	Created by Sanehiro Kodama on 9/3/09.
	Copyright (c) 2009 Sanehiro Kodama. All rights reserved.
 *
 */
public class AllenLanguage 
{

	private int[][][] dictionary;
	private int[] paramArray;
	
	// constructor
	public AllenLanguage(String fileName)
	{
		Scanner sc = null;
		
		try
		{
			sc = new Scanner(new File(fileName));
			
			// read first line to read in parameters
			String params = sc.nextLine();
			Scanner sc1 = new Scanner(params).useDelimiter(" ");
			paramArray = new int[3];
			int paramCount = 0;
			while(sc1.hasNext())
			{
				paramArray[paramCount] = sc1.nextInt();
				paramCount++;
			}
			sc1.close();
			
			// initialize dictionary (populate with ZERO)
			dictionary = initDictionary(paramArray[0], paramArray[1]);
			
			// populate dictionary with actual word data
			populateDictionary(dictionary, sc, paramArray[0], paramArray[1]);
			
			countMatches(sc, paramArray[1]);
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
		finally
		{
			if(sc != null)
			{
				sc.close();
			}
		}
	}
	
	// initialize dictionary
	private int[][][] initDictionary(final int l, final int d)
	{
		// 3D array to store words
		// x: num of words, y: word, z: alphabet
		int[][][] dict = new int[d][l][27];
		
		for (int i = 0 ; i < d ; i++) {		
			for (int j = 0 ; j < l ; j++) {
				for (int k = 0 ; k < 27 ; k++){
					dict[i][j][k] = 0;
				}
			}
		}
		
		return dict;
	}
	
	// create dictionary
	private void populateDictionary(int[][][] dictionary, Scanner input, final int l, final int d)
	{
		int wordCount = 0;
		while(input.hasNext() && wordCount < d)
		{
			String word = input.nextLine();
			for(int i = 0 ; i < l ; i++)
			{ 
				dictionary[wordCount][i][getCharNum(word.charAt(i))] = 1;
			}
			
			wordCount++;
		}
		
	}
	
	private void countMatches(Scanner input, final int l)
	{
		PrintWriter out = null;
		
		try
		{
			out = new PrintWriter(new File("A-Large.out"));
			
			int caseCount = 1;
			while(input.hasNext())
			{
				// prepare match array
				int[][] mpArray = initMatchPatternArray(l);
				
				String matchPattern = input.nextLine();
				
				int openPrtIdx = 0;
				int closePrtIdx = 0;
				int lPosition = 0;
				do
				{

					openPrtIdx = matchPattern.indexOf("(");
					closePrtIdx = matchPattern.indexOf(")");
					
					String token = matchPattern;
					boolean isSelection = false;
					if(openPrtIdx > 0)
					{
						token = matchPattern.substring(0, openPrtIdx);
						matchPattern = matchPattern.substring(openPrtIdx);
						isSelection = false;
					}
					else if(openPrtIdx == 0)
					{
						token = matchPattern.substring(openPrtIdx + 1, closePrtIdx);
						matchPattern = matchPattern.substring(closePrtIdx + 1);
						isSelection = true;
					}
					
					System.out.println(token);
					
					if(isSelection)
					{
						for(int i = 0 ; i < token.length() ; i++)
						{
							mpArray[lPosition][getCharNum(token.charAt(i))] = 1;
						}
						
						lPosition++;
					}
					else
					{
						for(int i = 0 ; i < token.length() ; i++)
						{
							mpArray[lPosition][getCharNum(token.charAt(i))] = 1;
							lPosition++;
						}
					}

					
				}while(openPrtIdx >= 0 && matchPattern.length() > 0);
				
				// match dictionary
				int matchCount = 0;
				for(int i = 0 ; i < dictionary.length ; i++)
				{
					String word = "";
					boolean matchedChar = true;
					for(int j = 0 ; j < dictionary[1].length && matchedChar; j++)
					{ 
						boolean foundChar = false;
						for(int k = 0 ; k < 27 && !foundChar ; k++)
						{
							if(dictionary[i][j][k] ==1 && mpArray[j][k] == 1)
							{
								word += (char)(k + 97);
								foundChar = true;
							}
						}
						
						matchedChar = foundChar;
					}
					
					if(matchedChar)
					{
						matchCount++;
					}
//					System.out.println(word);
				}
				
				// output result
				out.println("Case #" + caseCount + ": " + matchCount);
				
				caseCount++;
			}
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
		finally
		{
			if(out != null)
			{
				out.close();
			}
		}
		
	}
	
	private int[][] initMatchPatternArray(final int l)
	{
		int[][] mpa = new int[l][27];
		for(int i = 0 ; i < l ; i++)
		{
			for(int j = 0 ; j < 27 ; j++)
			{
				mpa[i][j] = 0;
			}
		}
		
		return mpa;
	}
	
	
	public void showDictionary()
	{
		for(int i = 0 ; i < dictionary.length ; i++)
		{
			String word = "";
			for(int j = 0 ; j < dictionary[1].length ; j++)
			{ 
				for(int k = 0 ; k < 27 ; k++)
				{
					if(dictionary[i][j][k] == 1)
					{
						word += (char)(k + 97);
					}
				}
			}
			
			System.out.println(word);
		}
	}
	
	private int getCharNum(char ch)
	{
		// ascii code for a = 97
		return (int)ch - 97;
	}


	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		AllenLanguage test = new AllenLanguage("A-large.in");
//		test.showDictionary();
	}
}