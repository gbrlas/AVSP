import java.util.Scanner;
import java.util.*;
import java.io.*;

public class coba
{
	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);
		try
		{
			PrintWriter out = new PrintWriter(new FileOutputStream("C-small.txt"), true);


			int loop=scan.nextInt();
			int R,K,N,income=0;
			for (int i=0;i<loop;i++)
			{
				R=scan.nextInt();
				K=scan.nextInt();
				N=scan.nextInt();

				List gi = new ArrayList();
				List queue = new ArrayList();

				for (int j=0;j<N;j++)
				{
					gi.add(scan.nextInt());
				}




				for (int j=0;j<R;j++)
				{
					int count=0;
					int limit=0;
					while (true && gi.size()>0)
					{
						//System.out.println(count);
						limit+=(Integer)(gi.get(0));
						if (limit <= K)
						{
							queue.add(gi.get(0));
							gi.remove(0);
							count++;
						}
						else
						{
							limit-=(Integer)(gi.get(0));
							gi.add(queue.get(0));
							queue.remove(0);
							count--;
							break;
						}

						//trace
						/*System.out.println("Limit : " + limit);
						for (int z=0;z<gi.size();z++)
						{
							System.out.println(gi.get(z));
						}
						System.out.println("===");*/
					}

					//System.out.println("keluar");
					for (int z=0;z<count;z++)
					{
						gi.add(queue.get(0));
						queue.remove(0);
					}
					/*System.out.println("baru : ");
					for (int z=0;z<gi.size();z++)
					{
						System.out.println(gi.get(z));
					}*/


					income+=limit;
				}

				out.println("Case #" + (i+1) + ": " + income);
				income=0;
			}
			out.close();
		}catch(IOException ex){}

	}
}