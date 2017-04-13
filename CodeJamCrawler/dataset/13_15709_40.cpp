import java.io.*;
import java.math.*;


public class fairSquareGeneratorInt
{
    /**
     * @param args
     */
    public static void main( String[] args ) throws IOException
    {
        BufferedWriter writer = new BufferedWriter( new FileWriter( new File( "fairSquares.txt" ) ) );

        int big = 1;

        long counter = 1;

        while ( true )
        {
            big = (int)Math.pow( counter, 2 );
            counter++;
            if ( big >= 1E5 )
            {
                writer.close();
                return;
            }
            if ( isPalindrome( "" + big ) && isPalindrome( "" + ( counter - 1 ) ) )
            {
                writer.write( "" + big );
                // System.out.println( big.toString() );
                writer.newLine();
            }
        }
    }


    public static boolean isPalindrome( String word )
    {
        int left = 0; // index of leftmost unchecked char
        int right = word.length() - 1; // index of the rightmost

        while ( left < right )
        { // continue until they reach center
            if ( word.charAt( left ) != word.charAt( right ) )
            {
                return false; // if chars are different, finished
            }
            left++; // move left index toward the center
            right--; // move right index toward the center
        }

        return true; // if finished, all chars were same
    }
}
