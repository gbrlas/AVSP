import java.util.*;
import java.math.*;
import java.io.*;

public class c
{
	static Scanner in = new Scanner(System.in);
	static boolean[][] bw = new boolean[1][1];
	static boolean[][] used = new boolean[1][1];
	static int M = 0;
	static int N = 0;
	static int pbig = 512;
	public static void main(String[] args) throws Throwable
	{
		int tt = ip(in.nextLine());
		for(int iter = 1; iter <= tt; iter++)
		{
			System.out.print("Case #"+iter+": ");
			String[] t = in.nextLine().split(" ");
			M = ip(t[0]);
			N = ip(t[1]);
			int K = 0;
			pbig = Math.min(M, N);
			bw = new boolean[M][N];
			used = new boolean[M][N];
			int[] areas = new int[pbig+1];
			for(int i = 0; i < M; i++)
			{
				char[] c = in.nextLine().toCharArray();
				for(int j = 0; j < N; j += 4)
				{
					int curr = 0;
					if(c[j>>2] >= 'A' && c[j>>2] <= 'F')
						curr = c[j>>2] - 'A' + 10;
					else
						curr = c[j>>2] - '0';
					bw[i][j] = (curr&8)!=0;
					bw[i][j+1] = (curr&4)!=0;
					bw[i][j+2] = (curr&2)!=0;
					bw[i][j+3] = (curr&1)!=0;
				}
			}
			int area = M*N;
			while(area > 0)
			{
				int z = doyt();
				if(z == 1)
					break;
				else
				{
					area -= z*z;
					areas[z]++;
					if(areas[z] == 1)
						K++;
				}
			}
			if(area > 0)
				K++;
			System.out.println(K);
			for(int i = Math.min(M, N); i >= 2; i--)
				if(areas[i] > 0)
					System.out.println(i + " " + areas[i]);
			if(area > 0)
				System.out.println("1 " + area);
		}
	}
	static int doyt()
	{
		int best = 0;
		int q = -1, r = -1;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
			{
				int pbest = best;
				int yuh = pbig;
				while(best < yuh - 2)
				{
					int mid = (yuh + best)/2;
					if(isYouGoodness(i,j,mid))
						best = mid;
					else
						yuh = mid - 1;
				}
				while(isYouGoodness(i,j,best+1))
					best++;
				if(pbest != best)
				{
					q = i;
					r = j;
				}
			}
		for(int i = 0; i < best; i++)
			for(int j = 0; j < best; j++)
				used[q+i][r+j] = true;
		return best;
	}
	static boolean isYouGoodness(int x, int y, int r)
	{
		if(x + r > M || y + r > N)
			return false;
		boolean ref = bw[x][y] ^ (((x&1) ^ (y&1))==1?true:false);
		for(int i = 0; i < r; i++)
			for(int j = 0; j < r; j++)
				if(ref != bw[x+i][y+j] ^ ((((x+i)&1) ^ ((y+j)&1))==1?true:false) || used[x+i][y+j])
					return false;
		return true;
	}
	static int ip(String a)
	{
		return Integer.parseInt(a);
	}
}