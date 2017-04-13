import java.util.*;
import java.io.*;

public class BotTrust
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintStream out = System.out;
					
		int cases = in.nextInt();
		
		for (int i = 1; i < cases+1; i++)
		{
			LinkedList<Integer> orange = new LinkedList<Integer>();
			LinkedList<Integer> blue = new LinkedList<Integer>();
			LinkedList<String> list = new LinkedList<String>();
		
			int numButtons = in.nextInt();
			int seconds;
			
			for (int j = 0; j < numButtons; j++)
			{
				String c = in.next();
				int button = in.nextInt();
				
				if (c.equals("O"))
					orange.add(button);
				else if (c.equals("B"))
					blue.add(button);
				else
					out.println("Error determining colour of bot.");	
				list.add(c);
								
			}
			
			boolean actFinish = false;
			int oDest = 1;
			int oPos = 1;
			int bDest = 1;
			int bPos = 1;
			String c = "";
			if (list.size() != 0)
			{
				c = list.pollFirst();
				if (orange.size() != 0)
				{
					oDest = orange.pollFirst();
					oPos = 1;
				}
				if (blue.size() != 0)
				{
					bDest = blue.pollFirst();
					bPos = 1;
				}
			}
			for (seconds = 0; (list.size() != 0) || !actFinish; seconds++)
			{
				if (actFinish)
				{
					actFinish = false;
					c = list.pollFirst();					
				}
				
				if (oDest == oPos)
				{
					if (c.equals("O"))
					{
						actFinish = true;
						if (orange.size() != 0)
							oDest = orange.pollFirst();
					}
				}
				else if (oDest > oPos)
					oPos++;
				else
					oPos--;
			
				if (bDest == bPos)
				{
					if (c.equals("B"))
					{
						actFinish = true;
						if (blue.size() != 0)
							bDest = blue.pollFirst();		
					}
				}
				else if (bDest > bPos)
					bPos++;
				else
					bPos--;
			}
			
			out.printf("Case #%d: %d\n", i, seconds);
			
		}
	}
}
