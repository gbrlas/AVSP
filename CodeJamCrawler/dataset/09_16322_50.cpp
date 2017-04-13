import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class War {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        final int t = sc.nextInt();
        sc.nextLine();

        for (int tt = 1; tt <= t; ++tt) {

            String msg = sc.nextLine().trim();
            HashMap<Character, Long> map = new HashMap<Character, Long>();
            LinkedList<Long> number = new LinkedList<Long>();

            char first = msg.charAt(0);
            map.put(first, 1L);
            number.add(1L);

            long next = 1;
            boolean begin = true;

            for (int i = 1; i < msg.length(); ++i) {

                char c = msg.charAt(i);

                if (begin) {
                    if (c == first) {
                        number.add(1L);
                    } else {
                        map.put(c, 0L);
                        number.add(0L);
                        begin = false;
                    }
                } else {
                    if (map.containsKey(c)) {
                        number.add(map.get(c));
                    } else {
                        ++next;
                        map.put(c, next);
                        number.add(next);
                    }
                }
            }

            ++next;

            long result = 0;

            while (!number.isEmpty()) {
                result *= next;
                result += number.removeFirst();
            }

            System.out.println("Case #" + tt + ": " + result);

        }

    }

}
