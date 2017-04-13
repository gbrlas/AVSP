import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-small.in"));
		FileWriter fw = new FileWriter("C-small.out");
		/*BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		FileWriter fw = new FileWriter("A-large.out");*/
		int T = new Integer(in.readLine());
		for (int cases = 1; cases <= T; cases++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int R = new Integer(st.nextToken());	//R-times
			int k = new Integer(st.nextToken());	//k-people
			int N = new Integer(st.nextToken());	//N-size_group
			int[] queue = new int[N];
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < queue.length; j++) {
				queue[j] = new Integer(st.nextToken());
			}
			int money = 0;
			int punt = 0;			
			for (int i = 0; i<R; i++){
				int gr = N;
				int aux_k = k;
				boolean fin = false;
				while (!fin){
					if ((queue[punt] <= aux_k) && (gr>0)){
						aux_k = aux_k - queue[punt];
						money = money + queue[punt];
						punt= (punt + 1) % N;
						gr--;
					}
					else
						fin = true;
				}
			}
			fw.write("Case #" + cases + ": " + money + "\n");		
		}
		fw.flush();
		fw.close();
	}

}