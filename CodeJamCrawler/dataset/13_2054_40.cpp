import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class B {

	final String FILENAME_IN = "C-small-attempt0.in.txt";
	final String FILENAME_OUT = "C-small-attempt0.out.txt";
	
	Scanner sc;
	
	HashSet<Long> list;
	
	boolean isPalindromes(long num)
	{
		String number = Long.toString(num);
		int len = number.length();
		String forward = number.substring(0, (len+1)/2);
		String backward = number.substring((len+1)/2, len);
		
		for(int i=0; i<len/2; i++)
		{
			if(forward.charAt(i) != backward.charAt(i))
				return false;
		}
		return true;
	}

	void prepare()
	{
		/* get the number list which is fair and square numbers. */
		list = new HashSet<Long>();
		for(long num = 1; num <= 1e7; num++)
		{
			if(isPalindromes(num) && isPalindromes(num*num))
			{
				list.add(num*num);
			}
		}
	}
	
	void run()
	{
		/* 前準備（回文かつ平方数なものを10^14まで列挙） */
		prepare();
		
		PrintWriter pw;
		try
		{
			sc = new Scanner(new File(FILENAME_IN));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File(FILENAME_OUT))));
			
		}
		catch(Exception e)
		{
			System.err.println(e);
			return;
		}

		
		/* inputファイルから読み出し */
		int n = sc.nextInt();
		for(int caseNum = 1; caseNum <= n; caseNum++)
		{
			long startNum = sc.nextLong();
			long endNum = sc.nextLong();
			
			/* A以上B以下の　回文かつ平方数を数える */
			int count = 0;
			for(long num = startNum; num <= endNum; num++)
			{
				if(list.contains(num))
				{
					//System.err.println(num);
					count++;
				}
			}
			
			/* 出力 */
			if(caseNum != 1)
				pw.println();
			pw.printf("Case #%d: %d", caseNum, count);
		}
		
		pw.close();
	}
	
	public static void main(String[] args)
	{
		new B().run();
	}
}
