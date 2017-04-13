import java.io.*;
import java.util.*;
import java.math.*;


public class fairAndSquare
{
    /**
     * @param args
     */
    public static void main( String[] args ) throws IOException
    {
        BufferedReader reader = new BufferedReader( new FileReader( new File( "C-small-attempt1.in" ) ) );
        BufferedWriter writer = new BufferedWriter( new FileWriter( new File( "C-out.txt" ) ) );
        int cases = Integer.parseInt( reader.readLine() );

        for ( int i = 1; i <= cases; i++ )
        {
            int answer = 0;
            StringTokenizer st = new StringTokenizer( reader.readLine() );
            int a = Integer.parseInt( st.nextToken() );
            int b = Integer.parseInt( st.nextToken() );

            BufferedReader data = new BufferedReader( new FileReader( new File( "fairSquares.txt" ) ) );

            while ( data.ready() )
            {
                int temp = Integer.parseInt( data.readLine() );

                if ( ( a <= temp ) && b >= temp )
                {
                    answer++;
                }
            }
            data.close();
            writer.write( "Case #" + ( i ) + ": " + answer );
            writer.newLine();

        }
        reader.close();
        writer.close();
    }
}
