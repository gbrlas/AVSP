import java.io.*;
import java.util.*;
import java.math.*;

public class C
{
	public static void main(String[] args) throws Exception
	{
	    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());


		for (int i=1; i<=T; i++)
		{
            String line=in.readLine();
            String[] temp=line.split(" ");
            int R=Integer.parseInt(temp[0]);
            int k=Integer.parseInt(temp[1]);            
            int N=Integer.parseInt(temp[2]);
            line=in.readLine();
            String[] temp2=line.split(" ");
            int[] size=new int[N];
            for (int m=0; m<N; m++)
                size[m]=Integer.parseInt(temp2[m]);
            String ans=solve2(R,k,N,size);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

	public static String solve(int R, int k, int N, int[] size)
    {
        Vector<Integer> a=new Vector<Integer>();
        for (int i=0; i<size.length; i++) a.add(size[i]);
        long total=0;
        for (int m=0; m<R; m++)
        {
            int sum=0;
            for (int i=0; i<N; i++)
            {
                if (sum+a.get(0)>k) break;
                sum+=a.get(0);
                int b=a.remove(0);
                a.add(b);
            }
            total+=sum;
        }
        
        return ""+total;
	}
	
	public static String solve2(int R, int k, int N, int[] size)
    {
        long[][] c=new long[N][2];     //iter, value
        for (int i=0; i<N; i++) for (int m=0; m<2; m++) c[i][m]=-1;
        
        Vector<Integer> a=new Vector<Integer>();
        for (int i=0; i<size.length; i++) a.add(size[i]);
        long total=0;
        int cur=0;
        for (int m=0; m<R;)
        {
            int sum=0;
            for (int i=0; i<N; i++)
            {
                if (sum+a.get(0)>k) break;
                sum+=a.get(0);
                int b=a.remove(0);
                a.add(b);
                cur++;
                if (cur==N) cur=0;
            }
            total+=sum;
            
            if (c[cur][0]==-1)
            {
                c[cur][0]=m;
                c[cur][1]=total;
                m++;
            }
            else
            {
                int diffIter=m-(int)c[cur][0];
                long diffVal=total-c[cur][1];
                int n=(R-1-m)/diffIter;
//                System.out.println(diffIter+" "+n);
                total+=diffVal*n;
                m+=diffIter*n+1;
//                System.out.println(total+" "+m);
                for (int p=0; p<N; p++) for (int q=0; q<2; q++) c[p][q]=-1;
            }
        }
        
        return ""+total;
	}	
}

