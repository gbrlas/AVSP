import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class ProblemThree {

	public static void main(String[] args) throws NumberFormatException, IOException {
		File f = new File("input.txt");
		FileInputStream instream = new FileInputStream(f);
		BufferedReader reader = new BufferedReader(new InputStreamReader(instream));
				
		File f2 = new File("output.txt");
		FileOutputStream outstream = new FileOutputStream(f2);
		
		int cases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < cases; i++) {
			Scanner sc = new Scanner(reader.readLine());
			int start = sc.nextInt();
			int end = sc.nextInt();
			
			String s = String.format("Case #%d: %d\n", i+1, calc(start, end));
			System.out.println(s);
			outstream.write(s.getBytes());
		}
	}
	
	public static int calc(int start, int end){
		int count = 0;
		for (int i = start; i <= end; i++) {
			if (checkPalindrome(i)) {
				int sq = (int)Math.sqrt(i);
				
				if(sq*sq == i && checkPalindrome(sq))
					count++;
			}
		}
		return count;
	}
	
	public static boolean checkPalindrome(int x){
		String s = Integer.toString(x);
		int j = s.length() - 1;
		int half = s.length() >> 1;
		
		for (int i = 0; i < half; i++) {
			if (s.charAt(i) != s.charAt(j)) {
				return false;
			}
			j--;
		}
		return true;
	}
}
