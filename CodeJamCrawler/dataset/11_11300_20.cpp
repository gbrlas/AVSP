import java.util.Hashtable;
import java.util.Map;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		StringBuilder result = new StringBuilder();
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			
			int N = s.nextInt();
			String[] items = new String[N * 2];
			for (int k = 0; k < N * 2; k++) {
				items[k] = s.next();
			}
			
			Map<String, Integer> posMap = new Hashtable<String, Integer>();
			posMap.put("B", 1);
			posMap.put("O", 1);
			
			int totalTime = 0;
			int actionTime = 0;
			String bBO = null;
			for (int j = 0 ; j < N; j++) {
				
				String bo = items[j * 2];
				
				int nextPos = Integer.parseInt(items[1 + j * 2]);
				
				int curPos = posMap.get(bo);
				if (bBO == null || bBO.equals(bo)) {
					// move
					actionTime += Math.abs(nextPos - curPos);
					totalTime += Math.abs(nextPos - curPos);
					// push
					actionTime += 1;
					totalTime += 1;
				} else {
					int n = Math.abs(nextPos - curPos) + 1 - actionTime;
					if (n > 0) {
						actionTime = n;
						totalTime += n;
					} else {
						actionTime = 1;
						totalTime += 1;
					}
				}
				// set position
				posMap.put(bo, nextPos);
				
				bBO = bo;
				
			}
			
			result.append("Case #" + (i + 1) + ": " + totalTime + "\n");
			
		}
		
		System.out.println(result);
	}
	
}
