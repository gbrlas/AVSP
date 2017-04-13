import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
    public static void main(String args[]) throws IOException{
        BufferedReader in =  new BufferedReader(new FileReader("B-small-attempt0.in"));

        int T = Integer.parseInt(in.readLine());
        BigInteger a[] = new BigInteger[1000];
        BigInteger g[][] = new BigInteger[1000][1000];

        for(int tc=1;tc<=T;++tc){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(st.nextToken());

            for(int i=0;i<N;++i) a[i] = new BigInteger(st.nextToken());

            BigInteger G = (a[0].subtract(a[1])).abs();

            for(int i=0;i<N;++i) for(int j=i+1;j<N;++j) G = G.gcd(a[i].subtract(a[j])).abs();

            System.out.println("Case #"+tc+": "+a[0].negate().mod(G));
        }
    }
}
