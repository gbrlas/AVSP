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
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

/**
 * @author Eric Galluzzo, eric@galluzzo.net
 */
public class Milkshakes
{
	protected class Preference
	{
		public int type;
		public boolean malted;
	}
	
	public static void main( String[] args ) throws IOException
	{
		if ( args.length == 2 )
		{
			new Milkshakes().run( args[0], args[1] );
		}
		else
		{
			System.err.println( "Usage: java " +
				Milkshakes.class.getName() + " inputFile outputFile" );
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
			int numFlavors = scanner.nextInt();
			scanner.nextLine();
			int numCustomers = scanner.nextInt();
			scanner.nextLine();
			List<List<Preference>> customers = new ArrayList<List<Preference>>();
			for ( int j = 0; j < numCustomers; j++ )
			{
				int numTypes = scanner.nextInt();
				List<Preference> preferences = new ArrayList<Preference>();
				for ( int k = 0; k < numTypes; k++ )
				{
					Preference pref = new Preference();
					pref.type = scanner.nextInt() - 1;
					pref.malted = ( scanner.nextInt() == 1 );
					preferences.add( pref );
				}
				customers.add( preferences );
			}
			
			boolean[] maltedFlavors = shouldBeMalted( numFlavors, customers );
			String result = " IMPOSSIBLE";
			if ( maltedFlavors != null )
			{
				StringBuffer sb = new StringBuffer();
				for ( boolean malted : maltedFlavors )
				{
					sb.append( " " );
					sb.append( malted ? "1" : "0" );
				}
				result = sb.toString();
			}
			
			out.write( "Case #" + (i + 1) + ":" + result + "\n" );
		}
	}
	
	protected boolean[] shouldBeMalted( int numFlavors, List<List<Preference>> customers )
	{
		boolean[] mustBeMalted = new boolean[numFlavors];
		boolean[] mustBeUnmalted = new boolean[numFlavors];
		for ( List<Preference> customer : customers )
		{
			if ( !checkSatisfaction( mustBeMalted, mustBeUnmalted, customer ) )
			{
				return null;
			}
		}
		
		int removed = 0;
		do
		{
			removed = 0;
			for ( List<Preference> customer : customers )
			{
				for ( Iterator<Preference> prefIter = customer.iterator(); prefIter.hasNext(); )
				{
					Preference pref = prefIter.next();
					if ( ( mustBeMalted[pref.type] && !pref.malted )
						|| ( mustBeUnmalted[pref.type] && pref.malted ) )
					{
						prefIter.remove();
						removed++;
					}
				}
				
				if ( !checkSatisfaction( mustBeMalted, mustBeUnmalted, customer ) )
				{
					return null;
				}
			}
		} while ( removed > 0 );
		
		return mustBeMalted;
	}

	/**
	 * @param mustBeMalted
	 * @param mustBeUnmalted
	 * @param customer
	 */
	protected boolean checkSatisfaction( boolean[] mustBeMalted,
		boolean[] mustBeUnmalted, List<Preference> customer )
	{
		if ( customer.size() == 1 )
		{
			int flavor = customer.get( 0 ).type;
			if ( customer.get( 0 ).malted )
			{
				mustBeMalted[flavor] = true;
			}
			else
			{
				mustBeUnmalted[flavor] = true;
			}
			
			if ( mustBeMalted[flavor] && mustBeUnmalted[flavor] )
			{
				return false;
			}
		}
		return true;
	}
}
