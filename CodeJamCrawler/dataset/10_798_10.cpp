import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GoogleCodeJam {
	private static boolean print = false;
	protected static List<String> inputData = new ArrayList<String>();
	protected static List<String> outputData = new ArrayList<String>();
	protected static String inputDataSource = "C:/Users/Lian/Desktop/A-large-practice.in";
	protected static String outputDataSource = "C:/Users/Lian/Desktop/A-large-practice.out";
	protected static final String HEADER = "Case #";
	protected static final String COLON = ":";
	protected static final String EOF = "\r\n";
	static int count = 0;
	static int loop = 1;
	public static void add(String result)
	{
		System.out.println(result);
		loop++;
		outputData.add(result);
	}
	public static int get(int i) throws Exception
	{
		return Integer.parseInt(inputData.get(i));
	}
	public static int getInt(List<String> list,int i) throws Exception
	{
		return Integer.parseInt(list.get(i));
	}

	/**
	 * @param args
	 */
//	public static void main(String[] args) throws Exception {
//		// read file
//		readFile();
//		count = count*3;
//		for(int i = 0;i<count;i = i+3)
//		{
//			
//			List<String> cases = new ArrayList<String>();
//			List<String> price;
//			for(int k = 0;k < 3; k++)
//			{
//				cases.add(inputData.get(i+k));
//			}
//			price = Arrays.asList(cases.get(2).split(" "));
//			int j;
//			int k;
//			boolean found = false;
//			for(k = 0;k < getInt(cases,1)-1 ;k++)
//			{
//				for(j = 1; j <= getInt(cases,1)-1 ; j++)
//				{
//					if((getInt(price,k)+getInt(price,j)) == (getInt(cases,0)))
//					{
//						add("Case #" + loop + ": " +  getInt(price,k) + " " + getInt(price,j) + "\n\r");
//						found = true;
//						break;
//						
//					}
//					
//				}
//				if(found)
//					break;
//			}
//			
//			
//		}
//		writeFile();
//	}

	public static void print()
	{
		print = true;
	}
	
	public static void readFile() throws Exception {
		File file = new File(inputDataSource);
		BufferedReader in = new BufferedReader(new FileReader(file));
		String temp = "";
		count = Integer.parseInt(in.readLine());
		if(print)
		{
			System.out.println("Count = " +count + EOF);
		}
			
		while ((temp = in.readLine()) != null) {
			if(print)
				System.out.println(temp);
			inputData.add(temp);
		}
		in.close();
		
	}
	
	public static void writeFile() throws Exception {
		File outputFile = new File(outputDataSource);
		if (outputFile.exists())
			outputFile.delete();
		outputFile.createNewFile();
		BufferedWriter out = new BufferedWriter(new FileWriter(outputFile));
		for (String temp : outputData) {
			out.write(temp);
		}

		out.close();
	}
}
