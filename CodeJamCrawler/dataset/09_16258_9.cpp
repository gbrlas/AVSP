import java.util.Scanner;
import java.util.Arrays;

public class ProblemB
{
	public static void main(String args[])
	{
		int i, T;
		long N;
		boolean found = false;
		Scanner in = new Scanner(System.in);
		
		/* Read the value of T */
		T = in.nextInt();

		for(i = 0; i < T; i++)
		{
			String num = in.next();
			found = false;
			N = Long.parseLong(num);
			char[] arr = num.toCharArray();
			Arrays.sort(arr);
			long sortedN = Long.parseLong(new String(arr));
			int length = num.length();

			long curNum = N + 1;
			while(true)
			{
				char[] content = Long.toString(curNum).toCharArray();
				Arrays.sort(content);

				if(Long.parseLong(new String(content)) == sortedN)
					break;

				curNum++;
			}

			System.out.println("Case #" + (i+1) + ": " + curNum);
		}
	}


}
