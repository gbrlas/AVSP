import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	
	
	public static void main(String args[]) throws IOException
	{
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String in,target=new String("welcome to code jam");
		String append;
		int[][] dp=new int[5000][21];
		StringTokenizer st;
		int res=0,N,t,i,j,k,MOD=10000,c;
		N = Integer.parseInt(br.readLine());
		for(t=1;t<=N;t++)
		{
			in = br.readLine();
			for(i=0;i<in.length();i++)
			if(in.charAt(i)=='w')
			dp[i][0]=1;
			else
			dp[i][0]=0;
			for(i=1;i<target.length();i++)
			{
				for(j=i;j<in.length();j++)
				{
					c = 0;
					if(in.charAt(j) != target.charAt(i))
					{
						dp[j][i]=0;
						continue;
					}
					for(k=i-1;k<j;k++)
					c = (c + dp[k][i-1])%MOD;
					dp[j][i] = c;
					//System.out.println(j+" "+i+" "+dp[j][i]);
				}
			}
			//System.out.println(i+" "+target.length());
			res=0;
			for(j=0;j<in.length();j++)
			res = (res+dp[j][i-1])%MOD;
			if(res<10)
			append="000";
			else if(res<100)
			append="00";
			else if(res<1000)
			append="0";
			else
			append="";
			System.out.println("Case #"+t+": "+append+res);
		}
		
	}
}