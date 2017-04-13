//Solution to A for Code Jam qualification round 2 2009
//By Dmitry Kamenetsky

import java.io.*;
import java.util.*;
import java.math.*;

public class D
{
	static int C, N;
	public static void main(String[] args) throws Exception
	{
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		C=Integer.parseInt(in.readLine());


		for (int i=1; i<=C; i++)
		{
    		N=Integer.parseInt(in.readLine());
    		int[][] a=new int[N][3];
    		for (int k=0; k<N; k++)
    		{
		      String[] temp=(in.readLine()).split(" ");
		      a[k][0]=Integer.parseInt(temp[0]);
		      a[k][1]=Integer.parseInt(temp[1]);
		      a[k][2]=Integer.parseInt(temp[2]);
		    }

            double ans=solve(a);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

	public static double solve(int[][] a)
    {
        double[][] b=new double[N][N];
        for (int i=0; i<N; i++)
        {
            for (int k=0; k<N; k++)
            {
                b[i][k]=center(a[i],a[k]);
               // System.out.print(b[i][k]+" ");
            }
           // System.out.println();
        }
        
        if (N==1)
        {
            return b[0][0];
        }
        
        if (N==2)
        {
            double ab=b[0][1];
            double a2=b[0][0];
            double b2=b[1][1];
            double[] c={Math.max(ab,ab),Math.max(a2,b2)};
            Arrays.sort(c);
            return c[0];
        }
        
        double ab=b[0][1];
        double ac=b[0][2];
        double bc=b[1][2];
        double a2=b[0][0];
        double b2=b[1][1];
        double c=b[2][2];
        double[] d={Math.max(ab,c),Math.max(ab,ac),Math.max(ab,bc),Math.max(ac,b2),Math.max(bc,a2),
                  Math.max(ac,bc)};
        Arrays.sort(d);  
        return d[0];
    }
    
    public static double center(int[] c1, int[] c2)
    {
        double dist=Math.sqrt((c1[0]-c2[0])*(c1[0]-c2[0]) + (c1[1]-c2[1])*(c1[1]-c2[1]));
        double left=Math.max(c1[2],c2[2]-dist);
        double right=Math.max(c2[2],c1[2]-dist);
        return (dist+left+right)/2.0;
    }
    
  /*  public static double center(int[] c1, int[] c2, int[] c3)
    {
        int[] x={c1[0],c2[0],c3[0]};
        int[] y={c1[1],c2[1],c3[1]};
        Arrays.sort(x);
        Arrays.sort(y);
        int minX=x[0];
        int maxX=x[2];
        int minY=y[0];
        int maxY=y[2];
        int num=1000;
        for (int i=0; i<num; i++)
        {
            int x2=Math.random()*(maxX-minX)+minX
            int y2=Math.random()*(maxY-minY)+minY            
            
        }
    }*/
}