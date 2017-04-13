import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;


public class BotTrust {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		ArrayList<String> lines = getInput(new File("A-small-attempt0 (1).in"));
		ArrayList<String> out = new ArrayList<String>();
		for(int i = 0; i < lines.size(); i++){
			if(i ==0)
				continue;
			out.add("Case #"+i+": "+solveSequence(new Sequence(lines.get(i))));
		}
		writeOutput(out, new File("A-small-attempt0 (1).out"));
		

	}
	
	public static int solveSequence(Sequence seq){
		int time = 0;
		Bot botO = new Bot('O');
		Bot botB = new Bot('B');
		
		while(!seq.isSolved()){
			boolean pressed = false;
			time++;
			System.out.println("time "+time);
			if(letBotDo(botO, seq))
				pressed = true;
			if(letBotDo(botB, seq))
				pressed = true;
			System.out.println("");
			if(pressed)
				seq.nextStep();
		}	
		return time;
	}
	
	public static boolean letBotDo(Bot bot, Sequence seq){
		int nextPos = seq.getPositionOfNextButtonToPress(bot.hallway);
		if(nextPos < bot.pos){
			System.out.println(bot.hallway+" Walk left"+(bot.pos-1));
			bot.pos--;
		}else if(nextPos > bot.pos){
			System.out.println(bot.hallway+" Walk right "+(bot.pos+1));
			bot.pos++;
		}else{
			if(seq.amINextToPress(bot.hallway)){
				System.out.println(bot.hallway+" press "+(bot.pos));
				return true;
			}else{
				System.out.println(bot.hallway+" stay"+(bot.pos));
			}
		}
		return false;
	}
	 class Bot {
		
		public int pos = 1;
		public char hallway;
		
		public Bot(char hallway){
			this.hallway = hallway;
		}

	}
	 
	 class Sequence {

			private int[] positions;
			private char[] hallways;
			private int currentStep = 0;
			
			public Sequence(String inputString){
				String[] parts = inputString.split(" ");
				int numberSteps = Integer.parseInt(parts[0]);
				positions = new int[numberSteps];
				hallways = new char[numberSteps];
				
				for(int i = 0; i< numberSteps; i++){
					hallways[i] = parts[1+i*2].charAt(0);
					positions[i] = Integer.parseInt(parts[1+i*2+1]);
				}
			}
			
			public int getPositionOfNextButtonToPress(char hallway){
				for(int i = currentStep; i < positions.length; i++){
					if(hallways[i]==hallway)
						return positions[i];
				}
				return -1;
			}
			
			public boolean amINextToPress(char hallway){
				return hallways[currentStep] == hallway;
			}
			public void nextStep(){
				currentStep++;
			}

			public boolean isSolved() {
				return currentStep >= positions.length;
			}
			
			
			public String toString(){
				StringBuffer buf = new StringBuffer();
				for(int i = 0; i < positions.length; i++){
					buf.append(positions[i]).append(hallways[i]).append(" ");
				}
				return buf.toString();
			}
			
		}
	 
	 public static ArrayList<String> getInput(File f) throws IOException{
			BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
			String line = null;
			ArrayList<String> result =  new ArrayList<String>();
			while((line= r.readLine()) != null){
				result.add(line);
			}
			r.close();
			return result;		
		}
		
		public static void writeOutput(ArrayList<String> output, File f) throws IOException{
			if(!f.exists())
				f.createNewFile();
			BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f)));
			for(String line: output){
				System.out.println(line);
				writer.write(line+"\n");
			}
			writer.close();
		}

}
