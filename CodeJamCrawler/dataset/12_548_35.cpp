import java.io.FileInputStream;


public class Googlerese {

	
	public static void main(String [] args)
	{
		
		
		java.util.Scanner scanner = new java.util.Scanner(System.in);
	    int line = 0;
	    String argus[] = null;
	    int n = 0;
	    
	    while (scanner.hasNextLine()) 
	    {
	    	if(line == 0)
	    	{
	    		n = Integer.parseInt(scanner.nextLine());
	    		argus = new String[n];
	    	}
	    	else
	    	{
	    		String test = scanner.nextLine();
				char[] testchars = test.toCharArray();
				for(int y = 0; y < testchars.length ; y++)
				{
					testchars[y] = convert(testchars[y]);
				}
				String result = new String(testchars);
				System.out.println("Case #" + line + ": " + result);
	    	}
	    	line++;
	    }

		
//		String argus[] = new String[4];
//		argus[0] = "3";
//		argus[1] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
//		argus[2] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
//		argus[3] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		
		
		
//		for(int i = 0; i< n; i++)
//		{
//			String test = argus[i+1];
//			char[] testchars = test.toCharArray();
//			for(int y = 0; y < testchars.length ; y++)
//			{
//				testchars[y] = convert(testchars[y]);
//			}
//			String result = new String(testchars);
//			System.out.println("Case #" + i + ": " + result);
//		}
		
	}
	
	public static char convert(char x)
	{
		if(x == 'a')
		{
			x = 'y';
		}
		
		else if(x == 'b')
		{
			x = 'h';
		}

		else if(x == 'c')
		{
			x = 'e';
		}

		else if(x == 'd')
		{
			x = 's';
		}

		else if(x == 'e')
		{
			x = 'o';
		}

		else if(x == 'f')
		{
			x = 'c';
		}

		else if(x == 'g')
		{
			x = 'v';
		}

		else if(x == 'h')
		{
			x = 'x';
		}

		else if(x == 'i')
		{
			x = 'd';
		}

		else if(x == 'j')
		{
			x = 'u';
		}

		else if(x == 'k')
		{
			x = 'i';
		}

		else if(x == 'l')
		{
			x = 'g';
		}

		else if(x == 'm')
		{
			x = 'l';
		}

		else if(x == 'n')
		{
			x = 'b';
		}

		else if(x == 'o')
		{
			x = 'k';
		}

		else if(x == 'p')
		{
			x = 'r';
		}

		else if(x == 'q')
		{
			x = 'z';
		}

		else if(x == 'r')
		{
			x = 't';
		}

		else if(x == 's')
		{
			x = 'n';
		}

		else if(x == 't')
		{
			x = 'w';
		}

		else if(x == 'u')
		{
			x = 'j';
		}

		else if(x == 'v')
		{
			x = 'p';
		}

		else if(x == 'w')
		{
			x = 'f';
		}

		else if(x == 'x')
		{
			x = 'm';
		}

		else if(x == 'y')
		{
			x = 'a';
		}

		else if(x == 'z')
		{
			x = 'q';
		}
		
		return x;
	}
	
}


