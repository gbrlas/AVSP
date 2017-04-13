
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Кирилл
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("input.in")));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
        int numOfTestCases = Integer.parseInt(in.readLine());
        for (int testCase = 1; testCase <= numOfTestCases; testCase++) {
            StringTokenizer tokens = new StringTokenizer(in.readLine());
            String leftBoundString = tokens.nextToken();
            String rightBoundString = tokens.nextToken();
            BigInteger leftBound = new BigInteger(leftBoundString);
            BigInteger rightBound = new BigInteger(rightBoundString);
            int initialSize = leftBoundString.length() / 4;
            BigInteger thisPart = new BigInteger(init(initialSize));
            long res = 0;
            while (true) {
                String thisPartString = thisPart.toString();
                if (!thisPartString.equals("0")) {
                    BigInteger thisInt = new BigInteger(thisPartString
                            + new StringBuilder(thisPartString).reverse());
                    BigInteger square = thisInt.multiply(thisInt);
                    if (square.compareTo(rightBound) > 0) {
                        break;
                    }
                    res += check(square, leftBound, rightBound, false);
                } else {
                    thisPartString = "";
                }
                for (int i = 0; i < 10; i++) {
                    BigInteger smth = new BigInteger(thisPartString + i
                            + new StringBuilder(thisPartString).reverse());
                    BigInteger square = smth.multiply(smth);
                    if (square.compareTo(rightBound) > 0) {
                        break;
                    }
                    res += check(square, leftBound, rightBound, false);
                }
                thisPart = thisPart.add(BigInteger.ONE);
            }
            out.write("Case #" + testCase + ": " + res);
            out.newLine();
            out.flush();
        }
        in.close();
        out.close();
    }

    private static int check(BigInteger square,
            BigInteger leftBound,
            BigInteger rightBound,
            boolean checkRight) {
        if (square.compareTo(leftBound) < 0) {
            return 0;
        }
        if ((checkRight) && (square.compareTo(rightBound) > 0)) {
            return 0;
        }
        String str = square.toString();
        return isPalindrom(str) ? 1 : 0;
    }

    private static boolean isPalindrom(String str) {
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    private static String init(int size) {
        if (size == 0) {
            return "0";
        }
        StringBuilder builder = new StringBuilder(size);
        builder.append("1");
        for (int i = 0; i < size - 1; i++) {
            builder.append("0");
        }
        return builder.toString();
    }
}
