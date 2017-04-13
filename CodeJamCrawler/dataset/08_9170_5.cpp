import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.Callable;

public class R3_D {

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            System.out.println("Usage: " + R3_D.class.getSimpleName()
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
        scanner.close();

        long after = System.currentTimeMillis();
        long elapsed = after - before;

        System.err.println("Elapsed: " + elapsed + "ms");
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

        int n = 1;
        for (Callable<String> testCase : testCases) {
            out.print("Case #" + n++ + ":");
            out.println(testCase.call());
            out.flush();
        }
    }

    private static Callable<String> parseTestCase(final Scanner scanner) {
        final int H = scanner.nextInt();
        final int W = scanner.nextInt();
        final int R = scanner.nextInt();
        scanner.nextLine();
        int[] rows = new int[R];
        int[] cols = new int[R];
        final Set<Pos> rocks = new HashSet<Pos>();

        for (int i = 0; i < R; ++i) {
            int row = scanner.nextInt() - 1;
            int col = scanner.nextInt() - 1;
            scanner.nextLine();
            rocks.add(new Pos(col, row));
        }
        return new Callable<String>() {
            @Override
            public String call() throws Exception {
                int[][] counts = new int[H][W];
                counts[0][0] = 1;
                Set<Pos> current = new HashSet<Pos>();

                current.add(new Pos(0, 0));

                while (current.size() > 0) {
                    Set<Pos> next = new HashSet<Pos>();
                    for (Pos p : current) {
                        int count = counts[p.getY()][p.getX()];
                        Pos px = p.getPos(Dir.EAST).getPos(Dir.SOUTH);
                        Pos p2 = px.getPos(Dir.EAST);
                        Pos p3 = px.getPos(Dir.SOUTH);

                        int p2x = p2.getX(), p2y = p2.getY(), p3x = p3.getX(), p3y = p3.getY();
                        if (p2x < W && p2y < H && !rocks.contains(p2)) {
                            next.add(p2);
                            counts[p2y][p2x] += count;
                            counts[p2y][p2x] %= 10007;
                        }
                        if (p3x < W && p3y < H && !rocks.contains(p3)) {
                            next.add(p3);
                            counts[p3y][p3x] += count;
                            counts[p3y][p3x] %= 10007;
                        }
                    }
                    current = next;
                }

                return " " + counts[H - 1][W - 1];
            }
        };
    }
}

enum Dir {
    NORTH, SOUTH, WEST, EAST;

    Dir turnRight() {
        switch (this) {
        case NORTH:
            return EAST;
        case SOUTH:
            return WEST;
        case WEST:
            return NORTH;
        default:
            return SOUTH;
        }
    }

    Dir turnLeft() {
        return turnRight().turnRight().turnRight();
    }

    Dir turnAround() {
        return turnRight().turnRight();
    }
}

class Pos implements Comparable<Pos> {
    private final int x, y;

    Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    Pos getPos(Dir dir) {
        switch (dir) {
        case NORTH:
            return new Pos(x, y - 1);
        case SOUTH:
            return new Pos(x, y + 1);
        case WEST:
            return new Pos(x - 1, y);
        case EAST:
            return new Pos(x + 1, y);
        }
        throw new IllegalStateException();
    }

    @Override
    public int compareTo(Pos p) {
        if (this.y < p.y)
            return -1;
        if (this.y > p.y)
            return 1;
        if (this.x < p.x)
            return -1;
        if (this.x > p.x)
            return 1;
        return 0;
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Pos))
            return false;
        Pos p2 = (Pos) obj;
        return x == p2.x && y == p2.y;
    }

    @Override
    public int hashCode() {
        return x << 16 | y;
    }

    @Override
    public String toString() {
        return "[" + x + "," + y + "]";
    }
}
