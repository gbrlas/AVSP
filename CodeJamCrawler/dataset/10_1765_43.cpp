import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;



public class SnapperChain {

	public static void main(String[] args) {
		SnapperChain test = new SnapperChain();
		try {
			test.doMain();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/sajith/A-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("/home/sajith/output.txt"));
		int N = sc.nextInt();
		
		for (int caseNum=1; caseNum <= N; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			String value = solve(sc);
			pw.println(value);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	private String solve(Scanner sc) {
		int n = sc.nextInt();
		int k = sc.nextInt();
		int isOn = 1;
		int nK = k;
		for(int i=0; i<n; i++){
			isOn *= (nK%2);
			if(isOn == 0)
				return "OFF";
			nK /= 2;
		}
		return "ON";
	}

	
}
