import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SnapperChain
{
	int[] minSnaps;
	public SnapperChain()
	throws Exception
	{
		BufferedReader reader = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter("output");
		
		fillMinSnaps();
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for(int x=1;x<=testCases;x++)
		{
			StringTokenizer line = new StringTokenizer(reader.readLine()," ");
			int devices = Integer.parseInt(line.nextToken());		//N
			int snaps = Integer.parseInt(line.nextToken());			//K
			
			boolean on = solveProblem(devices,snaps);
			if(on)
				out.write("Case #"+x+": ON\n");
			else
				out.write("Case #"+x+": OFF\n");
		}
		out.close();
	}
	
	public boolean solveProblem(int devices, int snaps)
	{
		if(devices==1)
		{
			if(snaps%2==0)
				return false;
			return true;
		}
		while(snaps>minSnaps[devices])
		{
			snaps-=minSnaps[devices];
			snaps--;
		}
		if(minSnaps[devices]>snaps)
			return false;
		else if (minSnaps[devices]==snaps)
			return true;
		return false;
	}
	
	public void fillMinSnaps()
	{
		minSnaps = new int[32];
		minSnaps[1]=1;
		for(int x=2;x<minSnaps.length;x++)
		{
			minSnaps[x] = minSnaps[x-1]*2+1;
		}
	}
	
	public static void main(String args[])
	{
		try {
			new SnapperChain();
		} catch (Exception e) {e.printStackTrace();}
	}
}
