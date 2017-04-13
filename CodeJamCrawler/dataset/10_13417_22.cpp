import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class SubC {
	int N = 0 ; 
	final int One = 1;
	FileWriter out; // = new FileWriter(new File("pro1.out"));

	public SubC() {
		try {
			run();
		} catch (Exception e) {
			// System.err.println();
			e.printStackTrace();
		}
	}

	int all = 0 ;
	int intialIndex = 1 ;
	
	private void run() throws IOException {

		Scanner scan = new Scanner(new File("extra.in"));
		out = new FileWriter(new File("pro2.out"));
		int numberOfTestCases = scan.nextInt();

		for (int i = 0; i < numberOfTestCases; i++) {
			
			N = scan.nextInt();
			
			if(N == 1 ){
				int temp = scan.nextInt() ;
				temp = scan.nextInt() ;
				out.write("Case #"+(i+1)+": 0\n");
			}else{
				int a1 = scan.nextInt() ;
				int b1 = scan.nextInt() ;
				int a2 = scan.nextInt() ;
				int b2 = scan.nextInt() ;
				
				if((a1 < a2 && b1 > b2 ) || (a1 > a2 && b1 < b2 ) ){
					out.write("Case #"+(i+1)+": 1\n");
				}else{
					out.write("Case #"+(i+1)+": 0\n");
				}
			}
			

		}

		out.close();
		scan.close();
	}



		
		
		

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new SubC();
	}

}
