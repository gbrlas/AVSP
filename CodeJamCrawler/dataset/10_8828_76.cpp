import java.util.*;
import java.math.*;
import java.io.*;

public class b
{
	static Scanner in = new Scanner(System.in);
	public static void main(String[] args) throws Throwable
	{
		int tt = ip(in.nextLine());
		for(int iter = 1; iter <= tt; iter++)
		{
			System.out.print("Case #"+iter+": ");
			long L = in.nextInt();
			long P = in.nextInt();
			int C = in.nextInt();
			int uhh = 0;
			while(true)
			{
				if(P/L < C || (P/L == C && P%L == 0))
					break;
				uhh++;
				long LL = L, PP = P;
				while(Math.abs(LL-PP) >= 4)
				{
					long lt = (2*LL + PP)/3;
					long rt = (LL + 2*PP)/3;
					double lwf = Math.max(lt*1./L, P*1./lt);
					double rwf = Math.max(rt*1./L, P*1./rt);
					if(lwf < rwf)
						PP = rt;
					else
						LL = lt;
				}
				double bwf = Double.POSITIVE_INFINITY;
				boolean repl = true;
				long val = 0;
				for(long i = Math.max(LL-2, L+1); i <= Math.min(PP+2, P-1); i++)
				{
					boolean replh = true;
					double wf = P*1./i;
					if(wf < i*1./L)
					{
						wf = i*1./L;
						replh = false;
					}
					if(wf < bwf)
					{
						bwf = wf;
						repl = replh;
						val = i;
					}
				}
				if(repl) L = val; else P = val;
			}
			System.out.println(uhh);
		}
	}
	static int ip(String a)
	{
		return Integer.parseInt(a);
	}
}