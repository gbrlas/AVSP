import java.io.*;
import java.util.*;

import static java.lang.Math.*;

class P1 {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new FileReader("input.txt"));
		int ts = in.nextInt();
		for(int ii = 0; ii < ts; ++ii){
			int n = in.nextInt();
			int[] st = new int[n];
			int[] fin = new int[n];
			for(int i = 0;  i < n; ++i ){
				st[i] = in.nextInt();
				fin[i] = in.nextInt();
			}
			int ans = 0;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j) {
					if(st[i] < st[j] && fin[i] > fin[j])
						++ans;
				}
			}
			System.out.printf("Case #%d: %d\n", (ii+1), ans);
		}
		in.close();
	}
	
}