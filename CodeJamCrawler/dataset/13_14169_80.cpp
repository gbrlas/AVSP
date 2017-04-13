import java.io.IOException;
import java.io.StreamTokenizer;
import java.lang.Exception;
import java.lang.String;
import java.lang.System;
import java.math.BigInteger;
import java.lang.Integer;
import java.io.*;
import java.util.StringTokenizer;

public class FairAndSquare
{
    private static boolean isPalindrome(BigInteger n) {
        String s = n.toString();
        int lastElem = s.length() - 1;
        int limit = s.length()/2;

        for (int i = 0; i < limit; ++i) {
            if (s.charAt(i) != s.charAt(lastElem - i)) {
                return false;
            }
        }

        return true;
    }

    private static String getMinBinWithLength(int length)
    {
        String s = "1";
        for (int i = 0; i < length; ++i) {
            s += '0';
        }

        return s;
    }

    private static BigInteger ceilSqrt(BigInteger n) {
        int lengthMin = (n.bitLength() - 1)/2;
        int lengthMax = (n.bitLength() + 1)/2;
        BigInteger min = new BigInteger(getMinBinWithLength(lengthMin), 2);
        BigInteger max = new BigInteger(getMinBinWithLength(lengthMax), 2);
//        System.out.println("in ceil sqrt");
//        System.out.println("n = " + n.toString());
//        System.out.println("min = " + min.toString());
//        System.out.println("max = " + max.toString());
        //change to binary search -> use max
        while (min.pow(2).compareTo(n) == -1) {
            min = min.add(BigInteger.ONE);
            if (min.compareTo(max) == 1) {
                System.out.println("ceil wtf, this shouldn't be happening, too bad");
            }
        }

        return min;
    }

    private static BigInteger floorSqrt(BigInteger n) {
        int lengthMin = (n.bitLength() - 1)/2;
        int lengthMax = (n.bitLength() + 1)/2;
        BigInteger min = new BigInteger(getMinBinWithLength(lengthMin), 2);
        BigInteger max = new BigInteger(getMinBinWithLength(lengthMax), 2);
//        System.out.println("in floor sqrt");
//        System.out.println("n = " + n.toString());
//        System.out.println("min = " + min.toString());
//        System.out.println("max = " + max.toString());


        //change to binary search -> use max
        while (max.pow(2).compareTo(n) == 1) {
            max = max.subtract(BigInteger.ONE);
            if (max.compareTo(min) == -1) {
                System.out.println("floor wtf, this shouldn't be happening, too bad");
            }
        }

        return max;
    }


    public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";
        int n = 0;
        try {
            n = Integer.parseInt(br.readLine());
        } catch (IOException e) {

        }

		for (Integer i = 1; i <= n; ++i){
            try {
			    input = br.readLine();
            } catch (IOException e) {

            }

            StringTokenizer tok  = new StringTokenizer(input);

            String sA, sB;
            sA = tok.nextToken();
            sB = tok.nextToken();
			BigInteger A = new BigInteger(sA);
            BigInteger B = new BigInteger(sB);

            Integer numFairandSquare = 0;

            BigInteger auxA = ceilSqrt(A);
            BigInteger auxB = floorSqrt(B);

//            System.out.println("A = " + A.toString());
//            System.out.println("B = " + B.toString());
//            System.out.println("auxA = " + auxA.toString());
//            System.out.println("auxB = " + auxB.toString());

            while (auxA.compareTo(auxB)  <= 0) {
                if (isPalindrome(auxA) && isPalindrome(auxA.pow(2))) {
                    ++numFairandSquare;
                }

                auxA = auxA.add(BigInteger.ONE);
            }

			System.out.println("Case #"+i.toString()+": " +  numFairandSquare.toString());
		}
	}
}
