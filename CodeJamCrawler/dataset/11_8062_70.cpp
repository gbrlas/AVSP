/*
choochootrain
Google Code Jam 2011
*/
import java.io.*;
import java.util.*;

class ProblemC 
{
  public static void main (String [] args) throws IOException 
  {
	String filename = "C-small-attempt0";  
    BufferedReader f = new BufferedReader(new FileReader(filename + ".in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")));
    int numberOfTests = Integer.parseInt(f.readLine());
    for(int n = 1; n <= numberOfTests; n++)
    {
    	int numCandies = Integer.parseInt(f.readLine());
    	int[] values = new int[numCandies];
    	StringTokenizer st = new StringTokenizer(f.readLine());
    	int totalBinary = 0;
    	int total = 0;
    	for(int i = 0; i < numCandies; i++)
    	{
    		values[i] = Integer.parseInt(st.nextToken());
    		totalBinary = intXOR(totalBinary, values[i]);
    		total = total + values[i];
    	}
    	if(totalBinary != 0)
    	{
    		//there is no way to do this
    		out.println("Case #" + n + ": NO");
    		continue;
    	}
    	
    	int smallestCandy = values[0];
    	for(int i = 1; i < values.length; i++)
    	{
    		if(values[i] < smallestCandy)
    			smallestCandy = values[i];
    	}
    		
    	//since the whole pile xor's to 0,
    	//we can split it so patrick only gets the smallest candy.
    	int largestPile = total - smallestCandy;
    	String solution = "" + largestPile;
    	
    	out.println("Case #" + n + ": " + solution);
    }
    out.close();
    System.exit(0);
  }
  
  public static int intXOR(int i1, int i2)
  {
	  String s1 = Integer.toBinaryString(i1);
	  String s2 = Integer.toBinaryString(i2);
	  char[] s3;
	  if(s1.length() > s2.length())
	  {
		  s3 = s1.toCharArray();
		  int offset = s1.length() - s2.length();
		  for(int i = 0; i < s2.length(); i++)
		  {
			  s3[i + offset] = charXOR(s1.charAt(i + offset), s2.charAt(i));
		  }
	  }
	  else
	  {
		  s3 = s2.toCharArray();
		  int offset = s2.length() - s1.length();
		  for(int i = 0; i < s1.length(); i++)
		  {
			  s3[i + offset] = charXOR(s2.charAt(i + offset), s1.charAt(i));
		  }
	  }
	  String answer = new String(s3);
	  return Integer.parseInt(answer, 2);
  }
  
  public static char charXOR(char a, char b)
  {
	  if(a == '1' && b == '1' || a == '0' && b == '0')
		  return '0';
	  else
		  return '1';
  }
}