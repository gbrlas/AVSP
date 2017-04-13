import java.lang.*;
import java.io.*;
import java.util.*;

public class FairAndSquare{

	public boolean isFairSquare(long n){
		long sqrt;

		if(isPalindrome(n)){
			sqrt = (long)Math.sqrt(n);

			if(sqrt*sqrt == n){
				return isPalindrome(sqrt);
			}
		}

	  	return false;
	}

	public boolean isPalindrome(long n){
		StringBuilder rev;
		String sqrt = Long.toString(n);
		String sub1;
		String sub2;
		int half = 0;

		if(sqrt.length()%2 == 0){
			half = sqrt.length()/2;
			sub1 = sqrt.substring(0, half);
			sub2 = sqrt.substring(half, sqrt.length());
		}else{
			half = sqrt.length()/2;
			sub1 = sqrt.substring(0, half+1);
			sub2 = sqrt.substring(half, sqrt.length());
		 }

		rev = new StringBuilder(sub2);

		if(sub1.equals(rev.reverse().toString())){
			return true;
		}
		return false;
	}

	public int fsCounter(long start, long end){
		int fscount = 0;

		while(start <= end){
			if(isFairSquare(start)){
				fscount++;
			}
			start++;
		}

		return fscount;
	}

	public static void main(String args[])throws IOException{
		FairAndSquare test = new FairAndSquare();
		Scanner scan = null;

		FileWriter fw = null;
		BufferedWriter bw = null;

		try{
			scan = new Scanner(new File("C-small-attempt0.in"));

			fw = new FileWriter("C-small-attempt0.out");
			bw = new BufferedWriter(fw);

			int inputnum = scan.nextInt();
			int ctr = 1;

			while(scan.hasNextLine() && ctr <= inputnum){
				bw.write("Case #"+ctr+": "+test.fsCounter(scan.nextLong(), scan.nextLong()) + "\n");
				ctr++;
			}
		}catch(IOException e){
			System.out.println("File not found!");
			e.printStackTrace();
		}finally{
			bw.close();
		 }

	}
}