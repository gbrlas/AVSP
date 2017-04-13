import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;


public class ThemePark {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		int T = 0;
		BufferedReader br = new BufferedReader(new FileReader("C:\\in\\ThemePark.in"));
		T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String[] tokens = br.readLine().split(" ");
			int R = Integer.parseInt(tokens[0]);
			int k = Integer.parseInt(tokens[1]);
			int N = Integer.parseInt(tokens[2]);
			
			tokens = br.readLine().split(" ");
			Queue<Integer> q = new LinkedList<Integer>(); 
			for (int j = 0; j < N; j++) {
				q.add(Integer.valueOf(tokens[j]));
			}
			
			int euros = 0;
			for (int j = 0; j < R; j++) {
				int placesLeft = k;
				boolean canAcomodateGroup = true;
				Queue<Integer> nextQueue = new LinkedList<Integer>();
				while (canAcomodateGroup) {
					if (!q.isEmpty() && placesLeft >= q.peek()) {
						int groupSize = q.poll();
						euros += groupSize;
						placesLeft -= groupSize;
						nextQueue.add(groupSize);
					} else {
						canAcomodateGroup = false;
					}
				}
				q.addAll(nextQueue);
			}
			
			System.out.println("Case #" + (i + 1) + ": " + euros);
			
		}
		
	}

}
