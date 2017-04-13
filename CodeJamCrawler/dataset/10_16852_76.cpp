import java.util.*;
import java.math.*;

public class Main
{
	public static BigInteger gcd(BigInteger x,BigInteger y)
	{
		if(x.equals(BigInteger.valueOf(0)))
			return y;
		if(y.equals(BigInteger.valueOf(0)))
			return x;
		return gcd(y,x.mod(y));
	}
      public static void main(String []args)
     { 
               Scanner cin=new Scanner(System.in);
               BigInteger [] a = new BigInteger [1010];
               int t,cas = 1,i,n;
               BigInteger num,temp;
               t = cin.nextInt();
               while(t!=0)
               {
            	   n=cin.nextInt();
            	   for(i=0;i<n;i++)
            		   a[i]=cin.nextBigInteger();
            	   Arrays.sort(a,0,n);
            	   num = a[n-1].subtract(a[n-2]);
            	   
            	   for(i=n-2;i>=1;i--)
            		   num = gcd(num,a[i].subtract(a[i-1]));
            	   System.out.printf("Case #%d: ",cas++);
            	   temp = a[0].mod(num);
            	   if(num.equals(BigInteger.valueOf(0))||temp.equals(BigInteger.valueOf(0)))
            		   System.out.println("0");
            	   else System.out.println(num.subtract(temp));
            	   t--;
               }
     }
}
