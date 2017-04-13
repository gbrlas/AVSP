import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CandySplitting {
	public static void main(String[] args) {
		int cases;
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			cases = Integer.parseInt(in.readLine());

			for (int i = 1; i <= cases; i++) {
				int candies = Integer.parseInt(in.readLine());
				String[] candySet = in.readLine().split(" ");
				int seanBest = 0; // Most candy Sean has managed to trick Patrick into thinking is fair
				//Try each combination of splitting the candy
				for (int j = 1; j < (1 << candies)-1; j++) {
					int seanTotal = 0, patTotal = 0, falseSeanTotal = 0;
					//Give a candy to Sean or Patrick
					for (int k = 0; k < candySet.length; k++) {
						if ((j | (1 << k)) == j) {
							seanTotal += Integer.parseInt(candySet[k]);
							falseSeanTotal ^= Integer.parseInt(candySet[k]);
						} else {
							patTotal ^= Integer.parseInt(candySet[k]);
						}
					}
					//If Patrick thinks the candy is evenly split, update Sean's score
					if (falseSeanTotal == patTotal) {
						if (seanTotal > seanBest)
							seanBest = seanTotal;
					}
				}
				if (seanBest > 0) {
					System.out.println("Case #" + i + ": " + seanBest);
				} else {
					System.out.println("Case #" + i + ": NO");
				}
			}

		} catch (IOException e) {
			//do nothing
		}
	}
}
