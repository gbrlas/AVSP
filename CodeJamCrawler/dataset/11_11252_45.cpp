/**
 * Google Code Jam - Qualification Round - A. Bot Trust
 * 
 * @author Eric Pelz
 * @date 5/06/11
 */
import java.io.*;
import java.util.*;
import java.lang.Math;

public class botTrust
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(new File("A-large.in"));

        PrintWriter outF = new PrintWriter("A-large.out");
        int t = sc.nextInt();

        for (int i=0; i<t; i++) {
        	int n = sc.nextInt();
        	
        	ArrayList<Integer> olist = new ArrayList<Integer>();
        	ArrayList<Integer> blist = new ArrayList<Integer>();
        	ArrayList<String> order = new ArrayList<String>();
        	for (int j=0; j<n; j++) {
        		String c = sc.next();
        		int temp = sc.nextInt();
        		if (c.equals("O"))
        			olist.add(temp);
        		else
        			blist.add(temp);
				order.add(c);
        	}
			
        	int counter = 0;
        	
        	int oposition = 1;
        	int bposition = 1;

        	while (!order.isEmpty())
        	{
				Boolean removeOrder = false;
        		// orange
				if (!olist.isEmpty())
				{
					if (oposition == olist.get(0))
					{
						//stay
						if (order.get(0).equals("O"))
						{
							//push orange
							removeOrder = true;
							olist.remove(0);
						}
					}
					else if (oposition > olist.get(0))
					{
						//move back one
						oposition--;
					}
					else
					{
						//move forward one
						oposition++;
					}
				}
				
				// blue
				if (!blist.isEmpty())
				{
					if (bposition == blist.get(0))
					{
						//stay
						if (order.get(0).equals("B"))
						{
							//push blue
							removeOrder = true;
							blist.remove(0);
						}
					}
						else if (bposition > blist.get(0))
						{
							//move back one
							bposition--;
						}
						else
						{
							//move forward one
							bposition++;
						}
				}
				
				if (removeOrder)
					order.remove(0);
				counter++;
        	}
            outF.println("Case #" + (i+1) + ": " + counter);
        }

        sc.close();
        outF.close();
    }
}