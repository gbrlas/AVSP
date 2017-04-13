import java.util.*;
import java.math.*;
import java.io.*;

public class a
{
	static Scanner in = new Scanner(System.in);
	public static void main(String[] args) throws Throwable
	{
		int tt = ip(in.nextLine());
		for(int iter = 1; iter <= tt; iter++)
		{
			System.out.print("Case #"+iter+": ");
			int N = in.nextInt();
			int[] A = new int[N], B = new int[N];
			for(int i = 0; i < N; i++)
			{
				A[i] = in.nextInt();
				B[i] = in.nextInt();
			}
			int ct = 0;
			for(int i = 0; i < N; i++)
				for(int j = i+1; j < N; j++)
					if(Math.signum(A[i]-A[j]) != Math.signum(B[i]-B[j]))
						ct++;
			System.out.println(ct);
		}
	}
	static int ip(String a)
	{
		return Integer.parseInt(a);
	}
}