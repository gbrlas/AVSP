import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintStream;
import java.util.TreeMap;

/**
 * Created by IntelliJ IDEA.
 * User: Geo
 * Date: Jul 18, 2008
 * Time: 1:01:50 AM
 * To change this template use File | Settings | File Templates.
 */
public class SearchEngine {
    public static void main(String[] args) throws Exception {
        BufferedReader fin=new BufferedReader(new FileReader("in.txt"));
        PrintStream fout=new PrintStream("out.txt");
        TreeMap<String,Integer> engs=new TreeMap<String,Integer>();
        boolean used[]=new boolean[100];
        int nousg=0;
        int swcs=0;
        int cases = Integer.parseInt(fin.readLine());
        for (int tcase=0;tcase<cases;tcase++) {
            int srcengs=Integer.parseInt(fin.readLine());
            engs.clear();
            nousg=0;
            swcs=0;
            for (int i=0;i<srcengs;i++) {
                engs.put(fin.readLine(),i);
                used[i]=false;
            }
            int quers=Integer.parseInt(fin.readLine());
            for (int i=0;i<quers;i++) {
                int loc=engs.get(fin.readLine());
                if (!used[loc]) {
                    nousg++;
                    used[loc]=true;
                }
                if (nousg==srcengs) {
                    swcs++;
                    for (int j=0;j<srcengs;j++)
                        used[j]=false;
                    used[loc]=true;
                    nousg=1;
                }
            }
            fout.println("Case #"+(tcase+1)+": "+swcs);
        }
        fin.close();
        fout.close();
    }
}
