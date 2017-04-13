import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ProblemD {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("test.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int test = Integer.parseInt(st.nextToken());
        for (int testNo = 1; testNo <= test; testNo++) {
            int n = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
            double []first = new double[n + 1];
            double []second = new double[n + 1];
            boolean []over = new boolean[n + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n ; i++) {
                first[i] = Double.parseDouble(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n ; i++) {
                second[i] = Double.parseDouble(st.nextToken());
            }
            Arrays.sort(first);
            Arrays.sort(second);
            int strategy1 = 0,strategy2 = 0;
            boolean fl = false;
            double max = second[n];
            for (int i = 1; i <= n ; i++) {
                for (int j = 1; j <= n ; j++) {
                    if (second[j] > first[i] && !over[j]){
                        over[j] = true;
                        break;
                    }
                }
            }
            for (int i = 1; i <= n ; i++) {
                if (!over[i])strategy1++;
            }
            Arrays.fill(over, false);
            boolean flag = false;
            for (int i = 1; i <= n ; i++) {
                flag = true;
                for (int j = 1; j <= n ; j++) {
                    if (over[j])continue;
                    if (second[i] < first[j]){
                        strategy2++;
                        over[j] = true;
                        flag = false;
                        break;
                    }
                }
                if (flag)break;
            }
            out.print("Case #" + "" + testNo + ": " + strategy2 +" "+strategy1+ "\n");
        }
        out.close();
    }
}
