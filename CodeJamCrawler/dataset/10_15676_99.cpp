import java.util.*;
import java.math.*;
import java.io.*;
public class B {
	public static void main(String args[]) throws IOException
	{
		FileReader fin=new FileReader("B-large.in");
		FileWriter fout=new FileWriter("B-large.out");
		Scanner cin=new Scanner(fin);
		int i,j,n=0,t;
		BigInteger ans,temp;
		BigInteger a[]=new BigInteger[1000];
		t=cin.nextInt();
		for(i=1;i<=t;i++)
		{
			n=cin.nextInt();
			for(j=0;j<n;j++)
				a[j]=cin.nextBigInteger();
			Arrays.sort(a,0,n);
			temp=a[1].subtract(a[0]);
			for(j=1;j<n-1;j++)
				temp=temp.gcd(a[j+1].subtract(a[j]));
			if((a[0].mod(temp)).equals(BigInteger.ZERO)) 
				fout.write("Case #"+i+": "+"0"+"\n");
			else fout.write("Case #"+i+": "+temp.subtract(a[0].mod(temp)).toString()+"\n");
		}
		fout.close();
	}

}
