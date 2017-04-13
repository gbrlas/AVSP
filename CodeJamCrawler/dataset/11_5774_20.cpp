package gcj2011.round1b;

import java.io.File;
import java.util.Scanner;

public class RPI {
	
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("data/gcj2011/round1b/A-large.in"));
		
		int T = s.nextInt();
		for (int t=1; t<=T; t++) {
			int N = s.nextInt();
			String[] input = new String[N];
			for (int n=1; n<=N; n++) {
				input[n-1] = s.next();
			}
			
			int[] games = new int[N];
			int[] won = new int[N];
			double[] wp = new double[N];
			
			for (int a=0; a<N; a++) {
				for (int b=0; b<N; b++) {
					switch (input[a].charAt(b)) {
						case '1':
							won[a]++;
						case '0':
							games[a]++;
					}
				}
				wp[a] = won[a] * 1.0 / games[a];
			}
			
			double[] owp = new double[N];
			for (int a=0; a<N; a++) {
				int opponents = 0;
				for (int b=0; b<N; b++) {
					if (input[a].charAt(b) != '.') {
						opponents++;
						int opponentWon = won[b];
						int opponentGames = games[b];
						switch (input[b].charAt(a)) {
							case '1':
								opponentWon--;
							case '0':
								opponentGames--;
						}
						owp[a] += (opponentWon * 1.0 / opponentGames);
					}
				}
				owp[a] /= opponents;
			}
			
			double[] oowp = new double[N];
			for (int a=0; a<N; a++) {
				int opponents = 0;
				for (int b=0; b<N; b++) {
					if (input[a].charAt(b) != '.') {
						opponents++;
						oowp[a] += owp[b];
					}
				}
				oowp[a] /= opponents;
			}
			
			System.out.printf("Case #%d:%n", t);
			for (int a=0; a<N; a++) {
				double RPI = RPI(wp[a], owp[a], oowp[a]);
				System.out.println(RPI);
			}
		}
	}
	
	private static double RPI(double WP, double OWP, double OOWP) {
		double RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP;
		return RPI;
	}

}
