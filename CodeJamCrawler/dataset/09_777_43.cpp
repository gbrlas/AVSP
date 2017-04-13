import	java.io.*;
import java.util.Vector;
import java.util.*;

class	AlienCharacter
{
	Vector<Character>	c;				// list of possible characters this AlienCharacter can be
	
	public AlienCharacter( Vector<Character> cIn )
	{
		c = cIn;
	//	for( int i=0; i<c.length; i++ )
	//		System.out.print(c[i] + " ");
	}
}



public class	AlienLanguage
{
	static public	void	main( String[] args ) throws IOException
	{
		int	L, D, N;
		int	i, j;
		/* first, lets open the input file */
		File inFile = new File("A-large.in");
		File	outFile = new File( "output.out" );
		BufferedReader input =  new BufferedReader(new FileReader(inFile));
		BufferedWriter output = new BufferedWriter(new FileWriter(outFile));
		/* read in first line */
		String line = input.readLine();
		
		String[] split = line.split(" ");
		
		//for( i=0; i<split.length; i++ )
		//	System.out.println( split[i] );
		L = Integer.parseInt(split[0]);
		D = Integer.parseInt(split[1]);
		N = Integer.parseInt(split[2]);
		
		/* now, read in the dictionary of possible words */
		Vector<String> dict = new Vector<String>();
		for( i=0; i<D; i++ )
		{
			dict.add(input.readLine());		
		}
		Collections.sort(dict);
		/* now, read in and set-up the transmitted words one at a time */
		/*  alienWord[i] is the character in alienWord at i */
		AlienCharacter[] alienWord = new AlienCharacter[L];
		for( int n=0; n<N; n++ )
		{
			String	aW = input.readLine();
			int	idx = 0;
			for( j=0; j<aW.length(); j++ )
			{
				if( aW.charAt(j) != '(' )
				{
					Vector<Character> c = new Vector<Character>();
					c.add(aW.charAt(j));
					//System.out.println( c[0] );
					alienWord[idx] = new AlienCharacter( c ); 
					idx++;
				}
				else		// char is a parenthesis
				{
					j++;	// skip it
					// create the array of potential characters...
					Vector<Character> c = new Vector<Character>();	
					while( aW.charAt(j) != ')' )
					{
						c.add( aW.charAt(j) );
						j++;
					}
					Collections.sort(c);
					alienWord[idx] = new AlienCharacter( c ); 
					idx++;

					//System.out.print( "Character array is " );
					//for( int t=0; t<c.length; t++ )
					//	System.out.print( c[t] );
					//System.out.println();
				}	
			}
			int	alienCount = 0;
			for( i=0; i<dict.size(); i++ )
			{
				boolean	matchFound = true;
				for( j=0; j< dict.elementAt(i).length(); j++ )
				{
					if( Collections.binarySearch( alienWord[j].c, dict.elementAt(i).charAt(j) ) < 0 )
					{
						matchFound = false;
						break;
					}
				}
				if( matchFound )
					alienCount++;
			}
			output.write( "Case #" + (n+1) + ": " + alienCount + "\n" );
			System.out.println( "Case #" + (n+1) + ": " + alienCount );
		}
		input.close();
		output.close();
	}
	
}