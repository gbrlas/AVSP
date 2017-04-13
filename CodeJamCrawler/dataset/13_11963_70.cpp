package code.jam.y2013.quali;

import java.io.File;
import java.util.Scanner;

public class B
{
	static String path = "D:/Martin/TempFiles/";
	static String file = "B-small-attempt0.in";

	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(new File(path + file));
		int T = sc.nextInt();

		for (int i = 1; i <= T; i++)
		{
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[][] field = new int[N][M];
			int[] maxrow = new int[N];
			int[] maxcol = new int[M];
			for (int row = 0; row < N; row++)
			{
				for (int col = 0; col < M; col++)
				{
					int val = sc.nextInt();
					field[row][col] = val;
					if (val > maxrow[row])
						maxrow[row] = val;
					if (val > maxcol[col])
						maxcol[col] = val;
				}
			}

			boolean ok = true;
			CHECK: for (int row = 0; row < N; row++)
			{
				for (int col = 0; col < M; col++)
				{
					int val = field[row][col];
					if (maxrow[row] > val && maxcol[col] > val)
					{
						ok = false;
						break CHECK;
					}
				}
			}

			System.out.println("Case #" + i + ": " + ((ok) ? "YES" : "NO"));
		}
	}

}
