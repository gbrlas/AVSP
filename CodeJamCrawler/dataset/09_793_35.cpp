import java.io.*;
import java.util.Vector;
import java.util.*;



public	class	NextInt
{
	public	static	void	main( String[] args ) throws IOException
	{
		int	i, j, k;
		int	n;
		
		/* first, lets open the input file and create the output file */
		File inFile = new File("B-large.in");	//for sure!!!!!!!!!
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
			//int num = Integer.parseInt(line);
			//int	n2 = num;
			//int	s = 0;
			//while( n2 > 0 )
			//{
			//	s++;
			//	n2/=10;
			//}
			//n2 = num;
			int s = line.length();
			int[]	A = new int[s+2];
			for( i=0; i<s+2; i++ )
				A[i] = 99;
			for( i=s-1; i>=0; i-- )
			{	
				A[i] = line.charAt(i) - '0';//n2%10;
				//n2/=10;
			}
			//for( i=0; i<s; i++ )
			//	System.out.print(A[i]);
			//System.out.println();
			int	s1, s2;
			int	t;
			s1 = s-1;
			int	smallerIdx1, smallerIdx2;
			smallerIdx1 = -1;
			smallerIdx2 = -1;
			boolean	foundSmaller = false;
			while( s1 > smallerIdx2 )
			{
				foundSmaller = false;
				for( s2 = s1-1; s2 >= 0 && !foundSmaller; s2-- )
				{
					if( A[s2] < A[s1] && s2 > smallerIdx2 )
					{
						foundSmaller = true;
						smallerIdx1 = s1;
						smallerIdx2 = s2;
					}
				}
				s1--;
			}
			
			if( smallerIdx1 != -1 )
			{
				int	temp = A[smallerIdx1];
				for( t=smallerIdx1; t>smallerIdx2; t-- )
				{
					A[t] = A[t-1]; 
				}
				A[t] = temp;
				// from smallerIdx2 + 1 to the end, sort in ascending order
				int s22 = smallerIdx2+1;
				int d = s - s22;
				if( d>1 )
				{
					int[] newA = new int[d];
					for( i=0; i<d; i++ )
						newA[i] = A[s22++];
					Arrays.sort(newA);
					for( i=0; i<d; i++ )
					{
						A[smallerIdx2+1] = newA[i];
						smallerIdx2++;
					}
				}				
			}
			
			// did we find smaller???
			else	//no - insert a 0
			{
				//sort the array
				Arrays.sort(A);
				// find first non-leading 0
				s1 = 0;
				while( A[s1] < 1 )
					s1++;
				if( s1 != 0 )
				{
					int	temp = A[s1];
					for( i=s1; i>0; i-- )
						A[i] = A[i-1];
					A[0] = temp;
				}	
				//now!! insert 0 into second character
				for( i=s; i>1; i-- )
					A[i] = A[i-1];
				A[1] = 0;
				s++;
				
			}
			String st = "";
			for( i=0; i<s; i++ )
				st+=A[i];
			output.write(st + "\n");
		}
		input.close();
		output.close();
	}
}