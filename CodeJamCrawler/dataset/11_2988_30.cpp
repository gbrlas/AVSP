import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class SquareTiles {

	public static void main(String[] args) {
		

		try {
			
			BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("A-small-attempt0.out"));

			String inString;
			
			// first line
			inString = in.readLine();
			String[] numberOfLines = inString.split(" ");
			
			int numberOfTestCases = Integer.parseInt(numberOfLines[0]);
			
			// test cases
			for(int i=0 ; i<numberOfTestCases ; i++ ) {
				
				// row, column
				inString = in.readLine();

				int row = Integer.parseInt(inString.split(" ")[0]);
				int column = Integer.parseInt(inString.split(" ")[1]);
				
				char[][] picture = new char[row][column];
				
				for( int j=0 ; j<row ; j++ ) {

					inString = in.readLine();
					
					for( int k=0 ; k<column ; k++ ) {
						picture[j][k] = inString.charAt(k);
					}
				}
				
				boolean possible = true;
				
				for( int j=0 ; j<row ; j++ ) {

					for( int k=0 ; k<column ; k++ ) {


						if( picture[j][k] == '#' ) {
							
							if( j+1 >= row || k+1 >= column ) {
								possible = false;
								break;
							}
							
							if( 
							picture[j][k+1] == '#'
							&& picture[j+1][k] == '#'
							&& picture[j+1][k+1] == '#' )
							{
								picture[j][k] = '/';
								picture[j][k+1] = '\\';
								picture[j+1][k] = '\\';
								picture[j+1][k+1] = '/';
							}
						}
					}
				}
				
				
				int testCaseNo = i+1;
				String result = "";
				
				System.out.println("Case #" + testCaseNo + ": ");
				
				out.write("Case #" + testCaseNo + ": "); 
				out.newLine();
				
				if( possible ) {
					
					for( int j=0 ; j<row ; j++ ) {
						for( int k=0 ; k<column ; k++ ) {
							System.out.print(picture[j][k]);
							
							out.write(picture[j][k]); 
						}
						System.out.println();
						out.newLine();
					}
				}
				else {
					System.out.println("Impossible");
					
					out.write("Impossible"); 
					out.newLine();
				}
			}
			
			in.close();
			out.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
