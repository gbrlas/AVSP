import java.io.*;
import java.util.*;
import java.math.*;


public class bullseye
{
    static BufferedReader reader;

    static PrintWriter writer;


    /**
     * @param args
     */
    public static void main( String[] args ) throws IOException
    {
        reader = new BufferedReader( new FileReader( new File( "A-small-attempt0.in" ) ) );
        writer = new PrintWriter( new BufferedWriter( new FileWriter( new File( "A-out.txt" ) ) ) );
        int cases = Integer.parseInt( reader.readLine() );

        for ( int i = 1; i <= cases; i++ )
        {
            String result = run();
            System.out.println( "Case #" + i + ": " + result );
            writer.println( "Case #" + i + ": " + result );
        }
        reader.close();
        writer.close();
    }


    private static String run() throws IOException
    {
        StringTokenizer st = new StringTokenizer( reader.readLine() );
        // long radius = Integer.parseInt( st.nextToken() );
        // long amtPaint = Integer.parseInt( st.nextToken() );

        BigInteger radius = new BigInteger( st.nextToken() );
        BigInteger amtPaint = new BigInteger( st.nextToken() );

        // int circles = 0;
        BigInteger two = new BigInteger( "2" );
        BigInteger circles = new BigInteger( "0" );

        while ( true )
        {

            BigInteger area = ( square( radius.add( BigInteger.ONE ) ).subtract( square( radius ) ) );
//            System.out.println( area );

            radius = radius.add( two );
            amtPaint = amtPaint.subtract( area );
            circles = circles.add( BigInteger.ONE );
            if ( amtPaint.compareTo( new BigInteger( "0" ) ) == -1 )
            {
                return "" + circles.subtract( BigInteger.ONE );
            }
        }

    }


    private static BigInteger square( BigInteger n )
    {
        return n.multiply( n );
    }
}
