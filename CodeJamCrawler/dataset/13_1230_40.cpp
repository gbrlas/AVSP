import java.util.Scanner;


public class FairAndSquare 
{

	static int[][] area;
	static int low,high;
	public static void main(String[] args) 
	{
		Scanner scan = new Scanner(System.in);
		int rounds = scan.nextInt();
		//ttt = new char[4][4];
		int curRound = 0;
		while(rounds-- > 0)
		{
			curRound++;
			low = scan.nextInt();
			high = scan.nextInt();
			int count = getCount(low,high);
			System.out.println("Case #" + curRound + ": " + count);
		}
	}
	
	static int getCount(int low, int high)
	{
		int count = 0;
		for(int i =low; i <= high; i++)
		{
			if(isPalindrone(i))
			{
				if(isSquare(i))
				{
					if(isPalindrone((int)Math.sqrt(i)))
					{
						//System.out.println("Found: " + i);
						count++;
					}
				}
			}
		}
		return count;
	}
	static boolean isPalindrone(int num)
	{
		boolean result = true;
		String s =String.valueOf(num);
		if(s.length()>1)
		{
			for(int i = 0; i < s.length()/2; i++)
			{
				result &= s.charAt(i) == s.charAt(s.length()-1-i);
			}
		}
		else
			return true;
		
		return result;
	}
	static boolean isSquare(int num)
	{
		boolean result = true;
		double number = Math.sqrt(num);
		int intNum = (int)number;
		return intNum == number;
	}
}
