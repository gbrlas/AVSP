import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.HashSet;
import java.util.regex.Pattern;

public class Tree {

    static final Pattern patternOpen = Pattern.compile("\\(");
    static final Pattern patternMaybeOpen = Pattern.compile("\\(|[a-z]*");
    static final Pattern patternClose = Pattern.compile("\\)");
    static final Pattern patternMaybeClose = Pattern.compile("\\)|[a-z]");

    public static void main(String[] args) throws Exception {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        final int n = Integer.parseInt(bf.readLine().trim());

        for (int nn = 1; nn <= n; ++nn) {

            bf.readLine();
            Tri tri = tree(bf);
            bf.readLine();
            
            final int anims = Integer.parseInt(bf.readLine().trim());

            
            System.out.println("Case #" + nn + ":");

            for (int aa = 1; aa <= anims; ++aa) {
                String[] props = bf.readLine().split(" ");
                HashSet<String> propss = new HashSet<String>();
                for (String p : props)
                    propss.add(p);
                
                Tri cur = tri;
                BigDecimal result = BigDecimal.ONE;
                
                for (;;)
                {
                    result = result.multiply(cur.weight);
                    if (cur.prop == null)
                        break;
                    if (propss.contains(cur.prop))
                        cur = cur.left;
                    else
                        cur = cur.right;
                }

                System.out.println(result);

            }


        }
    }

    static class Tri {
        BigDecimal weight;
        String prop;
        Tri left;
        Tri right;

        @Override
        public String toString() {
            if (prop != null)
                return "\n(" + weight + " :" + prop + left.toString() + right.toString() + "\n)";
            return "\n(" + weight + "\n)";

        }
    }

    private static Tri tree(BufferedReader bf) throws Exception {
        char c;

        Tri tri = new Tri();

        while (bf.read() != '(')
            ;

        String d = "";
        while ((c = (char) bf.read()) != '.' && !Character.isDigit(c))
            ;
        d += c;
        while ((c = (char) bf.read()) == '.' || Character.isDigit(c))
            d += c;

        tri.weight = BigDecimal.valueOf( Double.parseDouble(d));

        while (c != ')' && !Character.isLetter(c))
            c = (char) bf.read();

        if (c == ')')
            return tri;

        tri.prop = "" + c;
        while (Character.isLetter(c = (char) bf.read()))
            tri.prop += c;

        tri.left = tree(bf);

        tri.right = tree(bf);

        while (bf.read() != ')')
            ;

        return tri;
    }
}
