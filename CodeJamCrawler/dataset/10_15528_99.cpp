import java.io.*;
import java.util.*;
import java.math.*;

public class B
{
	static int C;
	public static void main(String[] args) throws Exception
	{
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		C=Integer.parseInt(in.readLine());


		for (int i=1; i<=C; i++)
		{
            String line=in.readLine();
            String[] temp=line.split(" ");
            int N=Integer.parseInt(temp[0]);
            String[] num=new String[N];
            for (int k=0; k<N; k++) num[k]=temp[k+1];
            String ans=solve(num);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

	public static String solve(String[] num)
    {
        BigInteger[] num2=new BigInteger[num.length];
        for (int i=0; i<num2.length; i++) num2[i]=new BigInteger(num[i]);
        
        BigInteger gcd=(num2[1].subtract(num2[0])).abs();
        for (int i=0; i<num2.length; i++)
        {
            for (int k=i+1; k<num2.length; k++)
            {
                BigInteger diff=(num2[i].subtract(num2[k])).abs();
                gcd=GCD(gcd,diff);
            }
        }
        //System.out.println("gcd "+gcd);
        
        BigInteger a=num2[0].divide(gcd);
        BigInteger b=a.multiply(gcd);
        if (b.equals(num2[0])) return "0";
        return ""+b.add(gcd).subtract(num2[0]);
	}
	
    public static BigInteger GCD(BigInteger a, BigInteger b)	{
	   if (b.equals(new BigInteger("0"))) return a;
	   BigInteger c=a.mod(b);
	   return GCD(b,c);	}
	

}

