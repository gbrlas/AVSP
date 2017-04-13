import java.io.*;

public final class QualificationA {
	public static String INPUT_FILE = "C:\\Users\\Jonathanasdf\\Desktop\\A-small-attempt1.in";
	/**
	 * @param args
	 * @throws IOException 
	 */
	private static String[] dict;
	
	public static void main(String[] args) throws IOException {
	// TODO Auto-generated method stub
		 File inFile  = new File(INPUT_FILE);
		 File outFile = new File("bin\\Output.txt");  
		 BufferedReader reader = new BufferedReader(new FileReader(inFile));
	     BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));

	     String result = "";
	     
	     String[] firstLine = reader.readLine().split(" ");
	     
	     int D = Integer.parseInt(firstLine[1]);
	     int N = Integer.parseInt(firstLine[2]);
	     
	     dict = new String[D];
	     
	     for (int i=0; i<D; i++) {
	    	 dict[i] = reader.readLine();
	     }
	     for (int i=1; i<=N; i++) {
	    	 result += "Case #" + i + ": " + solve(reader.readLine()) + "\r\n";
	     }
	     writer.write(result);
	     writer.newLine();
	     reader.close();  
	     writer.close(); 
	}
	
	public static int solve(String line) {
		int result = 0;
		
		line = line.replace("(", "[").replace(")", "]");
		for (int i=0; i<dict.length; i++) {
			if (dict[i].matches(line)) 
				result++;
		}
		
		return result;
	}

}
