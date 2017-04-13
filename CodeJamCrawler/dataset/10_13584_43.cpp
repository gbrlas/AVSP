import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class SnapperChain {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		PrintStream ps  = new  PrintStream( "output.out" );
		Scanner sc = new  Scanner( new  File( "input.in" ));

		int  N = sc.nextInt();
		sc.nextLine();

		for ( int  i =0;i<N;i++)
		{
		String T = sc.nextLine();
		
		boolean   O  = computeOutput (T);
	    if(O)
	    	ps.printf("Case #%d: ON\n",i+1);
	    else
	    	ps.printf("Case #%d: OFF\n",i+1);
		
		}

		}

		private   static   boolean  computeOutput(String input) {
		// TODO  Auto-generated method stub
			Integer N = Integer.parseInt(input.split(" ")[0]);
			Integer K = Integer.parseInt(input.split(" ")[1]);
			if (K == 0)
				return false;
			System.out.println("K="+K+",N="+N+",Output:"+Math.pow(2, N));
			return ((K+1)%Math.pow(2, N))==0;
		
		}

}
