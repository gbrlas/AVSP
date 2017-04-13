import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class C 
{
	public static final int MAXN = 501;
	public static final long MODULO = 100003;
	
	public static int n;
	public static long count;
	public static long bin [][] = new long [MAXN][MAXN];
	public static long d [][] = new long [MAXN][MAXN];
	
	public static void solve ()
	{
		bin [0][0] = 1;
		for (int i = 1; i < MAXN; i++)
		{
			bin [i][0] = 1;
			bin [i][i] = 1;
			for (int j = 1; j < i; j++)
				bin [i][j] = (bin [i - 1][j] + bin [i - 1][j - 1]) % MODULO;
		}
		for (int i = 0; i < MAXN; i++)
		{
			for (int j = 0; j < MAXN; j++)
				d [i][j] = -1;
//			System.out.println(i + " " + bin [i][3]);
		}
		
		d [2][1] = 1;
		for (n = 3; n < MAXN; n++)
		{
			d [n][1] = 1;
			for (int m = 2; m <= n - 1; m++)
			{
				d [n][m] = 0;
				for (int k = 1; k <= m - 1; k++)
					d [n][m] = (d [n][m] + d [m][k] * bin [n - m - 1][m - k - 1]) % MODULO; 
			}
		}
	}
	
	public static void main(String[] args) 
	{
		solve ();
		try
		{
			BufferedReader input =  new BufferedReader (new FileReader (new File ("C-large.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("C-large.out")));
			int testNumber = Integer.parseInt(input.readLine());
			for (int t = 1; t <= testNumber; t++)
			{
				String line [] = input.readLine().split(" ");
				n = Integer.parseInt(line [0]);
				System.out.println(t + ": " + n);
				
				count = 0;
				for (int i = 1; i <= n - 1; i++)
					count = (count + d [n][i]) % MODULO;
				output.write("Case #" + t + ": " + count);
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
