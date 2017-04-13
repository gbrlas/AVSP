import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class Magicka {
	public static void main(String[] args) {

		try {

			BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("B-large.out"));

			String inString;

			// first line
			inString = in.readLine();
			int numberOfTestCases = Integer.parseInt(inString);

			// test cases
			for(int i=0 ; i<numberOfTestCases ; i++ ) {
				
				inString = in.readLine();
				String[] inArray = inString.split(" ");
				
				int indexOfArray = 0;
				List<Invokeable> baseInvoke = new ArrayList<Invokeable>();
				List<Invokeable> opposedInvoke = new ArrayList<Invokeable>();

				// base element
				int numberOfBase = Integer.parseInt(inArray[indexOfArray]);
				indexOfArray++;
				for( int j=0 ; j<numberOfBase ; j++ ) {
					
					baseInvoke.add(new InvokeBase(inArray[indexOfArray]));
					indexOfArray++;
				}
				
				// opposed element
				int numberOfOpposed = Integer.parseInt(inArray[indexOfArray]);
				indexOfArray++;
				for( int j=0 ; j<numberOfOpposed ; j++ ) {

					opposedInvoke.add(new InvokeOpposed(inArray[indexOfArray]));
					indexOfArray++;
				}
				
				// invoked element
				int numberOfInvoked = Integer.parseInt(inArray[indexOfArray]);
				indexOfArray++;
				String invokedList = inArray[indexOfArray];
				String invokeResult = "";
				for( int j=0 ; j<numberOfInvoked ; j++ ) {
					
					invokeResult = invokeResult + invokedList.charAt(j);

					for( Invokeable invokeable : baseInvoke ) {
						invokeResult = invokeable.invoke(invokeResult);
					}

					for( Invokeable invokeable : opposedInvoke ) {
						invokeResult = invokeable.invoke(invokeResult);
					}
				}
				
				int testCaseNo = i + 1;

				String elementalList = "";
				
				if( invokeResult.length() > 0 ) { 
					elementalList = "" + invokeResult.charAt(0);
				}
				
				for( int j=1 ; j<invokeResult.length() ; j++ ) {
					elementalList = elementalList + ", " + invokeResult.charAt(j);
				}
				
				
				System.out.println("Case #" + testCaseNo + " : [" + elementalList + "]");
				out.write("Case #" + testCaseNo + ": [" + elementalList + "]"); 
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
