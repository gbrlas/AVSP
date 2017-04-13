import java.util.*;

public class q3 {

	static String w = new String("welcome to code jam");
	static String str;
	static int c = w.length();
	static int len, rtn;
	static int[][] array;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine());
		w = " "+w;
		for(int i=1; i<=n; i++){
			str = sc.nextLine();
			len = str.length();
			array = new int[5001][c+1];
			str = " "+str; rtn=0;
			solve(); System.out.printf("Case #%d: %04d\n", i, rtn%10000);
		}
	}
	
	public static void solve()
	{
		for(int i=1; i<=len; i++){
			if(w.charAt(1)==str.charAt(i))
				array[i][1] = 1;
			for(int j=2; j<=c; j++){
				if(w.charAt(j)==str.charAt(i)){
					int val = 0;
					for(int k=1; k<i; k++)
						val += array[k][j-1];
					array[i][j] = val;
				}
			}
			rtn += array[i][c];
		}
	}
}
