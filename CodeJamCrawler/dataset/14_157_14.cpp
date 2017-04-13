import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class MagicTrick {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) {
		int testCases = Integer.parseInt(readInput());
		String finalOutput = new String();
		for( int i=1; i <= testCases; i++ ) {
			finalOutput += doMagicTrick(i) + "\n";
		}    
		System.out.print(finalOutput);
	}
	
	public static String doMagicTrick(int testCase) {
		String output = "Case #" + String.valueOf(testCase) + ": ";
		String[] firstRow = readCorrectRow().split(" ");
		String[] secondRow = readCorrectRow().split(" ");
		
		Set<String> firstSet = new HashSet<String>(Arrays.asList(firstRow));
		Set<String> secondSet = new HashSet<String>(Arrays.asList(secondRow));
		
		firstSet.retainAll(secondSet);
		
		if (firstSet.size() == 1) {
			output+= firstSet.iterator().next();
		} else if (firstSet.size() == 0) {
			output+= "Volunteer cheated!";
		} else {
			output+= "Bad magician!";
		}
		
		return output;
	}
	
	public static String readCorrectRow() {
		int rowNum = Integer.parseInt(readInput());
		String row = new String();
		for( int i=1; i <= 4; i++ ) {
			String rowVals = readInput();
			if(i==rowNum) {
				row = rowVals;
			}
		}
		return row;
	}
	
	public static String readInput() {
		String input = new String();
	    // assuming input is always correct 
	    try {
	    	input =  br.readLine();
	    	
	    } catch (IOException e) {
	        System.err.println("Wrong input!");
	    }
	    return input;
	}
}
