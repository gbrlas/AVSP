import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;

public final class Round_1A {
	public static String INPUT_FILE = "C:\\Users\\Jonathanasdf\\Desktop\\A-small-attempt0.in";
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
	// TODO Auto-generated method stub
		 File inFile  = new File(INPUT_FILE);
		 File outFile = new File("C:\\Users\\Jonathanasdf\\Desktop\\Output.txt");  
		 BufferedReader reader = new BufferedReader(new FileReader(inFile));
	     BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
	     String line = null;
	     int lineNumber = 0;
	     String result = "";
	     reader.readLine();
	     System.out.println("Starting program.");
	     while ((line=reader.readLine()) != null) {
	    	 lineNumber++;
	    	 result += "Case #" + lineNumber + ": " + solve(line) + "\r\n";
	    	 System.out.println("Done parsing: " + lineNumber);
	     }
	     writer.write(result);
	     writer.newLine();
	     reader.close();  
	     writer.close(); 
	}
	
	public static int solve(String line) {

		ArrayList<Character> has = new ArrayList<Character>();
		ArrayList<Integer> mapped = new ArrayList<Integer>();
		String result = "";
		mapped.add(1);
		mapped.add(0);
		for (int i=2; i<10; i++) {
			mapped.add(i);
		}
		for (int i=0; i<line.length(); i++) {
			if (!has.contains(line.charAt(i))) {
				has.add(line.charAt(i));
				result += mapped.get(has.size()-1);
			} else {
				result += mapped.get(has.indexOf(line.charAt(i)));
			}
			
		}
		int base = has.size();
		if (base == 1) {
			base = 2;
		}

		int result2 = Integer.parseInt(result, base);
		return result2;
	}

}
