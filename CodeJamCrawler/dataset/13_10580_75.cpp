import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FairAndSquare {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("fairAndSquare.in"));
		int n = in.nextInt();

		for (int i = 1; i <= n; i++) {
			long start = in.nextLong();
			long end = in.nextLong();

			long answer = findFairAndSquares(start, end);
			System.out.println("Case #" + i + ": " + answer);
		}
	}

	private static long findFairAndSquares(long start, long end) {
		int count = 0;

		for (long i = start; i <= end; i++)
		{
			if (isPalindrome(i) && isPerfectSquare(i))
			{
				count++;
			}
		}
		
		return count;
	}

	private final static boolean isPalindrome(long number) {
		long palindrome = number;
		long reverse = 0;

		while (palindrome != 0) {
			long remainder = palindrome % 10;
			reverse = reverse * 10 + remainder;
			palindrome = palindrome / 10;
		}

		if (number == reverse) {
			return true;
		}
		return false;
	}

	private final static boolean isPerfectSquare(long n) {
		if (n < 0)
			return false;

		switch ((int) (n & 0x3F)) {
		case 0x00:
		case 0x01:
		case 0x04:
		case 0x09:
		case 0x10:
		case 0x11:
		case 0x19:
		case 0x21:
		case 0x24:
		case 0x29:
		case 0x31:
		case 0x39:
			long sqrt;
			if (n < 410881L) {
				// John Carmack hack, converted to Java.
				// See: http://www.codemaestro.com/reviews/9
				int i;
				float x2, y;

				x2 = n * 0.5F;
				y = n;
				i = Float.floatToRawIntBits(y);
				i = 0x5f3759df - (i >> 1);
				y = Float.intBitsToFloat(i);
				y = y * (1.5F - (x2 * y * y));

				sqrt = (long) (1.0F / y);
			} else {
				// Carmack hack gives incorrect answer for n >= 410881.
				sqrt = (long) Math.sqrt(n);
			}
			long answer = sqrt * sqrt;
			if (answer == n && isPalindrome(sqrt))
				return true;

		default:
			return false;
		}
	}
}
