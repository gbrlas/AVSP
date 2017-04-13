import java.util.HashSet;
import java.util.Scanner;

public class Happy {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		final int t = sc.nextInt();
		sc.nextLine();

		for (int i = 0; i < t; ++i) {

			HashSet<Integer> bases = new HashSet<Integer>();

			String[] sbases = sc.nextLine().split(" ");
			for (String sbase : sbases) {

				if (sbase.equals(""))
					continue;

				bases.add(Integer.valueOf(sbase));
			}


			int cand = 2;
			cand: for (;; ++cand) {

				base: for (int base : bases) {

					HashSet<Integer> work = new HashSet<Integer>();

					int v = cand;

					while (!work.contains(v)) {
						work.add(v);
						v = next(base, v);
					}

					if (v == 1) 
						continue base;
					

					continue cand;
				}

				break;
			}

			System.out.println("Case #" + (i + 1) + ": " + cand);
			
		}

	}

	private static int next(final int base, int v) {

		int r = 0;
		while (v >= base) {
			r += (v % base) * (v % base);
			v /= base;
		}
		r += v * v;
		return r;
	}

}
