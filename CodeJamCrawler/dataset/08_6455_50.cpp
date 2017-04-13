import java.io.InputStreamReader;
import java.io.Reader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Formatter;
import java.util.Locale;

/**
 * <p>TODO: Describe me </p>
 * <p>&copy; 2008. Genesys Telecommunications Laboratories, Inc.</p>
 *
 * @author Nikolay Ugarov, nugarov@genesyslab.com
 * @since 7.6.100.00
 */
public class GCJ2008FlySwatter {

    static double sqr(double no) {
        return no * no;
    }


    static class Raquet {
        double innerR;
        double cellSize;
        double cellSpacing;

        Raquet(double innerR, double cellSize, double cellSpacing) {
            this.innerR = innerR;
            this.cellSize = cellSize;
            this.cellSpacing = cellSpacing;
        }

        double proto(double x) {
            double a = sqr(innerR);
            return
                    (x * Math.sqrt(a - sqr(x))
                            + a * Math.atan(x / Math.sqrt(a - sqr(x)))
                    ) / 2;
        }

        double cellArea(double x, double y) {
            double crossY = Math.sqrt(sqr(innerR) - sqr(x));
            double crossX = Math.sqrt(sqr(innerR) - sqr(y));
            if (Double.isNaN(crossX) || Double.isNaN(crossY) || crossY <= y || crossX <= x)
                return 0;
            double farCrossY = Math.sqrt(sqr(innerR) - sqr(x + cellSize));
            double farCrossX = Math.sqrt(sqr(innerR) - sqr(y + cellSize));
            if (crossX <= x + cellSize && crossY <= y + cellSize)
                return proto(crossX) - proto(x) - (crossX - x) * y;
            if (farCrossX >= x + cellSize || farCrossY >= y + cellSize)
                return sqr(cellSize);
            if (crossX >= x + cellSize && crossY <= y + cellSize)
                return proto(x + cellSize) - proto(x) - cellSize * y;
            if (crossX >= x + cellSize && crossY >= y + cellSize)
                return proto(x + cellSize) - proto(farCrossX) - (x + cellSize - farCrossX) * y + cellSize * (farCrossX - x);
            throw new RuntimeException("We failed!!!!!!");
        }

        double areaAboveCell(double x, double y) {
            double area = 0;
            double toAdd = 0;
            do {
                toAdd = cellArea(x, y = y + cellSize + cellSpacing);
                area += toAdd;
            } while (toAdd > 0);
            return area;
        }

        double area() {
            double area = 0;
            double x = cellSpacing / 2;
            double y = cellSpacing / 2;
            double toAdd = 0;
            do {
                toAdd = cellArea(x, y) / 2 + areaAboveCell(x, y);
                area += toAdd;
                x += cellSize + cellSpacing;
                y += cellSize + cellSpacing;
            } while (toAdd > 0);
            return area * 8;
        }


    }


    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long n = Integer.parseInt(in.readLine());
        for (int i = 1; i <= n; i++) {
            String[] tc = in.readLine().split(" ");
            double f = Double.parseDouble(tc[0]);
            double R = Double.parseDouble(tc[1]);
            double t = Double.parseDouble(tc[2]);
            double r = Double.parseDouble(tc[3]);
            double g = Double.parseDouble(tc[4]);
            double innerR = R - t - f;
            double cellSize = g - 2 * f;
            double cellSpacing = 2 * r + 2 * f;
            double out = 1;
            if (innerR > 0 && cellSize > 0) {
                Raquet fixedRaquet = new Raquet(innerR, cellSize, cellSpacing);
                double bigArea = Math.PI * sqr(R);
                out = 1 - fixedRaquet.area() / bigArea;
            }
            System.out.println(String.format(Locale.ENGLISH,"Case #"+i+": %7.6f", out));
        }

    }
}
