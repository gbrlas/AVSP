import java.util.*;

public class pickup_chicks {
	private static class Chick {
		double x, v;
		boolean possible;
	}

	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int C = in.nextInt();
		for (int c=1;c<=C;c++) {
			int N = in.nextInt();
			int K = in.nextInt();
			int B = in.nextInt();
			int T = in.nextInt();
			Chick[] chicks = new Chick[N];
			for (int i=0;i<N;i++) {
				Chick chick = new Chick();
				chick.x = in.nextDouble();
				chicks[i] = chick;
			}
			for (Chick chick : chicks) {
				chick.v = in.nextDouble();
				chick.possible = (B-chick.x)/chick.v <= T;
			}
			int i=N-1;
			int missedChicks = 0;
			int swaps = 0;
			while (K>0 && i>=0) {
				if (chicks[i].possible) {
					swaps += missedChicks;
					K--;
				} else {
					missedChicks++;
				}
				if (K==0) break;
				i--;
			}
			System.out.print("Case #"+c+": ");
			if (i<0) {
				System.out.println("IMPOSSIBLE");
			} else {
				System.out.println(swaps);
			}
		}
	}
}

