import java.io.*;
import java.util.StringTokenizer;
import java.util.Vector;

public class AlienLanguage {

    /**
         * @param args
         */
    /**
         * @param args
         */
    public static void main(String[] args) {
	// TODO Auto-generated method stub

	int L, D, N, testSpot = 0;
	Vector<String> pattern = null;
	Vector<String> testCases = null;
	Vector<Integer> result = null;
	String inputFile = "A-small-attempt0.in";

	try {
	    BufferedReader br = new BufferedReader(new FileReader(inputFile));
	    String first = br.readLine();
	    StringTokenizer st = new StringTokenizer(first);
	    L = Integer.parseInt(st.nextToken());
	    D = Integer.parseInt(st.nextToken());
	    N = Integer.parseInt(st.nextToken());
	    pattern = new Vector<String>(D);
	    testCases = new Vector<String>(N);
	    result = new Vector<Integer>(N);

	    for (int i = 0; i < D; i++) {
		pattern.add(br.readLine());
	    }

	    for (int i = 0; i < N; i++) {
		String fileLine = br.readLine();
		testCases.add("");
		result.add(0);

		while (!fileLine.isEmpty()) {
		    if (fileLine.startsWith("(")) {
			fileLine = fileLine.substring(0, 0)
				+ fileLine.substring(1);
			int spot = fileLine.indexOf(")");
			testCases
				.setElementAt(testCases.elementAt(testSpot)
					+ (fileLine.substring(0, spot)) + "#",
					testSpot);
			// String hello1 = fileLine.substring(0, spot);
			fileLine = fileLine.substring(spot + 1);
			// System.out.println("hello1: " + hello1);
			// System.out.println("fileLine: " + fileLine);
		    } else {
			testCases.setElementAt(testCases.elementAt(testSpot)
				+ "" + fileLine.charAt(0) + "#", testSpot);
			// String hello2 = "" + fileLine.charAt(0) + "";
			fileLine = fileLine.substring(0, 0)
				+ fileLine.substring(1);
			// System.out.println("hello2: " + hello2);
			// System.out.println("fileLine: " + fileLine);
		    }
		}

		testSpot++;
	    }

	    for (int i = 0; i < D; i++) {
		char[] splitPattern = pattern.elementAt(i).toCharArray();
		String[] strPattern = new String[L];
		for (int j = 0; j < L; j++)
		    strPattern[j] = "" + splitPattern[j] + "";

		for (int j = 0; j < N; j++) {
		    String fetchFromTestCases = testCases.elementAt(j);

		    String[] strTestCases = fetchFromTestCases.split("#");

		    boolean flag = true;
		    for (int k = 0; k < L; k++) {
			if (strTestCases[k].contains(strPattern[k])
				&& flag == true) {
			} else {
			    flag = false;
			    break;
			}
		    }

		    if (flag == true) {
			int res = result.elementAt(j);
			res++;
			result.setElementAt(res, j);
		    }
		}
	    }

	    br.close();
	    
	    String outputFile = inputFile.replaceAll(".in", ".out");
	    BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
	    for (int i = 0; i < N; i++) {
		bw.append("Case #" + (i + 1) + ": " + result.elementAt(i)+"\n");
		System.out.println("Case #" + (i + 1) + ": " + result.elementAt(i));
	    }
	    bw.close();

	} catch (FileNotFoundException fnfe) {
	    System.err
		    .println("File was not found Error: " + fnfe.getMessage());
	} catch (IOException ioe) {
	    System.err.println("IOException Error: " + ioe.getMessage());
	}
    }
}