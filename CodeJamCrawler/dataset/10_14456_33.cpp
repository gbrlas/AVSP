import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Snapper {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File(args[0]);
		try {
           Scanner scanner = new Scanner(f);
           int numberOfCases = Integer.parseInt(scanner.nextLine());
           
           for(int i=0; i < numberOfCases; i++) {
        	   String line = scanner.nextLine();
        	   StringTokenizer tokens = new StringTokenizer(line);
        	   int numberOfSnappers = Integer.parseInt(tokens.nextToken());
        	   int snaps = Integer.parseInt(tokens.nextToken());
        	   
        	   double k = Math.pow(2, numberOfSnappers);
        	   String y = "OFF";
        	   if(k - snaps%k == 1) {
        		   y = "ON";
        	   }
        	   
        	   System.out.println("Case #" + (i+1) + ": " + y);
           }
           
	    } catch (FileNotFoundException e) {
		           e.printStackTrace();
	    }
	}

}
