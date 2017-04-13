import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class SpaceEmergency {

	public static void main(String[] args) {
		

		try {
			
			BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("B-small-attempt0.out"));

			String inString;
			
			// first line
			inString = in.readLine();
			String[] numberOfLines = inString.split(" ");
			
			int numberOfTestCases = Integer.parseInt(numberOfLines[0]);
			
			// test cases
			for(int i=0 ; i<numberOfTestCases ; i++ ) {
				
				inString = in.readLine();
				String[] inStringArray = inString.split(" ");
				
				int L = Integer.parseInt(inStringArray[0]);
				long t = Long.parseLong(inStringArray[1]);
				int N = Integer.parseInt(inStringArray[2]);
				int C = Integer.parseInt(inStringArray[3]);
				
				int[] a = new int[C];
				for( int j=0 ; j<C ; j++ ) {
					a[j] = Integer.parseInt(inStringArray[4 + j]);
				}
				
				// make
				int[] d = new int[N];
				for( int j=0 ; j<N ; j++ ) {
					d[j] = a[j % C] * 2;
				}
				
				// pick L largest distance after t include at t
				int allA = 0;
				long pointAtT = t;
				long[] canBoostD = new long[N];
				long[] canNotBoostD = new long[N];
				for( int j=0 ; j<N ; j++ ) {
					
					if( allA + d[j] >= pointAtT ) {
						
						// check at t
						if( allA < pointAtT ) {
							canBoostD[j] = allA + d[j] - pointAtT;
							canNotBoostD[j] = pointAtT - allA;
						}
						else {
							canBoostD[j] = d[j];
						}
					}
					else {
						canNotBoostD[j] = d[j];
					}
					
					allA += d[j];
				}
				
				Arrays.sort(canBoostD);
				
				// reduce boosted distance
				for( int j=0 ; j<L ; j++ ) {
					canBoostD[N-j-1] = canBoostD[N-j-1] / 2;
				}
				
				// calculate total time
				int totalTime = 0;
				for( int j=0 ; j<N ; j++ ) {
					totalTime += canBoostD[j];
					totalTime += canNotBoostD[j];
				}
				
				int testCaseNo = i+1;
				String result = "";
				
				
				System.out.println("Case #" + testCaseNo + " : " + totalTime);
				
				out.write("Case #" + testCaseNo + ": " + totalTime); 
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
