import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class MagicTrick_2014 {
	
	private static String in = "2014.in";
	
	private static String out = "2014.out";
	
	private static int cases = 0;
	
	private static int[][] row;
	
	private static int[][] squares;
	
	public static void read() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(in))));
		String t = br.readLine();
		cases = Integer.parseInt(t);
		row = new int[cases][2];
		squares = new int[cases * 8][4];
		for(int i = 0, j = 0, k = 0; i < 10 * cases; i++) {
			t = br.readLine();
			if( i % 5 == 0) {
				if(i % 10 == 0)
					row[j][0] = Integer.parseInt(t);
				else {
					row[j][1] = Integer.parseInt(t);
					j++;
				}
				
			}
			else {
				String[] temp = t.split(" ");
				squares[k][0] = Integer.parseInt(temp[0]);
				squares[k][1] = Integer.parseInt(temp[1]);
				squares[k][2] = Integer.parseInt(temp[2]);
				squares[k][3] = Integer.parseInt(temp[3]);
				k++;
			}
			
		}
		br.close();
	}
	
	public static String[] calc() {
		String[] retVal = new String[cases];
		for(int i = 0; i < cases; i++) {
			int first = row[i][0] - 1;
			int last = row[i][1] - 1;
			int[] firstTime = squares[i * 8 + first];
			int[] lastTime = squares[i * 8 + 4 + last];
			int result = getTimes(firstTime, lastTime);
			retVal[i] = "Case #" + (i + 1) + ": ";
			if(result == 0) retVal[i] += "Volunteer cheated!";
			else if(result == -1) retVal[i] += "Bad magician!";
			else retVal[i] += result;
		}
		return retVal;
	}
	
	public static int getTimes(int[] firstTime, int[] lastTime) {
		int count = 0;
		int val = 0;
		for(int i = 0; i < 4; i++) 
			for(int j = 0; j < 4; j++) {
				if(firstTime[i] == lastTime[j]) {
					count++;
					val = firstTime[i];
				}					
			}
		if(count == 0) return 0;
		return count == 1 ? val : -1;
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
		try {
			MagicTrick_2014.read();
			String[] retVal = MagicTrick_2014.calc();
			MagicTrick_2014.write(retVal);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
