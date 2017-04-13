import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Problem2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader inputStream = null;
        PrintWriter outputStream = null;

        try {
            inputStream = new BufferedReader(new FileReader("C:\\Users\\Maheshwaran\\Downloads\\CodeJam\\B-small-attempt1.in"));
            outputStream = new PrintWriter(new FileWriter("C:\\Users\\Maheshwaran\\Downloads\\CodeJam\\B-small-attempt1out.out"));

            
            String num = inputStream.readLine();
            //System.out.println("Number of test cases "+num);
           // System.out.println(num);
            for(int i=1;i<Integer.valueOf(num)+1;i++)
            {
            	String[] l1=inputStream.readLine().split(" ");
            	int a=Integer.parseInt(l1[0]);
            	int b=Integer.parseInt(l1[1]);
            	int k=Integer.parseInt(l1[2]);
            	int na=Integer.toBinaryString(a-1).length();
            	int nb=Integer.toBinaryString(b-1).length();
            	int nk=Integer.toBinaryString(k-1).length();
            	int len;
            	if(na>nb&&na>nk)
            		len=na;
            	else if(nb>nk)
            		len=nb;
            	else
            		len=nk;
            	int count=0;
            	for(int p=0;p<k;p++)
            	{
            		String bk=Integer.toBinaryString(p);
            		int bkn=bk.length();
            		while(bkn<len)
            		{
            			bk="0"+bk;
            			bkn++;
            		}
            		for(int q=0;q<a;q++)
            		{
            			String ba=Integer.toBinaryString(q);
                		int ban=ba.length();
                		while(ban<len)
                		{
                			ba="0"+ba;
                			ban++;
                		}	
                		int indexbk=0;
                		String bkcopy=new String(bk);
                		int flag=0;
                		while((indexbk=bkcopy.indexOf('1',indexbk))!=-1)
                		{
                			if(ba.charAt(indexbk)=='0')
                				{
                				flag=1;
                				break;
                				}
                			indexbk+=1;
                			//bkcopy=bkcopy.substring(indexbk+1, bkcopy.length());
                		}
                		if(flag==0)
                		{
                			for(int r=0;r<b;r++)
                			{
                				String bb=Integer.toBinaryString(r);
                        		int bbn=bb.length();
                        		while(bbn<len)
                        		{
                        			bb="0"+bb;
                        			bbn++;
                        		}	
                        		int f2=0;
                        		bkcopy=new String(bk);
                        		indexbk=0;
                        		while((indexbk=bkcopy.indexOf('1',indexbk))!=-1)
                        		{
                        			if(bb.charAt(indexbk)=='0')
                        				{
                        				f2=1;
                        				break;
                        				}
                        			indexbk+=1;
                        			//bkcopy=bkcopy.substring(indexbk+1, bkcopy.length());
                        		}
                        		if(f2==0)
                        		{
                        		int f=0;
                        		bkcopy=new String(bk);
                        		indexbk=0;
                        		while((indexbk=bkcopy.indexOf('0',indexbk))!=-1)
                        		{
                        			if(ba.charAt(indexbk)=='1'&&bb.charAt(indexbk)=='1')
                        			{
                        				f=1;
                        				break;
                        			}
                        			indexbk+=1;
                        			//bkcopy=bkcopy.substring(indexbk+1, bkcopy.length());
                        		}
                        		if(f==0)
                        			count++;
                        		}
                			}
                		}
            		}
            	}
            	System.out.println("Case #" + i + ": " +count);
            	outputStream.write("Case #" + i + ": " +count+"\n");
                
            }
            inputStream.close();
            outputStream.close();
        }
        catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
