

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * User: spuvvada
 * Date: 4/13/13
 */
public class FairNSquare
{
    public static void main(String [] s)throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        String line = null;
        int count =0;
        for(int i=0; i<cases; i++)
        {
            if((line = br.readLine()) != null )
            {
                String[] split = line.split(" ");
                long A = Integer.parseInt(split[0]);
                long B = Integer.parseInt(split[1]);

                for(long j=A; j<=B; j++)
                {
                    if(isPalindrome(j))
                    {
                        long sqrt = isPerfectSquare(j);
                        if(sqrt !=-1 && isPalindrome(sqrt))
                        {
                            count++;
                        }
                    }
                }

                System.out.println("Case #"+(i+1) +": " + count);
                count = 0;
            }
        }
    }

    private static boolean isPalindrome(long x) {

        int div = 1;
        while (x / div >= 10) {
            div *= 10;
        }

        while (x != 0) {
            long l = x / div;
            long r = x % 10;
            if (l != r) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }

    private final static long isPerfectSquare(long n)
    {
        long sqrt = -1;
        switch((int)(n & 0x3F))
        {
            case 0x00: case 0x01: case 0x04: case 0x09: case 0x10: case 0x11:
            case 0x19: case 0x21: case 0x24: case 0x29: case 0x31: case 0x39:

            if(n < 410881L)
            {
                //John Carmack hack, converted to Java.
                // See: http://www.codemaestro.com/reviews/9
                int i;
                float x2, y;

                x2 = n * 0.5F;
                y  = n;
                i  = Float.floatToRawIntBits(y);
                i  = 0x5f3759df - ( i >> 1 );
                y  = Float.intBitsToFloat(i);
                y  = y * ( 1.5F - ( x2 * y * y ) );

                sqrt = (long)(1.0F/y);
            }
            else
            {
                //Carmack hack gives incorrect answer for n >= 410881.
                sqrt = (long)Math.sqrt(n);
            }
            return sqrt*sqrt == n ? sqrt : -1;

            default:
                return -1;
        }
    }
}
