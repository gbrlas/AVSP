import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Prob {

	boolean []snappers ;
	boolean []incommingPower ;
	final int One = 1 ;
	FileWriter out ; //=  new FileWriter(new File("pro1.out"));
	
	public Prob() {
		try {
			run();
		} catch (Exception e) {
//			System.err.println();
			e.printStackTrace();
		}
	}
	
	
	private void run() throws IOException {
		
		Scanner scan = new Scanner(new File("test.in"));
		out =  new FileWriter(new File("pro1.out"));
		int numberOfTestCases = scan.nextInt();
		int K=0 , N=0;
		int temp=0;
		for (int i = 0; i < numberOfTestCases ; i++) {
			N = scan.nextInt() ;
			K = scan.nextInt() ;
			temp = K & One ;
			//Even
			if( temp == 0){
				out.write("Case #"+(i+1)+": OFF\n");
			}else {
				
//				snappers = new boolean[N];
//				incommingPower = new boolean[N+1];
//				for (int j = 0; j < N ; j++) {
//					snappers[j] = false ;
//					incommingPower[j] = false ;
//				}
//				incommingPower[0] = true ;
//				incommingPower[N] = true ;
//				
//				for (int j = 0; j < K ; j++) {
//
//					for (int m = 0 ; m < N ; m++) {
//						if(incommingPower[m]){
//							snappers[m] = !snappers[m];
//						}
//					}
//					
//					for (int m = 1 ; m <= N ; m++) {
//						incommingPower[m] = ( incommingPower[m-1] & snappers[m-1] );
//					}
//				}
//				if(incommingPower[N])
//					System.out.println("Case #"+(i+1)+": ON");
//				else
//					System.out.println("Case #"+(i+1)+": OFF");
				
				float x = K + 1 ;
				
				float div = (float) (x / Math.pow(2, N));
				int integerDivision = (int) (x / Math.pow(2, N));
				
				if((div - integerDivision) > .000001){
					out.write("Case #"+(i+1)+": OFF\n");
				}else{
					out.write("Case #"+(i+1)+": ON\n");
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
		new Prob();
	}

}
