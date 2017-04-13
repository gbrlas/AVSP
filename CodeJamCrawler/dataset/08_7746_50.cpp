import java.io.*;
import java.util.*;
import java.math.*;

public class GCJB
{
	public static void main(String[] args) throws Throwable
	{
		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
		int N = Integer.parseInt(in.readLine());
		int iter = 0;
		while(N-->0)
		{
			iter++;
			int T = Integer.parseInt(in.readLine());
			String[] tempy = in.readLine().split(" ");
			int AtoB = Integer.parseInt(tempy[0]);
			int BtoA = Integer.parseInt(tempy[1]);
			int[] A = new int[5001], B = new int[5001];
			int[] Adept = new int[AtoB];
			int[] Aarri = new int[AtoB];
			int[] Bdept = new int[BtoA];
			int[] Barri = new int[BtoA];
			int stA = 0, stB = 0;
			for(int i = 0; i < AtoB; i++)
			{
				String[] ss = in.readLine().split(" ");
				String[] ss1 = ss[0].split(":");
				Adept[i] = Integer.parseInt(ss1[0])*60+Integer.parseInt(ss1[1]);
				ss1 = ss[1].split(":");
				Aarri[i] = Integer.parseInt(ss1[0])*60+Integer.parseInt(ss1[1]);
			}
			for(int i = 0; i < BtoA; i++)
			{
				String[] ss = in.readLine().split(" ");
				String[] ss1 = ss[0].split(":");
				Bdept[i] = Integer.parseInt(ss1[0])*60+Integer.parseInt(ss1[1]);
				ss1 = ss[1].split(":");
				Barri[i] = Integer.parseInt(ss1[0])*60+Integer.parseInt(ss1[1]);
			}
			for(int i = 0; i < AtoB; i++)
				for(int j = 0; j < AtoB-1; j++)
					if(Adept[j] > Adept[j+1])
					{
						int temp1 = Adept[j], temp2 = Aarri[j];
						Adept[j] = Adept[j+1];
						Aarri[j] = Aarri[j+1];
						Adept[j+1] = temp1;
						Aarri[j+1] = temp2;
					}
			for(int i = 0; i < BtoA; i++)
				for(int j = 0; j < BtoA-1; j++)
					if(Bdept[j] > Bdept[j+1])
					{
						int temp1 = Bdept[j], temp2 = Barri[j];
						Bdept[j] = Bdept[j+1];
						Barri[j] = Barri[j+1];
						Bdept[j+1] = temp1;
						Barri[j+1] = temp2;
					}
			int iterA = 0, iterB = 0;
			for(int t = 0; t <= 2400; t++)
			{
				if(t > 0)
				{
					A[t] += A[t-1];
					B[t] += B[t-1];
				}
				while(iterA < AtoB && t == Adept[iterA])
				{
					if(A[t] == 0)
					{
						A[t]++;
						stA++;
					}
					A[t]--;
					B[Aarri[iterA]+T]++;
					iterA++;
				}
				while(iterB < BtoA && t == Bdept[iterB])
				{
					if(B[t] == 0)
					{
						B[t]++;
						stB++;
					}
					B[t]--;
					A[Barri[iterB]+T]++;
					iterB++;
				}
			}
			out.println("Case #"+iter+": "+stA+" "+stB);
		}
		out.close();
		System.exit(0);
	}
}