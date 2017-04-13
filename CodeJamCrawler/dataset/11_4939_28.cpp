import java.io.*;
class CodeJamTools 

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
	
	public static int[] readIntsFromRow(String row) {
		String[] cText = row.split("\\s");
		int[] result = new int[cText.length]; 
		for (int i=0; i<cText.length; i++) {
			result[i] = new Integer(cText[i]);
		}
		return result;
	}

	public static double[] readDoublesFromRow(String row) {
		String[] cText = row.split("\\s");
		double[] result = new double[cText.length]; 
		for (int i=0; i<cText.length; i++) {
			result[i] = new Double(cText[i]);
		}
		return result;
	}
	
	public static String pilkuta(String t) {
		String res = "[";
		for (int i=0; i<t.length(); i++) {
			if (i>0)
				res += ", ";
			res += t.substring(i,i+1);
		}
		res += "]";
		return res;
	}
	
}
	