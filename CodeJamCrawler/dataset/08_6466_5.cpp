import java.io.*;
import java.util.*;


public class GCJ2008Messaging {


    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(args[0]));
        final PrintStream out = new PrintStream(new FileOutputStream(args[1]));
        long N = Long.parseLong(in.readLine());
        for (long caseno = 1; caseno <= N; caseno++) {
            System.out.println("Case:" + caseno);
            String[] nums = in.readLine().split(" ");
            int lpk = Integer.parseInt(nums[0]);
            int k= Integer.parseInt(nums[1]);
            int l = Integer.parseInt(nums[2]);
            String[] freqss = in.readLine().split(" ");
            List<Integer> fr = new ArrayList<Integer>(freqss.length);
            for (int i = 0; i < freqss.length; i++) fr.add( Integer.parseInt(freqss[i]));
            Collections.sort(fr);
            int res = 0;
            for(int i=1; i<=lpk && !fr.isEmpty(); i++ ){
                for(int j=1; j<=k && !fr.isEmpty(); j++){
                    int freq = fr.remove(fr.size() - 1);
                    res += i*freq;
                }
            }
            out.println("Case #" + caseno + ": " + res);

        }

    }

}
