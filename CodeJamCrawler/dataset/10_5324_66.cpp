import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * 
 * @author "Blake Arnold"
 *
 *
 *used binary pattern matching
 */
public class Snapper {
	
	private final static String filename = "A-large.in";
	private final static String outFilename = "file1.out";
	
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new File(filename));
		BufferedWriter out = new BufferedWriter(new FileWriter(outFilename));
		long time = System.currentTimeMillis();
	    int totalTests = new Integer(sc.nextLine());
	    for(int i = 1; i < totalTests+1; i++){
	    	 String line[] = sc.nextLine().split("\\s");
	    	 int n = new Integer(line[0]);
	    	 int k = new Integer(line[1]);
	    	 out.write("Case #" + i + ": ");
	    	 //System.out.println(n+ " "+k + " ");
	    	 
	    	 if((k+1)%Math.pow(2,n) == 0){
	    		 out.write("ON\n");
	    		// System.out.println("on");
	    	 }
	    	 else{
	    		 out.write("OFF\n");
	    		// System.out.println("off");
	    	 }
	    		 
	    }
	    System.out.println("Done. " + (System.currentTimeMillis() - time));
	    out.close();
		
		
	}
}
