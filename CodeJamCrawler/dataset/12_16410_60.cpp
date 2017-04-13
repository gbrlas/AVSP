import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Scanner;

public class SpeakingInTongues {


	public static void main(String[] args) throws Exception {
		SpeakingInTongues speakingInTougues = new SpeakingInTongues();
		// file name
		String fileName = "speaking_in_tongues";
		
		// file variable
		File inputFile = new File(fileName + ".in");
		File outputFile = new File(fileName + ".out");
		Scanner scanner = new Scanner(inputFile);
		FileWriter writer = new FileWriter(outputFile);


		// problem variable
		int totalCase;
	
		// get total case
		totalCase = Integer.parseInt(scanner.nextLine());
		System.out.println("Total case:"+totalCase);
		
		HashMap< String, String> dictionaryMap = speakingInTougues.constructDataDictionary();
		
		for (int caseIndex = 1; caseIndex <= totalCase; caseIndex++) {

			String lineDetail = scanner.nextLine();
			String googlerereseString = "";
			googlerereseString = speakingInTougues.translateToGooglerese(lineDetail, dictionaryMap);
			
			
			String output = "Case #" + caseIndex + ": " + googlerereseString;		
			System.out.println(output);
			//System.out.println("Line Detail:"+lineDetail);
			writer.write(output + "\n");
		}
		scanner.close();
		writer.close();
	}
	
	private HashMap<String, String> constructDataDictionary(){
		HashMap<String, String> dataMap = new HashMap<String, String>();
		dataMap.put("a", "y");
		dataMap.put("b", "h");
		dataMap.put("c", "e");
		dataMap.put("d", "s");
		dataMap.put("e", "o");
		dataMap.put("f", "c");
		dataMap.put("g", "v");
		dataMap.put("h", "x");
		dataMap.put("i", "d");
		dataMap.put("j", "u");
		dataMap.put("k", "i");
		dataMap.put("l", "g");
		dataMap.put("m", "l");
		dataMap.put("n", "b");
		dataMap.put("o", "k");
		dataMap.put("p", "r");
		dataMap.put("q", "z");
		dataMap.put("r", "t");
		dataMap.put("s", "n");
		dataMap.put("t", "w");
		dataMap.put("u", "j");
		dataMap.put("v", "p");
		dataMap.put("w", "f");
		dataMap.put("x", "m");
		dataMap.put("y", "a");
		dataMap.put("z", "q");
		dataMap.put(" ", " ");
		
		return dataMap;
	}
	
	private String translateToGooglerese(String englishText, HashMap<String, String> dataDict)
	{
		String googlereseText = "";
		char []charArrInput = englishText.toCharArray();
		
		if( (charArrInput!=null) && (charArrInput.length > 0))
		{
			for(int i=0; i<charArrInput.length; i++)
			{
				String chInput = ""+charArrInput[i];
				String chOutput = dataDict.get(chInput);
				googlereseText += chOutput;	
			}
		}
		
		return googlereseText;
	}
	

}

