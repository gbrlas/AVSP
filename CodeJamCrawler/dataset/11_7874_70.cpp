import java.util.*;

public class Magicka {
    static String[][] combos;
    static Map<String,List<String>> killers;
    static String magic;
    static int c,d,n;


    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int numCases = Integer.valueOf(s.nextLine());
        for (int i = 0; i < numCases; ++i) {
            int ff = 0;
            String[] in = s.nextLine().split(" ");
            c = Integer.valueOf(in[ff++]);
            combos = new String[c][2];
            for (int j = 0; j < c; ++j) {
                String combo = in[ff++];
                combos[j][0] = combo.substring(0, 2);
                combos[j][1] = combo.substring(2);
            }
            d = Integer.valueOf(in[ff++]);
            killers = new HashMap<String, List<String>>();
            for (int j = 0; j < d; ++j) {
                String combo = in[ff++];
                String ab = combo.substring(0,1);
                String bc = combo.substring(1);
                if (!killers.containsKey(ab)) {
                    killers.put(ab, new ArrayList<String>());
                }
                if (!killers.containsKey(bc)) {
                    killers.put(bc, new ArrayList<String>());
                }
                killers.get(ab).add(bc);
                killers.get(bc).add(ab);
            }
            n = Integer.valueOf(in[ff++]);
            magic = in[ff];
            doIt(i);
        }
    }

    static void doIt(int i) {
        List<String> invoked = new ArrayList<String>();
        invoked.add(String.valueOf(magic.charAt(0)));

        for (int jj = 1; jj < magic.length(); ++jj) {
            String next = String.valueOf(magic.charAt(jj));
            String c = invoked.isEmpty() ? "" : invoked.get(invoked.size()-1);
            String cc = c + next;
            String dd = next + c;
            String add = next;
            // any composition?
            for (String[] s : combos) {
                if (s[0].equals(cc) || s[0].equals(dd)) {
                    invoked.remove(invoked.size()-1);
                    add = s[1];
                }
            }
            boolean boom = false;
            if (killers.containsKey(add)) {
                List<String> ohoh = killers.get(add);
                for (int ii = 0; ii < invoked.size(); ++ii) {
                    String ch = invoked.get(ii);
                    if (ohoh.contains(ch)) {
                        //boom!
                        invoked.clear();
                        boom = true;
                    }
                }
            }
            if (!boom) {
                invoked.add(add);
            }
        }


        System.out.print("Case #" + (i + 1) + ": [");
        for (int ii = 0; ii < invoked.size(); ++ii) {
            String s = invoked.get(ii);
            System.out.print(s);
            if (ii < invoked.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
}
