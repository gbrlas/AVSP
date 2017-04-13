import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


class FairAndSquare {

	static void fairAndSquare(int start, int end, int time) {
		int counter = 0;
		int low = (int)Math.sqrt(start);
		int high = (int)Math.sqrt(end);
		for (int i = low; i <= high; i++ ) {
			if (isPalindrome(i) && i * i >= start && isPalindrome(i * i)) {
				counter++;
			}
		}
		System.out.println("Case #" + time + ": " + counter);
	}
	
	static boolean isPalindrome(int x) {
		int power = 1;
        while (x / power >= 10) {
            power *= 10;
        }
        while (x >= 10) {
            int quotient = x / power;
            int remainder = x % 10;
            if (quotient != remainder) {
                return false;
            }
            x -= quotient * power;
            x /= 10;
            power /= 100;
        }
        return true;
	}
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("C:\\Users\\Xing\\C-small-attempt0.in"));
		int num = scanner.nextInt();
		for (int i = 0; i < num; i++) {
			int start = scanner.nextInt();
			int end = scanner.nextInt();
			fairAndSquare(start, end, i + 1);
		}
		scanner.close();
	}

}
