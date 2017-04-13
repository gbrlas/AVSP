import java.io.*;

class TimeTable {


	public int[] getNumberOfTrains (String shA[], String shB[], int turnaroundTime) {

		int lA = shA.length;
		int lB = shB.length;
		int mA[][] = new int[shA.length][2];
		int mB[][] = new int[shB.length][2];

		for (int i=0; i<shA.length; i++) {
			String temp[] = shA[i].split (" ");
			String dep[] = temp[0].split (":");
			String rec[] = temp[1].split (":");
			mA[i][0] = Integer.parseInt (dep[0])*60 + Integer.parseInt (dep[1]);
			mA[i][1] = Integer.parseInt (rec[0])*60 + Integer.parseInt (rec[1]);
		}
		for (int i=0; i<shB.length; i++) {
			String temp[] = shB[i].split (" ");
			String dep[] = temp[0].split (":");
			String rec[] = temp[1].split (":");
			mB[i][0] = Integer.parseInt (dep[0])*60 + Integer.parseInt (dep[1]);
			mB[i][1] = Integer.parseInt (rec[0])*60 + Integer.parseInt (rec[1]);
		}

		int maxA = 0, maxB = 0;
		int currA = 0, currB = 0;
		for (int i=0; i<(24*60); i++) {

			for (int j=0; j<mB.length; j++)
				if (mB[j][1]+turnaroundTime == i)
					currA--;
			for (int j=0; j<mA.length; j++)
				if (mA[j][1]+turnaroundTime == i)
					currB--;

			for (int j=0; j<mA.length; j++) {
				if (mA[j][0] == i) {
					currA++;
					if (currA > maxA)
						maxA = currA;
					mA[j][0] = 0;
				}
			}
			for (int j=0; j<mB.length; j++) {
				if (mB[j][0] == i) {
					currB++;
					if (currB > maxB)
						maxB = currB;
					mB[j][0] = 0;
				}
			}
		}
		return new int[] {maxA,maxB};
	}

	public static void main (String args[]) throws Exception {

		TimeTable tt = new TimeTable ();

		FileReader fr = new FileReader ("B-small-attempt0.in");
		BufferedReader br = new BufferedReader (fr);

		FileWriter fw = new FileWriter ("B-small-attempt0.out");
		BufferedWriter bw = new BufferedWriter (fw);

		String line;
		line = br.readLine ();
		int noOfCases = Integer.parseInt (line);
		for (int i=0; i<noOfCases; i++) {
			StringBuffer sb = new StringBuffer ("Case #"+(i+1)+": ");
			int taTime = Integer.parseInt (br.readLine ());
			String sch = br.readLine ();
			String schAB[] = sch.split (" ");
			int noOfSchA = Integer.parseInt (schAB[0]);
			int noOfSchB = Integer.parseInt (schAB[1]);
			String schA[] = new String [noOfSchA];
			String schB[] = new String [noOfSchB];
			for (int j=0; j<noOfSchA; j++)
				schA[j] = br.readLine ();
			for (int j=0; j<noOfSchB; j++)
				schB[j] = br.readLine ();
			int noOfTrains[] = tt.getNumberOfTrains (schA,schB,taTime);
			sb.append (noOfTrains[0] + " " + noOfTrains[1]);
			bw.write (sb.toString ());
			bw.write ("\n");
		}
		br.close ();
		bw.close ();
	}
}





/*
		String shA[] = new String[] {
"09:00 09:01",
"12:00 12:02"

						"09:00 12:00",
						"10:00 13:00",
						"11:00 12:30",
						};
		String shB[] = new String[] {
						"12:02 15:00",
						"09:00 10:30"
						};
		int n[] = tt.getNumberOfTrains (shA,shB,2);
		for (int i=0; i<n.length; i++)
			System.out.println (n[i]);
*/