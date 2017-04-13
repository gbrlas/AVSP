import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
    public static void main(String args[]) throws IOException{
        BufferedReader input =  new BufferedReader(new FileReader("B-large.in"));
        Writer output = new BufferedWriter(new FileWriter("out.txt"));
        
        int T = Integer.parseInt(input.readLine());
        BigInteger a[] = new BigInteger[1000];
        BigInteger g[][] = new BigInteger[1000][1000];

        for(int tc=1;tc<=T;++tc){
            StringTokenizer st = new StringTokenizer(input.readLine());
            int N = Integer.parseInt(st.nextToken());

            for(int i=0;i<N;++i) a[i] = new BigInteger(st.nextToken());

            BigInteger G = (a[0].subtract(a[1])).abs();

            for(int i=0;i<N;++i) for(int j=i+1;j<N;++j) G = G.gcd(a[i].subtract(a[j])).abs();

            output.write("Case #"+tc+": "+a[0].negate().mod(G)+"\n");
        }
        
        output.close();
    }
}
