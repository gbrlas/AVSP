import java.util.*;

public class ThemePark {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t=0;t<T;t++) {
			int R = in.nextInt();
			int k = in.nextInt();
			int N = in.nextInt();
			int money = 0;
			ArrayList<Integer> g = new ArrayList<Integer>();
			int queueFront = 0, firstUsed = 0;
			for (int n=0;n<N;n++) {
				g.add(in.nextInt());
			}
			int remain = k;
			while (R>0) {
				if (remain>=g.get(queueFront)) {
					remain -= g.get(queueFront);
					money += g.get(queueFront);
					queueFront = (queueFront+1)%N;
				}
				if (remain<g.get(queueFront) || queueFront==firstUsed) {
					R--;
					remain = k;
					firstUsed = queueFront;
				}
			}
			System.out.println("Case #"+(t+1)+": "+money);
		}
	}
}
