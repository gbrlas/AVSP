import java.util.Scanner;


public class rpi {

	static Team[] teams = new Team[101];
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int cases = scn.nextInt();
		for (int c = 1; c <= cases; c++) {
			int tcount = scn.nextInt();
			scn.nextLine();
			
			Matrix m = new Matrix(tcount, scn);
			for (int t = 0; t < tcount; t++) {
				m.compute(t);
			}
			
			System.out.println("Case #" + c + ":");
			for (int t = 0; t < tcount; t++) {
				System.out.println(m.rpi(t));
			}
			
		}
	}


}

class Team {
	int index;
	int win;
	int fail;
	public double owp;
	
	public Team(int index) {
		this.index = index;
		win = 0;
		fail = 0;
	}

	public Team(int t, String input) {
		this(t);
		for(int i = 0; i < input.length(); i++) {
			if (input.charAt(i) == '1') {
				win++;
			} else if (input.charAt(i) == '0') {
				fail++;
			}
		}
	}
	
	public double getWP() {
		return ((double) win ) / (win + fail);
	}
	
}

class Matrix {
	String[] input;
	Team[] teams;
	
	public Matrix(int tcount, Scanner scn) {
		teams = new Team[tcount];
		input = new String[tcount];
		for (int t = 0; t < tcount; t++) {
			teams[t] = new Team(t);
			input[t] = scn.nextLine();
			addInput(t, input[t]);
		}
	}

	public double rpi(int t) {
		double wp = teams[t].getWP();
		double owp = teams[t].owp;
		double oowp = 0;
		
		double oowp_total = 0;
		double oowp_count = 0;
		for (int x = 0; x < teams.length; x++) {
			if (x == t) continue;
			char c = input[t].charAt(x);
			if (c == '.') continue;
			
			oowp_total += teams[x].owp;
			oowp_count++;
		}
		
		if (oowp_count > 0) {
			oowp = oowp_total / oowp_count;
		}
		
		return 0.25 * wp + 0.5 * owp + 0.25 * oowp;
	}

	private void addInput(int t, String input) {
		for (int x = 0; x < t; x++) {
			char c = input.charAt(x);
			if (c == '1') {
				teams[t].win++;
				teams[x].fail++;
			} else if (c == '0') {
				teams[x].win++;
				teams[t].fail++;
			}
		}
	}
	
	public void compute(int t) {
		double wp_total = 0;
		double wp_count = 0;
		
		for(int op = 0; op < input[t].length(); op++) {
			if (op == t) continue;
			char c = input[t].charAt(op);
			if (c == '.') continue;
			
			int w = teams[op].win;
			int f = teams[op].fail;
			if (c == '1') {
				f--;
			} else {
				w--;
			}
			
			wp_total += (w)/((double) w + f);
			wp_count++;
		}
		teams[t].owp = wp_count > 0 ? wp_total/wp_count : 0;
	}
}
