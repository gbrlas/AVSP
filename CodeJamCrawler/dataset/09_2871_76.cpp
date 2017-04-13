import java.util.Scanner;


public class WaterSheds {

	static int matrix[][];
	static char result[][];
	private static int w;
	private static int h;
	
	static final String NL = System.getProperty("line.separator");
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		matrix = new int[101][101];
		result = new char[101][101];
		Scanner scn = new Scanner(System.in);
		
		int cases = scn.nextInt();
		w = 0;
		h = 0;
		for( int c = 0; c < cases; c++ ) {
			h = scn.nextInt();
			w = scn.nextInt();
			for( int i = 0; i < h; i++ ) {
				for( int j = 0; j < w; j++) {
					int x = scn.nextInt();
					matrix[i][j] = x;
					result[i][j] = 0;
				}
			}
			
			char turn = 'a';
			for( int i = 0; i < h; i++ ) {
				for( int j = 0; j < w; j++) {
					if( result[i][j] != 0 ) {
						continue;
					}
					
					char nturn = process( i, j, turn );
					if( nturn == turn )
						turn++;
					
				}
			}
			StringBuilder builder = new StringBuilder();
			builder.append("Case #");
			builder.append(c+1);
			builder.append(":");
			builder.append(NL);
			for( int i = 0; i < h; i++ ) {
				for( int j = 0; j < w; j++) {
					if( j != 0 )
						builder.append(' ');
					builder.append(result[i][j]);
				}
				builder.append(NL);
			}
			System.out.print(builder.toString());
		}
		

	}

	private static char process(int i, int j, char turn) {
		if( result[i][j] != 0 ) {
			return result[i][j];
		}
		int menor = Integer.MAX_VALUE;
		int a = getTop(i, j);
		int b = getLeft(i, j);
		int c = getRight(i, j);
		int d = getBottom(i, j);
		
		menor = Math.min(Math.min(a,b), Math.min(c, d));
		if( menor >= matrix[i][j])
			menor = Integer.MAX_VALUE;
		char co = turn;
		if( menor == Integer.MAX_VALUE) {
			result[i][j] = turn;
			return turn;
		} else if( menor == a ) {
			co = process(i-1, j, turn);
		} else if ( menor == b ) {
			co = process(i, j-1, turn);
		} else if ( menor == c ) {
			co = process(i, j+1, turn);
		} else if ( menor == d ) {
			co = process(i+1, j, turn);
		}
		result[i][j] = co;
		return co;
	}

	private static int getBottom(int i, int j) {
		if( i == h - 1) {
			return Integer.MAX_VALUE;
		}
		return matrix[i+1][j];
	}

	private static int getRight(int i, int j) {
		if( j == w - 1) {
			return Integer.MAX_VALUE;
		}
		return matrix[i][j+1];
	}

	private static int getLeft(int i, int j) {
		if( j == 0) {
			return Integer.MAX_VALUE;
		}
		return matrix[i][j-1];
	}

	private static int getTop(int i, int j) {
		if( i == 0 ) {
			return Integer.MAX_VALUE;
		}
		return matrix[i-1][j];
	}

}
