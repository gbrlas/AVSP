import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;

public class BullsEye {
	public static void main(String... args) {
		BufferedReader br = null;
		BufferedWriter bw = null;
		try {

			String sCurrentLine = null;
			br = new BufferedReader(new FileReader(
					System.getProperty("user.home") + "\\A-small-attempt1.in"));

			bw = new BufferedWriter(new FileWriter(
					System.getProperty("user.home") + "\\A-small-attempt1.out"));
			PrintWriter fileOut = new PrintWriter(bw);
			BigDecimal radius = null;
			BigDecimal secRaDecimal = null;
			BigDecimal paint = null;
			BigDecimal area = null;
			boolean first = true;
			int i = 1;
			br.readLine();
			while ((sCurrentLine = br.readLine()) != null) {
				int circles = 0;
				String[] values = sCurrentLine.split(" ");
				radius = new BigDecimal(values[0]);
				paint = new BigDecimal(values[1]);
				secRaDecimal = radius;
				while (paint.compareTo(BigDecimal.ZERO) == 1) {
					if (first) {
						radius = radius.add(BigDecimal.valueOf(1));
						first = false;
					} else {
						radius = radius.add(BigDecimal.valueOf(2));
						secRaDecimal = radius.subtract(BigDecimal.valueOf(1));
					}
					area = (radius.multiply(radius)).subtract(secRaDecimal
							.multiply(secRaDecimal));
					paint = paint.subtract(area);
					if (paint.compareTo(BigDecimal.ZERO) != -1) {
						circles++;
					}
				}
				first = true;
				System.out.println("Case #" + i + ": " + circles);
				fileOut.println("Case #" + i + ": " + circles);
				i++;
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
}
