import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main( String[] argv ) throws IOException{
		FileWriter fout = new FileWriter( "Bs.out" );
		FileReader fin = new FileReader( "Bs.in" );
		Scanner cin = new Scanner ( fin );
		BigInteger[] data = new BigInteger[1000];
		BigInteger dif;
		int i, n, tt = 0;
		int t = cin.nextInt();
		while( t -- != 0 ){
			n = cin.nextInt();
			for ( i = 0; i < n; i ++ )
				data[i] = cin.nextBigInteger();
			Arrays.sort( data, 0, n );
			dif = data[1].subtract( data[0] );
			for ( i = 2; i < n; i ++ )
				dif = dif.gcd( data[i].subtract( data[ i - 1 ] ) );
			if ( dif.compareTo( BigInteger.ZERO ) == 0 || data[0].mod( dif ).compareTo( BigInteger.ZERO ) == 0 )
				fout.write( "Case #" + ( ++ tt ) + ": " + 0 );
			else
				fout.write( "Case #" + ( ++ tt ) + ": " + dif.subtract( data[0].mod( dif ) ) );
			fout.write( "\n" );
		}
		fout.close();
		fin.close();
	}
}
