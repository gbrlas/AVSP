import java.io.File;
import java.io.PrintStream;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class R2_D {

    private static final NumberFormat DOUBLE_FORMAT;
    private static final NumberFormat INTEGER_FORMAT;

    static {
        DOUBLE_FORMAT = NumberFormat.getNumberInstance();
        DOUBLE_FORMAT.setMinimumIntegerDigits(3);
        DOUBLE_FORMAT.setMinimumFractionDigits(6);
        DOUBLE_FORMAT.setMaximumFractionDigits(6);
        DOUBLE_FORMAT.setGroupingUsed(false);

        INTEGER_FORMAT = NumberFormat.getIntegerInstance();
        INTEGER_FORMAT.setMinimumIntegerDigits(3);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            System.out.println("Usage: " + R2_D.class.getSimpleName()
                    + " <input file> {output file}");
            System.exit(1);
        }

        PrintStream out = System.out;
        if (args.length > 1) {
            out = new PrintStream(new File(args[1]));
        }

        long before = System.currentTimeMillis();

        Scanner scanner = new Scanner(new File(args[0]));

        process(scanner, out);

        long after = System.currentTimeMillis();
        long elapsed = after - before;

        out.flush();
        System.err.println("Elapsed: " + elapsed + "ms");
        scanner.close();
    }

    private static void process(final Scanner scanner, final PrintStream out) throws Exception {
        int N = Integer.parseInt(scanner.nextLine());

        List<Callable<String>> testCases = new ArrayList<Callable<String>>(N);

        for (int n = 1; n <= N; ++n) {
            Callable<String> testCase = parseTestCase(scanner);
            // if (n <= 1)
            testCases.add(testCase);
        }

        if (scanner.hasNext()) {
            throw new IllegalStateException("Parse incomplete");
        }

        ExecutorService threadPool = Executors.newFixedThreadPool(1);
        List<Future<String>> testResults = threadPool.invokeAll(testCases);

        int n = 1;
        for (Future<String> future : testResults) {
            out.print("Case #" + n++ + ":");
            out.println(future.get());
        }

        threadPool.shutdown();
    }

    private static Callable<String> parseTestCase(final Scanner scanner) {
        final int k = Integer.parseInt(scanner.nextLine());
        final String s = scanner.nextLine();

        return new Callable<String>() {
            @Override
            public String call() throws Exception {
                // System.err.println(s);
                char[] cs = s.toCharArray();
                // System.err.println(measureCompression(cs));
                //System.err.println(measureCompression("aabbccabc".toCharArray(
                // )));
                // char[] pcs = permute(cs, new int[] { 3, 2, 1, 0 });
                // System.err.println(pcs);

                int[] leadingKs = new int[0];
                Set<Integer> allKs = new HashSet<Integer>();
                for (int i = 0; i < k; ++i) {
                    allKs.add(i);
                }
                return " " + getMinSize(leadingKs, allKs, cs);

                // StringBuilder sb = new StringBuilder();
                // for (int i = 0; i < SOMETHING; ++i) {
                // sb.append(" ");
                // sb.append(SOMETHING);
                // }
                // return sb.toString();
            }

            private int getMinSize(int[] leadingKs, Set<Integer> remainingKs, char[] cs) {
                if (remainingKs.isEmpty())
                    return measureCompression(permute(cs, leadingKs));

                int[] subKs = new int[leadingKs.length + 1];
                System.arraycopy(leadingKs, 0, subKs, 0, leadingKs.length);
                int result = Integer.MAX_VALUE;
                Set<Integer> tryKs = new HashSet<Integer>(remainingKs);
                for (int x : remainingKs) {
                    subKs[leadingKs.length] = x;
                    tryKs.remove(x);
                    result = Math.min(result, getMinSize(subKs, tryKs, cs));
                    tryKs.add(x);
                }
                return result;
            }

            private char[] permute(char[] cs, int[] ks) {
                assert cs.length % ks.length == 0;
                char[] result = new char[cs.length];
                int stride = ks.length;
                for (int base = 0; base < cs.length; base += stride) {
                    for (int i = 0; i < ks.length; ++i) {
                        result[base + i] = cs[base + ks[i]];
                    }
                }
                return result;
            }

            private int measureCompression(char[] cs) {
                if (cs.length == 0)
                    return 0;
                char current = cs[0];
                int count = 1;
                for (int i = 1; i < cs.length; ++i) {
                    if (cs[i] != current) {
                        ++count;
                        current = cs[i];
                    }
                }
                return count;
            }
        };
    }
}
