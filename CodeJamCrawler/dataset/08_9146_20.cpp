import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class C {

    private static final NumberFormat DOUBLE_FORMAT;

    static {
        DOUBLE_FORMAT = NumberFormat.getNumberInstance();
        DOUBLE_FORMAT.setMinimumIntegerDigits(3);
        DOUBLE_FORMAT.setMinimumFractionDigits(6);
        DOUBLE_FORMAT.setMaximumFractionDigits(6);
        DOUBLE_FORMAT.setGroupingUsed(false);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            System.out.println("Usage: " + C.class.getSimpleName() + " <input file> {output file}");
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
        final int num = Integer.parseInt(scanner.nextLine());
        System.err.println(Math.sqrt(5.0));
        return new Callable<String>() {
            @Override
            public String call() throws Exception {
                int n = num;
                final BigInteger[] x = new BigInteger[] { BigInteger.valueOf(3),
                        BigInteger.valueOf(1) };
                BigInteger[] y = new BigInteger[] { BigInteger.valueOf(1), BigInteger.valueOf(0) };
                BigInteger[] z = x;

                for (;;) {
                    if ((n & 0x1) == 1) {
                        y = mult(y, z);
                    }
                    n >>= 1;
                    if (n == 0)
                        break;
                    z = mult(z, z);
                }

                BigInteger intRoot = new BigInteger(
                        "223606797749978969640917366873127623544061835961152572427089", 10); // 60
                // places

                // System.err.println("y=(" + y[0] + "," + y[1] + ")");
                // double total = Math.sqrt(5.0) * y[1].doubleValue()
                // + y[0].mod(BigInteger.valueOf(1000)).doubleValue();
                // String full = DOUBLE_FORMAT.format(total);
                // // System.err.println(full);
                // int pos = full.indexOf('.');
                // return " " + full.substring(pos - 3, pos);
                BigInteger result = y[1].multiply(intRoot).divide(BigInteger.valueOf(10).pow(59))
                        .add(y[0]).add(BigInteger.valueOf(1000));
                String s = result.toString();
                System.err.println(s);
                return " " + s.substring(s.length() - 3, s.length());
            }
        };
    }

    private static BigInteger[] mult(BigInteger[] a, BigInteger[] b) {
        BigInteger ta = a[0].multiply(b[0]);
        BigInteger tb = a[1].multiply(b[0]).add(a[0].multiply(b[1]));
        BigInteger tc = a[1].multiply(b[1]);

        BigInteger ra = ta.add(tc.multiply(BigInteger.valueOf(5)));
        BigInteger rb = tb;

        return new BigInteger[] { ra, rb };
    }
}
