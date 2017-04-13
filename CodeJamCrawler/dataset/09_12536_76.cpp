package qualification.watersheds;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Watersheds.java
 * 
 *	Created by Sanehiro Kodama on 9/3/09.
	Copyright (c) 2009 Sanehiro Kodama. All rights reserved.
 */

public class Watersheds 
{
	private final int NORTH = 0;
	private final int WEST = 1;
	private final int EAST = 2;
	private final int SOUTH = 3;
	
	private int[][][] elevationMap;
	
	private static char basinLabel = 'a';	// a
	
	private static final String INPUT_FILE = "B-small2.in";
//	private static final String INPUT_FILE = "watershedtest.txt";
	private static final String OUTPUT_FILE = "B-small.out";
	
	public Watersheds(String fileName)
	{
		Scanner sc = null;
		PrintWriter pw = null;
		try
		{
			sc = new Scanner(new File(fileName)).useDelimiter("[\r\n ]");
			pw = new PrintWriter(new File(OUTPUT_FILE));
			
			// read first line to read in parameters
			int t = sc.nextInt();
			sc.nextLine();
			
			for(int i = 0 ; i < t ; i++)
			{
				int h = sc.nextInt();
				int w = sc.nextInt();
				
				System.out.println(h + " " + w);
				
				initMap(h, w, sc);
				
				
				for(int row = 0 ; row < h ; row++)
				{
					for(int colmn = 0 ; colmn < w ; colmn++)
					{
						getBasin(row, colmn);
					}
				}
				
				printMap(i+1, pw, h, w);
			}
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
			
			if(pw != null)
			{
				pw.flush();
				pw.close();
			}
		}
	}
	
	private void initMap(int h, int w, Scanner input)
	{
		basinLabel = 'a';
		
		elevationMap = new int[h][w][2];
		
		for(int i = 0 ; i < h ; i++)
		{
			input.nextLine();
			for(int j = 0 ; j < w ; j++)
			{
				elevationMap[i][j][0] = input.nextInt();
				elevationMap[i][j][1] = 0;
			}
			
		}
	}
	
	private void printMap(int caseNum, PrintWriter pw, int h, int w)
	{
		pw.println("Case #" + caseNum + ":");
		for(int i = 0 ; i < h ; i++)
		{
			String row = "";
			for(int j = 0 ; j < w ; j++)
			{
				row += (char)elevationMap[i][j][1] + " ";
			}
			pw.println(row.trim());
		}
		pw.flush();
	}
	
	private int getBasin(int row, int colmn)
	{
		// process if basin is not determined yet
		if(elevationMap[row][colmn][1] == 0)
		{
			int[] nwes = {Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE};
			
			if(row - 1 >= 0)
			{
				// north
				nwes[NORTH] = elevationMap[row - 1][colmn][0];
			}
			
			if(colmn - 1 >= 0)
			{
				// west
				nwes[WEST] = elevationMap[row][colmn - 1][0];
			}
			
			if(colmn + 1 < elevationMap[0].length)
			{
				// east
				nwes[EAST] = elevationMap[row][colmn+1][0];
			}
			
			if(row + 1 < elevationMap.length)
			{
				// south
				nwes[SOUTH] = elevationMap[row + 1][colmn][0];
			}
			
			int min = nwes[NORTH];
			int direction = NORTH;
			for(int i = 1 ; i < nwes.length ; i++)
			{
				if(min > nwes[i])
				{
					min = nwes[i];
					direction = i;
				}
			}
			
			if(min >= elevationMap[row][colmn][0])
			{
				// sink
				elevationMap[row][colmn][1] = basinLabel;
				basinLabel++;
			}
			else
			{
				switch(direction)
				{
				case NORTH:
					elevationMap[row][colmn][1] = getBasin(row-1, colmn);
					break;
				case WEST:
					elevationMap[row][colmn][1] = getBasin(row, colmn-1);
					break;
				case EAST:
					elevationMap[row][colmn][1] = getBasin(row, colmn+1);
					break;
				case SOUTH:
					elevationMap[row][colmn][1] = getBasin(row+1, colmn);
					break;
					default:
				}
				
			}
		}
		
		return elevationMap[row][colmn][1];
	}
	
	public static void main(String[] args)
	{
		Watersheds test = new Watersheds(INPUT_FILE);
	}
}


