import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class PerfectHarmony {

	public static void main(String[] args) {
		

		try {
			
			BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("C-small-attempt0.out"));

			String inString;
			
			// first line
			inString = in.readLine();
			String[] numberOfLines = inString.split(" ");
			
			int numberOfTestCases = Integer.parseInt(numberOfLines[0]);
			
			// test cases
			for(int i=0 ; i<numberOfTestCases ; i++ ) {
				
				inString = in.readLine();

				int N = Integer.parseInt(inString.split(" ")[0]);
				int L = Integer.parseInt(inString.split(" ")[1]);
				int H = Integer.parseInt(inString.split(" ")[2]);
				
				inString = in.readLine();
				String[] othersArray = inString.split(" ");

				int testCaseNo = i+1;
				String result = "NO";

				for( int frequency=L ; frequency<=H ; frequency++ ) {
					
					boolean possible = true;
					
					for( int j=0 ; j<N ; j++ ) {
						int otherFrequency = Integer.parseInt(othersArray[j]);
						
						if( otherFrequency % frequency != 0 
								&& frequency % otherFrequency != 0 ) {
							possible = false;
							break;
						}
					}
					
					if( possible ) {
						result = frequency + "";
						break;
					}
				}

				System.out.println("Case #" + testCaseNo + ": " + result);
				
				out.write("Case #" + testCaseNo + ": " + result); 
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
