import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.HashSet;
import java.util.Set;


public class codejam11 {
	public static char[] map;
	public static void main(String[] args) throws IOException{
		readFile();
	}

	public static Double keepTyping(double input, int total, int already){
		DecimalFormat df = new DecimalFormat("#.######");
		//return df.format(input*(total-already+1)+(1-input)*(total-already+1+total+1));
		return input*(total-already+1)+(1-input)*(total-already+1+total+1);
	}
	
	public static Double backSpace(int backTime, String[] possibilites, int total, int already){
		int posToCheck = already - backTime;
		double allRight = 1;
		for(int i=0; i<posToCheck; i++){
			double current = Double.valueOf(possibilites[i]);
			allRight = allRight * current;
		}
		double allRightEx = (backTime+(total-(already-backTime)+1))*allRight;
		//System.out.println(allRightEx+":"+allRight);
		double haveFaultEx = (1-allRight)*(total-(already-backTime)+1+backTime+total+1);
		//System.out.println(haveFaultEx);
		return allRightEx + haveFaultEx;
	}
	
	public static String getResult(int already, int total, String input){
		String[] splitResult = input.split(" ");
		double allRight = 1;
		double keeptyping;
		for(int i=0;i<splitResult.length;i++){
			double current = Double.valueOf(splitResult[i]);
			allRight = allRight * current;
		}
		keeptyping = keepTyping(allRight,total,already);
		//System.out.println(keeptyping);
		double enterRightAway = 1+total+1;
		//System.out.println(enterRightAway);
		double backspace[] = new double[already];
		double min = enterRightAway;
		for(int i = 0; i < already; i++){
			Double current = backSpace(i+1, splitResult, total, already);
			if(current<min)
				min = current;
		}
		Double comp = Math.min(enterRightAway, min);
		comp = Math.min(comp, keeptyping);
		
		DecimalFormat df = new DecimalFormat("#.000000");
		return df.format(comp);
	}
	public static void readFile() throws IOException{
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
            FileReader input = new FileReader("in.txt");
            BufferedReader bufRead = new BufferedReader(input);	
            String line = bufRead.readLine();
            int i = 1;
            while (line != null){
            	String[] splitResult = line.split(" ");
            	int already = Integer.parseInt(splitResult[0]);
            	int total = Integer.parseInt(splitResult[1]);
            	line = bufRead.readLine();
          	  	out.write("Case #" + i + ": " + getResult(already, total, line));
          	  	line = bufRead.readLine();
          	  if(line!=null)
        	  		out.write('\n');
          	  	i++;
            }             
            bufRead.close();
            out.close();
	}
}
