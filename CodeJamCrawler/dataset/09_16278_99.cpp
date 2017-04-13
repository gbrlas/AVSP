import java.util.HashSet;
import java.util.Scanner;

public class Alien {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        final int l = sc.nextInt();
        final int d = sc.nextInt();
        final int n = sc.nextInt();

        String[] words = new String[d];

        for (int i = 0; i < d; ++i)
            words[i] = sc.next();

        for (int j = 0; j < n; ++j) {

            String pattern = sc.next();
            int p1 = 0;

            HashSet<Character>[] pat = new HashSet[l];
            for (int p2 = 0; p2 < l; ++p2) {

                pat[p2] = new HashSet<Character>();

                char c = pattern.charAt(p1++);
                if (c == '(')
                    while ((c = pattern.charAt(p1++)) != ')')
                        pat[p2].add(c);
                else
                    pat[p2].add(c);
            }
            
            int matched = 0;
            for (int w = 0; w < d; ++w) {
                if (match(pat, words[w])) {
                    ++matched;
                }
            }
            
            System.out.println("Case #" + (j+1) + ": " + matched);
        }

    }

    static boolean match(HashSet<Character>[] pat, String word) {

        for (int i = 0; i < pat.length; ++i)
            if (!pat[i].contains(word.charAt(i)))
                return false;

        return true;

    }

}
