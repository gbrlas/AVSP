import java.io.*;
import java.util.Vector;
import java.util.*;



public	class	MultiBase
{
	public	static	void	main( String[] args ) throws IOException
	{
		int	i, j, k;
		int	n;
		/* first, lets open the input file and create the output file */
		File inFile = new File("A-small-attempt0.in");
		File	outFile = new File( "output.out" );
		BufferedReader input =  new BufferedReader(new FileReader(inFile));
		BufferedWriter output = new BufferedWriter(new FileWriter(outFile));

		/* read in first line */
		String line = input.readLine();
		int T = Integer.parseInt(line);	
		
		// we do from here to the bottom T times...
		int	cse = 1;
		while( T>0 )
		{
			T--;
			output.write( "Case #" + cse + ": " );
			cse++;
			line = input.readLine();
			String[] str = line.split(" ");
			n = str.length;
			int[]bases = new int[n];
			for( i=0; i<n; i++ )
			{
				bases[i] = Integer.parseInt(str[i]);
			}
			boolean	finished = false;
			int	startNum = 2;
			while( !finished )
			{
				int	num = startNum;
				int	newNum = 0;
				boolean isHappy = true;
				for( i=0; i<n && isHappy; i++ )
				{
					num = startNum;
					newNum = 0;
					boolean equalsOne = false;
					Vector<Integer> v = new Vector<Integer>();
					while( !equalsOne )
					{
						newNum = 0;
						while( num > 0 )
						{
							newNum += (num % bases[i]) * (num % bases[i]);
							num /= bases[i];
						}
						if( v.contains(newNum) )
						{
							isHappy = false;
							break;
						}
						else
							v.add( newNum );
						if( newNum == 1 )
							equalsOne = true;
						num = newNum;
					}
				}
				if( isHappy )
				{
					finished = true;
				}
				else
				{
					startNum++;
				}
			}
			output.write( startNum + "\n");			
			
		}
		input.close();
		output.close();
	}
}	