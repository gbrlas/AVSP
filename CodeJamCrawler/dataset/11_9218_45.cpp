import java.io.File;
import java.util.ArrayList;


public class Magika {

	public static void main(String [] args)
	{
		System.out.println("Magika...\n");
		
		FileHelper inputFile = new FileHelper(args[0]);
		inputFile.readFile();
		int numberOfTests = inputFile.getNumberOfTests();
		
		String outputFilename = args[1];
		File outputFile = new File(outputFilename);
		if (outputFile.exists())
		{
			outputFile.delete();
		}
		
		for (int index = 0; index < numberOfTests; index++)
		{
			Magika currentGame = new Magika(inputFile.getTest(index), index+1, outputFilename);
			
			currentGame.setupGame();
			currentGame.play();
			currentGame.finish();
		}
	}
	
	
	private String gameRules;
	private int gameNumber;
	private String outputFilename;
	private ArrayList<Character> invokeQueue = new ArrayList<Character>();
	private ArrayList<String> combinationRules = new ArrayList<String>();
	private ArrayList<Character> combinationResults = new ArrayList<Character>();
	private ArrayList<String> opposingRules = new ArrayList<String>();
	private ArrayList<Character> elementList = new ArrayList<Character>();
	
	public Magika(String gameRules, int gameNumber, String outputFilename)
	{
		this.gameRules = gameRules;
		this.gameNumber = gameNumber;
		this.outputFilename = outputFilename;
	}
	
	public void setupGame()
	{
		String[] rules = gameRules.split(" ");
		
		int numberOfCombineRules = Integer.parseInt(rules[0]);
		int numberOfOpposingRules = Integer.parseInt(rules[numberOfCombineRules + 1]);
		
		int listOffset = 1;
		// Populate combinationRules
		for (int index = 0; index < numberOfCombineRules; index++)
		{
			String combinationRule = rules[index + listOffset];
			char[] combinationChars = combinationRule.toCharArray();
			combinationRules.add("" + combinationChars[0] + combinationChars[1]);
			combinationResults.add(combinationChars[2]);
		}
		
		listOffset = numberOfCombineRules + 2;
		// Populate opposingRules
		for (int index = 0; index < numberOfOpposingRules; index++)
		{
			opposingRules.add(rules[index + listOffset]);
		}
		
		// Populate invokeQueue
		String elementString = rules[rules.length - 1];
		char[] elementChars = elementString.toCharArray();
		for (int index = 0; index < elementChars.length; index++)
		{
			invokeQueue.add(elementChars[index]);
		}
	}
	
	public void play()
	{
		while (invokeQueue.size() > 0)
		{
			char currentElement = invokeQueue.get(0);
			invokeQueue.remove(0);
			elementList.add(currentElement);
			
			findCombination();
			findOpposition();
		}
	}
	
	private void findCombination()
	{
		if (elementList.size() > 1)
		{
			char lastElement = elementList.get(elementList.size() - 2);
			char newElement = elementList.get(elementList.size() - 1);
			
			int resultA = combinationRules.indexOf("" + lastElement + newElement);
			int resultB = combinationRules.indexOf("" + newElement + lastElement);
			
			int ruleToFire = -1;
			
			if (resultA != -1)
			{
				ruleToFire = resultA;
			}
			else if (resultB != -1)
			{
				ruleToFire = resultB;
			}
			
			if (ruleToFire != -1)
			{
				elementList.remove(elementList.size() - 1);
				elementList.remove(elementList.size() - 1);
				elementList.add(combinationResults.get(ruleToFire));
			}
		}
	}
	
	private void findOpposition()
	{
		if (elementList.size() > 1)
		{
			char newElement = elementList.get(elementList.size() - 1);
			char currentElement = elementList.get(0);
			
			for (int index = 0; index < elementList.size() - 1; index++)
			{
				currentElement = elementList.get(index);
				
				int resultA = opposingRules.indexOf("" + currentElement + newElement);
				int resultB = opposingRules.indexOf("" + newElement + currentElement);
				
				if ((resultA != -1) || (resultB != -1))
				{
					elementList = new ArrayList<Character>();
				}
			}
		}
	}
	
	public void finish()
	{
		String result = "Case #" + gameNumber + ": " + elementList.toString();
		System.out.println(result);
		FileHelper output = new FileHelper(outputFilename);
		output.writeToFile(result + "\n");
		output.close();
	}
}
