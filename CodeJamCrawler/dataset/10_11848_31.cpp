import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class B {

	private static final String INPUT = "d:/input.txt";

	private static final String OUTPUT = "d:/output.txt";
	
	private static PrintWriter output;
	
	private static Scanner input;
	
	private static int[] one = new int[1024]; 
	
	public static void prepare() {
		for (int i = 0; i <= 1023; i++) {
			int v = i, t = 0;
			while (v > 0) {
				if (v % 2 == 1) {
					t++;
				}
				v = v / 2;
			}
			one[i] = t;
		}
	}
	
	public static int diff(int x, int y) {
		int t = 0;
		while (x % 2 == 1) {
			t++;
			x = x / 2;
		}
		return t;
	}
	
	public static int get(int p, int n, int[] price, int mask, int position) {
		//System.out.println(p);
		int result = 0;
		int offset = 0;
		int w = n / 2;
		for (int i = 0; i < p; i++) {
			position = position / 2;
			int j = position + offset;
			if (mask % 2 == 1)
				result += price[j];
			mask = mask / 2;
			offset += w;
			w = w / 2;
		}
		return result;
	}
	
	public static void exec() {
		int p = input.nextInt();
		int n = 1 << p;
		int[] m = new int[n];
		for (int i = 0; i < n; i++) {
			m[i] = input.nextInt();
			m[i] = p - m[i];
		}
		int[] price = new int[n - 1];
		for (int i = 0; i < n - 1; i++)
			price[i] = input.nextInt();
		
		/// after input
		int[] begin = new int[n];
		int[] end = new int[n];
		int[] temp = null;
		
		/// init level 1;
		for (int i = 0; i < n; i++) {
			if (one[i] < m[0]) {
				begin[i] = -1;
			} else {
				begin[i] = get(p, n, price, i, 0);
			}
		}
		
		for (int position = 1; position < n; position++) {
			if (position % 100 == 0)
			System.out.println("position " + position);

			for (int i = 0; i < n ;i++) {
				if (one[i] < m[position]) {
					end[i] = -1;
				} else {
					end[i] = Integer.MAX_VALUE;
				}
			}
			//System.out.println(position);
			int di = diff(position - 1, position);
			int w = 1 << di;
			for (int i = 0; i < n; i++) {
				if (begin[i] != -1) {
					int base = i / w * w;
					int s = 0;
					int t = w - 1;
					for (int j = s; j <= t; j++) {
						int ret = get(p, n, price, j, position);
						ret += begin[i];
						int k = j + base;
						if (end[k] != -1 && end[k] > ret) {
							end[k] = ret;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (end[i] == Integer.MAX_VALUE) {
					end[i] = -1;
				}
			}
			
			// swap
			temp = begin;
			begin = end;
			end = temp;
		}
		int ret = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			if (begin[i] < ret && begin[i] != -1) {
				ret = begin[i];
			}
		}
		output.print(ret);
	}

	public static void main(String[] args) throws Exception {
		prepare();
		input = new Scanner(new File(INPUT));
		output = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
				OUTPUT)));
		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			System.out.println("case " + i);
			output.print("Case #" + (i + 1) + ": ");
			exec();
			output.println();
		}
		output.close();
		input.close();
	}

}
