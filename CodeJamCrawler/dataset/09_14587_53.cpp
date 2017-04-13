import java.io.*;
import java.util.*;

public class Watersheds {

	
	public static void main(String[] args)
	{
		int T, H=0, W=0;
		int altitudes[][][] = null;
		char basinData[][][] = null; 
		char basin;
		
		try
		{
			Scanner scanner = new Scanner(new File("B-small-attempt0.in"));
			PrintWriter outputStream = new PrintWriter(new FileOutputStream("output.out"));
			
			T = scanner.nextInt();
			
			altitudes =  new int[T][][];
			basinData = new char[T][][];
			
			for(int i = 0; i < T; i++)
			{	
				H = scanner.nextInt();
				W = scanner.nextInt();	
				
				altitudes[i] = new int[H+2][W+2];
				basinData[i] = new char[H+2][W+2];
				
				for(int j = 1; j <= H; j++)
				{
					altitudes[i][j][0] = 99999;
					altitudes[i][j][W+1] = 99999;
					basinData[i][j][0] = '+';
					basinData[i][j][W+1] = '+';
					for(int k = 1; k <= W; k++)
					{
						altitudes[i][j][k] = scanner.nextInt();
						basinData[i][j][k] = '-';
						//System.out.print(altitudes[i][j][k] + " ");
					}
					for(int l = 0; l < W+2; l++)
					{
						altitudes[i][0][l] = 99999;
						altitudes[i][H+1][l] = 99999;
						basinData[i][0][l] = '+';
						basinData[i][H+1][l] = '+';
					}
					//System.out.println();
				}
				
				basin = (char)('a' - 1);
				
				for(int j = 1; j < H+1; j++)
					for(int k = 1; k < W+1; k++)
						if(basinData[i][j][k] == '-')
							basin = findSink(altitudes, basinData, i, j, k, basin);

				outputStream.println("Case #" + (i+1) + ":" + " ");
				System.out.println("Case #" + (i+1) + ":" + " ");
				for(int j = 1; j < H+1; j++)
				{
					for(int k = 1; k < W+1; k++)
					{
						outputStream.print(basinData[i][j][k] + " ");
						System.out.print(basinData[i][j][k] + " ");
					}
					outputStream.println();
					System.out.println();
				}
			}
			
			scanner.close();
			
			
			
/*			for(int i = 0; i < T; i++)			
				for(int j = 1; j < H+1; j++)
				{
					for(int k = 1; k < W+1; k++)
						System.out.print(i+"\'"+ j +"\'"+ k +":"+ basinData[i][j][k] + " ");
					System.out.println("A");
				}
*/			outputStream.close();
		}
		catch(FileNotFoundException e)
		{
			System.out.println("FileNotFoundException");
		}
/*		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("ArrayIndexOutOfBoundsException");
		}*/
		catch(IOException e)
		{
			System.out.println("IOException");
		}
	}

	static char findSink(int alt[][][], char bas[][][], int map, int h, int w, char currBas)
	{
		char temp;
		if(alt[map][h-1][w] < alt[map][h][w] &&
				alt[map][h-1][w] <= alt[map][h][w-1] &&
				alt[map][h-1][w] <= alt[map][h][w+1] &&
				alt[map][h-1][w] <= alt[map][h+1][w])
		{
			temp = findSink(alt, bas, map, h-1, w, currBas);
			bas[map][h][w] = temp;
			return temp;
		}
		else if(alt[map][h][w-1] < alt[map][h][w] &&
				alt[map][h][w-1] <= alt[map][h][w+1] &&
				alt[map][h][w-1] <= alt[map][h+1][w])
		{
			temp = findSink(alt, bas, map, h, w-1, currBas);
			bas[map][h][w] = temp;
			return temp;
		}
		else if(alt[map][h][w+1] < alt[map][h][w] &&
				alt[map][h][w+1] <= alt[map][h+1][w])
		{
			temp = findSink(alt, bas, map, h, w+1, currBas);
			bas[map][h][w] = temp;
			return temp;
		}
		else if(alt[map][h+1][w] < alt[map][h][w])
		{
			temp = findSink(alt, bas, map, h+1, w, currBas);
			bas[map][h][w] = temp;
			return temp;
		}
		else if(bas[map][h][w] == '-')
		{
			bas[map][h][w] = ++currBas;
			return currBas;
		}
		else
			return bas[map][h][w];
	}
}