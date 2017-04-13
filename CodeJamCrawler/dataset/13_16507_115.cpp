import java.io.BufferedWriter;
import java.util.*;

//port java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;	
//import java.lang.Math;
//import java.util.ArrayList;
//import java.util.HashMap;
public class Problem2

{
	public static void main(String args[])
	{
		String filename = args[0];
		int i=0,j=0;
		int testcase=0 ;
		int k=0;
		String out="";
		BufferedWriter bufferedWriter = null;
		try { BufferedReader in = new BufferedReader(new FileReader(filename));
		String str;

		boolean output;
		str = in.readLine();
		testcase = Integer.parseInt(str);

		//Construct the BufferedWriter object
		bufferedWriter = new BufferedWriter(new FileWriter("oneoutput.txt"));
		
		for (k=0;k <testcase; k++)
		{
			String result = null;
			int not_over =-1;
			int n=0,m=0;
			str = in.readLine(); //read n m
			String str1= str.substring(0, str.indexOf(' '));
			n = Integer.parseInt(str1);
			str= str.substring( str.indexOf(' ')+1);
			m = Integer.parseInt(str);
		
			int[][] grid=new int[n][m];
			int[][] currgrid=new int[n][m];
			int maxrow[]=new int [100];
			int maxcol[]=new int [100];
			for(i=0;i<n;i++)
			{
				StringTokenizer st1;
				str = in.readLine(); 
				st1 = new StringTokenizer(str, " ");

				for(j=0;j<m;j++)
				{
						grid[i][j] = Integer.parseInt(st1.nextToken());
				}
			}
			
					
			//logic
			/*	//if grid n,m is smaller than any of the row elements then it shld be largest in its row.
					
			 * 3 3
2 1 2
1 1 1
2 1 2
			*/
			
			for(i=0;i<n;i++) //for each row -->
			{
				//find max of row
				maxrow[i]=0;
				for(j=0;j<m;j++)
				{
					if(grid[i][j]>maxrow[i])
					{
						maxrow[i]=grid[i][j];
					}
				}
			} // 2 1 2
			for(i=0;i<m;i++) //for each col |
			{
				//find max of col
				maxcol[i]=0;
				for(j=0;j<n;j++)
				{
					if(grid[j][i]>maxcol[i])
					{
						maxcol[i]=grid[j][i];
					}
				}
			}// 2 1 2
			
			int success =0;
			
			for(i=0;i<n;i++) 
			{
				for(j=0;j<m;j++)
				{
					System.out.println("element at "+i+","+j+"="+grid[i][j]+" maxrow="+maxrow[i]+" maxcol="+maxcol[j]+" sucess="+success);
					if (grid[i][j] < maxrow[i] && grid[i][j]==maxcol[j])
					{
						success++;
					}
					if (grid[i][j] == maxrow[i])
					{
						success++;
					}
					
				}
			}
			System.out.println(" sucess="+success);
			
			if( success == n*m)
				result ="YES";
			else
				result ="NO";
			
		/*	for(i=0;i<n;i++) //for each row -->
			{
				//find max of row
				maxrow[i]=0;
				for(j=0;j<m;j++)
				{
					if(grid[i][j]>maxrow[i])
					{
						maxrow[i]=grid[i][j];
					}
				}
			}
			
			//mover by the maxrow[i] row wise
			for(i=0;i<n;i++) //for each row -->
			{
				for(j=0;j<m;j++)
						currgrid[i][j]=maxrow[i];
				
			}
			//								|
		
			
			//mover by the maxcol[i] col wise
			for(i=0;i<m;i++) 
			{
				for(j=0;j<n;j++)
						currgrid[j][i]=maxcol[i];
				
			}
			
	
			//logic end
			*/
			//logic ends here output has a string	
			out="Case #"+(k+1)+": "+result+"\n";
		/*	for(int r1=0;r1<output1.length();r1++)
			out = out+output1.charAt(r1)+", ";
			if (output1.length()>0)
			out= out.substring(0, out.length()-2);
			out=out+"]";
		*/	bufferedWriter.write(out);
			
		}
		in.close(); } 
		catch (IOException ex) {               ex.printStackTrace();} 
		finally {
			//Close the BufferedWriter
			try {
				if (bufferedWriter != null) {
					bufferedWriter.flush();
					bufferedWriter.close();
				}
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

	
}
