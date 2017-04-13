import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class CandySplitting {
	/**
	 * @param args
	 */
	public static void main(String[] args) {


		try {
			
			BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("C-small-attempt0.out"));

			String inString;
			
			// first line
			inString = in.readLine();
			int numberOfTestCases = Integer.parseInt(inString);
			
			// test cases
			for(int i=0 ; i<numberOfTestCases ; i++ ) {
				
				// N
				inString = in.readLine();
				int numberOfCandy = Integer.parseInt(inString);

				// Ci
				inString = in.readLine();
				String[] candyString = inString.split(" ");
				int[] candy = new int[numberOfCandy];
				for( int j=0 ; j<numberOfCandy ; j++ ) {
					candy[j] = Integer.parseInt(candyString[j]);
				}
				
				int testCaseNo = i + 1;
				
				// if impossible
				int xorAll = 0;
				for( int j=0 ; j<numberOfCandy ; j++ ) {
					xorAll = xorAll ^ candy[j];
				}
				if( xorAll != 0 ) {
					System.out.println("Case #" + testCaseNo + " : NO");
					out.write("Case #" + testCaseNo + ": NO"); 
				}
				
				// or it's possible
				else {
					
					// sort
					int[] candySorted = Arrays.copyOf(candy, candy.length);
					Arrays.sort(candySorted);
					
					int valueOfSean = 0;
					for( int j=1 ; j<numberOfCandy ; j++ ) {
						valueOfSean = valueOfSean + candySorted[j];
					}

					System.out.println("Case #" + testCaseNo + " : " + valueOfSean);
					out.write("Case #" + testCaseNo + ": " + valueOfSean); 
				}
				
				out.newLine();
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
