import java.io.*;
import java.util.*;

import static java.lang.Math.*;

class P2 {
	static int[][] memo;
	static int c;

	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new FileReader("input.txt"));
		int ts = in.nextInt();
		memo = new int[1024][1024];
		for(int ii = 0; ii < ts; ++ii){
			for(int[] i:memo)
				Arrays.fill(i, -1);
			int l = in.nextInt();
			int r = in.nextInt();
			c = in.nextInt();
			int ans = find(l, r);
			System.out.printf("Case #%d: %d\n", (ii+1), ans );
		}
		in.close();
	}
	
	static int find(int l, int r){
		if(l * c >= r)
			return 0;
		if(memo[l][r] != -1)
			return memo[l][r];
		int ans = (int) 1e9;
		for(int i = l + 1; i < r; ++i){
			ans = min(ans, max(find(l, i), find(i, r)) + 1);
		}
		memo[l][r] = ans;
		return ans;
	}
}