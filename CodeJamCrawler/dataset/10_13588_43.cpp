import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class ThemePark {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		PrintStream ps  = new  PrintStream( "output.out" );
		Scanner sc = new  Scanner( new  File( "input.in" ));

		int  T = sc.nextInt();
		sc.nextLine();

		for ( int  i =0;i<T;i++)
		{
			String vars = sc.nextLine();
			long R = Long.parseLong(vars.split(" ")[0]);
			long k = Long.parseLong(vars.split(" ")[1]);
			int N = Integer.parseInt(vars.split(" ")[2]);
			String grps = sc.nextLine();
			long output = compute(R,k,N,grps);
			ps.printf("Case #%d: "+output+"\n",i+1);
			System.out.println("Case #"+(i+1)+": "+output+"\n");
		}
	}

	private static long compute(long r, long k, int n, String grps) {
		long[] group = new long[n];
		String[] strgrp = grps.split(" ");
		int i = 0;
		
		for (String s : strgrp) {
			group[i++] = Long.parseLong(s);
		}
		int pointer = 0;
		long total = 0;
		
		long subtotal = 0;
		for (int j = 0; j < r; ++j) {
			int traverseCount =n;	
				while (k >= (subtotal + group[pointer]) && traverseCount > 0)
				{
					subtotal+= group[pointer];
					traverseCount -- ;
					pointer = (pointer+1)%n;								
				}			
					total += subtotal;					
					subtotal = 0;
		}	
		
		return total;
	}

}
