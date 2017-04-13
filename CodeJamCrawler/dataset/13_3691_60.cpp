import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class MainProgram {

	static BufferedReader in = null;
	static int A, B;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		in = new BufferedReader(new FileReader("/Users/himanshugupta/workspace/practice/FairAndSquare/input.txt")); 
		int N = Integer.parseInt(in.readLine());
		for (int i=0; i<N; i++){
			readInput();
			System.out.println("Case #"+(i+1)+": "+getOutput());
		}
		in.close();
	}

	public static int reverse(int num) {
		int rev = 0;
		while (num != 0) {
			rev = rev * 10 + num % 10;
			num /= 10;
		}
		return rev;
	}
	
	public static boolean isPalindrome(int p){
		if (p < 10)
			return true;
		return (p == reverse (p));
	}
	
	public static void readInput() throws IOException{
		String str = in.readLine();
		String S[] = str.split(" ");
		A = Integer.parseInt(S[0]);
		B = Integer.parseInt(S[1]);
	}
	
	public static void findSqrt(){
		double t = Math.sqrt(A);
		int r = (int)t;
		if ((double) r == t)
			A = r;
		else
			A = r + 1;
		t = Math.sqrt(B);
		B = (int)t;
	}
	
	public static int getOutput(){
		findSqrt();
		int sum = 0;
		for (int i=A; i<=B; i++){
			if (!isPalindrome(i))
				continue;
			if (!isPalindrome(i*i))
				continue;
			sum++;
		}
		return sum;
	}
}
