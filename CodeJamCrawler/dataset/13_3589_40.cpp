import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class FairAndSquare {
	public static void main(String... args) {
		BufferedReader br = null;
		BufferedWriter bw = null;
		try {

			String sCurrentLine = null;

			br = new BufferedReader(new FileReader(System.getProperty("user.home") + "\\in.txt"));

			bw = new BufferedWriter(new FileWriter(System.getProperty("user.home") + "\\C-small-attempt3.out"));
			PrintWriter fileOut = new PrintWriter(bw);

			int startIndex = 0;
			int endIndex = 0;
			int countOfFairNSq = 0;
			
			int numberInp = Integer.parseInt(br.readLine());

			for (int index = 1; index <= numberInp; index++) {
				sCurrentLine = br.readLine();
				if (sCurrentLine != null) {
					String[] range = sCurrentLine.split(" ");
					startIndex = Integer.parseInt(range[0]);
					endIndex = Integer.parseInt(range[1]);
					for (int i = startIndex; i <= endIndex; i++) {
						if (Math.sqrt(i) == Double.valueOf(Math.sqrt(i)).intValue()) {
							if(checkFairNSq(i)) {
									countOfFairNSq++;
							}
						}
					}
					fileOut.println("Case #"+index+": "+ countOfFairNSq);
					countOfFairNSq = 0;
				}
			}
			fileOut.flush();
			bw.flush();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
				bw.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

	private static boolean checkFairNSq(int i) {
		
		int sqrt = Double.valueOf(Math.sqrt(i)).intValue();
		String rev = new StringBuffer(String.valueOf(i)).reverse().toString();
		String revSqrt = new StringBuffer(String.valueOf(sqrt)).reverse().toString();
		
		if (String.valueOf(i).equals(rev) && String.valueOf(sqrt).equals(revSqrt)) {
			return true;
		}
		return false;
	}
}
