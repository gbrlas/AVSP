import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class WelcomeToCodeJam
{
	public static void main(String[] args)
	{
		String phrase = new String("welcome to code jam");
		//phrase = phrase.trim();
		
		try
		{
			Scanner scanner = new Scanner(new File("C-small-attempt1.in"));
			int N = Integer.parseInt(scanner.nextLine().trim());
			String input[] = new String[N];
			
			for(int i = 0; i < N; i++)
				input[i] = scanner.nextLine().trim();

//			for(int i = 0; i < N; i++)
//				System.out.println(input[i]);

			scanner.close();
			
			PrintWriter outputStream = new PrintWriter(new FileOutputStream("output.out"));
			
			for(int i = 0; i < N; i++)
			{
				long temp = checkPhrase(phrase, input[i]) % 10000;
				
//				System.out.println(phrase + "###" + input[i]);
				System.out.print("Case #" + (i+1) + ": ");
				outputStream.print("Case #" + (i+1) + ": ");
				if(temp < 1000)
				{
					System.out.print("0");
					outputStream.print("0");					
				}
				if(temp < 100)
				{
					System.out.print("0");
					outputStream.print("0");					
				}
				if(temp < 10)
				{
					System.out.print("0");
					outputStream.print("0");					
				}
				System.out.println(temp);
				outputStream.println(temp);					
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
	
	static long checkPhrase(String jamPhrase, String inputCheck)
	{
		//System.out.println(jamPhrase + "###" + inputCheck);		
		//if phrase is empty
		if (jamPhrase.equals(""))
			return 1;	//match found
		//if phrase is not empty but input is empty
		else if (inputCheck.equals(""))
			return 0;
		//if phrase and input are both not empty
		//and match found
		else if(inputCheck.indexOf(jamPhrase.charAt(0)) != -1)
		{
			return checkPhrase(jamPhrase, inputCheck.substring(inputCheck.indexOf(jamPhrase.charAt(0))+1)) 
			+ checkPhrase(jamPhrase.substring(1), inputCheck.substring(inputCheck.indexOf(jamPhrase.charAt(0))+1));
		}
		//if no match
		else
			return 0;
	}
}
