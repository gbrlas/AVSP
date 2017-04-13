import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class ThemePark {

	
	public static void main(String[] args) {
		ThemePark test = new ThemePark();
		try {
			test.doMain();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("C:\\Documents and Settings\\SAJITH\\Desktop\\C-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C:\\Documents and Settings\\SAJITH\\Desktop\\output.txt"));
		int N = sc.nextInt();
		
		for (int caseNum=1; caseNum <= N; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int value = solve(sc);
			pw.println(value);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	private int solve(Scanner sc) {
		int R = sc.nextInt();
		int k = sc.nextInt();
		int n = sc.nextInt();
		
		int[] contents = new int[n];
		for(int i=0; i<n; i++){
			contents[i] = sc.nextInt();
		}
		int money = 0;
		int pos = 0;
		for(int i=0; i<R; i++){
			int load = 0;
			int sPos = pos;
			for(int j=0; j<n; j++){
				
				if(load<=k && (k-load)>=contents[pos]){
					load += contents[pos];
					pos = (pos+1)%n;
				}
				else{
					break;
				}
			}
			money += load;
		}
		
		return money;
	}
	
}
