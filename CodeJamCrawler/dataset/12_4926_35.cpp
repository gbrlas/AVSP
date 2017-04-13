import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

/**
 * 
 * @author ysan
 *
 */

public class Problem_A_small {
	
	static HashMap<String, String> reseMap;

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt3 (1).in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A-small-output3.txt"));
		
		int cases = Integer.parseInt(in.readLine());
		
		 reseMap = new HashMap<String, String>();
         setMap();

         for (int i = 1; i <= cases; i++) {
        	 out.write("Case #"+ i +": ");
                 String cha1;

                 String text = in.readLine();
                 for (int j = 0; j < text.length(); j++) {

                         cha1 = reseMap.get(String.valueOf(text.charAt(j)));
                         out.write(cha1);
   
                 }
                 out.newLine();
         }
		in.close();
		out.close();
		
		

	}
	
	 public static void setMap() {
         reseMap.put("a", "y");
         reseMap.put("b", "h");
         reseMap.put("c", "e");
         reseMap.put("d", "s");
         reseMap.put("e", "o");
         reseMap.put("f", "c");
         reseMap.put("g", "v");
         reseMap.put("h", "x");
         reseMap.put("i", "d");
         reseMap.put("j", "u");
         reseMap.put("k", "i");
         reseMap.put("l", "g");
         reseMap.put("m", "l");
         reseMap.put("n", "b");
         reseMap.put("o", "k");
         reseMap.put("p", "r");
         reseMap.put("q", "z");
         reseMap.put("r", "t");
         reseMap.put("s", "n");
         reseMap.put("t", "w");
         reseMap.put("u", "j");
         reseMap.put("v", "p");
         reseMap.put("w", "f");
         reseMap.put("x", "m");
         reseMap.put("y", "a");
         reseMap.put("z", "q");
         reseMap.put(" ", " ");
 }
		
}
