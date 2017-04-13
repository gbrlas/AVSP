import java.io.*;
import java.util.ArrayList;

public final class QualificationC {
	public static String INPUT_FILE = "C:\\Users\\Jonathanasdf\\Desktop\\C-small-attempt1.in";
	/**
	 * @param args
	 * @throws IOException 
	 */
	private static ArrayList<Integer>[] chars;
	
	public static void main(String[] args) throws IOException {
	// TODO Auto-generated method stub
		 File inFile  = new File(INPUT_FILE);
		 File outFile = new File("bin\\Output.txt");  
		 BufferedReader reader = new BufferedReader(new FileReader(inFile));
	     BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
	     String line = null;
	     int lineNumber = 0;
	     String result = "";
	     reader.readLine();
	     while ((line=reader.readLine()) != null) {
	    	 lineNumber++;
	    	 result += "Case #" + lineNumber + ": " + solve(line) + "\r\n";
	     }
	     writer.write(result);
	     writer.newLine();
	     reader.close();  
	     writer.close(); 
	}
	
	public static String solve(String line) {
		int result = 0;
		chars = new ArrayList[19];
		for (int i=0; i<chars.length; i++) {
			chars[i] = new ArrayList();
		}
		for (int i=0; i<line.length(); i++) {
			switch(line.charAt(i)) {
				case 'w':
					chars[0].add(i);
					break;
				case 'e':
					chars[1].add(i);
					chars[6].add(i);
					chars[14].add(i);
					break;
				case 'l':
					chars[2].add(i);
					break;
				case 'c':
					chars[3].add(i);
					chars[11].add(i);
					break;
				case 'o':
					chars[4].add(i);
					chars[9].add(i);
					chars[12].add(i);
					break;
				case 'm':
					chars[5].add(i);
					chars[18].add(i);
					break;
				case ' ':
					chars[7].add(i);
					chars[10].add(i);
					chars[15].add(i);
					break;
				case 't':
					chars[8].add(i);
					break;
				case 'd':
					chars[13].add(i);
					break;
				case 'j':
					chars[16].add(i);
					break;
				case 'a':
					chars[17].add(i);
					break;
				default:
					break;
			}
		}
		for (int i=0; i<chars.length; i++) {
			if (chars[i].isEmpty()) {
				return "0000";
			}
		}
		for (int i=0; i<chars[0].size(); i++) {
			result += check(0, chars[0].get(i));
		}
		
		String soln = Integer.toString(result%1000);
		while(soln.length() < 4) {
			soln = "0" + soln;
		}
		return soln;
	}
	
	public static int check (int step, int index) {
		if (step == 18) {
			return 1;
		}
		int result = 0;
		for (int i=0; i<chars[step+1].size(); i++) {
			if (chars[step+1].get(i) > index) {
				result += check(step+1, chars[step+1].get(i));
			}
		}
		return result % 1000;
	}

}
