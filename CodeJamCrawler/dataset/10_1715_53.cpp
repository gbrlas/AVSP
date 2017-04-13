import java.util.Scanner;
import java.util.*;
import java.math.BigInteger;
import java.io.*;

public class b
{
	public static void main(String[] args)
	{
		try
		{
			Scanner scan=new Scanner(System.in);
			PrintWriter out = new PrintWriter(new FileOutputStream("B-result.txt"));

			int loop=scan.nextInt();
			List data=new ArrayList();
			List data2=new ArrayList();
			BigInteger fpb;
			for (int i=0;i<loop;i++)
			{
				int loop2=scan.nextInt();
				data=new ArrayList();
				data2=new ArrayList();

				fpb = BigInteger.valueOf(0);
				for (int j=0;j<loop2;j++)
				{
					data.add(scan.nextBigInteger());
				}

				Collections.sort(data);

				for (int j=0;j<data.size()-1;j++)
				{
					BigInteger a=(BigInteger)data.get(j+1);
					BigInteger b=(BigInteger)data.get(j);
					BigInteger c=b.subtract(a);
					c=c.abs();
					data2.add(c);
					//System.out.println("data2 : " + data2.get(0));
					//System.out.println(c);
					/*c=c.gcd(BigInteger.valueOf(1));
					c.abs();
					fpb=c;
					System.out.println("FPB : " + fpb);*/
				}

				//Collections.sort(data2);
				/*System.out.println("panjang : " + data2.size());
				for (int j=0;j<data.size()-1;j++)
				{
					System.out.println("data2 : " + data2.get(j));
				}*/


				if (data2.size()>1)
				{
					for (int j=0;j<data2.size()-1;j++)
					{
						BigInteger a=(BigInteger)data2.get(j+1);
						BigInteger b=(BigInteger)data2.get(j);
						BigInteger c=a.gcd(b);
						c=c.abs();
						fpb=c;
						//System.out.println("FPB : " + fpb);
						if (!(((BigInteger)data.get(0)).mod(fpb)).equals(BigInteger.valueOf(0)))
							out.println("Case #"+(i+1)+": " + fpb.subtract(((BigInteger)data.get(0)).mod(fpb)));
						else
							out.println("Case #"+(i+1)+": 0" );
						//System.out.println("datra2 : " + data2.get(j));
					}
				}
				else
				{
					BigInteger a=(BigInteger)data2.get(0);
					BigInteger c=a.gcd(a);
					c=c.abs();
					fpb=c;
					//System.out.println("FPB : " + fpb);
					if (!(((BigInteger)data.get(0)).mod(fpb)).equals(BigInteger.valueOf(0)))
						out.println("Case #"+(i+1)+": " + fpb.subtract(((BigInteger)data.get(0)).mod(fpb)));
					else
					out.println("Case #"+(i+1)+": 0" );
				}


				/*for (int j=0;j<fpb.size();j++)
				{
					System.out.println(fpb.get(j));
				}*/

				//System.out.println(fpb.subtract(((BigInteger)data.get(0)).mod(fpb)));

			}
			out.close();
		}catch(IOException ex){}
	}
}