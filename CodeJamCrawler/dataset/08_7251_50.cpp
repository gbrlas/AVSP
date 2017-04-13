import java.util.Scanner;
import java.util.Arrays;

public class TrainTimetable {

	public static void main(String[] args) {
		
		Scanner console = new Scanner(System.in);
		
		int N = console.nextInt();
		int total = N;
		
		while (N > 0) {
			
			N--;
		
			int T = console.nextInt();
			String space = console.nextLine();
			int NA = console.nextInt();
			int NB = console.nextInt();
			space = console.nextLine();
		
			int[] NAdepartures = new int[NA];
			int[] NAarrivals = new int[NA];
			int[] NBdepartures = new int[NB];
			int[] NBarrivals = new int[NB];
		
			for (int i = 0; i < NA; i++) {
				String input = console.nextLine();
				input = input.replace(' ', ':');
				Scanner s1 = new Scanner(input).useDelimiter(":");
				Scanner s2 = new Scanner(input);
				int departure1 = s1.nextInt();
				int departure2 = s1.nextInt();
				int arrival1 = s1.nextInt();
				int arrival2 = s1.nextInt();
				NAdepartures[i] = (departure1 * 60) + departure2;
				NAarrivals[i] = (arrival1 * 60) + arrival2;
			}

			for (int i = 0; i < NB; i++) {
				String input = console.nextLine();
				input = input.replace(' ', ':');
				Scanner s1 = new Scanner(input).useDelimiter(":");
				Scanner s2 = new Scanner(input);
				int departure1 = s1.nextInt();
				int departure2 = s1.nextInt();
				int arrival1 = s1.nextInt();
				int arrival2 = s1.nextInt();
				NBdepartures[i] = (departure1 * 60) + departure2;
				NBarrivals[i] = (arrival1 * 60) + arrival2;
			}

			Arrays.sort(NAdepartures);
			Arrays.sort(NAarrivals);
			Arrays.sort(NBdepartures);
			Arrays.sort(NBarrivals);
			
			int Atrains = NA;
			int Btrains = NB;
			
			for (int i = 0; i < NB; i++) {
				int j = 0;
				boolean cont = true;
				while (j < NA && cont) {
					if ((NBarrivals[i] + T) <= NAdepartures[j]) {
						NAdepartures[j] = 0;
						Atrains--;
						cont = false;
					}
					j++;
				}
			}
			
			for (int j = 0; j < NA; j++) {
				int i = 0;
				boolean cont = true;
				while (i < NB && cont) {
					if ((NAarrivals[j] + T) <= NBdepartures[i]) {
						NBdepartures[i] = 0;
						Btrains--;
						cont = false;
					}
					i++;
				}
			}
			
			System.out.println("Case #" + (total - N) + ": " + Atrains + " " + Btrains);
			
		}
		
	}
	
}
