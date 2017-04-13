package round1.b;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.math.BigDecimal;

import sun.security.util.BigInt;


public class B 
{
	//private static String inputFile = "Round1C/B-sample.in";
	private static String inputFile = "Round1C/B-small-attempt1.in";
	
	private static BigDecimal ZERO = BigDecimal.ZERO;
	private static BigDecimal ONE = BigDecimal.ONE;
	private static BigDecimal TWO = new BigDecimal(2);
	private static BigDecimal THREE = new BigDecimal(3);
	private static BigDecimal FIVE = new BigDecimal(5);
	private static BigDecimal SEVEN = new BigDecimal(7);
	private static BigDecimal TEN = BigDecimal.TEN;
	
	private static boolean DEBUG = false;

	private String original;
	
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(inputFile));
			//PrintStream out = System.out;
			PrintStream out = new PrintStream(new FileOutputStream(inputFile + ".out"));
			int cases = Integer.parseInt(br.readLine());
			for (int cas=1 ; cas <= cases ; cas++)
			{
				B b = new B(br.readLine());
				
				int result = b.calculate();
				out.println("Case #" + cas + ": " + result);
			}
		}
		catch (Exception e)
		{
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
	}
	
	public B(String input)
	{
		original = input;
	}
	
	public int calculate()
	{
		int uglyCount = 0;
		//if (isUgly(new BigDecimal(original)))
		//{
		//	uglyCount ++;
		//}
		
		if (original.length() == 1)
		{
			return isUgly(new BigDecimal(original)) ? 1 : 0;
		}
		
		int [] modifiers = new int[original.length()-1]; // 0=nothing, 1=add, 2=subtract
		for (int i=0 ; i<modifiers.length ; i++)
		{
			modifiers[i] = 0;
		}
		
		//create big decimals
		long [] bds = new long[original.length()];
		for (int i=0 ; i<original.length() ; i++)
		{
			bds[i] = Long.valueOf(original.charAt(i) - '0');
		}
		
		boolean done = false;
		while (!done)
		{
			long current = 0;
			
			int workingMod = 1;
			long working = bds[0];
			
			if (DEBUG) debugPrint(modifiers);
			
			for (int i=0 ; i<modifiers.length ; i++)
			{
				if (modifiers[i] == 0)
				{
					working = working*10 + bds[i+1];
				}
				else// if (modifiers[i] == 1)
				{
					if (workingMod == 1)
					{
						current = current + working;
					}
					else
					{
						current = current - working;
					}
					if (i == modifiers.length-1)
					{
						//last time
						working = bds[i+1];
					}
					else if (modifiers[i+1] == 0) // no modifier
					{
						working = bds[i+1];
					}
					else
					{
						working = bds[i+1];
					}
					workingMod = modifiers[i];
				}
			}
			if (workingMod == 1)
			{
				current = current + working;
			}
			else
			{
				current = current - working;
			}
			
			if (DEBUG) System.err.print(" = " + current);
			
			// check ugly
			if (isUgly(current))
			{
				if (DEBUG) System.err.print("!");
				uglyCount++;
			}
			if (DEBUG) System.err.println();

				
			//check done
			done = true;
			for (int i=0 ; i<modifiers.length ; i++)
			{
				if (modifiers[i] != 2)
				{
					done = false;
				}
			}
			
			//next modifier
			if (!done)
			{
				modifiers[modifiers.length-1]++;
				for (int i=0 ; i<modifiers.length ; i++)
				{
					if (modifiers[modifiers.length-i-1] == 3)
					{
						modifiers[modifiers.length-i-1] = 0;
						if (modifiers.length-i-1 > 0)
						{
							modifiers[modifiers.length-i-2]++;
						}
					}
				}
			}
		}
		return uglyCount;
	}

	
	private boolean isUgly(long current) {
		return (current==0 || current%2 ==0 || current %3==0 || current%5==0 || current%7==0);
	}

	private void debugPrint(int[] modifiers) 
	{
		System.err.print(original.charAt(0));
		{
			for (int i=0 ; i<modifiers.length ; i++)
			{
				if (modifiers[i] == 1)
				{
					System.err.print("+");
				}
				else if (modifiers[i] == 2)
				{
					System.err.print("-");
				}
				System.err.print(original.charAt(i+1));
			}
		}
		//System.out.println();
	}

	public static boolean isUgly(BigDecimal bi)
	{
		if (bi.remainder(TWO).equals(ZERO) 
				|| bi.remainder(THREE).equals(ZERO)
				|| bi.remainder(FIVE).equals(ZERO)
				|| bi.remainder(SEVEN).equals(ZERO)
				|| bi.equals(ZERO)
				)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
