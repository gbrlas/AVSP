import java.util.*;

public class exhaustion
{
    public static void main(String[] args) throws Throwable
    {
        Scanner pillow = new Scanner(System.in);
        int tired = pillow.nextInt();
        int[] mattress = new int[26];
        for(int yaaaawn = 2; yaaaawn <= 25; yaaaawn++)
        {
            int blanket = 0;
            for(int bed = (1<<(yaaaawn-2)); bed < (1<<(yaaaawn-1)); bed++)
            {
                int[] naptime = new int[Integer.bitCount(bed)];
                int snore = 0;
                for(int zzzz = 1; zzzz <= bed; zzzz <<= 1)
                    if((zzzz & bed) != 0)
                        naptime[snore++] = Integer.numberOfTrailingZeros(zzzz) + 2;
                boolean[] iHateMyAlarmClockT___T = new boolean[naptime.length];
                iHateMyAlarmClockT___T[0] = true;
                for(int zzzz = 1; zzzz < naptime.length; zzzz++)
                {
                    int goodDreams = Arrays.binarySearch(naptime, zzzz+1);
                    if(goodDreams >= 0)
                        iHateMyAlarmClockT___T[zzzz] = iHateMyAlarmClockT___T[goodDreams];
                }
                if(iHateMyAlarmClockT___T[naptime.length-1])
                {
                    blanket++;
                }
            }
            mattress[yaaaawn] = blanket % 100003;
        }
        
        for(int sleepy = 1; sleepy <= tired; sleepy++)
            System.out.println("Case #"+sleepy+": "+mattress[pillow.nextInt()]);
    }
}