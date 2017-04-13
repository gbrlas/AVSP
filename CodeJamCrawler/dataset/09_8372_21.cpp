import java.io.*;
import java.util.*;

public class D
{
	public static void main(String[] args) throws Throwable
	{
		Scanner in = new Scanner(System.in);
		int tt = in.nextInt();
		for(int ii = 1; ii <= tt; ii++)
		{
			int N = in.nextInt();
			int[][] pla = new int[N][3];
			for(int i = 0; i < N; i++)
			{
				pla[i][0] = in.nextInt();
				pla[i][1] = in.nextInt();
				pla[i][2] = in.nextInt();
			}
			if(N == 1)
				System.out.println("Case #"+ii+": "+pla[0][2]);
			if(N == 2)
				System.out.println("Case #"+ii+": "+Math.max(pla[0][2], pla[1][2]));
			if(N == 3)
				System.out.println("Case #"+ii+": "+Math.min(Math.max(pla[0][2]+pla[1][2]+Math.hypot(pla[0][0]-pla[1][0], pla[0][1]-pla[1][1]), pla[2][2])/2,Math.min(Math.max(pla[0][2]+pla[2][2]+Math.hypot(pla[0][0]-pla[2][0], pla[0][1]-pla[2][1]), pla[1][2])/2,Math.max(pla[1][2]+pla[2][2]+Math.hypot(pla[1][0]-pla[2][0], pla[1][1]-pla[2][1]), pla[0][2])/2)));
		}
		System.exit(0);
	}
}