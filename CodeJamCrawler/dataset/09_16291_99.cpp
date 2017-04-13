import java.util.HashMap;
import java.util.Scanner;

public class Watersheds {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();

        for (int tt = 0; tt < t; ++tt) {

            final int h = sc.nextInt();
            final int w = sc.nextInt();

            int[][] altitudes = new int[h][w];
            int[][] klas = new int[h][w];
            int[][] order = new int[h][w];

            for (int hh = 0; hh < h; ++hh)
                for (int ww = 0; ww < w; ++ww) {
                    altitudes[hh][ww] = sc.nextInt();
                    klas[hh][ww] = hh * w + ww;
                    order[hh][ww] = 0;
                }

            for (int hh = 0; hh < h; ++hh)
                for (int ww = 0; ww < w; ++ww) {

                    int otherhw = -1;
                    int otheralt = altitudes[hh][ww];

                    if (hh > 0 && altitudes[hh - 1][ww] < otheralt) {
                        otheralt = altitudes[hh - 1][ww];
                        otherhw = (hh - 1) * w + ww;
                    }
                    if (ww > 0 && altitudes[hh][ww - 1] < otheralt) {
                        otheralt = altitudes[hh][ww - 1];
                        otherhw = hh * w + ww - 1;
                    }
                    if (ww < w - 1 && altitudes[hh][ww + 1] < otheralt) {
                        otheralt = altitudes[hh][ww + 1];
                        otherhw = hh * w + ww + 1;
                    }
                    if (hh < h - 1 && altitudes[hh + 1][ww] < otheralt) {
                        otheralt = altitudes[hh + 1][ww];
                        otherhw = (hh + 1) * w + ww;
                    }

                    if (otherhw != -1) {
                        int f1 = find(hh * w + ww, klas);
                        int f2 = find(otherhw, klas);
                        union(f1, f2, klas, order);
                    }
                }

            System.out.println("Case #" + (tt+1) + ":");
            
            char nextchar = 'a';
            
            HashMap<Integer, Character> klases = new HashMap<Integer, Character>();
            for (int hh = 0; hh < h; ++hh) {
                for (int ww = 0; ww < w; ++ww) {
                    
                    int f = find(hh * w + ww, klas);
                    Character c = klases.get(f);
                    if (c == null) {
                        c = nextchar;
                        ++nextchar;
                        klases.put(f, c);
                    }
                    
                    System.out.print(c + " ");
                }
                System.out.println();
            }
        }

    }

    static void union(final int hw1, final int hw2, int[][] klas, int[][] order) {

        final int w = klas[0].length;

        if (order[hw1 / w][hw1 % w] < order[hw2 / w][hw2 % w]) {
            klas[hw1 / w][hw1 % w] = hw2;
        } else if (order[hw1 / w][hw1 % w] > order[hw2 / w][hw2 % w]) {
            klas[hw2 / w][hw2 % w] = hw1;
        } else {
            klas[hw1 / w][hw1 % w] = hw2;
            ++order[hw2 / w][hw2 % w];
        }
    }

    static int find(final int hw, int[][] klas) {

        final int w = klas[0].length;

        int hw1 = hw;
        while (klas[hw1 / w][hw1 % w] != hw1)
            hw1 = klas[hw1 / w][hw1 % w];

        for (int hw2 = hw; klas[hw2 / w][hw2 % w] != hw1;) {
            int next = klas[hw2 / w][hw2 % w];
            klas[hw2 / w][hw2 % w] = hw1;
            hw2 = next;
        }

        return hw1;
    }

}
