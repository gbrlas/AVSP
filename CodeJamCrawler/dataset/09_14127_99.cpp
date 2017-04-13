//Solution to 'Watersheds' for Code Jam qualification round 2009
//By Dmitry Kamenetsky

import java.io.*;
import java.util.*;

public class Watersheds
{
	static String[] dic;
	static int T,H,W;
	static int[] dx={0,-1,1,0};		//W
	static int[] dy={-1,0,0,1};		//H
	public static void main(String[] args) throws Exception
	{
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());


		for (int i=1; i<=T; i++)
		{
			String[] temp=(in.readLine()).split(" ");
			H=Integer.parseInt(temp[0]);
			W=Integer.parseInt(temp[1]);
			int[][] grid=new int[H][W];
			for (int k=0; k<H; k++)
			{
				String[] temp2=(in.readLine()).split(" ");
				for (int m=0; m<W; m++)
					grid[k][m]=Integer.parseInt(temp2[m]);
			}
			System.out.println("Case #"+i+":");
			solve(grid);
		}

		in.close();
	}

	public static void solve(int[][] grid)
	{
		char[][] grid2=new char[H][W];

		for (int i=0; i<H; i++)
			for (int k=0; k<W; k++)
				grid2[i][k]='#';

		//label sinks
		char cur='a';
		for (int y=0; y<H; y++)
		{
			for (int x=0; x<W; x++)
			{
				int lower=0;
				for (int m=0; m<dx.length; m++)
				{
					int x2=x+dx[m];
					int y2=y+dy[m];
					if (x2>=0 && x2<W && y2>=0 && y2<H && grid[y2][x2]<grid[y][x])
						lower++;
				}
				if (lower==0)
				{
					grid2[y][x]=cur;
					cur++;
				}
			}
		}

		//run water
		for (int y=0; y<H; y++)
		{
			for (int x=0; x<W; x++)
			{
				//if (grid2[y][x]!='#') continue;

				int curX=x;
				int curY=y;
				while(true)
				{
					if (grid2[curY][curX]!='#') break;
					int posX=-1;
					int posY=-1;
					int min=Integer.MAX_VALUE;
					for (int m=0; m<dx.length; m++)
					{
						int x2=curX+dx[m];
						int y2=curY+dy[m];
						if (x2>=0 && x2<W && y2>=0 && y2<H && grid[y2][x2]<min)
						{
							min=grid[y2][x2];
							posX=x2;
							posY=y2;	
						}
					}
					curX=posX;
					curY=posY;
				}
				grid2[y][x]=grid2[curY][curX];
			}
		}

		//sort chars
		char[][] grid3=new char[H][W];
		cur='a';
		for (int y=0; y<H; y++)
			for (int x=0; x<W; x++)
				grid3[y][x]='#';
		
		for (int y=0; y<H; y++)
		{
			for (int x=0; x<W; x++)
			{
				if (grid3[y][x]=='#')
				{
					for (int y2=0; y2<H; y2++)
						for (int x2=0; x2<W; x2++)
							if (grid2[y2][x2]==grid2[y][x])
								grid3[y2][x2]=cur;
					cur++;
				}
			}
		}

				

		//print answer
		for (int y=0; y<H; y++)
		{
			for (int x=0; x<W; x++)
				System.out.print(grid3[y][x]+" ");
			System.out.println();
		}
	}
}