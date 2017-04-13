import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class BotTrust {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		PrintWriter print = new PrintWriter(new FileWriter("output1.txt"));
		BufferedReader buffy = new BufferedReader(new FileReader(args[0]));
		int n = Integer.parseInt(buffy.readLine());
		
		
		for (int i = 0; i < n; i++){
			
			String sequence = buffy.readLine();
			String output = "Case #" + (i+1) + ": " + getMinSecs(sequence);
			System.out.println(output); 
		}
		
		

	}

	private static int getMinSecs(String sequence) {
		
		String buttonSeq[] = sequence.split(" ");
		
		int buttons = Integer.parseInt(buttonSeq[0]);
		
		int button_O = 1;
		int time_O = 0;
		int button_B = 1;
		int time_B = 0;
		
		for (int i = 1; i <= 2*buttons; i += 2){
			
			String nextRobot = buttonSeq[i];
			int nextButton = Integer.parseInt(buttonSeq[i + 1]);
			
			int distanceToNextButton;
			
			if (nextRobot.equals("O")){
				distanceToNextButton = Math.abs(nextButton - button_O);
				if (distanceToNextButton + time_O > time_B){
					time_O += (distanceToNextButton + 1);
				} else {
					time_O = time_B + 1;
				}
				button_O = nextButton;
			} else {
				distanceToNextButton = Math.abs(nextButton - button_B);
				if (distanceToNextButton + time_B > time_O){
					time_B += (distanceToNextButton + 1);
				} else {
					time_B = time_O + 1;
				}
				button_B = nextButton;
			}
			
		}
		
		return (time_O > time_B) ? time_O : time_B;
	}

}
