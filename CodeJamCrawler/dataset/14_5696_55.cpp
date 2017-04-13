
import java.util.*;
import java.io.*;
public class Main {
	public static long time = 0;
	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		
		IN = new FileInputStream("input.txt");
		OUT = new FileOutputStream("output.txt");
		in = new BufferedReader(new InputStreamReader(IN));
		out = new PrintWriter(OUT, FLUSH);
		solveOne();
		out.flush();
	}
	
	public static void solveOne() throws Exception {
		int no = ni();
		for (int qq = 0; qq < no; qq++){
			Set<Integer> ans1 = new HashSet<>();
			int row1 = ni() - 1;
			for (int i = 0 ; i < 4; i++){
				for (int j = 0; j < 4; j++){
					int temp = ni();
					if (i == row1){
						ans1.add(temp);
					}
				}
			}
			Set<Integer> ans2 = new HashSet<>();
			int row2 = ni() - 1;
			for (int i = 0 ; i < 4; i++){
				for (int j = 0; j < 4; j++){
					int temp = ni();
					if (i == row2){
						ans2.add(temp);
					}
				}
			}
			ans1.retainAll(ans2);
			if (ans1.size() == 0){
				out.println("Case #" + (qq + 1) + ": " + "Volunteer cheated!");
			}
			else if (ans1.size() == 1){
				out.println("Case #" + (qq + 1) + ": " + ans1.iterator().next() );
			}
			else {
				out.println("Case #" + (qq + 1) + ": " + "Bad magician!");
			}
		}
	}
	
	public static void solveTwo() throws Exception {
		
	}
	
	public static void solveThree() throws Exception {
		
	}
	
	public static BufferedReader in;
	public static StringTokenizer st;
	public static InputStream IN;
	public static OutputStream OUT;
	public static String nx() throws Exception {
		for (;st == null || !st.hasMoreTokens();){
			String k1 = in.readLine();
			if (k1 == null) return null;
			st = new StringTokenizer(k1);
		}
		return st.nextToken();
	}
	public static int ni () throws Exception {
		return Integer.parseInt(nx());
	}
	public static long nl() throws Exception{
		return Long.parseLong(nx());
	}
	public static double nd() throws Exception{
		return Double.parseDouble(nx());
	}
	public static void px(Object ... l1){
		System.out.println(Arrays.deepToString(l1));
	}
	public static boolean FLUSH = false;
	public static PrintWriter out;
	public static void p(Object ... l1){
		for (int i = 0; i < l1.length; i++){
			if (i != 0) out.print(' ');
			out.print(l1[i].toString());
		}
	}
	public static void pn(Object ... l1){
		for (int i = 0; i < l1.length; i++){
			if (i != 0) out.print(' ');
			out.print(l1[i].toString());
		}
		out.println();
	}
	
	public static void pn(Collection l1){
		boolean first = true;
		for (Object e: l1){
			if (first) first = false;
			else out.print(' ');
			out.print(e.toString());
		}
		out.println();
	}

}
