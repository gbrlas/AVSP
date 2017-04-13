import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class TicTacToeTomek {

	
	public static int check (int a [][])
	{
//		return 1: X won , 2 : O won , 0 :Draw , 3: Not completed
		
		int sum = 0;
		
//		Check rows
		for (int i =0;i<a.length;i++)
		{
			sum = a[i][0] + a[i][1]+a[i][2]+a[i][3];
			if (sum == 4 || sum == 103)
				return 1;
			else if(sum == 40 || sum == 130)
				return 2;
		}
		
//		Check columns
		for (int i =0;i<a.length;i++)
		{
			sum = a[0][i] + a[1][i]+a[2][i]+a[3][i];
			if (sum == 4 || sum == 103)
				return 1;
			else if(sum == 40 || sum == 130)
				return 2;
		}
		
		sum = a[0][0] + a[1][1]+a[2][2]+a[3][3];
		if (sum == 4 || sum == 103)
			return 1;
		else if(sum == 40 || sum == 130)
			return 2;
		
		sum = a[0][3] + a[1][2]+a[2][1]+a[3][0];
		if (sum == 4 || sum == 103)
			return 1;
		else if(sum == 40 || sum == 130)
			return 2;
		
		for (int i =0;i<a.length;i++)
			for (int j=0;j<a[0].length;j++)
				if (a[i][j]  == 0)
					return 3;
		
		return 0;
	}
	
	public static int [][] fillArray (int [][] a ,String line , int row)
	{
		for (int i = 0 ; i < 4 ;i++)
		{
			if (line.charAt(i) == 'X')
				a [row][i]=1;
			else if (line.charAt(i) == 'O')
				a [row][i]=10;
			else if (line.charAt(i) == 'T')
				a [row][i]=100;
			else if (line.charAt(i) == '.')
				a [row][i]=0;
		}
		
		return a;
	}
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("input.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		String in_line = "";
		int result = 0;
		
		int numOfCases = Integer.parseInt(in.readLine());
		int [] [] a = new int [4][4];
		
		for (int i =0;i<numOfCases;i++)
		{
			for (int k=0;k<4;k++)
			{
				in_line = in.readLine();
				fillArray(a, in_line, k);
			}
			
			in.readLine(); // Empty line after each test case
			result = check(a);
//			return 1: X won , 2 : O won , 0 :Draw , 3: Not completed
			if (result == 1)
				out.println("Case #" + (i+1) + ": X won");
			else if (result == 2)
				out.println("Case #" + (i+1) + ": O won");
			else if (result == 0)
				out.println("Case #" + (i+1) + ": Draw");
			else if (result == 3)
				out.println("Case #" + (i+1) + ": Game has not completed");
			
		}
		
		in.close();
		out.close();
	}
}
