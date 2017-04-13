import java.io.*;
import java.math.*;

public class Lottery
{
	public static void main(String[] args) throws Exception
	{
		PrintWriter writer = new PrintWriter("output.txt","UTF-8");
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int T= Integer.parseInt(br.readLine());

		for(int x = 0;x<T;x++)
		{
			String[] input = br.readLine().split(" ");
			int A = Integer.parseInt(input[0]);
			int B =Integer.parseInt(input[1]);
			int K = Integer.parseInt(input[2]);
			int max = Math.min(A,B);
			int count = 0;
			for(int g = 0;g<A;g++)
			{
				for(int z=0;z<B;z++)
				{	
					if((g & z) < K)
						count++;
				}

			}
			String out = "Case #"+(x+1)+": ";
			out += count;
			System.out.println(out);
			writer.println(out);
		}
		writer.close();
	}
}