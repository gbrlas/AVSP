import java.io.*;
import java.util.*;

public class AlienLanguage
{
	public static void main(String[] args)
	{
		int L, D, N;
		
		try
		{
			Scanner scanner = new Scanner(new File("A-large.in"));
			String line = null;
			
			L = scanner.nextInt();
			D = scanner.nextInt();
			N = scanner.nextInt();
			
			scanner.nextLine();
			
			String words[] = new String[D];
			String patterns[][] = new String[N][L];
			int matches[] = new int[N];
			
			for(int i = 0; i < D; i++)
				words[i] = scanner.nextLine().trim();
			
			for(int j = 0; j < N; j++)
			{
//				System.out.println("\nTest");
				line = scanner.nextLine().trim();
				for(int k = 0; k < L; k++)
				{
					if(line.charAt(0) == '(')
					{
						patterns[j][k] = line.substring(1, line.indexOf(")"));
						line = line.substring(patterns[j][k].length() + 2);
					}
					else
					{
						patterns[j][k] = String.valueOf(line.charAt(0));
						line = line.substring(patterns[j][k].length());
					}
//					System.out.println(patterns[j][k] + " " + line);
				}
			}
			
			scanner.close();
			
			
			for(int l = 0; l < N; l++)
			{
				int counter = 0;
				for(int m = 0; m < D; m++)
				{
					boolean match = true;
//					System.out.println("\n" + m + "\t");
					for(int n = 0; n < L && match; n++)
					{
						if(patterns[l][n].indexOf(words[m].charAt(n)) == -1)
							match = false;
//						System.out.print("#");
					}
					if(match)
						counter++;
//					System.out.println();
				}
				matches[l] = counter;
			}
			
			
			PrintWriter outputStream = new PrintWriter(new FileOutputStream("output.out"));
			
			for(int o = 0; o < N; o++)
			{
				outputStream.println("Case #" + (o+1) + ": " + matches[o]);
				System.out.println("Case #" + (o+1) + ": " + matches[o]);
			}
			
			outputStream.close();
		}
		catch(FileNotFoundException e)
		{
			System.out.println("FileNotFoundException");
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("ArrayIndexOutOfBoundsException");
		}
		catch(IOException e)
		{
			System.out.println("IOException");
		}
	}
}
