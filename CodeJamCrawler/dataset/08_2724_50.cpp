import java.io.*;
import java.util.*;

public class Trains {
	public static void main(String args[])
	{
		String filename = args[0];
		File file = new File(filename);
		BufferedReader br;
		try
		{
			br = new BufferedReader(new FileReader(file));
			int n = Integer.parseInt(br.readLine());
			
			for (int i =0; i < n; i++)
				System.out.println("Case #" + (i + 1) + ": " + checkCase(br));
		}
		catch (Exception e) 
		{
			e.printStackTrace();
		}
	}
	
	private static String checkCase(BufferedReader br)
	{		
		String out = "";
		try
		{
		
			int t = Integer.parseInt(br.readLine());
			String[] nab = br.readLine().split(" ");
			int na = Integer.parseInt(nab[0]);
			int nb = Integer.parseInt(nab[1]);
						
			int[] aAtA = new int[na];
			int[] aAtB = new int[na];  
			int[] bAtB = new int[nb];
			int[] bAtA = new int[nb]; 
						
			for(int i = 0; i < na; i++){
				String[] times = br.readLine().split(" ");
				String[] times1 = times[0].split(":");
				aAtA[i]= Integer.parseInt(times1[0])*60 +Integer.parseInt(times1[1]);
				//System.out.println(aAtA[i]);
				String[] times2 = times[1].split(":");
				aAtB[i]= Integer.parseInt(times2[0])*60 +Integer.parseInt(times2[1]);	
				//System.out.println(aAtB[i]);
			}
			
			for(int i = 0; i < nb; i++){
				String[] times = br.readLine().split(" ");
				String[] times1 = times[0].split(":");
				bAtB[i]= Integer.parseInt(times1[0])*60 + Integer.parseInt(times1[1]);
				//System.out.println(bAtB[i]);
				String[] times2 = times[1].split(":");
				bAtA[i]= Integer.parseInt(times2[0])*60 + Integer.parseInt(times2[1]);		
				//System.out.println(bAtA[i]);
			}
			
			out = countTrainsNeeded(aAtA, bAtA, t) + " " + countTrainsNeeded(bAtB, aAtB, t);		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		return out;
	}
	
	private static PriorityQueue<Integer> arrayToPQ(int[] arr){
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		for(int i=0; i < arr.length; i++){
			pq.offer(new Integer(arr[i]));
		} 
		return pq;
	}
	
	
	private static int 	countTrainsNeeded(int[] arr1, int[] arr2, int t){
		PriorityQueue<Integer> pq1= arrayToPQ(arr1);
		//		System.out.println("pq1=" + pq1);

		PriorityQueue<Integer> pq2= arrayToPQ(arr2);
		//	System.out.println("pq2" + pq2);

		int cnt = 0;

		while ( pq1.size() > 0){
			int dt1 = (Integer) pq1.poll();
			
			if(pq2.size() > 0)
			{
				int dt2 = (Integer)  pq2.peek() + t;
				if( dt2 <= dt1)
					pq2.poll();
				else
					cnt++;
			} 
			else
				cnt++;
		}
		//System.out.println(cnt);	
		return cnt;
	}
}


