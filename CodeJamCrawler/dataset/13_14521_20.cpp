import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MainClass {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		File file = new File("input.txt");
		if (!file.exists())
			System.out.println("File not exist");
		Scanner scanner;
		try {
			scanner = new Scanner(file);
			int n = scanner.nextInt();
			long[][] input = new long[n][2];
			long c = 0;
			System.out.println("Start reading");
			for (int i = 0; i < n; i++) {
				input[i][0] = scanner.nextLong();
				input[i][1] = scanner.nextLong();
				c = count(input[i][0], input[i][1]);
				System.out.println("Case #" + (i + 1) + ": " + c);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static int count(long start, long end) {
		int result = 0;
		String temp="";
		while(start<=end){
			temp=Long.toString(start);
			int i=check(start);
			if(i==temp.length()/2+1){
				double t=Math.sqrt(start);
				if(t%1==0){
					i=check((long)t);
					if(i==temp.length()/2+1){
						result++;
					}
				}
			} 
			
			start+=1;
		}
		return result;
	}
	
	public static int check(long number){
		int i=0;
		String temp=Long.toString(number);
		for(i=0;i<temp.length()/2+1;i++){
			if(temp.charAt(i)!=temp.charAt(temp.length()-i-1)){
				break;
			}
		}
		return i;
	}
}
