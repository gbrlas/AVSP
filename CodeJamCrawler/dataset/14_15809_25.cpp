import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MagicTrick {

	public static void main(String args[]) throws NumberFormatException, IOException 
	{
		BufferedReader reader = new BufferedReader(new FileReader("D:/GoogleCodeJam/ActualCodeJam/A-small-attempt0.in"));

		int countOfTestCases = Integer.parseInt(reader.readLine());
		
		BufferedWriter writer = new BufferedWriter(new FileWriter(
				"D:/GoogleCodeJam/ActualCodeJam/output.txt"));
		
		String lineFromFile = "";
		
		int count = 0;
		
		ArrayList<Integer> firstArray = new ArrayList<Integer>();
		ArrayList<Integer> secondArray = new ArrayList<Integer>();
		
		int lineNumber =0;
		
		int arrangementCount = 0;
		
		int caseNumber = 1;
		
		while((lineFromFile = reader.readLine())!=null)
		{
			//System.out.println(lineFromFile);
			if(count == 5)
			{
				count = 0;
			}
			if(count == 0)
			{
				lineNumber = Integer.parseInt(lineFromFile);
				arrangementCount++;
			}
			if((count == lineNumber ))
			{
				if(arrangementCount == 1)
				{
					firstArray.addAll(readArray(lineFromFile));
				}
				if(arrangementCount == 2)
				{
					secondArray = readArray(lineFromFile);
					
					arrangementCount=0;
				}
			}
			if(firstArray.size() !=0 && secondArray.size() != 0)
			{
				String matching = findMatching(firstArray, secondArray);
				writer.write("Case #"+(caseNumber)+": "+matching+"\n");
				firstArray.clear();
				secondArray.clear();
				System.out.println("Case #"+(caseNumber)+": "+matching+"\n");
				caseNumber++;
			}
			count++;
		}
		reader.close();
		writer.close();
	}

	private static String findMatching(ArrayList<Integer> firstArray, ArrayList<Integer> secondArray) 
	{
		String matching = null;

		for(int i =0;i<firstArray.size() ; i++)
		{
			for(int j=0;j<secondArray.size();j++)
			{
			
				if(firstArray.get(i) == secondArray.get(j))
				{
					if(matching == null )
					{
						matching = String.valueOf(secondArray.get(j));
					}
					else
					{
						matching= "Bad magician!";
					}
				}
			}
		}
		
		if(matching == null)
		{
			matching = "Volunteer cheated!";
		}
		return matching;
	}

	private static ArrayList<Integer> readArray(String lineFromFile) 
	{
		String[] ints = lineFromFile.split(" ");
		ArrayList<Integer> result = new ArrayList<Integer>();
		for (int i = 0 ; i<ints.length  ; i++)
		{
			result.add(Integer.parseInt(ints[i])); 
		}
		return result;
	}
}
