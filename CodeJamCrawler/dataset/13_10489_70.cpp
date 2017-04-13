import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new File("B-large.out"));
		
		int t = in.nextInt();
		
		for(int c = 0; c < t; c++)
		{
			int w = in.nextInt();
			int h = in.nextInt();
			int [][] lawn = new int[w][h];
			for(int i = 0; i < lawn.length; i++)
			{
				for(int j = 0; j < lawn[i].length; j++)
				{
					lawn[i][j] = in.nextInt();
				}
			}
			
			boolean ok = true;
			
			
			int [] maxr = new int[w];
			int [] maxc = new int[h];
			for(int i = 0; i < w; i++)
				maxr[i] = Integer.MIN_VALUE;
			
			for(int i = 0; i < h; i++)
				maxc[i] = Integer.MIN_VALUE;
			
			for(int i = 0; i < w; i++)
			{
				
				for(int j = 0; j < h; j++)
				{
					if(lawn[i][j] > maxr[i])
						maxr[i] = lawn[i][j];
					if(lawn[i][j] > maxc[j])
						maxc[j] = lawn[i][j];
				}
			}
			
			
			
			
			if(c == 8)
				System.out.println("8");
			for(int i = 0; i < w && ok; i++)
			{
				for(int j = 0; j < h && ok; j++)
				{
					ok = checkPos(lawn, i, j, maxr, maxc);
				}
			}
			
			String ans = "YES";
			if(!ok)
				ans = "NO";
			out.printf("Case #%d: %s\n",c+1, ans);
			
		}
		
		out.flush();
		out.close();
		in.close();
	}
	
	
	
	public static boolean checkPos(int [][] board, int x, int y, int [] maxr, int [] maxc)
	{
		int v = getVal(board, x, y);
		if(v == maxr[x])
			return true;
		if(v == maxc[y] )
			return true;
		return false;
	}
	
	public static int getVal(int [][] board, int x, int y)
	{
		if(x < 0 || x >= board.length || y < 0 || y >= board[x].length)
			return 0;
		return board[x][y];
		
	}
}
