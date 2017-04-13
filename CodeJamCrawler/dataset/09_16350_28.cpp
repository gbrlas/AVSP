import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class C {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		final int t = sc.nextInt();

		for (int tt = 1; tt <= t; ++tt) {

			final int n = sc.nextInt();
			final int k = sc.nextInt();

			int[][] wykresy = new int[n][k];

			for (int nn = 0; nn < n; ++nn)
				for (int kk = 0; kk < k; ++kk)
					wykresy[nn][kk] = sc.nextInt();

			Vertex[] graph = new Vertex[n];
			for (int i = 0; i < n; ++i)
				graph[i] = new Vertex(i);

			for (int n1 = 0; n1 < n - 1; ++n1)
				for (int n2 = n1 + 1; n2 < n; ++n2)
					if (conflict(wykresy[n1], wykresy[n2])) {
						graph[n1].adj(graph[n2]);
						graph[n2].adj(graph[n1]);
					}

			Arrays.sort(graph);

			int maxColor = 0;

			for (int i = 0; i < n; ++i) {

				Vertex v = graph[i];
				v.color = v.color();
				maxColor = Math.max(maxColor, v.color);
			}

			System.out.println("Case #" + tt + ": " + maxColor);
		}

	}

	static class Vertex implements Comparable<Vertex> {
		final int number;
		int size;
		final ArrayList<Vertex> adjs = new ArrayList<Vertex>();
		int color;

		int color() {

			Collections.sort(adjs, new Comparator<Vertex>() {
				@Override
				public int compare(Vertex o1, Vertex o2) {
					return o1.color - o2.color;
				}
			});

			int nextColor = 1;
			for (Vertex adj : adjs) {
				if (adj.color > nextColor)
					return nextColor;
				if (adj.color == nextColor)
					++nextColor;
			}

			return nextColor;
		}

		public Vertex(int number) {
			this.number = number;
		}

		@Override
		public int compareTo(Vertex o) {
			return o.size - this.size;
		}

		public void adj(Vertex v) {
			++size;
			adjs.add(v);
		}
		
		@Override
		public String toString() {
			return "v" + number + ":" + size;
		}
	}

	static boolean conflict(int[] wykres1, int[] wykres2) {
		if (wykres1[0] == wykres2[0])
			return true;

		if (wykres1[0] < wykres2[0]) {
			for (int i = 1; i < wykres1.length; ++i)
				if (wykres1[i] >= wykres2[i])
					return true;
		} else {
			for (int i = 1; i < wykres1.length; ++i)
				if (wykres1[i] <= wykres2[i])
					return true;

		}
		return false;
	}

}
