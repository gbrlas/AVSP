import java.io.File;
import java.io.PrintStream;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class R2_A {

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
            System.out.println("Usage: " + R2_A.class.getSimpleName()
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
        final int M = scanner.nextInt();
        final boolean V = (scanner.nextInt() == 1);
        scanner.nextLine();

        final int numInterior = (M - 1) / 2;

        final boolean[] values = new boolean[M];
        final int[] gates = new int[numInterior];
        final boolean[] change = new boolean[numInterior];

        int i = 0;
        for (; i < numInterior; ++i) {
            // Interior node
            gates[i] = scanner.nextInt();
            change[i] = (scanner.nextInt() == 1);
            scanner.nextLine();
        }
        for (; i < M; ++i) {
            // Leaf node
            values[i] = (Integer.parseInt(scanner.nextLine()) == 1);
        }

        return new Callable<String>() {
            private static final int LIMIT = 100000;

            @Override
            public String call() throws Exception {
                for (int i = numInterior - 1; i >= 0; --i) {
                    final int left = 2 * i + 1;
                    final int right = left + 1;
                    if (gates[i] == 1) {
                        values[i] = values[left] && values[right];
                    } else {
                        values[i] = values[left] || values[right];
                    }
                }

                for (int i = 0; i < M; ++i) {
                    System.err.print(" " + (values[i] ? 1 : 0));
                }
                System.err.println();

                int result = numChangeToMakeValue(0, V);

                if (result >= LIMIT) {
                    return " IMPOSSIBLE";
                } else {
                    return " " + result;
                }
            }

            private int numChangeToMakeValue(int pos, boolean target) {
                if (values[pos] == target)
                    return 0;
                if (pos >= numInterior)
                    return LIMIT;

                int result = numChangeWithGate(pos, target, gates[pos]);
                if (change[pos]) {
                    result = Math.min(result, 1 + numChangeWithGate(pos, target, 1 - gates[pos]));
                }
                return result;
            }

            private int numChangeWithGate(int pos, boolean target, int gate) {
                final int left = 2 * pos + 1;
                final int right = left + 1;
                if (gate == 1) {
                    if (target) {
                        return numChangeToMakeValue(left, true) + numChangeToMakeValue(right, true);
                    } else {
                        return Math.min(numChangeToMakeValue(left, false), numChangeToMakeValue(
                                right, false));
                    }
                } else {
                    if (target) {
                        return Math.min(numChangeToMakeValue(left, true), numChangeToMakeValue(
                                right, true));
                    } else {
                        return numChangeToMakeValue(left, false)
                                + numChangeToMakeValue(right, false);
                    }
                }
            }
        };
    }
}
