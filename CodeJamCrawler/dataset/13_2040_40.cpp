import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	final String FILENAME_IN = "A-small-attempt0.in.txt";
	final String FILENAME_OUT = "A-small-attempt0.out.txt";
	
	Scanner sc;
	
	int judgeLine(long line)
	{
		if((line & 0x1FFF & 0xF1FF & 0xFF1F & 0xFFF1) == 0x1111)
		{
			return 1;	// winner is 'O'.
		}
		if((line & 0x2FFF & 0xF2FF & 0xFF2F & 0xFFF2) == 0x2222)
		{
			return 2;	// winner is 'X'.
		}
		return 0;
	}
	
	int judge(long[] map)
	{
		int total_col = 0xFFFF;
		
		int flagO_RL  = 1;
		int flagO_LR  = 1;
		
		int flagX_RL  = 1;
		int flagX_LR  = 1;
		
		int hasEmpty  = 0;
		
		for(int row=0; row<4; row++)
		{
			int lineResult = judgeLine(map[row]);
			if(lineResult != 0)
			{
				// ‰¡‚É‚»‚ë‚Á‚Ä‚¢‚é.
				return lineResult;
			}
			else
			{
				if((map[row] & (1<<(row*4))) == 0)		flagO_RL = 0;
				if((map[row] & (1<<((3-row)*4))) == 0)	flagO_LR = 0;

				if((map[row] & (2<<(row*4))) == 0)		flagX_RL = 0;
				if((map[row] & (2<<((3-row)*4))) == 0)	flagX_LR = 0;
				
				total_col &= map[row];
				
				if(hasEmpty == 1 || ((map[row] & 0x3000) == 0) || ((map[row] & 0x0300) == 0) || ((map[row] & 0x0030) == 0) || ((map[row] & 0x0003) == 0))
				{
					hasEmpty = 1;
				}
			}
		}
		
		if(flagO_RL == 1 || flagO_LR == 1
				|| (total_col & 0x1000) != 0 || (total_col & 0x0100) != 0 || (total_col & 0x0010) != 0 || (total_col & 0x0001) != 0)
		{
			return 1;	// winner is 'O'.
		}
		if(flagX_RL == 1 || flagX_LR == 1 || (total_col & 0x2222) != 0
				|| (total_col & 0x2000) != 0 || (total_col & 0x0200) != 0 || (total_col & 0x0020) != 0 || (total_col & 0x0002) != 0)
		{
			return 2;	// winner is 'X'.
		}
		
		if(hasEmpty == 1)
		{
			return 0;	// Game has not completed. 
		}
		else
		{
			return 100;	// Draw.
		}
		
	}
	
	void readMap(long[] map)
	{
		for(int row = 0; row < 4; row++)
		{
			String line = sc.nextLine();
			map[row] = 0;
			for(int col=0; col<4; col++)
			{
				char c = line.charAt(col);
				switch(c)
				{
				case 'O':
					map[row] |= 1<<(col*4);
					break;
				case 'X':
					map[row] |= 2<<(col*4);
					break;
				case 'T':
					map[row] |= (1 | 2)<<(col*4);
					break;
				default :
					// do nothing.
					break;
				}
			}
		}

		System.err.println();
		for(int i=0; i<4; i++)
			System.err.printf("%04x\n", map[i]);
	}
	
	void run()
	{
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
		
		int numOfCases = Integer.parseInt(sc.nextLine());
		
		for(int caseNum = 1; caseNum <= numOfCases; caseNum++)
		{
			if(caseNum != 1)
			{
				sc.nextLine();
				pw.println();
			}
			
			long[] map = new long[4];
			readMap(map);
			
			
			switch(judge(map))
			{
			case 1:
				pw.printf("Case #%d: %s", caseNum, "O won");
				break;
			case 2:
				pw.printf("Case #%d: %s", caseNum, "X won");
				break;
			case 0:
				pw.printf("Case #%d: %s", caseNum, "Game has not completed");
				break;
			case 100:
				pw.printf("Case #%d: %s", caseNum, "Draw");
				break;
			default:
				System.err.println("result is invalid.");
			}
		}
		
		sc.close();
		pw.close();
	}
	
	
	public static void main(String[] arg)
	{
		new A().run();
	}
}
