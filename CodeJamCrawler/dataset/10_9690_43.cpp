import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		FileWriter fw = new FileWriter("A-large.out");
		//BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		//FileWriter fw = new FileWriter("A-large.out");
		int T = new Integer(in.readLine());
		for (int cases = 1; cases <= T; cases++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = new Integer(st.nextToken());	//R-times
			int k = new Integer(st.nextToken());	//k-people
			long bin = 2;
			long num_min = 1;
			for (int i = 1;i<N;i++){
				num_min = num_min + bin;
				bin = 2*bin;
			}
			String ok;
			if (k % bin == num_min)
				ok = "ON";
			else
				ok="OFF";
			fw.write("Case #" + cases + ": " + ok + "\n");		
		}
		fw.flush();
		fw.close();
	}

}