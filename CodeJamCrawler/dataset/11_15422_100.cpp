import java.util.*;
import java.io.*;

public class bot
{
    public static void main(String[] O_O) throws Throwable
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        for(int Q=1,lim=Integer.parseInt(in.readLine());Q<=lim;Q++)
        {
            int os=0,bs=0,o=1,b=1,t=0,tt=0,d=0;
            String[] sa = in.readLine().split("\\s+");
            for(int i=1;i<sa.length;i+=2)
            {
                if(i==1 || (!sa[i].equals(sa[i-2])))
                {
                    os^=bs;bs^=os;os^=bs;
                    o^=b;b^=o;o^=b;
                }
                d=Integer.parseInt(sa[i+1]);
                tt=Math.max(Math.abs(d-o)-os,0)+1;
                o = d;
                os = 0;
                bs += tt;
                t += tt;
            }
            System.out.println("Case #"+Q+": "+t);
        }
    }
}
