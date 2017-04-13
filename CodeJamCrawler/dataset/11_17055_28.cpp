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
		FileReader in = new FileReader("C-small-attempt0.in");
		BufferedReader br = new BufferedReader(in);
		File file = new File("out.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		
		int t = Integer.valueOf(br.readLine());
		
		for (int k = 0; k < t; k++) {
			String str = br.readLine();
			String s[] = str.split(" ");
			
			ArrayList<Long> nums = new ArrayList<Long>();
			int n = Integer.valueOf(s[0]);
			long low = Long.valueOf(s[1]);
			long high = Long.valueOf(s[2]);
			
			long player[] = new long[n];
			
			ArrayList<ArrayList<Long>> bun = new ArrayList<ArrayList<Long>>();
			
			str = br.readLine();
			s = str.split(" ");
			for(int i=0; i<n; i++){
				player[i] = Long.valueOf(s[i]);
			}
			
			boolean flag = true;
			int i;
			for(i=(int)low; i<=high; i++){
				flag = true;
				for(int j=0; j<player.length;j++){
					if(player[j] % i == 0 )
						continue;
					if(i % player[j] == 0 )
						continue;
					flag = false;
				}
				if(flag)
					break;
			}
			
			System.out.print("Case #" + (k+1) + ": ");
			if(flag)
				System.out.println(i);
			else 
				System.out.println("NO");



		}
		pw.close();
	}

}
