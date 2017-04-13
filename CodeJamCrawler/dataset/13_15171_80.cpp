import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class FairandSquare {
	public static void main(String[] args) {
		FileReader fin;
		try {
			fin = new FileReader(
					new File(
							"D:\\CodeJam\\C-small-attempt0.in"));

			FileWriter fr = new FileWriter(
					new File(
							"D:\\CodeJam\\C-small-attempt0.out"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			for (int i = 0; i < N; i++) {
				line = br.readLine();
				String[] rc = line.split(" ");
				int r = Integer.parseInt(rc[0]);
				int c = Integer.parseInt(rc[1]);
							
				fr.write("Case #"+(i+1)+": "+compute(r,c)+"\r\n");
				
			}
			fr.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int compute(int r, int c) {
		int count =0;
		for(int i=r;i<=c;i++){
			if(palindrome(i)){
				int sqrt =(int) Math.sqrt(i);
				if(sqrt*sqrt==i && palindrome(sqrt)){
					count++;
				}
			}
		}
		return count;
	}
	private  static boolean palindrome(int i){
		String st = String.valueOf(i);
		StringBuffer str = new StringBuffer(st);
		return st.equals(str.reverse().toString());
	}
}
