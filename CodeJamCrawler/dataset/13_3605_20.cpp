import java.io.*;

class FairSquareSmall
{

public static boolean checkPalin(String s) {
  int l=s.length();
  for (int i=0;i<(l/2)+1;++i)
  {
    if (s.charAt(i) != s.charAt(l-i-1))
	return false;
  }
  return true;
}

public static boolean check(int n)
{
    if (n < 0)
        return false;

    switch((int)(n & 0xF))
    {   case 0:
     	case 1:
		case 4:
		case 9:
        int n2 = (int)Math.sqrt(n);
        if(n2*n2==n)
		{  if(checkPalin(""+n2))
		   return true;
		}
		else
		return false;
          default:
          return false;
    }
}

public static void main(String[] arg)
{
BufferedReader br=null;
FileWriter output = null;
try
{
	String line;
	int i=0,j=0,n,m,cntr=0;
	br=new BufferedReader(new FileReader("C-small-attempt0.in"));
	output = new FileWriter("C-small.out");
    
	
	line=br.readLine();
	int k=Integer.parseInt(line);
	
    for(i=1;i<=k;i++)
	{
    cntr=0;	
	line=br.readLine();
	String s[]=line.split(" ");
	n=Integer.parseInt(s[0]);
	m=Integer.parseInt(s[1]);
	
	for(j=n;j<=m;j++)
	{
	if(checkPalin(""+j) && check(j))
	cntr++;
	}
	
	output.write("Case #"+i+": "+cntr+"\n");
	}		
		
output.close();	

} catch (IOException e) {
			e.printStackTrace();
		}

}
}
