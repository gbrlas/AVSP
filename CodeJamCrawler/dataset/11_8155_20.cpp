package jam2011.botTrust;

import java.io.FileInputStream;
import java.util.Scanner;

public class BotTrust
{
	public static void doTestCase( Scanner file )
	{
		int numButtons = file.nextInt();
		
		int posO=1, timeO=0, posB=1, timeB=0, time=0;
		for( int i=0; i<numButtons; i++ )
		{
			String robot  = file.next();
			int button = file.nextInt();
			
			//System.out.println( "Robot "+robot+" to button " + button);
			
			if( robot.equals("O") )
			{
				int difference = Math.abs( posO - button );
				//System.out.println( "Difference of "+difference );
				
				posO = button;
				timeO += difference + 1;
				
				//System.out.println( "Time="+time+" timeO="+timeO );
				
				if( timeO <= timeB )
					timeO = timeB+1;
				
				time = Math.max( time, timeO );
				//System.out.println( "New time of " + time);
			}
			else
			{
				int difference = Math.abs( posB - button );
				//System.out.println( "Difference of "+difference );
				
				posB = button;
				timeB += difference + 1;
				
				if( timeB <= timeO )
					timeB = timeO+1;
				
				time = Math.max( time, timeB );
				//System.out.println( "New time of " + time);
			}
		}
		System.out.print( time );
	}
	
	public static void main(String[] args)
	{
		try {
			Scanner file = new Scanner( new FileInputStream( "A-large.in" ) );

			int numTestCases = file.nextInt( );
			
			for( int i = 1; i <= numTestCases; i++ )
			{
				System.out.print( "Case #"+i+": " );
				doTestCase( file );
				//System.out.println();System.out.println();System.out.println();
				if( i != numTestCases )
					System.out.println();
			}
		}
		catch( Exception e ) {
                        System.err.println( e );
                        e.printStackTrace( );
		}
	}
}
