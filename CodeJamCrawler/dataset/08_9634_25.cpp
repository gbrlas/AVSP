import java.io.File;
import java.io.RandomAccessFile;
import java.util.HashSet;
import java.util.Set;


public class SaveUniverse {
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub

		File f1=new File("C:\\A-small-attempt2.in");
		File f2=new File("C:\\A-small.out");

		RandomAccessFile rf1=new RandomAccessFile(f1,"r");
		RandomAccessFile rf2=new RandomAccessFile(f2,"rw");

		String FileData=new String("");
		String EachLine=new String();
		EachLine=rf1.readLine();

		int caseCount=0;

		while( (EachLine=rf1.readLine()) !=null )
		{
			int sCount= Integer.parseInt(EachLine);
			Set<String> sEng = new HashSet<String>();

			for( int k=0;k<sCount;k++)
				sEng.add(rf1.readLine());
			int n=Integer.parseInt(rf1.readLine());

			int swCount=0;
			String[] q=new String[n];
			for( int j=0; j<n; j++)
			{
				q[j]=new String();
				q[j]=rf1.readLine();
			}
			int i=0;
			Set<String> s1 = new HashSet<String>();
			Set<String> s2 = new HashSet<String>();

			s1.addAll(sEng);
			for(i=0;i<n;i++)
			{
				s2.add(q[i]);
				if(s2.size()==sEng.size())
				{
					swCount++;
					if( i < n)
						i--;
					s2.clear();
				}
			}

			FileData= FileData + "Case #"+ (caseCount+1) + ": " + swCount + "\n";
			System.out.println("Case #"+ (caseCount+1) + ": " + swCount);
			caseCount++;
		}
		rf2.writeBytes(FileData);
		rf1.close();
		rf2.close();
	}

}
