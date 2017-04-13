/**
 * Created on Jul 16, 2008
 */
package net.galluzzo.gcj;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * @author Eric Galluzzo, eric@galluzzo.net
 */
public class MinimumScalarProduct
{
	public static void main( String[] args ) throws IOException
	{
		if ( args.length == 2 )
		{
			new MinimumScalarProduct().run( args[0], args[1] );
		}
		else
		{
			System.err.println( "Usage: java " +
				MinimumScalarProduct.class.getName() + " inputFile outputFile" );
		}
	}
	
	public void run( String inputFile, String outputFile ) throws IOException
	{
		Reader in = new FileReader( inputFile );
		Writer out = new FileWriter( outputFile );
		try
		{
			run( in, out );
		}
		finally
		{
			in.close();
			out.close();
		}
	}
	
	public void run( Reader in, Writer out ) throws IOException
	{
		Scanner scanner = new Scanner( in );
		int numTests = scanner.nextInt();
		scanner.nextLine();
		for ( int i = 0; i < numTests; i++ )
		{
			int numCoords = scanner.nextInt();
			List<Integer> vector1 = new ArrayList<Integer>();
			List<Integer> vector2 = new ArrayList<Integer>();
			for ( int j = 0; j < numCoords; j++ )
			{
				vector1.add( scanner.nextInt() );
			}
			scanner.nextLine();
			for ( int j = 0; j < numCoords; j++ )
			{
				vector2.add( scanner.nextInt() );
			}
			scanner.nextLine();
			int result = calculateMinScalarProduct( vector1, vector2 );
			out.write( "Case #" + (i + 1) + ": " + result + "\n" );
		}
	}
	
	protected int calculateMinScalarProduct( List<Integer> vector1, List<Integer> vector2 )
	{
		Collections.sort( vector1 );
		Collections.sort( vector2 );
		Collections.reverse( vector2 );
		int scalarProduct = 0;
		for ( int i = 0; i < vector1.size(); i++ )
		{
			scalarProduct += vector1.get( i ) * vector2.get( i );
		}
		return scalarProduct;
	}
}
