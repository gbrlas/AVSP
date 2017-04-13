import java.io.*;


public class tictactoe
{
    private static BufferedReader reader;

    private static BufferedWriter writer;


    /**
     * @param args
     */
    public static void main( String[] args ) throws IOException
    {
        reader = new BufferedReader( new FileReader( new File( "A-large.in" ) ) );
        writer = new BufferedWriter( new FileWriter( new File( "out.txt" ) ) );
        int cases = Integer.parseInt( reader.readLine() );

        for ( int i = 1; i <= cases; i++ )
        {
            String result = doTicTacToe();
            reader.readLine();

            writer.write( "Case #" + ( i ) + ": " + result );
            writer.newLine();
        }
        reader.close();
        writer.close();
    }


    private static String doTicTacToe() throws IOException
    {
        char[][] board = new char[4][4];
        for ( int i = 0; i < 4; i++ )
        {
            String line = reader.readLine();
            for ( int a = 0; a < 4; a++ )
            {
                board[i][a] = line.charAt( a );
            }
        }

        // check horizontal cases
        for ( int i = 0; i < 4; i++ )
        {
            String tmp = "";
            for ( int a = 0; a < 4; a++ )
            {
                tmp += board[i][a];
            }
            tmp = handleT( tmp );
            System.out.println( tmp );
            char first = tmp.charAt( 0 );
            if ( first == '.' )
            {
                continue;
            }
            boolean same = true;
            for ( int b = 1; b < 4; b++ )
            {
                if ( tmp.charAt( b ) != first )
                {
                    same = false;
                    break;
                }
            }
            if ( same )
            {
                first = Character.toUpperCase( first );
                return first + " won";
            }

        }

        // check vertical cases
        for ( int a = 0; a < 4; a++ )
        {
            String tmp = "";
            for ( int i = 0; i < 4; i++ )
            {
                tmp += board[i][a];
            }
            tmp = handleT( tmp );
            System.out.println( tmp );
            char first = tmp.charAt( 0 );
            if ( first == '.' )
            {
                continue;
            }
            boolean same = true;
            for ( int b = 1; b < 4; b++ )
            {
                if ( tmp.charAt( b ) != first )
                {
                    same = false;
                    break;
                }
            }
            if ( same )
            {
                first = Character.toUpperCase( first );
                return first + " won";
            }
        }

        // check diagonal cases
        for ( int i = 0; i < 1; i++ )
        {
            String tmp = "";
            for ( int a = 0; a < 4; a++ )
            {
                tmp += board[a][a];
            }
            tmp = handleT( tmp );
            System.out.println( tmp );
            char first = tmp.charAt( 0 );
            if ( first == '.' )
            {
                continue;
            }
            boolean same = true;
            for ( int b = 1; b < 4; b++ )
            {
                if ( tmp.charAt( b ) != first )
                {
                    same = false;
                    break;
                }
            }
            if ( same )
            {
                first = Character.toUpperCase( first );
                return first + " won";
            }
        }

        for ( int i = 0; i < 1; i++ )
        {
            String tmp = "";
            for ( int a = 0; a < 4; a++ )
            {
                tmp += board[3 - a][a];
            }
            tmp = handleT( tmp );
            System.out.println( tmp );
            char first = tmp.charAt( 0 );
            if ( first == '.' )
            {
                continue;
            }
            boolean same = true;
            for ( int b = 1; b < 4; b++ )
            {
                if ( tmp.charAt( b ) != first )
                {
                    same = false;
                    break;
                }
            }
            if ( same )
            {
                first = Character.toUpperCase( first );
                return first + " won";
            }
        }
        boolean full = true;
        for ( char[] a : board )
        {
            for ( char n : a )
            {
                if ( n == '.' )
                {
                    full = false;
                    break;
                }
            }
            if ( !full )
            {
                break;
            }
        }
        if(!full)
        {
            return "Game has not completed";
        }
        return "Draw";

    }


    private static String handleT( String tmp )
    {
        int index = tmp.indexOf( "T" );
        char temp;
        System.out.println( index );
        if ( index == 3 )
        {
            temp = tmp.charAt( 2 );
        }
        else
        {
            temp = tmp.charAt( 3 );
        }
        System.out.println( temp );
        tmp = tmp.replace( 'T', temp );
        return tmp;

    }
}
