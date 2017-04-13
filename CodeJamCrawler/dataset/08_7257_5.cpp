import java.util.Scanner;

public class TextMessaging {

	public static void main(String[] args) {
		
		Scanner console = new Scanner(System.in);
		
		int N = console.nextInt();
		int caseNo = 0;
		
		while (caseNo < N) {
			
			caseNo++;
		
			int P = console.nextInt();
			int K = console.nextInt();
			int L = console.nextInt();
		
			int[] frequency = new int[L];
		
			for (int i = 0; i < L; i++) {
				frequency[i] = console.nextInt();
			}
		
			int[] sortedF = new int[L];
			int temp = 0;
			int tempIndex = -1;
		
			for (int i = 0; i < L; i++) {
				for (int j = 0; j < L; j++) {
					if (frequency[j] > temp) {
						temp = frequency[j];
						tempIndex = j;
					}
				}
				sortedF[i] = temp;
				temp = 0;
				frequency[tempIndex] = 0;
			}
		
			int presses = 0;
		
			int k = 0;
		
			try {
		
				for (int i = 0; i < P; i++) {
					for (int j = 0; j < K; j++) {
						presses += (i+1) * sortedF[k];
						k++;
					}
				}
		
			}
		
			catch (ArrayIndexOutOfBoundsException ex){
			}

			System.out.println("Case #" + caseNo + ": " + presses);
	
		}
		
	}
	
}
