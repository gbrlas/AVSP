/*
3
4 O 2 B 1 B 2 O 4
3 O 5 O 8 B 100
2 B 2 B 1

Case #1: 6
Case #2: 100
Case #3: 4
*/

import java.util.*;

class a
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int num = s.nextInt();
		
		int count=0;
		while(count<num)
		{
			int n = s.nextInt();
			int o = 1, b = 1;
			int c_cur = 0;
			int b_c_prev = 0, o_c_prev = 0;
			
			int count1 = 0;

			while(count1 < n)
			{
				count1++;
				String x = s.next();
				int xp = s.nextInt();
				int dist;
				if(x.equals("B"))
				{
					if(xp < b)
						dist = b - xp;
					else
						dist = xp - b;
					b = xp;
					
					int diff = c_cur - b_c_prev;
					if(diff >= dist)
					{
						c_cur += 1;
						b_c_prev = c_cur;
					}
					else
					{
						c_cur = c_cur + dist - diff + 1;
						b_c_prev = c_cur;						
					}
				}
				
				else if(x.equals("O"))
				{
					if(xp < o)
						dist = o - xp;
					else
						dist = xp - o;
					o = xp;
					int diff = c_cur - o_c_prev;
					if(diff >= dist)
					{
						c_cur += 1;
						o_c_prev = c_cur;
					}
					else
					{
						c_cur = c_cur + dist - diff + 1;
						o_c_prev = c_cur;						
					}
				}
			}
			System.out.println("Case #" + (count + 1) + ": " + c_cur);
			count++;
		}
	}
}