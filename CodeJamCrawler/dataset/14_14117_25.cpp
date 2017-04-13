import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	
	public static void main(String[] args) throws FileNotFoundException {

		Scanner in = new Scanner(new File("B.in"));
		int numOfCases = in.nextInt();
		PrintWriter out = new PrintWriter(new File("B.txt"));
		
		double X,F,C,s,R ;
		
		for (int TC = 1 ; TC <= numOfCases ; TC++)
		{
			s = 0;
			R = 2 ;
			C = in.nextDouble();
			F = in.nextDouble();
			X = in.nextDouble();
			
			while ( (X/R) > ((C/R)+(X/(R+F))))
			{
				s+= (C/R);
				R+=F ;
			}
			s+=(X/R);
			
			out.println("Case #" + TC + ": " + s);
			System.out.println("Case #" + TC + ": " + s);
			
		}
		
		out.close();
	}
}
