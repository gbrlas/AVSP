/*
choochootrain
Google Code Jam 2011
*/
import java.io.*;
import java.util.*;

class ProblemA 
{
  public static void main (String [] args) throws IOException 
  {
	String filename = "A-large";  
    BufferedReader f = new BufferedReader(new FileReader(filename + ".in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")));
    int numberOfTests = Integer.parseInt(f.readLine());
    for(int n = 1; n <= numberOfTests; n++)
    {
    	StringTokenizer st = new StringTokenizer(f.readLine());
    	int numButtons = Integer.parseInt(st.nextToken());
    	LinkedList<String> order = new LinkedList<String>();
    	LinkedList<Integer> orangeButtons = new LinkedList<Integer>();
    	LinkedList<Integer> blueButtons = new LinkedList<Integer>();
    	while(st.hasMoreElements())
    	{
    		String instruction = st.nextToken() + st.nextToken();
    		order.add(instruction);
    		if(instruction.contains("O"))
    			orangeButtons.add(Integer.parseInt(instruction.substring(1)));
    		else if(instruction.contains("B"))
    			blueButtons.add(Integer.parseInt(instruction.substring(1)));
    	}
    	
    	//initialize lists
    	/*
    	for(String s: order)
    		System.out.print(s + " ");
    	System.out.println();
    	
    	for(Integer i: orangeButtons)
    		System.out.print(i + " ");
    	System.out.println();
    	
    	for(Integer i: blueButtons)
    		System.out.print(i + " ");
    	System.out.println();
    	**/
    	int count = 0;
    	int oPos = 1;
    	int bPos = 1;
    	
    	while(!order.isEmpty())
    	{
    		String instruction = order.getFirst();
    		int location = -1;
    		if(instruction.contains("O"))
    		{
    			location = orangeButtons.getFirst().intValue();
    			if(location == oPos)//you are at the spot
    			{
    				//push button
    				order.remove();
    				orangeButtons.remove();
    			}
    			else if(oPos < location)
    			{
    				//move forward
    				oPos++;
    			}
    			else
    			{
    				//move backward
    				oPos--;
    			}
    			
    			if(!blueButtons.isEmpty() && bPos < blueButtons.getFirst().intValue())//blue needs to move
					bPos++;
    			else if(!blueButtons.isEmpty() && bPos > blueButtons.getFirst().intValue())//blue needs to move
					bPos--;
    		}
    		else
    		{
    			location = blueButtons.getFirst().intValue();
    			
    			if(location == bPos)//you are at the spot
    			{
    				//push button
    				order.remove();
    				blueButtons.remove();
    			}
    			else if(bPos < location)
    			{
    				//move forward
    				bPos++;
    			}
    			else
    			{
    				//move backward
    				bPos--;
    			}
    			
    			if(!orangeButtons.isEmpty() && oPos < orangeButtons.getFirst().intValue())//orange needs to move
					oPos++;
    			else if(!orangeButtons.isEmpty() && oPos > orangeButtons.getFirst().intValue())//orange needs to move
					oPos--;
    			
    		}
    		count++;
    	}
    	String solution = "" + count;
    	out.println("Case #" + n + ": " + solution);
    }
    out.close();
    System.exit(0);
  }
}