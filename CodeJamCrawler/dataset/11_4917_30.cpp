import java.io.*;
class FileHandler 

// http://snippets.dzone.com/posts/show/1335
{
	public static String readFileAsString(String filePath) {
	    byte[] buffer = new byte[(int) new File(filePath).length()];
	    BufferedInputStream f = null;
	    try {
	        f = new BufferedInputStream(new FileInputStream(filePath));
	        f.read(buffer);
	        f.close();
    	} catch (Exception e) {
    		e.printStackTrace();
    	}
	    return new String(buffer);
	}

	
	//http://www.daniweb.com/software-development/java/threads/94567
	public static void writeStringToFile(String filename, String output) {

		PrintStream fout;
		try {
			fout = new PrintStream(new FileOutputStream (filename));
			fout.print(output);		
			fout.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
	