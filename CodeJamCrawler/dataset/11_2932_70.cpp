import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class Main {

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
				inString = in.readLine();
				
				Robot orange = new Robot("O");
				Robot blue = new Robot("B");
				
				String[] inArray = inString.split(" ");
				
				int testCaseNo = i + 1;
				
				// number of buttons
				int numberOfButtons = Integer.parseInt(inArray[0]);
				
				// give order to robots
				for( int j=1 ; j<2 * numberOfButtons ; j++ ) {
					
					// orange robot's order
					if( "O".equals(inArray[j]) ) {
						j++;
						orange.addOrder(inArray[j]);
					}
					
					// or blue's one
					else {
						j++;
						blue.addOrder(inArray[j]);
					}
				}
				
				// get strategy
				int time = 0;
				int indexOfOrder = 1;
				while(true) {
					time++;
					
					String orderedRobot = inArray[indexOfOrder];
					int orderedButton = Integer.parseInt(inArray[indexOfOrder+1]);
					
					boolean orangeResult = orange.perfome(orderedRobot, orderedButton);
					boolean blueResult = blue.perfome(orderedRobot, orderedButton);
					
					if( orangeResult || blueResult ) {
						indexOfOrder++;
						indexOfOrder++;
					}
					
					if( indexOfOrder > 2 * numberOfButtons ) {
						break;
					}
				}
				
				System.out.println("Case #" + testCaseNo + " : " + time);
				
				out.write("Case #" + testCaseNo + ": " + time); 
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
