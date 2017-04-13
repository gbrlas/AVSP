import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Prob2 {

	int []groups ;
	int []nextStart ;
	int []earn ;
	final int One = 1 ;
	FileWriter out ; //=  new FileWriter(new File("pro1.out"));
	
	public Prob2() {
		try {
			run();
		} catch (Exception e) {
//			System.err.println();
			e.printStackTrace();
		}
	}
	
	
	private void run() throws IOException {
		
		Scanner scan = new Scanner(new File("test.in"));
		out =  new FileWriter(new File("pro2.out"));
		int numberOfTestCases = scan.nextInt();
		int K=0 , N=0, R= 0;
		for (int i = 0; i < numberOfTestCases ; i++) {
			R = scan.nextInt();
			K = scan.nextInt() ;
			N = scan.nextInt() ;
			
			groups = new int[N];
			nextStart = new int[N];
			earn = new int[N];
			
			for (int j = 0; j < N ; j++) {
				groups[j] = scan.nextInt();
				nextStart[j] = -1 ;
				earn[j] = 0 ;
			}
			int peopleInside;
			for (int j = 0; j < N ; j++) {
				peopleInside = 0 ;
				int whereIAm = j , steps = 0;
				while( true ){
					peopleInside += groups[whereIAm];
					steps ++ ;
					if(peopleInside > K || steps > N ){
						nextStart[j] = whereIAm ;
						earn[j] = peopleInside - groups[whereIAm] ;
						break;
					}
					whereIAm++ ;
					whereIAm %= N ;
				}
			}
			int startIndex = 0 , totalEarn = 0;
			for (int j = 0; j < R ; j++) {
				totalEarn += earn[startIndex];
				startIndex = nextStart[startIndex];
			}
			
			out.write("Case #"+(i+1)+": "+totalEarn+"\n");
			

		}
		
		
		
		out.close();
		scan.close();
	}


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Prob2();
	}

}
