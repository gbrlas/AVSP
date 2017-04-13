import java.util.Arrays;
import java.util.Scanner;


public class p3c {


	public static void debug(Object... obs)
	{
		System.out.println(Arrays.deepToString(obs));
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			int L=sc.nextInt();
			long T=sc.nextLong();
			int N=sc.nextInt();
			int C=sc.nextInt();
			int di[]=new int[C];
			for(int i=0;i<C;i++)
				di[i]=sc.nextInt();
			
			System.out.println("Case #" + c + ": "+solve(L,T,N,C,di));
			
		}
	}

	private static long solve(int l, long t, int n, int c, int[] ci)
	{
		long di[]=new long[n];
		for(int i=0;i<n;)
		{
			for(int j=0;j<c&&i<n;j++,i++)
				di[i]=ci[j];
		}
		
		//debug(di);
		long base=0;
		long prev=0;
		int ea=-1;
		for(int i=0;i<n;i++)
		{
			base+=di[i]*2;
			//debug(base);
			//debug(prev);
			if((base>=t)&&ea==-1)
			{
				long tmp = di[i];
				di[i]=((base - t)/2L);
				ea=i;
				base = prev + (tmp-di[i])*2;
				break;
			}
			prev=base;
		}
		
		//debug(ea);
		//debug(base);
		//debug(di);
		
		for(int i=0;i<n;i++)
		{
			if(i<ea)
				di[i]=0;
			di[i]=-di[i];
		}
		//debug(di);
		Arrays.sort(di);
		long tra=0;
		for(int i=0;i<n;i++)
		{
			if(i<l&&(ea!=-1))
				tra+=(-di[i]);
			else
				tra+=(-di[i]*2);
		}
		
		//debug(base,tra);
//		if(t!=base){
//			debug(base,t);
//			debug(ea);
//			//debug(di[ea]);
//			debug("error");
//		}
		if(ea==-1)
			return base;
		return tra+t;
	}
}
