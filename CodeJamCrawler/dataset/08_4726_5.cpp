import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

/**
 * User: Geo
 * Date: Aug 2, 2008
 * Time: 7:34:24 PM
 */
public class PermRLE {
    public static int perm(int k) {
        int ret=1;
        for (int i=1;i<=k;i++)
            ret*=i;
        return ret;
    }
    public static void nextprm(int prm[],int k) {
        int av=1;
        for (int i=k-1;i>=0;i--) {
            prm[i]+=av;
            if (prm[i]>=k) {
                prm[i]=0;
            }
            else {
                av=0;
            }
        }
        boolean ver[]=new boolean[k];
        for (int i=0;i<k;i++) {
            ver[i]=false;
        }
        boolean ok=true;
        for (int i=0;i<k;i++)
            if (ver[prm[i]]==true)
                ok=false;
            else
                ver[prm[i]]=true;
        if (!ok)
            nextprm(prm,k);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader in=new BufferedReader(new FileReader("input.txt"));
        PrintWriter out=new PrintWriter("output.txt");
        int n=Integer.parseInt(in.readLine());
        char ts[];
        char ns[];
        for (int ncase=0;ncase<n;ncase++) {
            int mrasp=2000;
            int k=Integer.parseInt(in.readLine());
            ts=in.readLine().toCharArray();
            ns=new char[ts.length];
            int prm[]=new int[k];
            for (int i=0;i<k;i++) {
                prm[i]=i;
            }
            for (int i=0;i<perm(k);i++) {
                for (int j=0;j<ts.length/k;j++)
                    for (int m=0;m<k;m++) {
                        ns[j*k+m]=ts[j*k+prm[m]];
                    }
                char lc=255;
                int rasp=0;
                for (int p=0;p<ts.length;p++) {
                    if (ns[p]!=lc)
                        rasp++;
                    lc=ns[p];
                }
                if (rasp<mrasp)
                    mrasp=rasp;
                nextprm(prm,k);
                //for (int j=0;j<k;j++)
                   // System.out.print(prm[j]+ " ");
               // System.out.println("");
            }
            out.println("Case #"+(ncase+1)+": "+mrasp);
        }
        in.close();
        out.close();
    }
}
