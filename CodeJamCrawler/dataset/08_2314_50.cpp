/**
 * Created on Jul 16, 2008
 */
package net.galluzzo.gcj.savingtheuniverse;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Eric Galluzzo, eric@galluzzo.net
 */
public class SaveTheUniverse
{
	public static void main( String[] args ) throws IOException
	{
		if ( args.length == 2 )
		{
			new SaveTheUniverse().saveTheUniverse( args[0], args[1] );
		}
		else
		{
			System.err.println( "Usage: java " +
				SaveTheUniverse.class.getName() + " inputFile outputFile" );
		}
	}
	
	public void saveTheUniverse( String inputFile, String outputFile )
		throws IOException
	{
		Reader in = new FileReader( inputFile );
		Writer out = new FileWriter( outputFile );
		try
		{
			saveTheUniverse( in, out );
		}
		finally
		{
			in.close();
			out.close();
		}
	}
	
	public void saveTheUniverse( Reader in, Writer out ) throws IOException
	{
		Scanner scanner = new Scanner( in );
		int numTests = scanner.nextInt();
		scanner.nextLine();
		for ( int i = 0; i < numTests; i++ )
		{
			Set<String> searchEngines = new HashSet<String>();
			int numSearchEngines = scanner.nextInt();
			scanner.nextLine();
			for ( int j = 0; j < numSearchEngines; j++ )
			{
				searchEngines.add( scanner.nextLine() );
			}
			
			List<String> queries = new ArrayList<String>();
			int numQueries = scanner.nextInt();
			scanner.nextLine();
			for ( int j = 0; j < numQueries; j++ )
			{
				queries.add( scanner.nextLine() );
			}
			
			int numChanges = calculateNumberOfChanges( searchEngines, queries );
			out.write( "Case #" + (i + 1) + ": " + numChanges + "\n" );
		}
	}
	
	public int calculateNumberOfChanges( Set<String> searchEngines,
		List<String> queries )
	{
		int numChanges = 0;
		Set<String> availableSearchEngines = new HashSet<String>( searchEngines );
		for ( String query : queries )
		{
			availableSearchEngines.remove( query );
			if ( availableSearchEngines.isEmpty() )
			{
				numChanges++;
				availableSearchEngines = new HashSet<String>( searchEngines );
				availableSearchEngines.remove( query );
			}
		}
		
		return numChanges;
	}
}
