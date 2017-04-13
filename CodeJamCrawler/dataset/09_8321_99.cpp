import java.io.*;
import java.util.*;

public class C
{
	public static void main(String[] args) throws Throwable
	{
		Scanner in = new Scanner(System.in);
		int N = Integer.parseInt(in.nextLine());
		char[] word = "welcome to code jam".toCharArray();
		for(int i = 1; i <= N; i++)
		{
			char[] rawr = in.nextLine().toCharArray();
			int[] pra = new int[word.length];
			for(char c : rawr)
				for(int j = 0; j < word.length; j++)
					if(word[j] == c)
						if(j == 0)
							pra[0]++;
						else
							pra[j] = (pra[j] + pra[j-1])%10000;
			System.out.println("Case #"+i+": "+make4(pra[word.length-1]));
		}
		System.exit(0);
	}
	static String make4(int x)
	{
		String s = ""+x;
		while(s.length() < 4)
			s = "0"+s;
		return s;
	}
}
