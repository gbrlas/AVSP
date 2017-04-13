import java.io.*;
import java.util.*;
import java.math.*;

public class A
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
            int N=Integer.parseInt(temp[0]);
            int K=Integer.parseInt(temp[1]);            
            String ans=solve(N,K);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

	public static String solve(int N, int K)
    {
        boolean[] a=new boolean[N];
        for (int i=1; i<=K; i++)
        {
            for (int k=0; k<N; k++)
            {
                if (a[k]) a[k]=false;
                else
                {
                    a[k]=true;
                    break;
                }
            }
        }
        boolean ok=true;
        for (int i=0; i<N; i++)
            if (!a[i])
            {
                ok=false;
                break;
            }
        
        if (ok) return "ON";
        return "OFF";
	}
		

}

