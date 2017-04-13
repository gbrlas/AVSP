import java.io.*;

// Author John Schroder
public class Snapper { 
	
	void fastRun( int caseNumber, int N, int K, PrintWriter out ) { 

		long cycle = 1L;
		
		for( int n = 0; n < N; ++n ) {
			
			cycle *= 2L;
		}
		
		long remainder = K % cycle;
		
	    String result = String.format( "Case #%d: %s", 
	    								caseNumber, 
	    								( remainder == (cycle - 1L) ? "ON" : "OFF" ));
	    
	    out.println( result ); 
	}
	
	public void process( String filename, String outputFilename) throws Exception{
		
		PrintWriter out = new PrintWriter(new FileWriter( outputFilename )); 
		 
		Reader r = new BufferedReader(new FileReader(filename));
		
	    StreamTokenizer stok = new StreamTokenizer(r);
	    
	    stok.parseNumbers();
	    
	    stok.nextToken();
	    
	    int nCount = (int)stok.nval;
	     
		for( int nCase = 1; nCase <= nCount; ++nCase ) {

			stok.nextToken();
		    
			int N = (int)stok.nval;
		    
			stok.nextToken();
		    
			int K = (int)stok.nval;
		    
			fastRun( nCase, N, K, out ); 
		}
		
		out.close();
	}
	
	public static void main( String[] args ) throws Exception{
		
		Snapper snapper = new Snapper(); 
		
		snapper.process(args[0], args[1] ); 
	}
}
