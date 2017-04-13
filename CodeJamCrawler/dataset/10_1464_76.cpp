import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;


public class SnapperChain {
	
	public static String reverse(String str) {
		StringBuffer buffer = new StringBuffer();
		for (int i = str.length() - 1; i >= 0; i--) {
			buffer.append(str.charAt(i));
		}
		return buffer.toString();
	}
	
	public static String fixLength(String str, int N) {
		if (str.length() > N) {
			return str.substring(0, N);
		} else {
			StringBuffer buffer = new StringBuffer(str);
			while (buffer.length() < N) {
				buffer.append("0");
			}
			return buffer.toString();
		}
	}
	
	public static boolean isLightOn(String snappers) {
		boolean lightOn = true;
		for (int i = 0; i < snappers.length(); i++) {
			if (snappers.charAt(i) == '0') {
				lightOn = false;
			}
		}
		return lightOn;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		int T = 0;
		BufferedReader br = new BufferedReader(new FileReader("C:\\in\\SnapperChain.in"));
		T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String[] tokens = br.readLine().split(" ");
			int N = Integer.parseInt(tokens[0]);
			BigInteger K = new BigInteger(tokens[1]);
			String snappers = fixLength(reverse(K.toString(2)), N);
			if (isLightOn(snappers)) {
				System.out.println("Case #" + (i + 1) + ": ON");
			} else {
				System.out.println("Case #" + (i + 1) + ": OFF");
			}
		}
		
	}
	
}
