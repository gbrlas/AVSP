import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
public class tictactoetomek 
{

	
	public static void main(String[] args) throws FileNotFoundException
	{Scanner sc = new Scanner (new File ("A-sample-input.in"));
	PrintWriter pw = new PrintWriter (new File ("output.txt"));
		String m;
		String n;
		String v;
		String x;
		String a[]=new String[4];
		String b[]=new String[4];
		String c[]=new String[4];
		String d[]=new String[4];
		int cases;
		int flagx;
		int flagy;
		int ntcomp;
		cases=sc.nextInt();
		
		for(int q=0;q<cases;q++)
		{
			
			m=sc.next();
			n=sc.next();
			v=sc.next();
			x=sc.next();
			a = m.split("");
			b = n.split("");
			c = v.split("");
			d = x.split("");
			flagx=0;
			flagy=0;
			ntcomp=0;
			if(((a[1].equals("X")) || (a[1].equals("T")))&&((a[2].equals("X")) || (a[2].equals("T"))) && ((a[3].equals("X")) || (a[3].equals("T"))) && ((a[4].equals("X")) || (a[4].equals("T"))))
		{
			flagx+=1;
		}
		
		else if(((b[1].equals("X")) || (b[1].equals("T")))&&((b[2].equals("X")) || (b[2].equals("T"))) && ((b[3].equals("X")) || (b[3].equals("T"))) && ((b[4].equals("X")) || (b[4].equals("T"))))
		{
			flagx+=1;
		}
		else if(((c[1].equals("X")) || (c[1].equals("T")))&&((c[2].equals("X")) || (c[2].equals("T"))) && ((c[3].equals("X")) || (c[3].equals("T"))) && ((c[4].equals("X")) || (c[4].equals("T"))))
		{
			flagx+=1;
		}
		else if(((d[1].equals("X")) || (d[1].equals("T")))&&((d[2].equals("X")) || (d[2].equals("T"))) && ((d[3].equals("X")) || (d[3].equals("T"))) && ((d[4].equals("X")) || (d[4].equals("T"))))
		{
			flagx+=1;
		}
		else if(((a[1].equals("X")) || (a[1].equals("T")))&&((b[1].equals("X")) || (b[1].equals("T"))) && ((c[1].equals("X")) || (c[1].equals("T"))) && ((d[1].equals("X")) || (d[1].equals("T"))))
		{
			flagx+=1;
		}
		else if(((a[2].equals("X")) || (a[2].equals("T")))&&((b[2].equals("X")) || (b[2].equals("T"))) && ((c[2].equals("X")) || (c[2].equals("T"))) && ((d[2].equals("X")) || (d[2].equals("T"))))
		{
			flagx+=1;
		}
		else if(((a[3].equals("X")) || (a[3].equals("T")))&&((b[3].equals("X")) || (b[3].equals("T"))) && ((c[3].equals("X")) || (c[3].equals("T"))) && ((d[3].equals("X")) || (d[3].equals("T"))))
		{
			flagx+=1;
		}
		else if(((a[4].equals("X")) || (a[4].equals("T")))&&((b[4].equals("X")) || (b[4].equals("T"))) && ((c[4].equals("X")) || (c[4].equals("T"))) && ((d[4].equals("X")) || (d[4].equals("T"))))
		{
			flagx+=1;
		}
		else if(((a[1].equals("X")) || (a[1].equals("T")))&&((b[2].equals("X")) || (b[2].equals("T"))) && ((c[3].equals("X")) || (c[3].equals("T"))) && ((d[4].equals("X")) || (d[4].equals("T"))))
		{
			flagx+=1;
		}
		else if(((a[4].equals("X")) || (a[4].equals("T")))&&((b[3].equals("X")) || (b[3].equals("T"))) && ((c[2].equals("X")) || (c[2].equals("T"))) && ((d[1].equals("X")) || (d[1].equals("T"))))
		{
			flagx+=1;
		}
		if(flagx>0)
		{

			pw.println("Case #" + (q+1) + ": X won");
		}
		if(((a[1].equals("O")) || (a[1].equals("T")))&&((a[2].equals("O")) || (a[2].equals("T"))) && ((a[3].equals("O")) || (a[3].equals("T"))) && ((a[4].equals("O")) || (a[4].equals("T"))))
		{
			flagy+=1;
		}
		
		else if(((b[1].equals("O")) || (b[1].equals("T")))&&((b[2].equals("O")) || (b[2].equals("T"))) && ((b[3].equals("O")) || (b[3].equals("T"))) && ((b[4].equals("O")) || (b[4].equals("T"))))
		{
			flagy+=1;
		}
		else if(((c[1].equals("O")) || (c[1].equals("T")))&&((c[2].equals("O")) || (c[2].equals("T"))) && ((c[3].equals("O")) || (c[3].equals("T"))) && ((c[4].equals("O")) || (c[4].equals("T"))))
		{
			flagy+=1;
		}
		else if(((d[1].equals("O")) || (d[1].equals("T")))&&((d[2].equals("O")) || (d[2].equals("T"))) && ((d[3].equals("O")) || (d[3].equals("T"))) && ((d[4].equals("O")) || (d[4].equals("T"))))
		{
			flagy+=1;
		}
		else if(((a[1].equals("O")) || (a[1].equals("T")))&&((b[1].equals("O")) || (b[1].equals("T"))) && ((c[1].equals("O")) || (c[1].equals("T"))) && ((d[1].equals("O")) || (d[1].equals("T"))))
		{
			flagy+=1;
		}
		else if(((a[2].equals("O")) || (a[2].equals("T")))&&((b[2].equals("O")) || (b[2].equals("T"))) && ((c[2].equals("O")) || (c[2].equals("T"))) && ((d[2].equals("O")) || (d[2].equals("T"))))
		{
			flagy+=1;
		}
		else if(((a[3].equals("O")) || (a[3].equals("T")))&&((b[3].equals("O")) || (b[3].equals("T"))) && ((c[3].equals("O")) || (c[3].equals("T"))) && ((d[3].equals("O")) || (d[3].equals("T"))))
		{
			flagy+=1;
		}
		else if(((a[4].equals("O")) || (a[4].equals("T")))&&((b[4].equals("O")) || (b[4].equals("T"))) && ((c[4].equals("O")) || (c[4].equals("T"))) && ((d[4].equals("O")) || (d[4].equals("T"))))
		{
			flagy+=1;
		}
		else if(((a[1].equals("O")) || (a[1].equals("T")))&&((b[2].equals("O")) || (b[2].equals("T"))) && ((c[3].equals("O")) || (c[3].equals("T"))) && ((d[4].equals("O")) || (d[4].equals("T"))))
		{
			flagy+=1;
		}
		else if(((a[4].equals("O")) || (a[4].equals("T")))&&((b[3].equals("O")) || (b[3].equals("T"))) && ((c[2].equals("O")) || (c[2].equals("T"))) && ((d[1].equals("O")) || (d[1].equals("T"))))
		{
			flagy+=1;
		}
		if(flagy>0)
		{
        pw.println("Case #" + (q+1) + ": O won");
		}
		else if (flagx==0 && flagy==0)
		{
			for(int i=0;i<=4;i++)
			{
			if((a[i].equals(".")) | (b[i].equals(".")) | (c[i].equals(".")) | (d[i].equals(".")))
			{
				ntcomp+=1;
			}
		
			}
		}
		if(ntcomp>0)
		{
			pw.println("Case #" + (q+1) + ": Game has not completed");
		}
		else if(flagx==0 && flagy==0 && ntcomp==0)
		{pw.println("Case #" + (q+1) + ": Draw");
		}		
		}
	pw.close();	
	}
		
		
	}
			
	
