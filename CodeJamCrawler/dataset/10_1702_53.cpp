import java.util.Scanner;
import java.io.*;
public class coba
{
	public static void main(String[] args)
	{
		try
		{
			PrintWriter out = new PrintWriter(new FileOutputStream("A-result.txt"));
			Scanner scan=new Scanner(System.in);
			int N,K,cek;
			String temp="",temp2="";
			int loop=scan.nextInt();

			for (int i=0;i<loop;i++)
			{
				temp="";
				N=scan.nextInt();
				K=scan.nextInt();

				for (int j=0;j<N;j++)
				{
					temp+="1";
				}

				temp2=Integer.toBinaryString(K);
				//StringBuffer sb = new StringBuffer(temp2);
				//sb.reverse();

				if (temp.length()<temp2.length())
				{
					StringBuffer sb = new StringBuffer(temp2);
					sb.reverse();
					temp2=sb.toString();
					temp2=temp2.substring(0,temp.length());
				}
				else if (temp.length()>temp2.length())
				{
					for(int j=0;j<(temp2.length()-temp.length());j++)
					{
						temp2+="0";
					}
				}

				String s="";
				if (temp.equals(temp2))
					s="Case #" + (i+1) + ": ON" ;
				else
					s="Case #" + (i+1) + ": OFF" ;

				if (i!=loop-1)
					out.println(s);
				else
					out.print(s);


				//System.out.println("N : " + temp);
				//System.out.println("K : " + temp2);

			}
			out.close();
		}catch(IOException ex) {}
	}
}