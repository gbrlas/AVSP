import java.io.*;
import java.util.*;

class B
{
	public static void main(String[] args) throws Throwable
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i = 1; i <= T; i++)
		{
			int H = in.nextInt(), W = in.nextInt();
			int[][] alt = new int[H][W], flo = new int[H][W], fta = new int[H][W];
			char[][] let = new char[H][W];
			PriorityQueue<thing> hmph = new PriorityQueue<thing>();
			for(int j = 0; j < H; j++)
				for(int k = 0; k < W; k++)
				{
					fta[j][k] = alt[j][k] = in.nextInt();
					hmph.add(new thing(alt[j][k], j, k));
				}
			char cucu = 'a';
			while(!hmph.isEmpty())
			{
				thing woo = hmph.remove();
				int h = woo.alt;
				int x = woo.x;
				int y = woo.y;
				if(flo[x][y] == 0)
					let[x][y] = cucu++;
				else if(flo[x][y] == 1)
					let[x][y] = let[x-1][y];
				else if(flo[x][y] == 2)
					let[x][y] = let[x][y-1];
				else if(flo[x][y] == 3)
					let[x][y] = let[x][y+1];
				else
					let[x][y] = let[x+1][y];
				if(x > 0)
					if(h < fta[x-1][y] || (h == fta[x-1][y] && flo[x-1][y] > 4))
					{
						fta[x-1][y] = h;
						flo[x-1][y] = 4;
					}
				if(y > 0)
					if(h < fta[x][y-1] || (h == fta[x][y-1] && flo[x][y-1] > 3))
					{
						fta[x][y-1] = h;
						flo[x][y-1] = 3;
					}
				if(y < W-1)
					if(h < fta[x][y+1] || (h == fta[x][y+1] && flo[x][y+1] > 2))
					{
						fta[x][y+1] = h;
						flo[x][y+1] = 2;
					}
				if(x < H-1)
					if(h < fta[x+1][y] || (h == fta[x+1][y] && flo[x+1][y] > 1))
					{
						fta[x+1][y] = h;
						flo[x+1][y] = 1;
					}
			}
			HashMap<Character, Character> xx = new HashMap<Character, Character>();
			cucu = 'a';
			o("Case #"+i+":");
			for(int j = 0; j < H; j++)
				for(int k = 0; k < W; k++)
				{
					if(xx.containsKey(let[j][k]))
						System.out.print(xx.get(let[j][k]));
					else
					{
						xx.put(let[j][k], cucu++);
						System.out.print(xx.get(let[j][k]));
					}
					if(k < W-1)
						System.out.print(" ");
					else
						System.out.println();
				}
		}
		System.exit(0);
	}
	static void o(String s)
	{
		System.out.println(s);
	}
}

class thing implements Comparable<thing>
{
	public int alt, x, y;
	public thing(int ALT, int X, int Y)
	{
		alt = ALT;
		x = X;
		y = Y;
	}
	public int compareTo(thing o)
	{
		return alt - o.alt;
	}
}