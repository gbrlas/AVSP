import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.lang.*;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Vector;
import java.util.Collections;
public class GCJ10
{
	public static void main(String args[])
	{
		System.out.println("Here\n");
		Scanner in = null; 
		FileOutputStream fos=null;
		OutputStreamWriter os=null;
		try 
		{
			in = new Scanner(new File("F:\\Preparation\\GCJ\\B-small-attempt0.in"));
			fos = new FileOutputStream("F:\\Preparation\\GCJ\\B-small-attempt0.out");
			os = new OutputStreamWriter(fos);
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		}
		
		int c=in.nextInt();
		for(int i=1;i<=c;i++)
		{
			int n=in.nextInt();
			Vector<BigInteger> v=new Vector<BigInteger>(n);
			BigInteger b[]=new BigInteger[n];
			for(int j=0;j<n;j++)
			{
				b[j]=in.nextBigInteger();
				v.add(b[j]);
			}
			Collections.sort(v);
			BigInteger res;
			res=(v.get(1)).subtract(v.get(0));
			for(int j=2;j<n;j++)
			{
				BigInteger t=(v.get(j)).subtract(v.get(0));
				res=res.gcd(t);
			}
			BigInteger gcd = v.get(0).mod(res);
			if(gcd.equals(BigInteger.ZERO) == false)
				res = res.subtract(v.get(0).mod(res));
			else
				res = BigInteger.ZERO;
			
			System.out.println("Case #"+i+": "+res);
			try 
			{
				os.write("Case #"+i+": "+res+"\n");
				os.flush();
			} 
			catch (IOException e) 
			{
				e.printStackTrace();
			}
		}
	}
}