import java.util.Arrays;
import java.util.Scanner;

public class Welcome {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        final int n = sc.nextInt();
        sc.nextLine();

        final String welcome = "welcome to code jam";

        for (int m = 0; m < n; ++m) {

            int[] pos = new int[welcome.length()];
            Arrays.fill(pos, 0);

            String line = sc.nextLine();

            for (int l = 0; l < line.length(); ++l) {
                char c = line.charAt(l);

                for (int w = welcome.length() - 1; w > 0; --w)
                    if (c == welcome.charAt(w))
                        pos[w] = (pos[w] + pos[w - 1]) % 10000;

                if (c == welcome.charAt(0))
                    pos[0] = (pos[0] + 1) % 10000;

            }

            System.out.print("Case #" + (m + 1) + ": ");

            int res = pos[pos.length - 1];

            if (res < 1000)
                System.out.print('0');
            if (res < 100)
                System.out.print('0');
            if (res < 10)
                System.out.print('0');
            System.out.println(res);
        }
    }
}
