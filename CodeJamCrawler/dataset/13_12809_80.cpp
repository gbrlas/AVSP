import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;


public class Lawnmower {

	static HashMap<Integer, Integer> row_max = new  HashMap<>();
	static HashMap<Integer, Integer> column_max = new  HashMap<>();
	
	public static void fillHashTables (int [][] a)
	{
		int max ;
//		fill row_max
		for (int i=0;i<a.length;i++)
		{			
			max = a[i][0];
			for (int j = 1;j<a[0].length;j++)
				if (a[i][j] > max)
					max = a[i][j];
			
			row_max.put(i, max);
		}
		
//		fill column_max
		for (int i=0;i<a[0].length;i++)
		{			
			max = a[0][i];
			for (int j = 1;j<a.length;j++)
				if (a[j][i] > max)
					max = a[j][i];
			
			column_max.put(i, max);
		}
	}
	
	public static boolean check (int [][] a)
	{
		for (int x=0;x<a.length;x++)
		{
			for (int y = 0;y<a[0].length;y++)
				if (a[x][y] < row_max.get(x) &&  a[x][y] < column_max.get(y))
					return false;
		}
		return true ;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("input.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		String in_line = "";
		String [] parms ;
		int numOfCases = Integer.parseInt(in.readLine());
		int [] [] a ;
		for (int i =0;i<numOfCases;i++)
		{
			in_line = in.readLine();
			parms = in_line.split(" ");
			a = new int [Integer.parseInt(parms[0])][Integer.parseInt(parms[1])];
			for (int k =0;k<a.length;k++)
			{
				in_line = in.readLine();
				parms = in_line.split(" ");
				for (int m = 0;m<a[0].length;m++)
					a[k][m] = Integer.parseInt(parms[m]);
			}
			
			fillHashTables(a);
			if (check(a))
				out.println("Case #" + (i+1) + ": YES");
			else
				out.println("Case #" + (i+1) + ": NO");
		}
		
		in.close();
		out.close();
		
	}
}
