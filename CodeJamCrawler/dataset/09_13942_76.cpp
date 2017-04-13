import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		System.out.println(Arrays.toString(args));
		String inputFileName = args[0];
		String outputFileName = args[1];
		
        Scanner scanner = new Scanner(new File(inputFileName));
        
        FileWriter fileWriter = new FileWriter(new File(outputFileName));
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        PrintWriter printWriter = new PrintWriter(bufferedWriter);
        
        int nTokens = scanner.nextInt();
        int nWords = scanner.nextInt();
        int nTestCases = scanner.nextInt();
        
        ArrayList<String> words = new ArrayList<String>(nWords);
        //String aWord = null;
        
        for (int i = 0 ; i < nWords ; i ++) {
            words.add(scanner.next());
        }
        System.out.println("Words: " + Arrays.toString(words.toArray()));
        
        String aTestCase = null;
        Pattern aPattern = null;
        int count = 0;
        
        for (int i = 0 ; i < nTestCases ; i ++) {
        	
        	count = 0;
        	
        	aTestCase = scanner.next();
        	System.out.println("Test case #" + (i+1) + ": " + aTestCase);
        	aPattern = convertToPattern(aTestCase);
        	
        	for (String aWord : words) {
				if ( aPattern.matcher(aWord).matches() ) {
					//System.out.println(" match: " + aWord);
					count++;
				}
			}
        	
        	System.out.println("Case #" + (i+1) + ": " + count );
        	printWriter.println("Case #" + (i+1) + ": " + count );
        	
        }
        
        printWriter.close();

    }
	
	private static Pattern convertToPattern(String testCaseString) {
		
		String regex = testCaseString.replace('(', '[').replace(')', ']');
		
		Pattern aPattern = Pattern.compile(regex);
		
		return aPattern;
		
	}

}
