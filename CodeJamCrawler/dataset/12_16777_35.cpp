import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Runner {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Runner().run();
	}
	
	
void printHelloWorld(String x)
{
	System.out.println("Print Hello World For ," + x);
}

void run()
{
	File file = new File("input.in"); 
	    
	    Scanner input;
	    FileWriter fstream = null;
	    
		try {
			input = new Scanner(file);
		
		int numberOfTestCases = input.nextInt();
		fstream = new FileWriter("out.out");
	    BufferedWriter out = new BufferedWriter(fstream);
	    String lineOfCharacter = input.nextLine() ;
	    
	    for(int i = 0 ; i < numberOfTestCases ; i++){
	    	
	    	lineOfCharacter = input.nextLine() ;
	    	String returnedNewLine = "";
	    	
	    	for (int j = 0; j < lineOfCharacter.length(); j++) {
	    		returnedNewLine+= getMappedCharacter(lineOfCharacter.charAt(j));
			}
	    	
	    	
	    	
	    	
	    	out.write("Case #" + (i+1) +": "+ returnedNewLine +"\n");
	    }
	    
	    
	    input.close(); 
    	out.close();
    	
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	    
	  
	
}

char getMappedCharacter(char inputCharacter){
	char returnedCharacter = '#';
	switch (inputCharacter) {
	case ' ':
		returnedCharacter = ' ';
		break;
	case 'a':
		returnedCharacter = 'y';
		break;
	case 'b':
		returnedCharacter = 'h';
		break;
	case 'c':
		returnedCharacter = 'e';
		break;
	case 'd':
		returnedCharacter = 's';
		break;
	case 'e':
		returnedCharacter = 'o';
		break;
	case 'f':
		returnedCharacter = 'c';
		break;
	case 'g':
		returnedCharacter = 'v';
		break;
	case 'h':
		returnedCharacter = 'x';
		break;
	case 'i':
		returnedCharacter = 'd';
		break;
	case 'j':
		returnedCharacter = 'u';
		break;
	case 'k':
		returnedCharacter = 'i';
		break;
	case 'l':
		returnedCharacter = 'g';
		break;
	case 'm':
		returnedCharacter = 'l';
		break;
	case 'n':
		returnedCharacter = 'b';
		break;
	case 'o':
		returnedCharacter = 'k';
		break;
	case 'p':
		returnedCharacter = 'r';
		break;
	case 'q':
		returnedCharacter = 'z';
		break;
	case 'r':
		returnedCharacter = 't';
		break;
	case 's':
		returnedCharacter = 'n';
		break;
	case 't':
		returnedCharacter = 'w';
		break;
	case 'u':
		returnedCharacter = 'j';
		break;
	case 'v':
		returnedCharacter = 'p';
		break;
	case 'w':
		returnedCharacter = 'f';
		break;
	case 'x':
		returnedCharacter = 'm';
		break;
	case 'y':
		returnedCharacter = 'a';
		break;
	case 'z':
		returnedCharacter = 'q';
		break;
	default:
		break;
	}
	
	
	return returnedCharacter;

}

}
