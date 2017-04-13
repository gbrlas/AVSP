/**
 * Google Code Jam - Qualification Round - B. Magicka
 * 
 * @author Eric Pelz
 * @date 5/06/11
 */
import java.io.*;
import java.util.*;
import java.lang.Math;

public class magicka
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(new File("B-large.in"));
		
        PrintWriter outF = new PrintWriter("B-large.out");
        int t = sc.nextInt(); //num test cases
		
        for (int i=0; i<t; i++)
		{
			ArrayList<String> combosA = new ArrayList<String>(); //combo from
			ArrayList<String> combosArev = new ArrayList<String>();
			ArrayList<String> combosB = new ArrayList<String>(); //combo to
			ArrayList<String> oppsA = new ArrayList<String>(); //char 1
			ArrayList<String> oppsB = new ArrayList<String>(); //char 2
			//combo initialization
			int c = sc.nextInt(); //number of combinations
			for (int ii=0; ii<c; ii++)
			{
				String temp = sc.next();
				combosA.add(temp.substring(0,2));
				combosArev.add(temp.substring(1,2) + temp.substring(0,1));
				combosB.add(temp.substring(2,3));
			}
			
			//opposition initialization
			int d = sc.nextInt(); //number of oppositions
			for (int ii=0; ii<d; ii++)
			{
				String temp = sc.next();
				oppsA.add(temp.substring(0,1));
				oppsB.add(temp.substring(1,2));
			}
			
			int n = sc.nextInt(); //number of base elements in series
			String temp = sc.next(); //base elements in series
			String out = "";
			for (int j=0; j<n; j++)
			{
				out+=temp.substring(0,1);
				int len=temp.length();
				temp=temp.substring(1,len);
				
				for (int ii=0; ii<c; ii++)
				{
					if (out.endsWith(combosA.get(ii)) || out.endsWith(combosArev.get(ii)))
					{
						//replace combosA with combosB
						int len2 = out.length();
						out = out.substring(0,len2-2);
						out += combosB.get(ii);
						break;
					}
				}
				
				for (int ii=0; ii<d; ii++)
				{
					if ((out.contains(oppsA.get(ii))) && (out.contains(oppsB.get(ii))))
					{
						out = "";
						break;
					}
				}
			}
			
			//System.out.println("DONE: " + out);
			
			outF.print("Case #" + (i+1) + ": [");
			
			for (int j=0; j<out.length(); j++)
			{
				if (j != 0)
					outF.print(", ");
				
				outF.print(out.substring(j,j+1));
			}
			
			outF.println("]");
		}
		
        sc.close();
        outF.close();
	}
}