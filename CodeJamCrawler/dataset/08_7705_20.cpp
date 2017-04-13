import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigDecimal;

/**
 * Created by IntelliJ IDEA.
 * User: Margarita
 * Date: 26.07.2008
 * Time: 5:08:35
 * To change this template use File | Settings | File Templates.
 */
public class Main
{
    private static BigDecimal arr[] = new BigDecimal[41];

    public static String f(int x)
    {
        StringBuffer sb = new StringBuffer();
        if(x == 2) sb.append("0");
        String p = arr[x].toString();
        int index = p.indexOf('.');

        sb.append(p.substring(Math.max(0, index - 3), index));
        return sb.toString();
    }

    public static void main(String[] args) throws Exception
    {

        BigDecimal xx = new BigDecimal("5.2360679774997896964091736687313");
        arr[1] = xx;
        for(int i = 2; i <= 40; i++)
        {
            arr[i] = arr[i-1].multiply(xx);
        }

        BufferedReader in = new BufferedReader(new FileReader("c.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("c.out"));

        int T = Integer.parseInt(in.readLine());
        for(int t = 1; t <= T; t++)
        {
            int c = Integer.parseInt(in.readLine());
            out.write("Case #" + t + ": " + f(c) + "\n");
        }
        out.flush();
        out.close();
    }
}
