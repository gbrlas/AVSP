package global2013.qualification;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class FairAndSquare {

    static final String INPUT_FILENAME = "C-large-1.in";
    static final boolean OUTPUT_TO_FILE = true;

    private BigInteger bigIntSqrtFloor(BigInteger x) {
        BigInteger min = BigInteger.ZERO;
        BigInteger max = BigInteger.TEN.pow(100);
        return bigIntSqrtFloorIter(x, min, max);
    }

    private BigInteger bigIntSqrtFloorIter(BigInteger x, BigInteger min, BigInteger max) {
        BigInteger guess = min.add(max).divide(BigInteger.valueOf(2));
        if (guess.multiply(guess).compareTo(x) != 1) {
            BigInteger guessPlusOne = guess.add(BigInteger.ONE);
            if (guessPlusOne.multiply(guessPlusOne).compareTo(x) == 1) {
                return guess;
            }
            return bigIntSqrtFloorIter(x, guess, max);
        } else {
            return bigIntSqrtFloorIter(x, min, guess);
        }
    }

    static class Palindrome {

        private BigInteger leftDigits = BigInteger.ZERO;
        private boolean hasMiddleDigit;
        private BigInteger middleDigit = BigInteger.ZERO;

        Palindrome(BigInteger n) {
            int ndigits = n.toString().length();
            hasMiddleDigit = ndigits % 2 == 1;
            for (int i = 0; i < ndigits / 2; i++) {
                n = n.divide(BigInteger.TEN);
            }
            if (hasMiddleDigit) {
                middleDigit = n.mod(BigInteger.TEN);
                n = n.divide(BigInteger.TEN);
            }
            leftDigits = n;
        }

        public BigInteger toBigInteger() {
            BigInteger value = leftDigits;
            if (hasMiddleDigit) {
                value = value.multiply(BigInteger.TEN).add(middleDigit);
            }
            BigInteger rightDigits = leftDigits;
            while (!rightDigits.equals(BigInteger.ZERO)) {
                value = value.multiply(BigInteger.TEN).add(rightDigits.mod(BigInteger.TEN));
                rightDigits = rightDigits.divide(BigInteger.TEN);
            }
            return value;
        }

        public void next() {
            if (hasMiddleDigit) {
                middleDigit = middleDigit.add(BigInteger.ONE);
                if (middleDigit.equals(BigInteger.TEN)) {
                    middleDigit = BigInteger.ZERO;
                    BigInteger newLeftDigits = leftDigits.add(BigInteger.ONE);
                    if (leftDigits.equals(BigInteger.ZERO) || leftDigits.toString().length() < newLeftDigits.toString().length()) {
                        hasMiddleDigit = false;
                    }
                    leftDigits = newLeftDigits;
                }
            } else {
                BigInteger newLeftDigits = leftDigits.add(BigInteger.ONE);
                if (leftDigits.toString().length() < newLeftDigits.toString().length()) {
                    leftDigits = newLeftDigits.divide(BigInteger.TEN);
                    hasMiddleDigit = true;
                    middleDigit = BigInteger.ZERO;
                } else {
                    leftDigits = newLeftDigits;
                }
            }
        }
    }

    private void solve(Scanner sc, PrintWriter pw) {
        BigInteger min = sc.nextBigInteger();
        BigInteger max = sc.nextBigInteger();
        BigInteger min_sqrt = bigIntSqrtFloor(min);
        if (min_sqrt.pow(2).compareTo(min) == 1) {
            System.err.println(String.format("error: sqrt(%d) >= %d", min_sqrt, min));
            return;
        }
        Palindrome pal = new Palindrome(min_sqrt);
        long count = 0;
        while (true) {
            BigInteger sq = pal.toBigInteger().pow(2);
            if (sq.compareTo(max) == 1) {
                break;
            }
            if (sq.compareTo(min) != -1 && isPalindrome(sq)) {
                //pw.println(String.format("%s **2 = %s", pal.toBigInteger().toString(), sq.toString()));
                count++;
            }
            pal.next();
        }
        pw.println(count);
        return;

    }

    private boolean isPalindrome(BigInteger i) {
        BigInteger temp = i;
        BigInteger reverse = BigInteger.ZERO;
        while (temp.compareTo(BigInteger.ZERO) != 0) {
            reverse = reverse.multiply(BigInteger.TEN).add(temp.mod(BigInteger.TEN));
            temp = temp.divide(BigInteger.TEN);
        }
        return reverse.equals(i);
    }

    public static void main(String[] args) throws FileNotFoundException {
        String inputFilename = System.getProperty("user.home") + "/Downloads/" + INPUT_FILENAME;
        Scanner sc = new Scanner(new FileReader(inputFilename));
        PrintWriter pw;
        if (OUTPUT_TO_FILE) {
            pw = new PrintWriter(inputFilename.replaceFirst("\\.in$", ".out"));
        } else {
            pw = new PrintWriter(System.out);
        }
        int caseCnt = sc.nextInt();
        sc.nextLine();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.err.println("Solving test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new FairAndSquare().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }

}
