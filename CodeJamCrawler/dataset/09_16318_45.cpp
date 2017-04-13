import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class Next {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        final int t = sc.nextInt();
        sc.nextLine();

        tt: for (int tt = 1; tt <= t; ++tt) {

            String snumber = sc.nextLine();

            LinkedList<Integer> number = new LinkedList<Integer>();
            for (int i = 0; i < snumber.length(); ++i)
                number.add(snumber.charAt(i) - '0');

            if (number.size() == 1) {
                System.out.println("Case #" + tt + ": " + number.get(0) + "0");
                continue tt;
            }

            LinkedList<Integer> pool = new LinkedList<Integer>();

            pool.add(number.removeLast());
            Integer last = number.removeLast();
            pool.add(last);
            Collections.sort(pool);

            while (last.equals(pool.getLast())) {
                if (number.isEmpty()) {

                    Iterator<Integer> iter = pool.iterator();
                    for (;;) {
                        Integer n = iter.next();
                        if (n > 0) {
                            pool.remove(n);
                            number.add(n);
                            break;
                        }
                    }

                    number.add(0);
                    while (!pool.isEmpty())
                        number.add(pool.removeFirst());
                    System.out.print("Case #" + tt + ": ");
                    for (Integer r : number)
                        System.out.print(r);
                    System.out.println();
                    continue tt;
                } else {
                    last = number.removeLast();
                    pool.add(last);
                    Collections.sort(pool);
                }
            }

            Iterator<Integer> iter = pool.iterator();
            while (iter.next() < last)
                ;

            for (;;) {
                Integer n = iter.next();
                if (n > last) {
                    pool.remove(n);
                    number.add(n);
                    break;
                }
            }
            while (!pool.isEmpty())
                number.add(pool.removeFirst());

            System.out.print("Case #" + tt + ": ");
            for (Integer r : number)
                System.out.print(r);
            System.out.println();

        }
    }
}
