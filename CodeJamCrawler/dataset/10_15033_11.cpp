import java.io.*;

// John Schroder
public class ProblemA {
	
	int N;
	
	int K;
	
	char[][] baseArray;
	
	char[][] testArray;
	
	public ProblemA( int N, int K, char[][] array ) {
		this.N = N;
		this.K = K;
		this.baseArray = array;
		this.testArray = new char[N][N];
	}
	
	void print( char[][] array ) {
		for(int row=0; row < N; ++row ) {
			for(int col=0; col < N; ++col ) {
				System.out.print( array[row][col]);
			}
			System.out.println();
		}
		System.out.println("-------");
	}
	
	char[][] rotate( char[][] array, boolean trace ) {
		for( int row = 0; row < N; row++ ) {
			for(int col =0; col < N; col++ ) {
				int newRow = col;
				int newCol = (N-1)-row;
				testArray[newRow][newCol] = array[row][col];
			}
		}
		
		for(int col = 0; col < N; col++ ) {
			int btmRow = N-1;  
			for(int row = N-1; row >= 0; row-- ) {
				if ( testArray[row][col] == '.') {
					btmRow = row; 
					break;
				}				
			}
			
			for(int row = btmRow -1; row >= 0; row-- ) {
				if ( testArray[row][col] != '.') {
					if ( testArray[btmRow][col] == '.' ) {
						testArray[btmRow][col] = testArray[row][col];
						testArray[row][col] = '.';
					}
					btmRow--;
				}
			} 
		}  
		return testArray;
	}
	
	boolean test( char[][] array, char color) {
		for(int row = 0; row < N; row++) {
			int inRow = 0;
			for(int col=0; col < N; col++) {
				if (array[row][col] == color ) {
					inRow++;
					if ( inRow == K) {
						return true;
					}
				}
				else {
					inRow = 0;
					if ( N - col < K ) {
						break;
					}
				}
			}
		}
		
		for(int col = 0; col < N; col++) {
			int inRow = 0;
			for(int row=0; row < N; row++) {
				if (array[row][col] == color ) {
					inRow++;
					if ( inRow == K) {
						return true;
					}
				}
				else {
					inRow = 0;
					if ( N - row < K ) {
						break;
					}
				}
			}
		}

		for(int offset = 0 ; offset < N; offset++ ) {
			int inRow = 0;
			for(int row = 0; row + offset < N; row++ ) {
				int col = row+offset;
				if (array[row][col] == color ) {
					inRow++;
					if ( inRow == K) {
						return true;
					}
				}
				else {
					inRow = 0;
				}
			}
		}
		
		for(int offset = 0 ; offset < N; offset++ ) {
			int inRow = 0;
			for(int row = 0; row + offset < N; row++ ) {
				int col = (N-1) - (row+offset);
				if (array[row][col] == color ) {
					inRow++;
					if ( inRow == K) {
						return true;
					}
				}
				else {
					inRow = 0;
				}
			}
		}
		
		for(int offset = 0 ; offset < N; offset++ ) {
			int inRow = 0;
			for(int col = 0; col + offset < N; col++ ) {
				int row = col+offset;
				if (array[row][col] == color ) {
					inRow++;
					if ( inRow == K) {
						return true;
					}
				}
				else {
					inRow = 0;
				}
			}
		}
		
		for(int offset = 0 ; offset < N; offset++ ) {
			int inRow = 0;
			for(int col = 0; col + offset < N; col++ ) {
				int row = (N-1) - (col+offset);
				if (array[row][col] == color ) {
					inRow++;
					if ( inRow == K) {
						return true;
					}
				}
				else {
					inRow = 0;
				}
			}
		}

		return false;
	}
	 
	public String run( boolean trace ) {
		
		char[][] output = rotate(baseArray, trace);

		boolean blue = test(output, 'B');
		boolean red = test(output, 'R');
		
		if ( blue && red ) 
			return "Both";
		if ( blue )
			return "Blue";
		if ( red )
			return "Red";
		return "Neither";
	}
	
	static public void process( String filename, String outputFilename) throws Exception{
		
		PrintWriter out = new PrintWriter(new FileWriter( outputFilename )); 
		
		BufferedReader in = new BufferedReader(new FileReader( filename ) );
		
		String line = in.readLine();
	    
	    int nCount = Integer.parseInt( line ); 
	     
		for( int nCase = 1; nCase <= nCount; ++nCase ) {
			
			line = in.readLine();
			
			String[] tokens = line.split( " " ); 
		    
			int N = Integer.parseInt( tokens[0] );
			
			int K = Integer.parseInt( tokens[1] );
			
			char[][] array= new char[N][N];
			
			for( int row = 0; row < N; row++ ) {
				line = in.readLine();
				for( int col = 0; col < N; col++ ) {
					array[row][col] = line.charAt(col);
				}
			}
			
			ProblemA problem = new ProblemA( N, K, array );
			out.println( String.format( "Case #%d: %s ", nCase, problem.run( false) ) );
		}
		
		out.close();
	}
	
	public static void main( String[] args ) throws Exception{ 
			
		ProblemA.process(args[0], args[1] ); 
	}
}
