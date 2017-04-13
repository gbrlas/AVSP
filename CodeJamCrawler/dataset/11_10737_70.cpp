import java.util.Arrays;
import java.util.Scanner;

public class BotTrust {

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			int n = sc.nextInt();
			char[] s = new char[n];
			int[] num = new int[n];
			for (int i = 0; i < n; i++)
			{
				s[i] = sc.next().charAt(0);
				num[i] = sc.nextInt();
			}
			System.out.println("Case #" + c + ": " + solve(s, num));
		}
	}

	static void debug(Object... objects)
	{
		System.out.println(Arrays.deepToString(objects));
	}

	private static long solve(char[] s, int[] num)
	{
		int no = 0;
		int nb = 0;
		for (int i = 0; i < s.length; i++)
		{
			if (s[i] == 'O')
				no++;
			if (s[i] == 'B')
				nb++;
		}
		int O[] = new int[no];
		int B[] = new int[nb];
		int co = 0;
		int cb = 0;
		for (int i = 0; i < s.length; i++)
		{
			if (s[i] == 'O')
			{
				O[co++]=num[i];
			}
			else if (s[i] == 'B')
			{
				B[cb++]=num[i];
			}
		}
		co = 0;
		cb = 0;
		
		long mint=0;
		int poso = 1;
		int posb = 1;
		int ts = 0;
		for(int i=0;i<s.length;i++)
		{
			if(s[i]=='O')
			{
				ts = Math.abs(O[co] - poso) + 1;
				poso = O[co];
				co++;
				mint+=ts;
				
				if(cb >= B.length) continue;
				
				if(posb > B[cb])
				{
					posb = Math.max(B[cb],posb - ts);
				}
				else if(posb < B[cb])
				{
					posb = Math.min(B[cb],posb + ts);
				}
			}
			else if(s[i]=='B')
			{
				ts = Math.abs(B[cb] - posb) + 1;
				posb = B[cb];
				cb++;
				mint+=ts;
				
				if(co >= O.length) continue;
				
				if(poso > O[co])
				{
					poso = Math.max(O[co],poso - ts);
				}
				else if(poso < O[co])
				{
					poso = Math.min(O[co],poso + ts);
				}
			}
		}
		
		return mint;
	}
}
