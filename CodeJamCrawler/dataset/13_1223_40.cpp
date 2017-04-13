

import java.util.Scanner;

public class TicTacToe
{
	static char[][] ttt;
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int rounds = scan.nextInt();
		ttt = new char[4][4];
		int curRound = 0;
		while(rounds-- > 0)
		{
			curRound++;
			boolean foundDot = false;
			for(int i = 0; i < 4;i++)
			{
				String s= scan.next();
				for(int j = 0; j < s.length();j++)
				{
					char c = s.charAt(j);
					if (c == '.')
						foundDot = true;
					ttt[i][j] = c;
				}
			}
			
			boolean x = checkWin('X');
			boolean o = checkWin('O');
			if(x == false && o == false)
			{
				if(foundDot) // game wasn't complete
				{
					System.out.println("Case #" + curRound + ": Game has not completed");
				}
				else
				{
					System.out.println("Case #" + curRound + ": Draw");
				}
			}
			else
			{
				if(x)
				{
					System.out.println("Case #" + curRound + ": X won");
				}
				else
				{
					System.out.println("Case #" + curRound + ": O won");
				}
			}
			
		}
		System.out.println(ttt);
	}
	
	static boolean checkWin(char c)
	{
		//boolean result = true;
		return checkRows(c) || checkCols(c) || checkDiags(c);
		
	}
	static boolean checkRows(char c)
	{
		boolean result = true;
		for(int i = 0; i < 4; i++)
		{
			result = true;
			for(int j = 0 ; j < 4; j++)
			{
				char cur = ttt[i][j];
				result &= (cur == c || cur == 'T');
			}
			if(result == true)
				return true;
		}
		return result;
	}
	static boolean checkCols(char c)
	{
		boolean result = true;
		for(int i = 0; i < 4; i++)
		{
			result = true;
			for(int j = 0 ; j < 4; j++)
			{
				result &= (ttt[j][i] == c || ttt[j][i] == 'T');
			}
			if(result)
				return true;
		}
		return result;
	}
	static boolean checkDiags(char c)
	{
		boolean result = true;
		boolean result2 = true;
		for(int i = 0; i < 4; i++)
		{
			result &= (ttt[i][i] == c || ttt[i][i] == 'T');
			result2 &= (ttt[3-i][i]==c || ttt[3-i][i]=='T');
		}
		
		return result || result2;
	}
	

}
