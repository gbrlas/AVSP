import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BotTrust {
	
	public int solve(int[][] steps){
		int bot0 = 1;
		int time0 = 0;

		int bot1 = 1;
		int time1 = 0;
		
		int time = 0;
		
		for(int i = 0; i < steps.length; i++){
			int location = steps[i][1];
			int dif = 0;
			if(steps[i][0] == 0){
				dif = Math.abs(location-bot0);
				if(dif < Math.abs(time-time0)){
					bot0 = location;
					time++;
					time0 = time;
				}else{
					bot0 = location;
					time += dif - Math.abs(time-time0) + 1;
					time0 = time;
				}
			}else{
				dif = Math.abs(location-bot1);
				if(dif < Math.abs(time-time1)){
					bot1 = location;
					time++;
					time1 = time;
				}else{
					bot1 = location;
					time += dif - Math.abs(time-time1) + 1;
					time1 = time;
				}
			}
		}
		
		
		return time;
	}//BotTrust.solve()

	public static void main(String[] args) throws IOException{
		File file = new File("A-small-attempt1.in");
		BotTrust b = new BotTrust();
		
		BufferedReader reader = new BufferedReader(new FileReader(file));
		BufferedWriter writer = new BufferedWriter(new FileWriter("A-small-attempt1.out"));
		
		String numCasesString = reader.readLine();
		int numCases = Integer.parseInt(numCasesString);
		
		for (int i = 0; i < numCases; i++){
			int caseNumber = i + 1;
			String[] terms = reader.readLine().split(" ");
			int[][] nums = new int[(terms.length-1)/2][2];
			
			
			
			for(int j = 1; j < terms.length-1; j++){
				if(terms[j].equals("O")){
					nums[(j-1)/2][0] = 0;
				}else{
					nums[(j-1)/2][0] = 1;					
				}
				j++;
				nums[(j-1)/2][1] = Integer.parseInt(terms[j]);				
			}
			
			
			int solution = b.solve(nums);
			writer.write("Case #" + caseNumber + ": " + solution +'\n');
		}
		reader.close();
		writer.close();
	}//BotTrust.main()
}//BotTrust
