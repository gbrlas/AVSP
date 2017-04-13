import java.io.*;

class SearchEngine {

	private String se[];

	public void setSearchEngine (String engine[]) {

		se = new String [engine.length];
		for (int i=0; i<engine.length; i++)
			se[i] = engine[i];		
	}

	public int countSwitches (String q[]) {

		int length = q.length;
		int count = -1;
		int index = 0;
		while (true) {
			index = getFarestEngine (index,q);
			count++;
			if (index > length - 1)
				break;
		}
		return count;
	}

	private int getFarestEngine (int index, String q[]) {

		int farMeter[] = new int [se.length];
		for (int i=0; i<farMeter.length; i++)
			farMeter[i] = q.length;

		for (int i=0; i<se.length; i++) {
			for (int j=index; j<q.length; j++)
				if (se[i].equals (q[j])) {
					farMeter[i] = j;
					break;
				}
		}
		int farest = 0;
		for (int i=0; i<se.length; i++)
			if (farMeter[i] > farest)
				farest = farMeter[i];

		return farest;
	}

	public static void main (String args[]) throws Exception {

		SearchEngine se = new SearchEngine ();

		FileReader fr = new FileReader ("A-large.in");
		BufferedReader br = new BufferedReader (fr);

		FileWriter fw = new FileWriter ("A-large.out");
		BufferedWriter bw = new BufferedWriter (fw);

		String line;
		line = br.readLine ();
		int noOfCases = Integer.parseInt (line);
		for (int i=0; i<noOfCases; i++) {
			StringBuffer sb = new StringBuffer ("Case #"+(i+1)+": ");
			int noOfEngines = Integer.parseInt (br.readLine ());
			String engine[] = new String[noOfEngines];
			for (int j=0; j<noOfEngines; j++)
				engine[j] = br.readLine ();
			se.setSearchEngine (engine);
			int noOfQElements = Integer.parseInt (br.readLine ());
			String queue[] = new String [noOfQElements];
			for (int j=0; j<noOfQElements; j++)
				queue[j] = br.readLine ();
			sb.append (se.countSwitches (queue));
			bw.write (sb.toString ());
			bw.write ("\n");
		}
		br.close ();
		bw.close ();
	}

}