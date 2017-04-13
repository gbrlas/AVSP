import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static int compaire(int[] a, int[] b) {
		int result = 0;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				if (a[i] == b[j]) {
					if (result == 0)
						result = a[i];
					else
						return -1;
				}
			}
		}
		
		return result ;
	}

	
	public static void printArr(int [] a)
	{
		for (int i=0;i<a.length;i++)
			System.out.print(a);
		
		System.out.println();
	}
	
	public static void main(String[] args) throws FileNotFoundException {

		Scanner in = new Scanner(new File("A.in"));
		int numOfCases = in.nextInt();
		PrintWriter out = new PrintWriter(new File("A.txt"));
		
		int [] a,b ;
		int T,tTemp,result;
		for (int TC = 1 ; TC <= numOfCases ; TC++)
		{
			T = in.nextInt();
			tTemp = 4-T ;
			while(T>=1)
			{
				T -- ;
				in.nextLine();
			}
			
			a = new int [4];
			for(int i = 0 ;i <4 ;i++)
				a[i] = in.nextInt();
			in.nextLine();
			
			while(tTemp >= 1)
			{
				tTemp -- ;
				in.nextLine();
			}
			
//			 Second Array
			T = in.nextInt();
			tTemp = 4-T ;
			while(T>=1)
			{
				T -- ;
				in.nextLine();
			}
			
			b = new int [4];
			for(int i = 0 ;i <4 ;i++)
				b[i] = in.nextInt();
			in.nextLine();
			while(tTemp >= 1)
			{
				tTemp -- ;
				in.nextLine();
			}
			
			result = compaire(a, b);
			if (result == -1)
			{
				out.println("Case #" + TC + ": " + "Bad magician!");
				System.out.println("Case #" + TC + ": " + "Bad magician!");
			}
			else if (result == 0)
			{
				out.println("Case #" + TC + ": " + "Volunteer cheated!");
				System.out.println("Case #" + TC + ": " + "Bad magician!");
			}
			else
			{
				out.println("Case #" + TC + ": " + result);
				System.out.println("Case #" + TC +": "+ result);
			}
		}
		
		out.close();
	}
}
