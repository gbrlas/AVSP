import java.io.File;
import java.io.PrintStream;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class A {

    private static final NumberFormat DOUBLE_FORMAT;

    static {
        DOUBLE_FORMAT = NumberFormat.getNumberInstance();
        DOUBLE_FORMAT.setMinimumFractionDigits(6);
        DOUBLE_FORMAT.setMaximumFractionDigits(6);
        DOUBLE_FORMAT.setGroupingUsed(false);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            System.out.println("Usage: " + A.class.getSimpleName() + " <input file> {output file}");
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
            testCases.add(parseTestCase(scanner));
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
        // TODO Parse data for one test case
        final int n = Integer.parseInt(scanner.nextLine());
        final int[] v1 = parseVector(scanner, n);
        final int[] v2 = parseVector(scanner, n);

        return new Callable<String>() {
            @Override
            public String call() throws Exception {
                Arrays.sort(v1);
                Arrays.sort(v2);

                int sum = 0;
                for (int i = 0; i < n; ++i) {
                    sum += v1[i] * v2[n - i - 1];
                }

                return " " + sum;
            }
        };
    }

    private static int[] parseVector(Scanner scanner, int n) {
        int[] v1 = new int[n];
        for (int i = 0; i < n; ++i) {
            v1[i] = scanner.nextInt();
        }
        scanner.nextLine();
        return v1;
    }
}
