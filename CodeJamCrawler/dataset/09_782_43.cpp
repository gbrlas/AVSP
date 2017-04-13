import	java.io.*;
import java.util.Vector;
import java.util.*;

class	Basin
{
	int	loc;
	char	name;
	Basin( int locIn, char nameIn )
	{
		loc = locIn;
		name = nameIn;
	}
}

public	class	Watersheds
{
	public	static	void	main(String[] args ) throws IOException
	{
		int	i, j, k;
		int	T;
		int	h, w;
			
		/* first, lets open the input file */
		File inFile = new File("B-small-attempt1.in");
		File	outFile = new File( "output.out" );
		BufferedReader input =  new BufferedReader(new FileReader(inFile));
		BufferedWriter output = new BufferedWriter(new FileWriter(outFile));
		/* read in first line */
		String line = input.readLine();
		T = Integer.parseInt(line);	
		
		// we do from here to the bottom T times...
		int	cse = 1;
		while( T>0 )
		{
			T--;
			System.out.println( "Case #" + cse + ":" );
			output.write( "Case #" + cse + ":\n" );
			cse++;
			line = input.readLine();
			String[] str = line.split(" ");
			h = Integer.parseInt(str[0]);
			w = Integer.parseInt(str[1]);
			System.out.println( T + " " + h + " " + w );
		
			int[][] A = new int[h][w];
			int[][] D = new int[h*w][h*w];
			char[][] Out = new char[h][w];
			for( i=0; i<h; i++ )
			{
				for( j=0; j<w; j++ )
				{
					Out[i][j] = 'Z';
				}
			}
		
			for( i=0; i<h*w; i++ )
			{
				for( j=0; j<h*w; j++ )
				{
					D[i][j] = -1;
				}
			}
			for( i=0; i<h; i++ )
			{
				line = input.readLine();
				str = line.split(" ");
				for( j=0; j<w; j++ )
				{
					A[i][j] = Integer.parseInt(str[j]);	// set value on map
				}
			}
			for( i=0; i<h; i++ )
			{
				for( j=0; j<w; j++ )
				{
					// now set [i][j] as source and find lowest altitude among neighbors
					int 	src = (i*w) + j;
					for( k=0; k<h*w; k++ )
						D[src][k] = 200000;	// init to infinity
					//D[src][src] = 0;
					
					// find the neighbor with the lowest altitude (lower than source)
					int lowestNeighborR = -1;
					int lowestNeighborC = -1;
					int lowestAltitude = 100000;
					int	dest;
					if( (i-1) >= 0 )	// valid spot?
					{
						if( (A[i-1][j] < A[i][j]) && (A[i-1][j] < lowestAltitude) )
						{
							lowestNeighborR = i-1;
							lowestNeighborC = j;
							lowestAltitude = A[i-1][j];
						}
					}
					if( (j-1) >= 0 )
					{
						if( (A[i][j-1] < A[i][j]) && (A[i][j-1] < lowestAltitude) )
						{
							lowestNeighborR = i;
							lowestNeighborC = j-1;
							lowestAltitude = A[i][j-1];
						}
					}
					if( (j+1) < w )
					{
						if( (A[i][j+1] < A[i][j]) && (A[i][j+1] < lowestAltitude) )
						{
							lowestNeighborR = i;
							lowestNeighborC = j+1;
							lowestAltitude = A[i][j+1];
						}
					}
					if( (i+1) < h )
					{
						if( (A[i+1][j] < A[i][j]) && (A[i+1][j] < lowestAltitude) )
						{
							lowestNeighborR = i+1;
							lowestNeighborC = j;
							lowestAltitude = A[i+1][j];
						}
					}
					if( lowestAltitude < A[i][j] )	//there is a lower point...
					{
						dest = lowestNeighborR*w+lowestNeighborC;
						D[src][dest] = lowestAltitude;
					}
				}		
			}
			for( i=0; i<w*h; i++ )
			{
				for( j=0; j<w*h; j++ )
					System.out.print( D[i][j] + " " );
				System.out.println();
			}
			//Now!!! find the shortest paths...
			for( i=0; i<h*w; i++ )
			{
				for( j=0; j<h*w; j++ )
				{
					for( k=0; k<h*w; k++ )
					{
						if( D[j][k] > (D[j][i] + D[i][k]) )
							D[j][k] = D[j][i] + D[i][k];
					}
				}
			}
			for( i=0; i<w*h; i++ )
			{
				for( j=0; j<w*h; j++ )
					System.out.print( D[i][j] + " " );
				System.out.println();
			}
			// Now!!! find and store the basins
			Vector<Basin> basins = new Vector<Basin>();
			char ch = 'Z';
			for( i=0; i<h*w; i++ )
			{
				boolean	isBasin = true;
				for( j=0; j<h*w; j++ )
				{
					if( D[i][j] < 200000 )
						isBasin = false;
				}
				if( isBasin )
				{
					Basin b = new Basin(i, ch);
					basins.add(b);
				}
			}
			ch = 'a';
			for( i=0; i<h*w; i++ )
			{
				boolean isBasin = true;
				for( j=0; j<h*w; j++ )
				{
					if( D[i][j] < 200000 )
					{
						isBasin = false;
						break;
					}
				}
				if( isBasin )
				{
					for( k=0; k<basins.size(); k++ )
					{
						if( basins.elementAt(k).loc == i )
						{	//found!!
							if( basins.elementAt(k).name == 'Z' )
							{
								basins.elementAt(k).name = ch;
								ch++;
							}
							int	t2 = i/w;
							int	t3 = i%w;
							Out[t2][t3] = basins.elementAt(k).name;
						}
					}
				}
				else //if( isBasin == false )
				{
					// find its basin...
					for( j=0; j<h*w; j++ )
					{
						if( D[i][j] < 200000 )
						{
							for( k=0; k<basins.size(); k++ )
							{
								if( basins.elementAt(k).loc == j )
								{	//found!!
									if( basins.elementAt(k).name == 'Z' )
									{
										basins.elementAt(k).name = ch;
										ch++;
									}
									int	t2 = i/w;
									int	t3 = i%w;
									Out[t2][t3] = basins.elementAt(k).name;
								}
							}
						}
					}				
				}
			}
			for( i=0; i<h; i++ )
			{
				for( j=0; j<w; j++ )
				{
					System.out.print( Out[i][j] + " " );
					output.write( Out[i][j] + " " );
				}
				System.out.println();
				output.write( "\n" );
			}	
		}
		output.close();
	}
}