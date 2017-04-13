import java.util.*;
import java.io.*;

public class B {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(in.readLine());

		for(int cas = 1; cas <= cases; cas++) {
			String[] parts = in.readLine().split(" ");
			double farmCost = Double.parseDouble(parts[0]);
			double farmGain = Double.parseDouble(parts[1]);
			double cookieTarget = Double.parseDouble(parts[2]);

			double cookies = 0;
			double time = 0;
			double rate = 2;

			while(cookies < cookieTarget) {
				double timeToTarget = (cookieTarget - cookies) / rate;
				double timeToFarm = (farmCost - cookies) / rate;
				double timeToFarmTarget = timeToFarm + cookieTarget / (rate + farmGain);

				if(timeToTarget <= timeToFarmTarget) {
					cookies = cookieTarget;
					time += timeToTarget;
					break;
				} else {
					rate += farmGain;
					cookies = 0;
					time += timeToFarm;
				}
			}

			System.out.println("Case #" + cas + ": " + time);
		}
	}
}
