import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class RPI {

	public static void main(String[] args) {
		

		try {
			
			BufferedReader in = new BufferedReader(new FileReader("A-small-attempt2.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("A-small-attempt2.out"));

			String inString;
			
			// first line
			inString = in.readLine();
			String[] numberOfLines = inString.split(" ");
			
			int numberOfTestCases = Integer.parseInt(numberOfLines[0]);
			
			// test cases
			for(int i=0 ; i<numberOfTestCases ; i++ ) {
				
				// team
				inString = in.readLine();
				int numberOfTeams = Integer.parseInt(inString.split(" ")[0]);

				Team[] allTeams = new Team[numberOfTeams];
				
				// new team, calc wp
				for( int j=0 ; j<numberOfTeams ; j++ ) {
					inString = in.readLine();
					
					allTeams[j] = new Team(j, inString);
				}
				
				// link each other
				for( int j=0 ; j<numberOfTeams ; j++ ) {
					
					for( int k=0 ; k<numberOfTeams ; k++ ) {

						allTeams[j].link(allTeams[k]);
					}
				}
				
				// calc owp
				for( int j=0 ; j<numberOfTeams ; j++ ) {
					allTeams[j].calcOWP();
				}
				
				// calc oowp
				for( int j=0 ; j<numberOfTeams ; j++ ) {
					allTeams[j].calcOOWP();
				}
				
				int testCaseNo = i+1;
				
				System.out.println("Case #" + testCaseNo + ": ");
				for( int j=0 ; j<numberOfTeams ; j++ ) {
					System.out.println(allTeams[j].getRPI() + "");
				}
				
				out.write("Case #" + testCaseNo + ": ");
				out.newLine();
				for( int j=0 ; j<numberOfTeams ; j++ ) {
					out.write(allTeams[j].getRPI() + "");
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
