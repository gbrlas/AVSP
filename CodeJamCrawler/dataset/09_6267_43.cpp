import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class WelcomeJam {
	
	private static final String str ="welcome to code jam";
	
	static String[] letter = new String[str.length()];

	public static void main(String[] args) throws IOException {
		
		
		for (int i=0; i<str.length();i++){
			letter[i]= str.substring(i,i+1);
		}
		BufferedReader r = new BufferedReader(new InputStreamReader(
				WelcomeJam.class.getResourceAsStream("/in")));
		String input = r.readLine();
		int n = Integer.valueOf(input);
		String[] inps = new String[n];
		for (int i=0;i<n;i++){
			inps[i]= r.readLine();
		}
		r.close();
		BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("out"))));
		for (int i=0;i<n;i++){
			//System.out.println("String - "+i);
			String curr = inps[i];
			Map<String,TreeSet<Integer>> map = new HashMap<String,TreeSet<Integer>>();
			for (String s: letter){
				if (!map.containsKey(s)){
					map.put(s , new TreeSet<Integer>());
				}
			}
			for (int j=0;j<curr.length();j++){
				String s = curr.substring(j,j+1);
				if (map.containsKey(s)){
					map.get(s).add(j);
				}
			}
			long result =0;
			Set<Integer> set = map.get(letter[0]);
			for (Integer p:set){
				//System.out.println("Level 0 - "+p);
				result += calculate(0,p,map);
				result = result%10000;
			}
			result = result%10000;
			String out =null;
			if (result>=1000){
				out = String.valueOf(result);
			} else if (result>=100){
				out = "0"+result;
			} else if (result>=10){
				out = "00"+result;
			} else if (result>=1){
				out = "000"+result;
			} else {
				out ="0000";
			}
			w.write("Case #"+(i+1)+": "+out+"\n");
		}
		w.close();
		
		
		
	}
	private static long calculate(int level,Integer position, Map<String,TreeSet<Integer>> map){
		long result=0;
		if (level == letter.length-1){
			//System.out.println("Encountered");
			result += 1;//(map.get(letter[level]).tailSet(position).size());
			result = result%10000;
		} else {
			Set<Integer> set = map.get(letter[level+1]).tailSet(position);
			for (Integer p:set){
				//System.out.println("Level "+(level+1)+" - "+p);
				result = result+calculate(level+1,p,map);
				result = result%10000;
			}
		}
		return result;
	}

}
