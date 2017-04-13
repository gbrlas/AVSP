

import java.io.*;
import java.util.Scanner;
import java.util.Vector;
public class Main1CA {

	/**
	 * @param args
	 */
	public static void main(String[] args)throws Exception {
		// TODO Auto-generated method stub
		
		File input = new File("A-large.in");
//		File input = new File("Atest.in");
		
		Scanner in = new Scanner(input);
		
		BufferedWriter out = new BufferedWriter(new FileWriter("large.out"));
		
		int T = in.nextInt();
		
		for(int i=0;i<T;i++)
		{
			int result=0;
			
			int N = in.nextInt();
			Vector<Integer> A = new Vector<Integer>();
			Vector<Integer> B = new Vector<Integer>();
			
			for(int j=0;j<N;j++)
			{
				A.add(in.nextInt());
			    B.add(in.nextInt());
				
				for(int itr = A.size()-1;itr>0;itr--)
				{
					int t;
					
					if(A.get(itr) < A.get(itr-1))
					{
						t = A.get(itr);
						A.set(itr, A.get(itr-1));
						A.set(itr-1, t);
						
						
						t = B.get(itr);
						B.set(itr, B.get(itr-1));
						B.set(itr-1, t);
						
					}
					
					
					
				}
			
				
			}
			
			for(int j=0;j<N;j++)
			{
				for(int k=j+1;k<N;k++)
				{
					if((A.get(j) > A.get(k)&& B.get(j)< B.get(k)) || (A.get(j) < A.get(k)&& B.get(j)> B.get(k)))
					{
						result++;
					}
				}
			}
			
		
			
			String str = new String("Case #"+(i+1)+": "+result+"\n");
			System.out.print(str);
			out.write(str);
		}
out.close();
System.out.println("am here");
	}

}
