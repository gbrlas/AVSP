import java.io.*;
import java.util.StringTokenizer;
public class FAS {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader h = new BufferedReader(new FileReader("C-small-attempt2.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("ride.out.txt"));
        int c = Integer.parseInt(h.readLine());
            for (int o = 1; o <= c; o++) {
                int n = 0;
                String l = h.readLine();
                StringTokenizer st = new StringTokenizer(l);
                int n1=Integer.parseInt(st.nextToken());
                int n2=Integer.parseInt(st.nextToken());
              //  System.out.println(n2);
                for (int i = n1; i <= n2; i++) {
                    if(Math.sqrt(i)-(int)Math.sqrt(i)==0 && new FAS().fair(i) && new FAS().fair((int)Math.sqrt(i)) ){
                        n++;
                      //  System.out.println(i);
                    }
                }
                bw.write("Case #"+o+": "+n);
                bw.newLine();
               // System.out.println(n);
            }
            bw.flush();
        bw.close();
    }
    boolean fair(int k){
        String kk = String.valueOf(k);
        
        for (int i = 0; i < kk.length(); i++) {
           if(kk.charAt(i)!=kk.charAt(kk.length()-i-1)) 
               return false;
        }
        return true;
    }
}
