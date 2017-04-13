import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
public class Main
{
	public static void main(String args[])throws Exception
	{
		Scanner cin=new Scanner(System.in);
		BigInteger a[]=new BigInteger[1100];
		BigInteger b[]=new BigInteger[1100];
		BigInteger c[]=new BigInteger[1100];
		int cas=cin.nextInt(),cc=0;
		while (cas-->0)
		{
			int n=cin.nextInt();
			for (int i=0;i<n;i++)
			{
				a[i]=cin.nextBigInteger();
			}
			System.out.printf("Case #%d: ",++cc);
			Arrays.sort(a,0,n);
			int size=0;
			b[size++]=a[0];
			for (int i=1;i<n;i++)
			{
				if (a[i].equals(a[i-1])==false)
					b[size++]=a[i];
			}
			//System.out.println(size);
			if (size==1)
			{
				System.out.println("0");
				continue;
			}
			for (int i=0;i<size-1;i++)
			{
				BigInteger tmp=b[i].subtract(b[i+1]);
				c[i]=tmp.abs();
			}
			BigInteger g=c[0];
			for (int i=1;i<size-1;i++)
			{
				g=g.gcd(c[i]);
			}
			BigInteger r=a[0].mod(g);
			if (r.equals(BigInteger.ZERO))
			{
				;
			}
			else 
			{
				r=a[0].divide(g);
				r=r.add(BigInteger.ONE);
				r=r.multiply(g);
				r=r.subtract(a[0]);
			}
			System.out.println(r);
		}
	}
}
