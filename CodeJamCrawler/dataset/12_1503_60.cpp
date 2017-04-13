import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class MainWorker {
    public static void maina(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("in.txt"));
        Scanner sco = new Scanner(new File("out.txt"));
        int[] abc = new int[255];
        while (sc.hasNext()) {
            char[] a = sc.next().toCharArray();
            char[] b = sco.next().toCharArray();
            for (int i=0; i<a.length; i++)
                abc[a[i]] = b[i];
        }
        for (int i='a'; i<= 'z'; i++) {
            System.out.println((char)i + " = " + (char)abc[i]);
        }
        for (int i='a'; i<= 'z'; i++) {
            System.out.print("'" + (char) abc[i] + "', ");
        }
    }
    static char[] abc = new char[]{'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g',
            'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("A-small-attempt3.in"));
        System.setOut(new PrintStream(new File("res.txt")));
        int tests = sc.nextInt(); sc.nextLine();
        for (int t = 1; t <= tests; t++) {
            Scanner line = new Scanner(sc.nextLine());
            System.out.printf("Case #%d: ", t);
            while (line.hasNext()) {
                char[] a = line.next().toCharArray();
                for (int i=0; i<a.length; i++) {
                    if (Character.isAlphabetic(a[i]))
                        System.out.print(abc[a[i]-'a']);
                    else
                        System.out.print(a[i]);
                }
                if (line.hasNext())
                    System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
}