import java.io.*;
import java.util.StringTokenizer;

public class ProblemA {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("test.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int test = Integer.parseInt(st.nextToken());
        for (int testNo = 1; testNo <= test; testNo++) {
            int r = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
            int []a = new int[17];
            for (int i = 1; i <= 4 ; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 1; j <= 4 ; j++) {
                    int te = Integer.parseInt(st.nextToken());
                    if (i == r){
                        a[te]++;
                    }
                }
            }
            r = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
            for (int i = 1; i <= 4 ; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 1; j <= 4 ; j++) {
                    int te = Integer.parseInt(st.nextToken());
                    if (i == r){
                        a[te]++;
                    }
                }
            }
            int c2 = 0,num = 0;
            for (int i = 1; i <= 16 ; i++) {
                if (a[i] == 2){
                    c2++;
                    num = i;
                }
            }
            if (c2 == 1){
                out.print("Case #" + "" + testNo + ": " + num + "\n");
            }
            if (c2 > 1){
                out.print("Case #" + "" + testNo + ": "+"Bad magician!"+"\n");
            }
            if (c2 == 0){
                out.print("Case #" + "" + testNo + ": "+"Volunteer cheated!"+"\n");
            }
        }
        out.close();
    }
}
