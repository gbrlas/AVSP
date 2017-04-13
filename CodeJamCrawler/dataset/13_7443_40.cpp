import java.util.LinkedList;
import java.util.Scanner;

public class FairSquare {
	
	private static boolean isFair(int n) {
		String s = Integer.toString(n);
		int len = s.length();
		boolean isFair = true;
		for (int i = 0; i < (len+1)/2; i++) {
			isFair &= (s.charAt(len-1-i) == s.charAt(i));
		}
		return isFair;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 0; t < T; t++) {
			in.nextLine();
			int min = in.nextInt();
			int max = in.nextInt();
			
			int min_root = (int)Math.sqrt(min);
			if (min_root*min_root != min) min_root++;
			int max_root = (int)Math.sqrt(max);
			
			int sum = 0;
			for (int i = 0; i < (max_root-min_root+1); i++) {
				int square = (min_root+i)*(min_root+i);
				if (isFair(min_root+i) && isFair(square)) sum++;
			}
			System.out.printf("Case #%d: %d\n", (t+1), sum);
		}
	}
}
