import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.TreeSet;


public class Magicka {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader buffy = new BufferedReader(new FileReader(args[0]));
		int t = Integer.parseInt(buffy.readLine());
		
		
		for (int i = 0; i < t; i++){
			
			String line = buffy.readLine();
			String output = "Case #" + (i+1) + ": " + getFormat(line);
			System.out.println(output); 
		}
		
		

	}

	private static String getFormat(String line) {
		String[] elements = line.split(" ");
		StringBuilder format = new StringBuilder();
		format.append("[");
		
		int c = Integer.parseInt(elements[0]);
		HashMap<String,String> combines = new HashMap<String,String>(c);
		for (int i = 1; i < c+1; i++){
			combines.put(elements[i].substring(0,2), elements[i].substring(2,3));
			combines.put(elements[i].substring(1,2) + elements[i].substring(0,1), elements[i].substring(2,3));
		}
		
		int d = Integer.parseInt(elements[c + 1]);
		HashMap<String,String> removes = new HashMap<String,String>(d);
		for (int i = c+2; i < c + d + 2; i++){
			removes.put(elements[i].substring(0,1),elements[i].substring(1,2));
			removes.put(elements[i].substring(1,2), elements[i].substring(0,1));
		}
		
		int n = Integer.parseInt(elements[c + d + 2]);
		
		String baseElements = elements[c + d + 3];
		
		

		String elementList = "";
		int listLen = 0;
		
		for (int i = 0; i < n; i++){
			String next = baseElements.substring(i,i+1);
			
			if (listLen > 0){
				/* Check combines */
				String combine = combines.get(elementList.substring(listLen-1,listLen) + next);
				if (combine != null){
					elementList = elementList.substring(0,listLen -1) + combine;
					continue;
				}
				
				String removal = removes.get(next);
				if (removal != null){
					int indexOf = elementList.indexOf(removal);
					if (indexOf != -1){
							elementList = "";
							listLen = 0;
							continue;
					}
				} 
			}
				
			
					
			elementList = elementList + next;
			listLen ++;
			
			
		}
		
		
		if (listLen == 0){
			return "[]";
		}
		
		for (int j = 0; j < listLen; j++){
			format.append(elementList.charAt(j) + ", ");
		}
		format.replace(format.length() -2, format.length() -1, "]");
		
		return format.toString();
	}

}
