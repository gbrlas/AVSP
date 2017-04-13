import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class CaseProcessor {	
	private String processCase(Scanner scan) throws IOException
	{		
		int perms = scan.nextInt();	
		int[] x = new int[perms];
		int[] y = new int[perms];
		
		scan.nextLine();
		for (int i = 0; i < perms; i++) {
			x[i] = scan.nextInt();
		}
		
		scan.nextLine();
		for (int i = 0; i < perms; i++) {
			y[i] = scan.nextInt();
		}
		
		Arrays.sort(x);
		Arrays.sort(y);
		int val = 0;
		for (int i = 0; i < perms; i++) {
			val = val + (x[i] * y[(perms-i)-1]);
		}
		
		return val+"";
	}

	public CaseProcessor() {
		String file = "A-small-attempt0";		
		String outputPath = "D:\\GoogleContest\\output\\";
		String inputPath = "D:\\GoogleContest\\";							

		try
		{
			File inputFile = new File(inputPath + file + ".in");
			FileWriter out = new FileWriter(outputPath + file + ".out");			
			Scanner scan = new Scanner(inputFile);
			
			
			int cases = scan.nextInt();									

			for (int i = 0; i < cases; i++)
			{								
				out.write("Case #" + (i+1) + ": " + processCase(scan) + "\n");
			}
			scan.close();
			out.close();
		}
		catch (Exception e)
		{
			System.out.println("Unknown Error: " + e.getMessage());
		}	
	}	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new CaseProcessor();
	}
}
