import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FairAndSquare {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("fairAndSquare.in"));
		int n = in.nextInt();

		preloadTable();

		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("output.txt")));
		for (int i = 1; i <= n; i++) {
			long start = in.nextLong();
			long end = in.nextLong();

			long answer = findFairAndSquares(start, end);
			writer.write("Case #" + i + ": " + answer + "\n");
		}
		writer.flush();
		writer.close();
	}

	private static void preloadTable() {
		table.add(Long.valueOf(1));

		for (long i = 2; i < 10000000; i++) {
			if (isPalindrome(i)) {
				long square = i * i;
				if (isPalindrome(square))
				{
					table.add(square);
				}
			}
		}
	}

	private static long findFairAndSquares(long start, long end) throws Exception {
		int count = 0;

		for (Long number : table)
		{
			if (number >= start && number <= end)
				count++;
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

	private static final List<Long> table = new ArrayList<Long>();
}
