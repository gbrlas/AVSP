/**
 * Google Code Jam - Round 1a - A. FreeCell
 * 
 * @author Eric Pelz
 * @date 5/20/11
 */
import java.io.*;
import java.util.*;
import java.lang.Math;

public class freeCell
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(new File("A-small-attempt1.in"));
		
        PrintWriter outF = new PrintWriter("A-small-attempt1.out.txt");
        int t = sc.nextInt();
		
        for (int i=0; i<t; i++) {
			boolean pdCase = false;
			boolean pgCase = false;
			
            int n = sc.nextInt();
            int pd = sc.nextInt();
			int pg = sc.nextInt();
			
			int d0=0;
			// check Pd case
			for (int d=1; d<=n; d++) {
				if ((pd%((1.0/d)*100)) == 0)
				{
					pdCase = true;
					System.out.println("Pd:True - d:" + d);
					d0=d;
					break;
				}
			}

			
			// check Pg case
			int numLost = (100-pg)*n;
			int total = 100*n;
			int dWon = (pd*d0)/100;
			
			if ((numLost>=(d0-dWon)) && ((total-numLost)>=dWon))
				pgCase=true;
				
			//output
			if (pgCase && pdCase)
				outF.println("Case #" + (i+1) + ": Possible");
			else
				outF.println("Case #" + (i+1) + ": Broken");
        }
		
        sc.close();
        outF.close();
    }
}