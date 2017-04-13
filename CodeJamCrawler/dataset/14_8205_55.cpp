import java.util.*;
import java.io.*;
class War
{
  static double[] sort(double a[],int n)
  {int i,j;double temp;
  	for(i=0;i<n;i++)
  		for(j=0;j<n-i-1;j++)
  		{
  			if(a[j]>a[j+1])
  			{
  				temp=a[j];
  				a[j]=a[j+1];
  				a[j+1]=temp;
  			}
  		}
  		
  	return a;
  }
	public static void main(String args[])throws IOException
	{
		File f=new File("D2.in");
		Scanner sc=new Scanner(f);
		FileWriter fout=new FileWriter("out1.out");
		int test,k,i,j,N,deceive,war;
		test=sc.nextInt();
		double temp;
		double Naomi[]=new double[10];
		double Ken[]=new double[10];
		double Ken1[]=new double[10];
		for(k=1;k<=test;k++)
		{	deceive=0;war=0;
		N=sc.nextInt();
			for(i=0;i<N;i++)
				Naomi[i]=sc.nextDouble();
			for(i=0;i<N;i++)
			Ken[i]=sc.nextDouble();
			Naomi=sort(Naomi,N);
			for(i=0;i<N;i++)
			Ken1[i]=Ken[i];
			Ken=sort(Ken,N);
			Ken1=sort(Ken1,N);
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
				{
					if(Naomi[i]<Ken[j])
					{
						deceive++;
						Ken[j]=0;
						break;
					}
				}
						
			for(i=0;i<N;i++)
			{
				
				{
					for(j=0;j<N;j++)
					{if(Naomi[i]<Ken1[i])
						if(Naomi[j]>Ken1[i]&&Naomi[j]<Ken1[j])
						{//System.out.println("Hello "+i);
							temp=Naomi[i];
							Naomi[i]=Naomi[j];
							Naomi[j]=temp;
							//Naomi[j]=Ken1[j]-0.005;
						}
					}
				}
			}
		
		
			for(i=0;i<N;i++)
				
				{
					if(Naomi[i]>Ken1[i])
					{
						war++;
						
					}
				}
				
	fout.write("Case #"+k+": "+war+" "+(N-deceive)+"\n");
		}
		
	fout.close();
	}}