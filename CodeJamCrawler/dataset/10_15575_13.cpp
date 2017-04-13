import java.io.*;
import java.util.*;
import java.math.*;

public class D
{
	public static void main(String[] args) throws Exception
	{
	  // System.out.println(Math.atan(1)*180/Math.PI);
	
	    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());

		for (int i=1; i<=T; i++)
		{
            String[] temp=in.readLine().split(" ");
            int N=Integer.parseInt(temp[0]);
            int M=Integer.parseInt(temp[1]); 
            int[][] p=new int[N][2];
            int[][] q=new int[M][2];            
            for (int k=0; k<N; k++)
            {
                temp=in.readLine().split(" ");
                int x=Integer.parseInt(temp[0]);
                int y=Integer.parseInt(temp[1]); 
                p[k][0]=x;
                p[k][1]=y;
            }
            for (int k=0; k<M; k++)
            {
                temp=in.readLine().split(" ");
                int x=Integer.parseInt(temp[0]);
                int y=Integer.parseInt(temp[1]); 
                q[k][0]=x;
                q[k][1]=y;
            }                        
            String ans=solve(p,q);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

    //solves small only
	public static String solve(int[][] p, int[][] q)
    {
        String out="";
        
        double d2=(p[0][0]-p[1][0])*(p[0][0]-p[1][0])+(p[0][1]-p[1][1])*(p[0][1]-p[1][1]);
        double d=Math.sqrt(d2);
        
        for (int i=0; i<q.length; i++)
        {
            double r12=(p[0][0]-q[i][0])*(p[0][0]-q[i][0])+(p[0][1]-q[i][1])*(p[0][1]-q[i][1]);
            double r1=Math.sqrt(r12);
            double r22=(p[1][0]-q[i][0])*(p[1][0]-q[i][0])+(p[1][1]-q[i][1])*(p[1][1]-q[i][1]);
            double r2=Math.sqrt(r22);            
            
            double y=(d2+r12-r22)/(2.0*d);
            double y2=y*y;
            double x2=r12-y2;
            double x=Math.sqrt(x2);
            double tri1=x*y;        //2xy/2
            double a=Math.atan(x/y)*180.0/Math.PI*2;
            if (a<0) a+=360.0;
            //System.out.println(x+" "+y+" "+a);
            double sec1=Math.PI*r12*(a/360.0);
            double area1=sec1-tri1;
//            System.out.println(sec1+" "+tri1+" "+area1);

            double b=Math.atan(x/(d-y))*180.0/Math.PI*2;
            if (b<0) b+=360.0;            
            double tri2=x*(d-y);
            double sec2=Math.PI*r22*(b/360.0);
            double area2=sec2-tri2;
            out+=" "+(area1+area2);
        }
        
        return out;
 	}
}

