import java.util.*;


public class Program {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int nCases = in.nextInt();
		in.nextLine();
		for (int caseNumber = 1; caseNumber <= nCases; caseNumber++) {
			String[] s = in.nextLine().split("/");
			long p = Long.parseLong(s[0]);
			long q = Long.parseLong(s[1]);
			
			int imin = -1;
			int i = 0;
			long deuxpuissancei = 1;
			while (p > 0) {
				i++;				
				deuxpuissancei *= 2;
				long a = p*deuxpuissancei;
				long b = q*deuxpuissancei;
				if (b == 0) break;
				long c = q;
				while (a >= c) {
					if (imin == -1) {
						imin = i;
					}
					a -= c;
				}
				p = a;
				q = b;
			}

			System.out.print("Case #");
			System.out.print(caseNumber);
			System.out.print(": ");
			if (p != 0) {
				System.out.println("impossible");
			} else {
				System.out.println(imin);
			}
			
		}
		in.close();
	}

}
