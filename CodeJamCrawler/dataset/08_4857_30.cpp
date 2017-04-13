import java.util.Scanner;


public class NumberSets {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int C = s.nextInt();
		
		for (int t = 1; t <= C; t++) {
			System.out.print("Case #" + t + ": ");
			
			long A = s.nextLong();
			long B = s.nextLong();
			int P = s.nextInt();
			
			int total = (int)(B-A) + 1;
			int[] buf = new int[total];
			PrimeSet ps = new PrimeSet(total);
			
			int prime = ps.nextPrime(P);
			while(prime > 0) {
				long first = A;
				while (first <= B && first % prime != 0) {
					first++;
				}
				if (first > B) break;
				for (int i = (int)(first - A); i < buf.length; i+=prime) {
					if (buf[i] == prime) continue;
					int g = buf[i];
					if (g != 0) {
						for (int j = 0; j < buf.length; j++) {
							if (buf[j] == g) {
								buf[j] = prime;
							}
						}
					}
					buf[i] = prime;
				}
				prime = ps.nextPrime(++prime);
			}
			
			int count = 0;
			for (int i = 0; i < buf.length; i++) {
				if (buf[i] == 0) count ++;
				else if (buf[i] > 0){
					count ++;
					int g = buf[i];
					for (int j = i; j < buf.length; j++) {
						if (buf[j] == g) {
							buf[j] = -1;
						}
					}
				}
			}
			
			System.out.println(count);
		}

	}
	
	static class PrimeSet {
		boolean[] ps;
		int max;
		PrimeSet(int max) {
			this.max = max;
			
			this.ps = new boolean[max + 1];

			int previousP = 1;
			while(true) {
				int p = previousP + 1;
				while (p <= max && ps[p]) p++;
				if (p > max) break;
				previousP = p;
				p += previousP;
				while (p <= max) {
					ps[p] = true;
					p += previousP;
				}
			}
		}
		
		int nextPrime(int from){
			while (from <= max && ps[from]) {
				from++;
			}
			if (from > max) return -1;
			return from;
		}
	}

}
