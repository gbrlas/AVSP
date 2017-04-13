import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws Exception {
        int N, S, Q;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        N = Integer.parseInt(br.readLine());

        for (int it = 1 ; it <= N; it++) {
            S = Integer.parseInt(br.readLine());

            String[] engines = new String[S];
            for (int i = 0; i < S; i++) engines[i] = br.readLine();

            Q = Integer.parseInt(br.readLine());
            String[] queries = new String[Q];
            for (int i = 0; i < Q; i++) queries[i] = br.readLine();

            int best[][] = new int[S][Q+1];
            for (int i = 0; i < S; i++)
                for (int j = 0; j <= Q; j++)
                    best[i][j] = 10000;
            for (int i = 0; i < S; i++) best[i][0] = 0;

            for (int j = 0; j < Q; j++) {
                for (int i = 0; i < S; i++) {
                    if (!queries[j].equals(engines[i])) {
                        // don't have to switch
                        best[i][j+1] = Math.min(best[i][j], best[i][j+1]);
                    }
                    
                    for (int k = 0; k < S; k++) {
                        if (k != i) {
                            best[k][j+1] = Math.min(best[i][j] + 1, best[k][j+1]);
                        }
                    }
                }
            }
            
            int ret = 100000;
            for (int i = 0; i < S; i++) ret = Math.min(ret, best[i][Q]);

            System.out.println("Case #" + it + ": " + ret);
        }
    }
}
