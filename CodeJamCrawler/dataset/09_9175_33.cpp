import java.util.*;
import java.io.*;

class Dictionary
{
	int l, d, n;
	ArrayList<String> avl;
	ArrayList<String> hand;
	ArrayList<String> test;
	
	void getIp()
	{
		try
		{
			BufferedReader in = new BufferedReader(new FileReader("Input.dat"));
			
			String temp;
			temp = in.readLine();
			StringTokenizer tokens = new StringTokenizer(temp);
			
			l = Integer.parseInt(tokens.nextToken());
			d = Integer.parseInt(tokens.nextToken());
			n = Integer.parseInt(tokens.nextToken());
			
			avl = new ArrayList<String>(l);
			test = new ArrayList<String>(n);
			int i;
		
			for(i=0; i<d; i++)
			{
				temp = in.readLine();
				avl.add(temp);
			}
			
			for(i=0; i<n; i++)
			{
				temp = in.readLine();
				test.add(temp);
			}
			in.close();
		}
		catch(IOException ioe)
		{}
	}
	
	void getCases()
	{
		try
		{
			PrintWriter pw = new PrintWriter("Output.dat");
			int i, cases = 0, j;
			String temp;
			StringTokenizer tokens;
			ArrayList<String> tmp;
			for(i=0; i<n; i++)
			{
				temp = test.get(i);
				tmp = new ArrayList<String>();
				char[] chars = temp.toCharArray();
				StringBuilder strb;
				for(j=0; j<chars.length; j++)
				{
					strb = new StringBuilder();
					if(chars[j] == '(')
					{
						j++;
						while(chars[j] != ')')
						{
							strb.append(chars[j]);
							j++;
						}
					}
					else
					{
						strb.append(chars[j]);
					}
					tmp.add(strb.toString());
				}
			//	test(tmp);
				cases = processAtHand(tmp);
				String res = new String("Case #"+(i+1)+": "+cases);
				pw.println(res);						
			}
			pw.close();
		}
		catch(Exception e)
		{}
	}
	
	
	void test(ArrayList<String> tokens)
	{
		System.out.println("************");
		for(int i=0; i<tokens.size(); i++)
		{
			System.out.println(tokens.get(i));
		}
	}
	int processAtHand(ArrayList<String> token)
	{
		int nc, i=0, j, c=0;
		String temp;
		ArrayList<Integer> getit = new ArrayList<Integer>();
		
		for(; i<avl.size(); i++)
		{
			getit.add(1);
		}
			
		for(i=0; i<token.size(); i++)
		{
			temp = token.get(i);
			
			for(j=0; j<d; j++)
			{
				if(temp.indexOf(avl.get(j).charAt(i)) == -1 && getit.get(j) == 1)
					getit.set(j, 0);
			}
		}
		for(i=0; i<getit.size(); i++)
		{
			if(getit.get(i) == 1)
				c++;
		}
		return c;
	} 
}		

class Q1
{
	public static void main(String args[])
	{
		Dictionary d = new Dictionary();
		d.getIp();
		d.getCases();
	}
}
