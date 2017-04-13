import java.util.Scanner;


public class Googlerese {
	public static void main( String args[] ) {
		new Googlerese();
	}
	
	public final char[] key = { 'y', 'h', 'e', 's', 'o',// a-e
								'c', 'v', 'x', 'd', 'u',// f-j
								'i', 'g', 'l', 'b', 'k',// k-o
								'r', 'z', 't', 'n', 'w',// p-t
								'j', 'p', 'f', 'm', 'a',// u-y
								'q'};                   // z
	
	public Googlerese() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		
		for( int j=1; j<=T; j++ ) {
			System.out.println( "Case #" + j + ": " + doCase(sc) );
		}
	}
	
	public String doCase( Scanner sc ) {
		String line = sc.nextLine();
		
		String solution = new String();
		for( char c : line.toCharArray() ) {
			if( c == ' ' )
				solution += ' ';
			else
				solution += key[c-'a'];
		}
		
		return solution;
	}
}
