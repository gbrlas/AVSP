import java.util.ArrayList;

public class BotTrust {

	private static FileHelper file;
	private static FileHelper outputFile;
	private static int testNumber;

	public static void main(String[] args) {
		
		file = new FileHelper(args[0]);
		file.readFile();
		outputFile = new FileHelper(args[1]);
		int numberOfTests = file.getNumberOfTests();

		for (testNumber = 0; testNumber < numberOfTests; testNumber++)
		{
			String currentTest = file.getTest(testNumber);
			BotTrust bt = new BotTrust();
			int totalTime = bt.run(currentTest);
			outputFile.writeToFile("Case #" + (testNumber+1) + ": " + totalTime + "\n");
		}
		
		outputFile.close();
	}

	private int run(String input)
	{
		String[] substrings  = input.split(" ");
		ArrayList<Instruction> instructions = new ArrayList<Instruction>(substrings.length >> 2);
		
		for (int index = 1; index < substrings.length-1; index+= 2)
		{
			int doorNumber = Integer.parseInt(substrings[index+1]);
			String botName = substrings[index];
			boolean isBotBlue = botName.equalsIgnoreCase("B");
			
			instructions.add(new Instruction(doorNumber, isBotBlue));
		}
		
		int totalTime = findTotalTime(instructions);
		
		System.out.println(input + "\n\t" + totalTime + " secs");
		
		return totalTime;
	}
	
	private int findTotalTime(ArrayList<Instruction> instructions)
	{
		int TOTAL_TIME = 0;
		
		int bluePosition = 1;
		int orangePosition = 1;
		
		boolean blueTurn;
		Instruction currentInstruction;
		Instruction nextInstruction;
		
		int currentWorkBlockTime = 0;
		int previousWorkBlockTime = 0;
		int currentPosition;
		
		for (int instructionNumber = 0; instructionNumber < instructions.size(); instructionNumber++)
		{
			currentInstruction = instructions.get(instructionNumber);
			blueTurn = currentInstruction.blue;
			currentPosition = (blueTurn) ? bluePosition : orangePosition;
			
			int additonalTimeToMove = timeToMove(currentPosition, currentInstruction.doorNumber);
			if (additonalTimeToMove > previousWorkBlockTime)
			{
				additonalTimeToMove = additonalTimeToMove - previousWorkBlockTime;
			}
			else
			{
				additonalTimeToMove = 0;
			}
			
			currentWorkBlockTime = additonalTimeToMove + 1;
			currentPosition = currentInstruction.doorNumber;
			
			while ((instructionNumber + 1 < instructions.size()) && 
					nextInstructionIsForSameBot(currentInstruction, instructions.get(instructionNumber + 1)))
			{
				nextInstruction = instructions.get(instructionNumber + 1);
				
				currentWorkBlockTime += timeToMove(currentPosition, nextInstruction.doorNumber) + 1;
				currentPosition = nextInstruction.doorNumber;
				
				instructionNumber++;
			}
			
			if (blueTurn)
			{
				bluePosition = currentPosition;
			}
			else
			{
				orangePosition = currentPosition;
			}
			
			TOTAL_TIME += currentWorkBlockTime;
			previousWorkBlockTime = currentWorkBlockTime;
		}
		
		return TOTAL_TIME;
	}
	
	private int timeToMove(int currentPosition, int endPosition)
	{
		int timeToMove = currentPosition - endPosition;
		
		if (timeToMove < 0)
		{
			timeToMove = timeToMove * -1;
		}
		
		return timeToMove;
	}
	
	private boolean nextInstructionIsForSameBot(Instruction currentInstruction, Instruction nextInstruction)
	{ 
		return (currentInstruction.blue == nextInstruction.blue);
	}
}
