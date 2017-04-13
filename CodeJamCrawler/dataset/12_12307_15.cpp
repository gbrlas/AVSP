import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Q1 {

	
	//ejp mysljylc kd kxveddknmc re jsicpdrysi
	//our language is impossible to understand

	
	//rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
	//there are twenty six factorial possibilities
	
	//de kr kd eoya kw aej tysr re ujdr lkgc jv
	//so it is okay if you want to just give up

	static Map<String,String> googlerese = null;
	
	static{
		googlerese = new HashMap<String,String>();
		googlerese.put("o", "k");
		googlerese.put("w", "f");
		googlerese.put("u", "j");
		googlerese.put("e", "o");
		googlerese.put("g", "v");
		googlerese.put("j", "u");
		googlerese.put("p", "r");
		googlerese.put("m", "l");
		googlerese.put("y", "a");
		googlerese.put("s", "n");
		googlerese.put("l", "g");
		googlerese.put("c", "e");
		googlerese.put("k", "i");
		googlerese.put("d", "s");
		googlerese.put("x", "m");
		googlerese.put("v", "p");
		googlerese.put("d", "s");
		googlerese.put("n", "b");
		googlerese.put("i", "d");
		googlerese.put("r", "t");
		googlerese.put("b", "h");
		googlerese.put("t", "w");
		googlerese.put("a", "y");
		googlerese.put("h", "x");
		googlerese.put("f", "c");
		googlerese.put("z", "q");
		googlerese.put("q", "z");
		
		googlerese.put(" ", " ");
		
		
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			
			//BufferedReader buf = new BufferedReader(new java.io.InputStreamReader(System.in));
			
			BufferedReader buf = new BufferedReader(new FileReader(new File("/Users/Shefali/VIKAS/Eeclipse_workspace/testproject/src/Q1Input.1.in")));
			
			int T = Integer.parseInt(buf.readLine());		
			
			
			StringBuilder strb = new StringBuilder();
			for (int i=0; i<T; i++) {
				String str = buf.readLine();
				//System.out.println(str);
				int strLength = str.length();
				for (int j = 0; j < strLength ; j++) {
					String literal = googlerese.get(""+str.charAt(j));
					//System.out.print(literal);
					if (literal !=null) {
						strb.append(literal);
					}else{
						strb.append(str.charAt(j));
					}
				}
				
				System.out.println("Case #"+(i+1)+": "+strb.toString());
				strb.delete(0, strb.length());
				
			}
		}
		catch (IOException e) {	
			e.printStackTrace();
		} 

	}
	
	
	

}
