/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	
	public static String resultString(int [][] first, int [][] second, int rowGuessOne, int rowGuessTwo)
	{
		int [] arrayOne = first[rowGuessOne-1];
		int [] arrayTwo = second[rowGuessTwo-1];
		
		ArrayList<Integer> rowOne = new ArrayList<Integer>();
		ArrayList<Integer> rowTwo = new ArrayList<Integer>();
		for(int i=0; i<arrayOne.length; i++)
			rowOne.add(arrayOne[i]);
		for(int i=0; i<arrayTwo.length; i++)
			rowTwo.add(arrayTwo[i]);
			
		ArrayList<Integer> common = new ArrayList<Integer>(rowOne);
		common.retainAll(rowTwo);
		if(common.size()==1)
			return common.get(0).toString();
		if(common.size()>1)
			return "Bad magician!";
		if(common.size()==0)
			return "Volunteer cheated!";
		
		
		
		return "";
		
		
	}

	public static void main (String[] args) throws java.lang.Exception
	{
		int numCases;
		int [][] first = new int[4][4];
		int [][] second = new int[4][4];
		
		Scanner in = new Scanner(System.in);
		numCases = in.nextInt();
		in.nextLine();
		int incrementCases = 1;
	//	System.out.println(numCases);
		while(incrementCases<=numCases)
		{
		//	System.out.println(incrementCases + "<" + numCases);
			int rowGuessOne = in.nextInt();
		
			in.nextLine();
			for(int i=0; i<first.length; i++)
			{
				for(int j=0; j<first[0].length; j++)
				{
					first[i][j]=in.nextInt();
					
				}
				in.nextLine();
			}
			
			int rowGuessTwo = in.nextInt();
			in.nextLine();
			for(int i=0; i<second.length; i++)
			{
				for(int j=0; j<second[0].length; j++)
				{
					second[i][j] = in.nextInt();
				}
				if(incrementCases!=numCases)
					in.nextLine();
			}
			
	    
		
				
		
		System.out.println("Case #"+incrementCases+": "+resultString(first, second, rowGuessOne, rowGuessTwo));
			
			incrementCases++;
		}
		
		
	
	}
}