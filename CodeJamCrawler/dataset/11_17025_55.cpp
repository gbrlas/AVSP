import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Main m = new Main();
		try {
			m.start();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private void start() throws IOException {
		FileReader in = new FileReader("C-small-attempt1.in");
		BufferedReader br = new BufferedReader(in);
		File file = new File("out.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		
		int t = Integer.valueOf(br.readLine());
		
		for (int k = 0; k < t; k++) {
			br.readLine();
			String str = br.readLine();
			String s[] = str.split(" ");
			
			ArrayList<Long> nums = new ArrayList<Long>();
			Long xor = 0L;
			for(int i=0; i<s.length;i++){
				nums.add(Long.parseLong(s[i]));
				xor = xor ^ nums.get(i);
			}
			if(xor != 0){
				pw.println("Case #" + (k+1) + ": NO");
				continue;
			}
			
			Collections.sort(nums);
			long min = nums.get(0);
			
			long ansa = 0;
			long ansb = 0;
			
			for(int i=0; i<nums.size(); i++){
				long x = nums.get(i);
				int index = nums.indexOf(new Long(-~x));
				if(index != -1){
					ansa += x;
					ansa += nums.get(index);
					nums.remove(index);
					nums.remove(i);
					i--;
					continue;
				}else{
					ansb += x;
				}
			}

			long ans = 0;

			if(ansa == 0){
				ans = ansb - min;
			}else if(ansb == 0){
				ans = ansb - (-~min);
			}else{
				ans = Math.max(ansa, ansb);
			}
			pw.println("Case #" + (k+1) + ": " + ans);
		}
		pw.close();
	}

}
