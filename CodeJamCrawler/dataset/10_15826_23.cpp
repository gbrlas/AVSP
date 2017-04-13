import java.io.*;
import java.util.*;

import static java.lang.Math.*;

class A {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new FileReader("input.txt"));
		int ts = in.nextInt();
		for(int i = 0; i < ts; ++i){
			int sz = in.nextInt();
			int win = in.nextInt();
			char[][] a = new char[sz][sz];
			for(int j = 0; j < sz; ++j)
				a[j] = in.next().toCharArray();
			//System.out.println(pretty(a));
			a = rotate(a);
			boolean red = win(a, 'R', win);
			boolean blue =  win(a, 'B', win);
			System.out.print("Case #"+(i+1)+": ");
			if(red && blue){
				System.out.println("Both");
				continue;
			}
			if(red){
				System.out.println("Red");
				continue;
			}
			if(blue){
				System.out.println("Blue");
				continue;
			}
			System.out.println("Neither");
		}
		in.close();
	}

	static char[][] rotate(char[][]a){
		int sz = a.length;
		char[][] ans = new char[sz][sz];
		for(int i = 0; i < sz; ++i)
			for(int j = 0; j < sz; ++j)
				ans[j][sz - i - 1] = a[i][j];

//		System.out.println(pretty(ans));

		char[][] ret = new char[sz][sz];

		for(char[] x:ret)
			Arrays.fill(x, '.');

		for(int j = 0; j < sz; ++j){
			int cnt = 0;
			for(int i = sz - 1; i >= 0; --i){
				if(ans[i][j] != '.'){
					ret[sz - cnt - 1][j] = ans[i][j];
					++cnt;
				}
			}
		}
//		System.out.println(pretty(ret));
		return ret;
	}
	
	static int[] di = new int[]{0, 1, -1, 1};
	static int[] dj = new int[]{1, 0, 1, 1};

	static boolean win(char[][]a, char val, int num){
		int sz = a.length;
		for(int i = 0; i < sz; ++i)
			for(int j = 0; j < sz; ++j)
				for(int w = 0; w < di.length; ++w)
					if(good(a, i + (num - 1) * di[w], j + (num - 1) * dj[w])){
						boolean ok = true;
						for(int k = 0; k < num; ++k)
							if(a[i + k * di[w]][j + k * dj[w]] != val)
								ok = false;
						
						if(ok)
							return true;
					}
		return false;
	}
	static boolean good(char[][] a, int i, int j){
		int sz = a.length;
		return i >= 0 && i < sz && j >= 0 && j < sz;
	}

	static String pretty(char[][] a){
		StringBuilder sb = new StringBuilder();
		int sz = a.length;
		for(int i = 0; i < sz; ++i){
			for(int j = 0; j < sz; ++j)
				sb.append(a[i][j]);
			sb.append("\n");
		}
		return sb.toString();
	}
}