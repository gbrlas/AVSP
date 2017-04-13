import java.io.*;
import java.util.Arrays;

public final class Round_1B {
	public static String INPUT_FILE = "C:\\Users\\Jonathanasdf\\Desktop\\B-large.in";
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
	// TODO Auto-generated method stub
		 File inFile  = new File(INPUT_FILE);
		 File outFile = new File("bin\\Output.txt");  
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
	
	public static String solve(String line) {
		String[] input = line.split("\\s");
		int[] digits = new int[input[0].length()];
		for (int i=0; i<digits.length; i++) {
			digits[i] = Integer.parseInt(Character.toString(input[0].charAt(i)));
		}
		if (digits.length == 1) {
			return digits[0] + "0";
		}
		
		int i=0;
		for (i=digits.length-2; i>=0; i--) {
			if (digits[i] < digits[i+1]) {
				break;
			}
			if (i == 0) {
				Arrays.sort(digits);
				if (digits[0] == 0) {
					int j;
					for (j=0; j<digits.length; j++) {
						if (digits[j] != 0) {
							break;
						}
					}
					digits[0] = digits[j];
					digits[j] = 0;
				}
				String result = digits[0] + "0";
				for (int j=1; j<digits.length; j++) {
					result += digits[j];
				}
				return result;
			}
		}
		int smallest = 10;
		int smallestPos = -1;
		for (int j=i;j<digits.length; j++) {
			if (digits[j] > digits[i] && digits[j] < smallest) {
				smallest = digits[j];
				smallestPos = j;
			}
		}
		digits[i] += digits[smallestPos];
		digits[smallestPos] = digits[i] - digits[smallestPos];
		digits[i] -= digits[smallestPos];
		
		
		String result = "";
		for (int j=0; j<=i; j++) {
			result += digits[j];
		}
		int[] newDigits = new int[digits.length-1-i];
		System.arraycopy(digits, i+1, newDigits, 0, newDigits.length);
		Arrays.sort(newDigits);
		for (int j=0; j<newDigits.length; j++) {
			result += newDigits[j];
		}
		
		return result;
	}

}
