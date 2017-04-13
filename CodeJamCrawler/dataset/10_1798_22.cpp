import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class IntersectionCount {

	public static void main(String[] args) {
		IntersectionCount test = new IntersectionCount();
		try {
			test.doMain();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/sajith/A-small-attempt2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("/home/sajith/out1.out"));
		int N = sc.nextInt();
		
		NumberFormat nf = NumberFormat.getInstance();
		for (int caseNum=1; caseNum <= N; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			pw.println(solve(sc));
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	private Object solve(Scanner sc) {
		int numWindows = sc.nextInt();
		int[][] arrays= new int[numWindows][2];
		for(int i=0; i<numWindows; i++){
			arrays[i][0] = sc.nextInt();
			arrays[i][1] = sc.nextInt();
		}
		
		int cnt = 0;
		for(int i=0; i<numWindows-1; i++){
			for(int j=i+1; j<numWindows; j++)
			if(arrays[i][0]>arrays[j][0]){
				if(arrays[j][1]>arrays[i][1])
					cnt++;
			}
			else{
				if(arrays[i][1]>arrays[j][1])
					cnt++;
				}
			}
		return cnt;
	}
}
