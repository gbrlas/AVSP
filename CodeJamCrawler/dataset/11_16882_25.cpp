import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, FileNotFoundException, IOException {
		System.out.println(System.getProperty("user.dir"));
		String inputName = "input.txt";
		Magicka ta = new Magicka();
		ta.process(new BufferedReader(new FileReader(inputName)), "output.txt");
	}

}
