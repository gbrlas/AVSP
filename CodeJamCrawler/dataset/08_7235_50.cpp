import java.util.Scanner;
import java.util.ArrayList;

public class SaveUniverseDriver {

	public static void main(String[] args) {
		
		Scanner console = new Scanner(System.in);
		
		int total = console.nextInt();
		String space = console.nextLine();
		
		while (total > 0) {
			total--;
		
			int S = console.nextInt();
			space = console.nextLine();
			
			ArrayList<String> SE = new ArrayList<String>();
			for (int i = 0; i < S; i++) {
				String newSE = console.nextLine();
				SE.add(newSE);
			}
		
			int Q = console.nextInt();
			space = console.nextLine();
		
			ArrayList<String> QR = new ArrayList<String>();
			for (int i = 0; i < Q; i++) {
				String newQR = console.nextLine();
				QR.add(newQR);
			}
		
			SaveUniverse test1 = new SaveUniverse(SE, QR);
			
			if (!test1.checkOccurQ()) {
				System.out.println("Case #" + (20 - total) + ": 0");
			}
			else {
				boolean cont = true;
				int switches = 0;
				while (QR.size() > 0 && cont) {
					String lastOccurQ = test1.lastOccurQ();
					int lastOccurIndex = QR.indexOf(lastOccurQ);
					for (int i = 0; i < lastOccurIndex; i++) {
						QR.remove(0);
					}
					switches++;
					test1.setQArray(QR);
					if (!test1.checkOccurQ()) {
						System.out.println("Case #" + (20 - total) + ": " + switches);
						cont = false;
					}
				}
			}
		
		}
		
	}
	
}
