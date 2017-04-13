import java.io.*;
import java.util.StringTokenizer;

public class SaveUniverse {
	
	String str1[],str2[];
	int frq[],mn[];
	int q,e;
	
	public static void main(String args[]) throws IOException
	{
		SaveUniverse sv = new SaveUniverse();
		sv.init();
	}
	
	public void init() throws IOException
	{
		File file = new File("c:/A-small.in");
		BufferedReader br = new BufferedReader(new FileReader(file));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int cases = Integer.parseInt(br.readLine());
		int temp=0;
		
		while(temp<cases)
		{
			temp++;
			e = Integer.parseInt(br.readLine());
			str1 = new String[e];
			frq = new int[e];
			mn = new int[e];
			
			for(int i=0;i<e;i++)
			{
				str1[i] = br.readLine();
				frq[i] = 0;
			}
			q = Integer.parseInt(br.readLine());
			
			str2 = new String[q];
			
			for(int i=0;i<q;i++)
			{
				str2[i] = br.readLine();
			}
			int count=0;
			int tmp=0;
			while(tmp<q)
			{
				tmp = findFarthest(tmp);
				if(tmp==-1)
				{
					break;
				}
				count++;	
			}
				
			System.out.println("Case #"+temp+": "+count);
		}
	}
	
	public int findFarthest(int k)
	{
		int index=k;
		for(int i=0;i<e;i++)
		{
			int mn = -1;
			for(int j=k;j<q;j++)
			{
				if(str1[i].equals(str2[j]))
				{
					mn = j;
					break;
				}
			}
			if(mn==-1 || index<mn)
			{
				index = mn;
//				System.out.println(str1[i]+" "+mn+" "+index);
				if(mn==-1)
				{
					break;
				}
			}
		}		
		return index;
	}
	public int find(int k)
	{
		for(int i=0;i<e;i++)
		{
			for(int j=k;j<q;j++)
			{
				if(str1[i].equals(str2[j]))
				{
					frq[i]++;
				}
			}
		}
		
		int min=frq[0];
		for(int i=1;i<e;i++)
		{
			if(frq[i]<min)
			{
				min = frq[i];
			}
		}
		return min;
	}
		
}
