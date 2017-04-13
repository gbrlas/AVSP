import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class C 
{
	public static final int MAXN = 501;
	
	public static int n, count;
	public static int a [][] = new int [MAXN][MAXN];
	public static int min, max;
	
	public static int solve()
	{
		count = 0;
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)
				if (a [i][j] == 1)
					count++;
		int time = 0;
		ArrayList<Integer> newX = new ArrayList<Integer>();
		ArrayList<Integer> newY = new ArrayList<Integer>();
		ArrayList<Integer> oldX = new ArrayList<Integer>();
		ArrayList<Integer> oldY = new ArrayList<Integer>();
		while (count > 0)
		{
			newX.clear();
			newY.clear();
			oldX.clear();
			oldY.clear();
			time++;
			for (int k = min; k <= max; k++)
			{
				boolean exists = false;
				for (int i = 1; i < k; i++)
				{
					int j = k - i;
					if (a [i][j] == 1)
					{
						exists = true;
						if ((a [i][j - 1] == 0) && (a [i - 1][j] == 0))
						{
							oldX.add(i);
							oldY.add(j);
							count--;
						}
						if ((a [i - 1][j + 1] == 1) && (a [i][j + 1] == 0))
						{
							newX.add(i);
							newY.add(j + 1);
							count++;
						}
					}
				}
				if ((exists == false) && (k == min))
					min++;
			}
//			System.out.println("*********");
//			System.out.println(min + " " + max + " " + count);
//			System.out.println(newX.size() + " " + oldX.size());
			for (int i = 0; i < newX.size(); i++)
			{
				a [newX.get(i)][newY.get(i)] = 1;
				if (max < newX.get(i) + newY.get(i))
					max = newX.get(i) + newY.get(i);
			}
			for (int i = 0; i < oldX.size(); i++)
				a [oldX.get(i)][oldY.get(i)] = 0;
		}
		return time;
	}
	
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader input =  new BufferedReader (new FileReader (new File ("C-small.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("C-small.out")));
			int testNumber = Integer.parseInt(input.readLine());
			for (int t = 1; t <= testNumber; t++)
			{
				System.out.println(t);
				for (int i = 0; i < MAXN; i++)
					for (int j = 0; j < MAXN; j++)
						a [i][j] = 0;
				n = Integer.parseInt(input.readLine());
				min = MAXN * MAXN;
				max = 1;
				for (int i = 0; i < n; i++)
				{
					String line [] = input.readLine().split(" ");
					int x1 = Integer.parseInt(line [0]);
					int y1 = Integer.parseInt(line [1]);
					int x2 = Integer.parseInt(line [2]);
					int y2 = Integer.parseInt(line [3]);
					if (min > x1 + y1)
						min = x1 + y1;
					if (max < x2 + y2)
						max = x2 + y2;
//					System.out.println(x1 + " " + x2 + " " + y1 + " " + y2);
					for (int x = x1; x <= x2; x++)
						for (int y = y1; y <= y2; y++)
							a [x][y] = 1;
				}
				output.write("Case #" + t + ": " + solve ());
				output.newLine();
			}
			output.close();
			input.close();
		}
		catch (IOException ex)
		{
			ex.printStackTrace();
		}

	}

}
