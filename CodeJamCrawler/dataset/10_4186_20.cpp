package codejam2010.qualification;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class ThemePark {

	public static void main(String[] args) throws Exception {
		InputFile input = new InputFile(new BufferedReader(new InputStreamReader(System.in)));
		int T = input.nextInt();
		for (int x=1; x<=T; x++) {
			
			int R = input.nextInt(); // number of rides
			int k = input.nextInt(); // ride capacity
			int n = input.nextInt(); // number of groups
			
			int g[] = new int[n];
			for (int i=0; i<n; i++) {
				g[i] = input.nextInt();
			}
			
			// If group n was at the front of the queue, this gives us the number of people who can fit on the next ride
			int numPeopleOnRide[] = new int[n];
			// And this would be the new front of the queue
			int newFront[] = new int[n];
			
			// Fill those two arrays
			for (int i=0; i<n; i++) {
				int peopleOnRide = 0;
				int groupsTaken = 0;
				for (int j=0; j<n; j++) {
					int index = (i + j) % n;
					if (peopleOnRide + g[index] > k) {
						break; // ride full
					}
					peopleOnRide += g[index];
					groupsTaken++;
				}
				numPeopleOnRide[i] = peopleOnRide;
				newFront[i] = (i + groupsTaken) % n;
			}
			
			// newFront defines a directed graph. Edges link successive rides.
			// Find loops in that graph
			int loopSize[] = new int[n];
			int peopleTakenPerLoop[] = new int[n];
			for (int i=0; i<n; i++) {
				int node = i;
				int peopleTakenSoFar = 0;
				int visited[] = new int[n];
				Arrays.fill(visited, -1);
				int step = 0;
				while (true) {
					// Already visited this node
					if (visited[node] > -1) {
						if (node == i) {
							// Found loop involving this node
							loopSize[i] = step - visited[node];
							peopleTakenPerLoop[i] = peopleTakenSoFar;
						} else {
							// Loop involves other nodes
							loopSize[i] = peopleTakenPerLoop[i] = -1;
						}
						break;
					}
					peopleTakenSoFar += numPeopleOnRide[node];
					visited[node] = step;
					step++;
					node = newFront[node];
				}
			}
			
			// Calculate total for this test case
			int total = 0;
			int frontOfQueue = 0;
			int rides = 0;
			while (rides < R) {
				
				// Check if there's a loop from this node back to itself
				if (loopSize[frontOfQueue] > -1) {
					int loops = (R - rides) / loopSize[frontOfQueue];
					if (loops > 0) {
						total += loops * peopleTakenPerLoop[frontOfQueue];
						rides += loops * loopSize[frontOfQueue];
						// front of queue remains unchanged
						continue;
					}
				}
				
				// If there's no loop, advance one ride
				total += numPeopleOnRide[frontOfQueue];
				rides++;
				frontOfQueue = newFront[frontOfQueue];
			}
			
			System.out.printf("Case #%d: %d\n", x, total);
		}
	}
	
	static class InputFile {
		
		private StreamTokenizer st;
		
		public InputFile(Reader r) {
			st = new StreamTokenizer(r);
		}
		
		public int nextInt() throws IOException {
			st.nextToken();
			return (int) st.nval;
		}
	}
	
}
