import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;


public class Speaking_in_Tongues {

	HashMap<String, String> map ;
	
	public Speaking_in_Tongues() {
		map = new HashMap<String, String>();
		
		map.put("a", "y");
		map.put("b", "h");
		map.put("c", "e");
		map.put("d", "s");
		map.put("e", "o");
		map.put("f", "c");
		map.put("g", "v");
		map.put("h", "x");
		map.put("i", "d");
		map.put("j", "u");
		map.put("k", "i");
		map.put("l", "g");
		map.put("m", "l");
		map.put("n", "b");
		map.put("o", "k");
		map.put("p", "r");
		map.put("q", "z");
		map.put("r", "t");
		map.put("s", "n");
		map.put("t", "w");
		map.put("u", "j");
		map.put("v", "p");
		map.put("w", "f");
		map.put("x", "m");
		map.put("y", "a");
		map.put("z", "q");
		
		map.put(" ", " ");
	}
	
	public void a3mlKol7aga ()
	{
		BufferedReader in = null ;
		PrintWriter out = null ;
		
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			
			try {

					String input_line ="";
					String output_line ="";
					
					int numberOfCases = Integer.parseInt(in.readLine()); 
					for (int i =0;i<numberOfCases;i++)
					{
						output_line ="";
						input_line = in.readLine();
						System.out.println(input_line);
						for (int j=0;j<input_line.length();j++)
							{
								output_line += map.get(Character.toString(input_line.charAt(j)));
							}
						System.out.println(output_line);
						out.println("Case #"+(i+1)+": " + output_line);
					}
			
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try {
			in.close();
			out.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		
		Speaking_in_Tongues obj = new Speaking_in_Tongues();
		obj.a3mlKol7aga();
	}
}
