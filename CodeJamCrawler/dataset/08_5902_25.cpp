/*Rosa Enciso
 *Google Code Jam 2008
 *practice problem: Alien
 **/

import java.io.*;
import java.util.*;

public class save
{
	public static void main(String[] args) throws IOException
	{
		
		//File file = new File ("sample.in");
		//File file = new File ("A-small.in");
		//File file = new File ("A-large.in");
 		//Scanner stdin = new Scanner(file);
 		BufferedReader stdin = new BufferedReader(new FileReader("A-small-attempt3.in"));
 		//BufferedReader stdin = new BufferedReader(new FileReader("sample.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt3.out")); 
		
 		int num_cases = Integer.parseInt(stdin.readLine());
 		
 		for(int i = 0;i<num_cases;i++)
 		{
	 		int num_search_engines = Integer.parseInt(stdin.readLine());
	 		String[] engines = new String[num_search_engines];
	 		
	 		for(int j = 0;j<num_search_engines;j++)
	 		{
	 			engines[j] = stdin.readLine();
	 			//System.out.println(stdin.readLine());
	 		}
	 
	 		int num_queries = Integer.parseInt(stdin.readLine());
	 		//System.out.println(num_queries);
	 		String[] queries = new String[num_queries];
	 		
	 		for(int j = 0;j<num_queries;j++)
	 		{
	 			queries[j] = stdin.readLine();
	 		}
	 		//System.out.println(num_cases + " " + num_search_engines + " " + num_queries);
	 		int switch_index = -1;
	 		int num_switches = 0;
	 		int new_index = 0;
	 		int index_of_best = 0;
	 		String best_engine;
	 		Vector best = new Vector();
	 		while(new_index < num_queries)
	 		{   
	 			best_engine = bestEngine(engines, queries, new_index, num_queries);
	 			best.addElement(best_engine);
	 			index_of_best = firstIndexOfEngine(best_engine, queries, new_index, num_queries);
	 			
	 			if(index_of_best == -1)
	 				new_index = num_queries;
	 			else
	 			{
	 				new_index = index_of_best;
	 				num_switches++;
	 			}
	 		}
	 		
	 		for(int j=0;j<best.size();j++)
	 		{
	 			System.out.println(best.elementAt(j));
	 		}
	 		
	 		System.out.println("Case #"+(i+1)+": " + num_switches + "\n");
	 		/*if(num_queries == 0)
	 			out.println("Case #"+(i+1)+":" + 0);
	 		else*/
		 		out.println("Case #"+(i+1)+": " + num_switches);
	 		
 		}
 		out.close();
	}
	
	public static int firstIndexOfEngine(String engine, String[] queries, int start, int end)
	{
		for(int i = start; i < end; i++)
		{
			if(engine.equals(queries[i]))
			{
				return i;
			}
		}
		
		return -1;
	}
	
	public static String bestEngine(String[] engines, String[] queries, int start, int end)
	{
		
		int max = -1;
		String bestEngine = "";
		
		for(int i = 0;i<engines.length;i++)
		{
			int index = firstIndexOfEngine(engines[i], queries, start, end);
			
			if(index == -1)
				return engines[i];
			else
			{
				if(max < index)
				{
					max = index;
					bestEngine = engines[i];
				}
			}
		}
		
		return bestEngine;
	}
	
	//this method converts a decimal number to the target language
	public static String decimalToTarget(String n, String t_lang)
	{
		int length_t = t_lang.length();
		String new_base;
		String n_t_lang = "";
		//convert decimal number 'n' to base lenght_t
		new_base = decimalToBase(Integer.parseInt(n), length_t);
		
		//System.out.println("new base " + new_base);
		
		for(int i = 0;i<new_base.length();i++)
		{
			int j = new_base.charAt(i) - 48;
			
			n_t_lang = n_t_lang + t_lang.charAt(j);
		}
		
		return n_t_lang;
	}
	
	//this method converts the number given in source language to decimal
	public static String sourceToDecimal(String n, String s_lang)
	{
		
		String n_base_lth = "";
		String n_dec = "";
		
		for(int i=0;i<n.length();i++)
		{
			int j = s_lang.indexOf(n.charAt(i));
			//System.out.print("j " + j);
			n_base_lth = n_base_lth + j;
		}
		//System.out.println("\n" + n_base_lth);
		n_dec = baseToDecimal(n_base_lth, s_lang.length());
		
		return n_dec;
	}
	
	public static String baseToDecimal(String n, int base)
	{
		int n_dec = 0;
		
		for(int i = 0;i<n.length();i++)
		{
			n_dec += (Math.pow(base, i) * (n.charAt( n.length() - 1 - i ) - '0') );
		}
		
		return ""+n_dec;
	}
	
	public static String decimalToBase(int n, int base)
	{
		String n_base = "";
		int q;
		int r;
		int d = n;
		
		do{
			//q = d/base;
			r = d%base;
			d = d/base;
			
			n_base = r + n_base;
			
		}while(d > 0);
		
		return n_base;
	}
}