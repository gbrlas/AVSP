//package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;

public class CookieClickerAlpha_2014 {
	
	private static String in = "2014.in";
	
	private static String out = "2014.out";
	
	private static int cases = 0;
	
	private static final BigDecimal initSpeed = new BigDecimal("2");
	
	private static BigDecimal[][] data;
	
	public static void read() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(in))));
		String t = br.readLine();
		cases = Integer.parseInt(t);
		data = new BigDecimal[cases][3];
		for(int i = 0; i < cases; i++) {
			t = br.readLine();
			String[] temp = t.split(" ");
			data[i][0] = new BigDecimal(temp[0]);
			data[i][1] = new BigDecimal(temp[1]);
			data[i][2] = new BigDecimal(temp[2]);
		}
		br.close();
	}
	
	public static String[] calc() {
		String[] retVal = new String[cases];
		for(int i = 0; i < cases; i++) {
			retVal[i] = "Case #" + (i + 1) + ": " + process(initSpeed, data[i][0], data[i][1], data[i][2]);
		}
		return retVal;
	}
	
	public static BigDecimal process(BigDecimal presentSpeed, BigDecimal c, BigDecimal f, BigDecimal x) {
		System.out.println(x.divide(presentSpeed, 7, BigDecimal.ROUND_HALF_UP));
		BigDecimal newSpeed = presentSpeed.add(f);
		BigDecimal buildTime = c.divide(presentSpeed, 7, BigDecimal.ROUND_HALF_UP);
		BigDecimal lastestTime = x.divide(newSpeed, 7, BigDecimal.ROUND_HALF_UP);
		System.out.println(buildTime.add(lastestTime));
		if(x.divide(presentSpeed, 7, BigDecimal.ROUND_HALF_UP).compareTo(buildTime.add(lastestTime)) <= 0) {
			return x.divide(presentSpeed, 7, BigDecimal.ROUND_HALF_UP);
		}
		else return buildTime.add(process(presentSpeed.add(f), c, f, x));
	}
	
	public static void write(String[] retVal) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(out))));
		for(int i = 0; i < cases; i++) {
			if(i == 0) bw.write(retVal[i]);
			else bw.append(retVal[i]);
			if(i != cases - 1) bw.newLine();
		}
		bw.flush();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			CookieClickerAlpha_2014.read();
			CookieClickerAlpha_2014.write(CookieClickerAlpha_2014.calc());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
