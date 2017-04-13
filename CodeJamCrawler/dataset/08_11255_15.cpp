package round1.a;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;

public class A 
{
	//List<Character> letters;
	int frequencies[];
	int maxLettersPerKey;
	int keysAvail;
	int lettersInAlpha;
	
	//private static String inputFile = "Round1C/A-sample.in";
	private static String inputFile = "Round1C/A-small-attempt0.in";
	
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
				String [] line = br.readLine().split(" ");
				int maxLettersPerKey = Integer.parseInt(line[0]);
				int keysAvail = Integer.parseInt(line[1]);
				int lettersInAlpha = Integer.parseInt(line[2]);
				A a = new A(maxLettersPerKey, keysAvail, lettersInAlpha, br.readLine());
				int result = a.calculate();
				if (result == -1)
				{
					out.println("Case #" + cas + ": Impossibe");
				}
				else
				{
					out.println("Case #" + cas + ": " + result);
				}
			}
			
		}
		catch (Exception e)
		{
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
	}

	public A(int maxLettersPerKey, int keysAvail, int lettersInAlpha, String frequencies)
	{
		this.maxLettersPerKey = maxLettersPerKey;
		this.keysAvail = keysAvail;
		this.lettersInAlpha = lettersInAlpha;
		String [] freqs = frequencies.split(" ");
		this.frequencies = new int[freqs.length];
		for (int i=0 ; i<freqs.length ; i++)
		{
			this.frequencies[i] = Integer.parseInt(freqs[i]);
		}
		Arrays.sort(this.frequencies);
	}
	
	public int calculate()
	{
		if (maxLettersPerKey * keysAvail < frequencies.length)
		{
			return -1;
		}
		int total = 0;
		int multipler = 0;
		for (int i=0 ; i<frequencies.length ; i++)
		{
			if (i%keysAvail == 0)
			{
				multipler++;
			}
			total += (frequencies[frequencies.length-i-1]*multipler);
		}
		return total;
	}
}
