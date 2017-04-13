import java.io.*;
import java.util.*;

import static java.lang.Math.*;

class P3 {
	static int[][] b;
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new FileReader("input.txt"));
		int ts = in.nextInt();
		for(int ii = 0; ii < ts; ++ii){
			int m = in.nextInt();
			int n = in.nextInt();

			b = new int[m][n];
			for(int i = 0; i < m; ++i){
				b[i] = parse(in.next());
			}
//			pretty(b);
			int [] ans = new int[min(m,n) + 1];
			for(int sz = min(m, n); sz > 0; --sz){
				for(int i = 0; i <= m - sz; ++i)
					for(int j = 0; j <= n - sz; ++j)
						if(good(i, j, sz)){
							++ans[sz];
							fill(i, j, sz);
//							pretty(b);
//							System.out.println();
						}
			}
			
			int cnt = 0;
			for(int sz = min(m, n); sz > 0; --sz)
				if(ans[sz] != 0)
					++cnt;
			System.out.printf("Case #%d: %d\n", (ii+1), cnt);
			for(int sz = min(m, n); sz > 0; --sz)
				if(ans[sz] != 0)
					System.out.printf("%d %d\n", sz, ans[sz]);
		}
		in.close();
	}
	private static boolean good(int i, int j, int sz){
		for(int di = 0; di < sz; ++di)
			for(int dj = 0; dj < sz; ++dj)
				if(b[i + di][j + dj] == -1)
					return false;

		int lu = b[i][j];
		for(int di = 0; di < sz; ++di)
			for(int dj = 0; dj < sz; ++dj)
				if(b[i + di][j + dj] != ((lu ^ di ^ dj) & 1))
					return false;
		return true;
	}

	private static void fill(int i, int j, int sz){
		for(int di = 0; di < sz; ++di)
			for(int dj = 0; dj < sz; ++dj)
				b[i + di][j + dj] = -1;
	}
	private static int[] parse(String s){
		int n = s.length();
		long val = Long.parseLong(s, 16);
		int[] ans = new int[n * 4];
		for(int i = 0; i < n * 4; ++i){
			ans[ans.length - i - 1] = (int)((val >> i) & 1);
		}
		return ans;
	}

	private static void pretty(int[][] val){
		int m = val.length;
		int n = val[0].length;
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(val[i][j] == 1)
					System.out.print(".");
				if(val[i][j] == 0)
					System.out.print("X");
				if(val[i][j] == -1)
					System.out.print(" ");
			}
			System.out.println();
		}
	}
}