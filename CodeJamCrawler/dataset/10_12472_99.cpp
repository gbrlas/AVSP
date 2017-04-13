import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 * @author fabrizyo
 *
 */
public class SnapperChain {
	
	public boolean isOn(int snappers, int snaps) {
		int snapsForCycle = (int) Math.pow(2, snappers);
		return snaps%snapsForCycle==snapsForCycle-1;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc=new Scanner(new File("A-large.in"));
		PrintWriter p=new PrintWriter("out-large-a.txt");
		int cases=sc.nextInt();
		for (int c = 1;  c <=cases; c++) {
			boolean isOn=new SnapperChain().isOn(sc.nextInt(), sc.nextInt());
			p.println("Case #"+c+": "+(isOn ? "ON" : "OFF"));
		}
		p.close();
	}

}
