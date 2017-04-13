import java.io.*;

public class Tongues {

	/**
	 * 
	 */
	public static void main(String[] args) {
		try{
			BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
			BufferedReader input = new BufferedReader(new FileReader("A-small-attempt0.in"));
			int i = 0;
			int j = Integer.parseInt(input.readLine());
			while(i < j) {
				String line = input.readLine();
				String newLine = decrypt(line);
				System.out.println(line);
				System.out.println(newLine);
				output.write("Case #" + (i+1) + ": " + newLine);
				output.newLine();
				i++;
			}
			output.close();
			input.close();
		} catch(Exception e) {System.out.println(e);}
	}
	
	private static String decrypt(String input) {
		String output = "";
		//input the cypher
		char[] cypher = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
		
		for (int i =0; i<input.length(); i++) {
			char decryptable = input.charAt(i);
			int index = (int) decryptable;
			String decrypted = "";
			
			if(index > 64 && index < 90) {
			// if upper case preserve upper caseness
				decrypted = ("" + cypher[index-65]).toUpperCase();
			} else if (index > 96 && index < 123) {
			// if lower case take directly from array
				decrypted = "" + cypher[index-97];
			} else {
			//if neither just output
				decrypted = "" + decryptable;
			}
			output = output + decrypted;
		}
		
		return output;
	}

}
