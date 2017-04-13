package code.jam.y2013.r1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A
{
	static PrintWriter pw;
	static String path = "D:/Martin/Downloads/";
	//static String file = "A-testin.txt";
	 static String file = "A-large.in";
	//static String file = "A-small-attempt4.in";

	static int count = 0;
	static long value = 0;

	public static void main(String[] args) throws Exception
	{
		pw = new PrintWriter(path + "out-" + file);
		Scanner sc = new Scanner(new File(path + file));
		int T = sc.nextInt();

		for (int i = 1; i <= T; i++)
		{
			int A = sc.nextInt();
			int N = sc.nextInt();
			long[] mote = new long[N];
			//int[] countl = new int[N+1];
			for (int j = 0; j < N; j++)
			{
				mote[j] = sc.nextLong();
			}
			Arrays.sort(mote);

			value = A;
			count = 0;
			int mincount = N;
			if (value != 1)
			{
				for (int z = 1; z <= N; z++)
				{
					long next = mote[z - 1];
					if (value > next)
					{
						value += next;
						mincount = Math.min(mincount, count + (N - z));
						continue;
					} else
					{
						// 1
						while (value <= next)
						{
							value = (2 * value) - 1;
							count++;
						}
						value += next;
						mincount = Math.min(mincount, count + (N - z));
						//countl[z-1] = count + (N - z + 1);
//						if ((count - oldcount) > (N - z + 1))
//						{
//							count = oldcount + (N - z + 1);
//							break;
//						}
					}

				}
			}

			out("Case #" + i + ": " + mincount);
		}

		pw.flush();
		pw.close();
	}

	
	static void out(Object o)
	{
		System.out.println(o);
		pw.println(o);
	}
}
