import java.io.*;

class Tttwrite
{
public static void main(String[] arg)
{
BufferedReader br=null;
FileWriter output = null;
try
{
	String line;
	int i=0,j=0,p=0,q=0,cntr1=0,cntr2=0;
	boolean dot=false;
	char c1='i',c2='i';
	br=new BufferedReader(new FileReader("A-small-attempt6.in"));
	output = new FileWriter("A-small.out");
    
	
	line=br.readLine();
	int n=Integer.parseInt(line);
	char[][] ar=new char[4][4];	
	
	for(i=1;i<=n;i++)
	{dot=false;
	
	for(j=0;j<4;j++) //Getting Input cases into a 2D array
	{ line=br.readLine();
	   ar[j]=line.toCharArray();
	}line=br.readLine();
	
	
	for(p=0;p<4;p++) //Checking for the row and column equality
	 { cntr1=cntr2=0;
	   c1=c2='i';
	  for(q=0;q<3;q++)
	  { if(ar[p][q]=='.')
	    dot=true;
		
	    if((ar[p][q]==ar[p][q+1] ||  ar[p][q+1]=='T' || ar[p][q]=='T')&&ar[p][q]!='.'&&ar[p][q+1]!='.')
	    {
		 if(c1=='i' || (c1!='i' && (ar[p][q]==c1 || ar[p][q+1]==c1)))
		 {cntr1++; 	if(ar[p][q]!='T')c1=ar[p][q]; }		
		}
	
	if((ar[q][p]==ar[q+1][p] || ar[q+1][p]=='T' || ar[q][p]=='T')&&ar[q][p]!='.'&&ar[q+1][p]!='.')
		{
		 if(c2=='i' || (c2!='i' && (ar[q][p]==c2 || ar[q+1][p]==c2)))
		 {cntr2++;   if(ar[q][p]!='T')c2=ar[q][p];}
		}
	   
	   }
	   if(cntr1==3 || cntr2==3)
	   break;
	   
	 }
	 
	 if(cntr1==3)
	 {output.write("Case #"+i+": "+c1+" won\r\n");
	  continue;}
	  else 	if(cntr2==3)
	 {output.write("Case #"+i+": "+c2+" won\r\n");
	  continue;}
	  
	  cntr1=cntr2=0;
	   c1=c2='i';
	  for(p=0;p<3;p++)//checking diagnols
	  {  if((ar[p][p]==ar[p+1][p+1] || ar[p][p]=='T' || ar[p+1][p+1]=='T')&&ar[p][p]!='.'&&ar[p+1][p+1]!='.')
	     { 
		 if(c1=='i' || (c1!='i' && (ar[p][p]==c1 || ar[p+1][p+1]==c1)))
		 {cntr1++; if(ar[p][p]!='T')c1=ar[p][p]; }
		 }
		 if((ar[p][3-p]==ar[p+1][3-p-1] || ar[p][3-p]=='T' || ar[p+1][3-p-1]=='T')&&ar[p][3-p]!='.'&&ar[p+1][3-p-1]!='.')
		 {
         if(c2=='i' || (c2!='i' && (ar[p][3-p]==c2 || ar[p+1][3-p-1]==c2)))
		 {cntr2++; if(ar[p][3-p]!='T')c2=ar[p][3-p]; }
		 }
	  }
	  
	  if(cntr1==3)
	 {output.write("Case #"+i+": "+c1+" won\r\n");
	  continue;}
	  else  if(cntr2==3)
			{output.write("Case #"+i+": "+c2+" won\r\n");
			 continue;}
			 else if(dot==true)
			       output.write("Case #"+i+": Game has not completed\r\n");
				   else
				   output.write("Case #"+i+": Draw\r\n");
				   
		
		
	}output.close();	
	
} catch (IOException e) {
			e.printStackTrace();
		}

}
}
