import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


class FairAndSquare1{
	public static void main(String arg[]) throws FileNotFoundException{
		Scanner scn = new Scanner(new File("sample-input.in"));
		PrintWriter pw = new PrintWriter(new File("output.txt"));
		long testCases = scn.nextLong();
		System.out.print("Started..");
		for(int testCase = 0; testCase < testCases; testCase++){
			long count = 0;			
			long min = scn.nextLong();
			long max = scn.nextLong();
			long minSqrt = (long) Math.sqrt(min);
			long maxSqrt = (long) Math.sqrt(max);
			for(long i = minSqrt; i<=maxSqrt; i++){
				if(IsPalindrome(i)){
					long square = i*i;
					if(IsPalindrome(square) && square<=(max) && square>=min){
						count++;
					}
				}
			}
			pw.println("Case #" + (testCase+1) + ": " + count);
		}
		System.out.println("Finished!");
		scn.close();
		pw.close();
	}

	private static boolean IsPalindrome(long i) {
		long num = i;
		long rev = 0;
		while(num > 0){
			long dig = num%10;
			rev = rev * 10 + dig;
			num = num/10;
		}
		if(rev==i)
			return true;
		else
			return false;
	}
}