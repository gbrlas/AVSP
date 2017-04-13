import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class ProblemA {
	public static void main(String[] args) {
	    try {
	    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	        String result = "-1";
	        int counter = 0;
	        int inputLines = Integer.parseInt(in.readLine());
	        
	        for (int i = 1, length = inputLines; i <= length; i++) {
	        	int row1 = Integer.parseInt(in.readLine());
	        	

	        	ArrayList<String> linearr = new ArrayList<String>();
	        	for (int j = 1; j <= 4; j++) {
	        		String line = in.readLine();
	        		if (j == row1) {
	        			String[] line1 = line.split(" ");
	        			for (String card : line1) {
	        				linearr.add(card);
	        			}
	        		}
	        	}
	        	
	        	int row2 = Integer.parseInt(in.readLine());
	        	
	        	String[] line2;
	        	for (int k = 1; k <= 4; k++) {
	        		String line = in.readLine();
	        		if (k == row2) {
	        			line2 = line.split(" ");
	        			for (int l = 0; l < 4; l++) {
	        				if (linearr.contains(line2[l])) {
	        					result = line2[l];
	        					counter++;
	        				}
	        			}
	        		}
	        	}
	        	
	        	if (counter < 1) {
	        		result = "Volunteer cheated!";
	        	} else if (counter > 1) {
	        		result = "Bad magician!";
	        	}
	        	counter = 0;
	        	System.out.println("Case #" + i + ": " + result);
	        }
	    }
	    catch (IOException e) {
	    }
	}
}
