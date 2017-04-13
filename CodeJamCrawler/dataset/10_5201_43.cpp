import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


class ProblemC {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int tt = 1; tt <= t; tt++) {
			int r = sc.nextInt();
			int k = sc.nextInt();
			int n = sc.nextInt();
			Queue<Integer> q = new LinkedList<Integer>();
			for (int i = 0; i < n; i++) {
				q.add(sc.nextInt());
			}
			int res = 0;
			for (int i = 0; i < r; i++) {
				int nro = 0;
				int cont = 0;
				while (nro + q.peek() <= k && cont < n) {
					int aux = q.remove();
					nro += aux;
					q.add(aux);
					cont++;
//					System.out.print(aux + " ");
				}
//				System.out.println();
				res += nro;
			}
			System.out.println("Case #" + tt + ": " + res);
		}
	}

}
