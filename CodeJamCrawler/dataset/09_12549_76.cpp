package qualification.welcometocodejam;

import java.io.File;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Scanner;

public class WelcomeToCodeJam {
	
	private int[][] charIndex;
	private static long phrasenum;
	
	private static NumberFormat nf = new DecimalFormat("0000");
	
//	private static final String INPUT_FILE = "welcome.txt";
	private static final String INPUT_FILE = "C-small.in";
	private static final String OUTPUT_FILE = "C-small.out";
	
	public WelcomeToCodeJam(String fileName)
	{
		Scanner sc = null;
		PrintWriter pw = null;
		try
		{
			sc = new Scanner(new File(fileName)).useDelimiter("[\r\n]");
			pw = new PrintWriter(new File(OUTPUT_FILE));
			
			// get test number
			int n = sc.nextInt();
			sc.nextLine();
			for(int testNum = 0 ; testNum < n ; testNum++)
			{
				String line = sc.nextLine();
				initIndex(line);
				
				for(int i = 0 ; i < charIndex[0].length ; i++)
				{
					if(charIndex[0][i] == 1)
					{
						countPhrase(1, i+1);
					}
				}
				
				pw.println("Case #" + (testNum+1) + ": " + nf.format(phrasenum));
				pw.flush();
				
				System.out.println("Case #" + (testNum+1) + ": " + nf.format(phrasenum));
			}
			
			
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
		finally
		{
			if(sc != null)
			{
				sc.close();
			}
			
			if(pw != null)
			{
				pw.flush();
				pw.close();
			}
		}
	}
	
	private void countPhrase(int charPos, int startIdx)
	{
		if(charPos == 19)
		{
			// found phrase
			phrasenum ++;
		}
		else
		{
			for(int i = startIdx ; i < charIndex[0].length ; i++)
			{
				if(charIndex[charPos][i] == 1)
				{
					countPhrase(charPos+1, i+1);
				}
			}
		}
	}
	
	private void initIndex(String line)
	{
		phrasenum = 0;
		
		charIndex = new int[19][500];
		for(int i = 0 ; i < 19 ; i++)
		{
			for(int j = 0 ; j < 500 ; j++)
			{
				charIndex[i][j] = 0;
			}
		}
		
		
		char[] orgCharArray = line.toCharArray();
		
		for(int i = 0 ; i < orgCharArray.length ; i++)
		{
			switch(orgCharArray[i])
			{
			case 'w':
				charIndex[0][i] = 1;
				break;
			case 'e':
				charIndex[1][i] = 1;
				charIndex[6][i] = 1;
				charIndex[14][i] = 1;
				break;
			case 'l':
				charIndex[2][i] = 1;
				break;
			case 'c':
				charIndex[3][i] = 1;
				charIndex[11][i] = 1;
				break;
			case 'o':
				charIndex[4][i] = 1;
				charIndex[9][i] = 1;
				charIndex[12][i] = 1;
				break;
			case 'm':
				charIndex[5][i] = 1;
				charIndex[18][i] = 1;
				break;
			case 't':
				charIndex[8][i] = 1;
				break;
			case ' ':
				charIndex[7][i] = 1;
				charIndex[10][i] = 1;
				charIndex[15][i] = 1;
				break;
			case 'd':
				charIndex[13][i] = 1;
				break;
			case 'j':
				charIndex[16][i] = 1;
				break;
			case 'a':
				charIndex[17][i] = 1;
				break;
				default:
			}
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		WelcomeToCodeJam test = new WelcomeToCodeJam(INPUT_FILE);

	}

}
