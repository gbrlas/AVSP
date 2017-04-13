
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
			int n1 = ni();
			double[] l1 = new double[n1];
			for (int i = 0; i < n1; i++){
				l1[i] = nd();
			}
			double[] l2 = new double[n1];
			for (int i = 0; i < n1; i++){
				l2[i] = nd();
			}
			Arrays.sort(l1);
			Arrays.sort(l2);
			int ans1 = 0;
			int ans2 = l2.length;
			px(qq);
			px(l1);
			px(l2);
			{
				int ptr = 0;
				for (double e: l1){
					if (e > l2[ptr]){
						ans1++;
						ptr++;
					}
					if (ptr >= l2.length) break;
				}
			}
			{
				int A = 0;
				int ptr1 = 0;
				int ptr2 = 0;
				for (;;){
					if (ptr1 >= l1.length && ptr2 >= l2.length) break;
					boolean takeA = true;
					if (ptr1 >= l1.length){
						takeA = false;
					}
					else if (ptr2 >= l2.length){
						
					}
					else if (l2[ptr2] < l1[ptr1]){
						takeA = false;
					}
					if (takeA){
						px("A", l1[ptr1]);
						ptr1++;
						A++;
					}
					else {
						px("b", l2[ptr2]);
						ptr2++;
						if (A > 0){
							ans2--;
							A--;
						}
					}
				}
			}
			out.printf("Case #%d: %d %d\n", qq + 1, ans1, ans2);
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
