/*
choochootrain
Google Code Jam 2011
*/
import java.io.*;
import java.util.*;

class ProblemB
{
  public static void main (String [] args) throws IOException 
  {
	String filename = "B-large";  
    BufferedReader f = new BufferedReader(new FileReader(filename + ".in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")));
    int numberOfTests = Integer.parseInt(f.readLine());
    for(int n = 1; n <= numberOfTests; n++)
    {
    	StringTokenizer st = new StringTokenizer(f.readLine());
    	
    	int numCombiners = Integer.parseInt(st.nextToken());
    	String[] combiners = new String[numCombiners];
    	for(int i = 0; i < numCombiners; i++)
    		combiners[i] = st.nextToken();
    	
    	int numOpposers = Integer.parseInt(st.nextToken());
    	String[] opposers = new String[numOpposers];
    	for(int i = 0 ;i < numOpposers; i++)
    		opposers[i] = st.nextToken();
    	
    	String list = "";
    	
    	int numElements = Integer.parseInt(st.nextToken());
    	for(char nextElement : st.nextToken().toCharArray())
    	{
    		list = list + nextElement;
    		list = checkCombiners(list, combiners);
    		list = checkOpposers(list, opposers);
    	}
    	
    	String solution = format(list);
    	
    	out.println("Case #" + n + ": " + solution);
    }
    out.close();
    System.exit(0);
  }

  private static String format(String list)
  {
	  if(list.equals(""))
		  return "[]";
	  
	  StringBuilder s = new StringBuilder();
	  s.append('[');
	  for(int i = 0 ; i < list.length() - 1; i++)
	  {
		  s.append(list.charAt(i));
		  s.append(',');
		  s.append(' ');
	  }
	  s.append(list.charAt(list.length() - 1));
	  s.append(']');
	  return s.toString();
  }

  private static String checkCombiners(String list, String[] combiners)
  {
	  for(String s: combiners)
	  {
		  String combo1 = s.substring(0,2);
		  String elementFormed = s.substring(2);
		  String combo2 = "" + combo1.charAt(1) + combo1.charAt(0);
		  if(list.contains(combo1) || list.contains(combo2))
		  {
			  list = list.substring(0, list.length() - 2) + elementFormed;
			  return list;
		  }
	  }
	  return list;
  }

  private static String checkOpposers(String list, String[] opposers)
  {
	  for(String s: opposers)
	  {
		  String element1 = "" + s.charAt(0);
		  String element2 = "" + s.charAt(1);
		  if(list.contains(element1) && list.contains(element2))//clear list
		  {
			  list = "";
			  return list;
		  }
	  }
	  return list;
  }
}