import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * Created by pratyush.verma on 13/04/14.
 */
public class DeceitfulWar {
    public static void main(String[] args) {
        int T;
        int index = 1;
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        while (T-- != 0) {
            double res = 0;
            int N = cin.nextInt();
            Double[] naomi = new Double[N];
            Double[] ken = new Double[N];
            TreeMap<Double, Boolean> naomiTree = new TreeMap<Double, Boolean>();
            TreeMap<Double, Boolean> kenTree = new TreeMap<Double, Boolean>();

            for (int i = 0; i < N; i++) {
                naomi[i] = cin.nextDouble();
                naomiTree.put(naomi[i], true);
            }
            for (int i = 0; i < N; i++) {
                ken[i] = cin.nextDouble();
                kenTree.put(ken[i], true);
            }
            int warScore = warScore(naomiTree, kenTree);
            int dWarScore = dWarScore(naomiTree, kenTree);
            System.out.println("Case #" + index++ + ": " + dWarScore + " " + warScore);

        }
    }

    private static int dWarScore(TreeMap<Double, Boolean> naomiTree, TreeMap<Double, Boolean> kenTree) {
        int res = 0;
        for (int i = 0; i <= naomiTree.size(); i++) {
            TreeMap<Double, Boolean> _naomiTree = new TreeMap<Double, Boolean>(naomiTree);
            TreeMap<Double, Boolean> _kenTree = new TreeMap<Double, Boolean>(kenTree);

            for (int j = 0; j < i; j++) {
                _naomiTree.remove(_naomiTree.pollFirstEntry().getKey());
                _kenTree.remove(_kenTree.pollLastEntry().getKey());
            }
            int score = _dWarScore(_naomiTree, _kenTree);
            res = Math.max(res, score);
        }
        return res;
    }

    private static int _dWarScore(TreeMap<Double, Boolean> naomiTree, TreeMap<Double, Boolean> kenTree) {
        int score = 0;
        TreeMap<Double, Boolean> _kenTree = new TreeMap<Double, Boolean>(kenTree);
        for(Map.Entry<Double, Boolean> entry : naomiTree.descendingMap().entrySet()) {
            Double nextHigherKey = _kenTree.higherKey(entry.getKey());
            if (nextHigherKey == null) {
                score++;
                _kenTree.remove(_kenTree.pollLastEntry().getKey());
            } else {
                _kenTree.remove(nextHigherKey);
            }
        }
        return score;
    }

    private static int warScore(TreeMap<Double, Boolean> naomiTree, TreeMap<Double, Boolean> kenTree) {
        int score = 0;
        TreeMap<Double, Boolean> _kenTree = new TreeMap<Double, Boolean>(kenTree);
        for(Map.Entry<Double, Boolean> entry : naomiTree.entrySet()) {
            Double nextHigherKey = _kenTree.higherKey(entry.getKey());
            if (nextHigherKey == null) {
                score++;
                _kenTree.remove(_kenTree.pollLastEntry().getKey());
            } else {
                _kenTree.remove(nextHigherKey);
            }
        }
        return score;
    }
}
