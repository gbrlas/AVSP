import java.io.*;
import java.util.*;

public class A {

	int max,given,n,row;
	int a[][];
	int s[];
	public static void main(String args[]) throws Exception
	{
		A obj = new A();
		obj.init();
	}	
	
	public void init() throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int cs = Integer.parseInt(br.readLine());
		int temp=0;
		while(temp<cs)
		{
			temp++;
			st  = new StringTokenizer(br.readLine());
			given = Integer.parseInt(st.nextToken());
			max = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			a = new int[n/max+1][max];
			st  = new StringTokenizer(br.readLine());
			s = new int[n];
			for(int i=0;i<n;i++)
			{
				s[i] = Integer.parseInt(st.nextToken());
			}
			
			selectionSort();
			for(int i=0;i<n;i++)
			{
				System.out.print(s[i]+" ");
			}
			System.out.println();
			System.out.println("Case #"+temp+": "+find());
		}
	}
	
	public int find()
	{
		for(int i=0;i<n;i++)
		{
			a[i/max][i%max] = s[i];
		}
		int sum=0;
		for(int i=0;i<n/max+1;i++)
		{
			for(int j=0;j<max;j++)
			{
				sum = sum + (i+1)*a[i][j];
			}			
		}
		return sum;
	}	
	
	public void selectionSort()
	{
		for(int i=0;i<n;i++)
		{
			int key = i;
			for(int j=i+1;j<n;j++)
			{
				if(s[j]>s[key])
				{
					key = j;
				}
			}
			int temp = s[i];
			s[i] = s[key];
			s[key] = temp;
		}
	}
}
