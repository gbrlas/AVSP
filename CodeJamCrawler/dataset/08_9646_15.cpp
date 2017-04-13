import java.io.File;
import java.io.FileReader;
import java.io.RandomAccessFile;
import java.util.Arrays;
import java.util.Scanner;


public class TextMessage {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		File f1=new File("C:\\A-small.in");
		File f2=new File("C:\\A-small.out");
		RandomAccessFile rf1=new RandomAccessFile(f1,"r");
		RandomAccessFile rf2=new RandomAccessFile(f2,"rw");

		String FileData=new String("");
		String EachLine;
		EachLine=rf1.readLine();
		int caseNum=1;
		while( (EachLine=rf1.readLine()) !=null )
		{
			String[] as=EachLine.split(" ");
			int P = Integer.parseInt(as[0]);
			int K = Integer.parseInt(as[1]);
			int L = Integer.parseInt(as[2]);
			EachLine=rf1.readLine();
			
			String[] as2=EachLine.split(" ");
			int[] ltrs=new int[L];
			for(int i=0;i<L;i++)
				ltrs[i]=Integer.parseInt(as2[i]);
			Arrays.sort(ltrs);
			int n=L;
			long[][] keys = new long[K][P];
			for(int i=0;i<K;i++)
				keys[i]=new long[P];
			for(int i=0;i<P;i++)
				for(int j=0;j<K;j++)
					{
					if(n==0)
						break;
					else
						{
						keys[j][i]=ltrs[n-1];
						n--;
						}
						
					}
			long sum=0;
			for(int i=0;i<P;i++)
				for(int j=0;j<K;j++)
					sum=sum + (i+1) * keys[j][i];
			
			FileData= FileData + "Case #"+ (caseNum++) + ": " + sum +"\n";
		}
		
		rf2.writeBytes(FileData);
		rf2.close();
		rf1.close();

	}
	
}
