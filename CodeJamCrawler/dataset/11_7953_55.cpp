import java.util.*;
import java.io.*;

public class A {
	void solve() {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.println("Case #" + caseNum + ": ");
			int N = sc.nextInt();
			sc.nextLine();
			
			char[][] games = new char[N][N];
			for (int i=0; i<N; i++) {
				games[i] = sc.nextLine().toCharArray();
			}
			
			double[] teamWins = new double[N];
			double[] teamGames = new double[N];
			double[] WP = new double[N];
			double[] OWP = new double[N];
			double[] OOWP = new double[N];
			
			boolean[][] opponents = new boolean[N][N];
			
			for (int i=0; i<N; i++) {
				double wins = 0;
				double totGames = 0;
				for (int j=0; j<N; j++) {
					if (games[i][j] == '1') {
						wins ++;
						totGames ++;
						opponents[i][j] = true;
					} else if (games[i][j] == '0') {
						totGames ++;
						opponents[i][j] = true;
					} else {
						opponents[i][j] = false;
					}
				}
				teamWins[i] = wins;
				teamGames[i] = totGames;
				WP[i] = wins/totGames;
			}
			
			
			
			for (int i=0; i<N; i++) {
				double totOps = 0;
				double totOpponents = 0;
				for (int j=0; j<N; j++) {
					if (opponents[i][j] && j!=i) {
						totOpponents ++;
						if (games[i][j] == '1') {
							totOps += (teamWins[j])/(teamGames[j] - 1);
						} else if (games[i][j] == '0') {
							totOps += (teamWins[j]-1)/(teamGames[j] - 1);
						} else {
							totOps += WP[j];
						}
					}
				}
				OWP[i] = totOps/totOpponents;
			}
			
			for (int i=0; i<N; i++) {
				double opOwp = 0;
				double totOpponents = 0;
				for (int j=0; j<N; j++) {
					if (opponents[i][j] && j!=i) {
						totOpponents ++;
						opOwp += OWP[j];
					}
				}
				OOWP[i] = opOwp/totOpponents;
				double RPI = 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
				//System.out.println(WP[i]+" "+OWP[i]+" "+OOWP[i]);
				System.out.println(RPI);
			}
			
			
			
			
		}
	}

	public static void main(String[] args) {
		new A().solve();
	}
}
