package code.jam.y2013.quali;

import java.io.*;
import java.util.*;

public class A
{
	static String path = "D:/Martin/TempFiles/";
	static String file = "A-small-attempt0.in";

	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(new File(path + file));
		int T = sc.nextInt();
		// Point[][] points = new Point[T][];
		// Integer[][] vendor = new Integer[T][];

		char[][] field = new char[4][4];
		TEST:
		for (int i = 1; i <= T; i++)
		{
			boolean notcomp = false;
			for (int row = 0; row < 4; row++)
			{
				field[row] = sc.next().toCharArray();
				for (char cs : field[row])
				{
					if (cs == '.')
						notcomp = true;
				}
			}
			
			for (int row = 0; row < 4; row++)
			{
				if (check(i, field[row]))
						continue TEST;
			}	

			for (int col = 0; col < 4; col++)
			{
				if (check(i, field[0][col],field[1][col],field[2][col],field[3][col]))
						continue TEST;
			}	
			if (check(i, field[3][0],field[2][1],field[1][2],field[0][3]))
				continue TEST;
			if (check(i, field[0][0],field[1][1],field[2][2],field[3][3]))
				continue TEST;


			System.out.println("Case #" + i + ": " + ((notcomp)?  "Game has not completed": "Draw"));
		}
	}

	static boolean check(int i, char... c1)
	{
		int t = 0;
		int o = 0;
		int x = 0;
		for (char c : c1)
		{
			if (c == 'X')
				x++;
			else if (c == 'T')
			{
				t++;
			} else if (c == 'O')
			{
				o++;
			}
		}
		if (x == 4 || (x == 3 && t == 1))
		{
			System.out.println("Case #" + i + ": " + "X won"); 
			return true;
		}	
		if (o == 4 || (o == 3 && t == 1))
		{	
			System.out.println("Case #" + i + ": " + "O won"); 
			return true;
		}	
		return false;
	}
}
