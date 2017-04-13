import java.io.*;
public class RA1 {




    public static void main(String[] args)throws IOException
   	{
   			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
   			PrintStream pw = new PrintStream("C:\\Documents and Settings\\Admin\\Desktop\\output1.txt");

   			int t = Integer.parseInt(br.readLine());
   			String temp[];
   			int n,pd,pg,n1=0,n2=0,l1,l2,t1,t2;
   			int a[] = {1,2,4,5,10,25,50,100};
   			int count=1;
   			while(t-->0)
   			{
   				n1 = 0;n2=0;l1=0;l2=0;t1=0;t2=0;
   				temp = br.readLine().split(" ");
   				n = Integer.parseInt(temp[0]);
   				pd = Integer.parseInt(temp[1]);
   				pg = Integer.parseInt(temp[2]);

   				boolean flag = false;

   				{

   				for(int i=1;i<=100&&!flag;i++)
   				{
   					if(i<=n&&((pd*i)%100==0))
   					{
   						//System.out.println(i);
   						for(int j=1;j<=100&&!flag;j++)
   						{
   							//System.out.println(j+" "+pg*a[j]+" "+((pg*a[j])%100==0));
   							if(((pg*j)%100==0))
   							{

								t1 = i;
								t2 = j;
   								n1 = (pd*i)/100;
   								n2 = (pg*j)/100;
   								l1 = i-n1;
   								l2 = j-n2;
   								if(i<=j&&n1<=n2&&l1<=l2)
   								{
   								flag  = true;
   								break;
   								}

   							}
   						}
   					}
   				}
   				if(flag)
   				{

   						System.out.println("Case #"+temp[0]+" "+temp[1]+" "+temp[2]+" "+count+": Possible "+t1+" "+t2);
   						pw.println("Case #"+count+": Possible");

   				}
   				else
   				{
   					System.out.println("Case #"+temp[0]+" "+temp[1]+temp[2]+" "+count+": Broken "+t1+" "+t2);
   					pw.println("Case #"+count+": Broken");
   				}
   				}
   				count++;


   			}
   			pw.flush();
   			pw.close();

    }
}
