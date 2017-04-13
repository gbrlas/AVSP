import java.io.*;

class C1 {

	public long keyPresses (int P, int K, int L, int f[]) {

		int np=0;
		if ((L & K) == K) {
			if (L/K > P)
				return -1;
			np = L/K;
		}
		else {
			if (L/K >= P)
				return -1;
			np = L/K + 1;
		}

		for (int i=0; i<f.length; i++)
			for (int j=0; j<f.length; j++)
				if (f[i] > f[j]) {
					int temp = f[i];
					f[i] = f[j];
					f[j] = temp;
				}
		int pr = 0;
		for (int i=0; i<f.length; i++) {
			pr += ((i/K)+1)*f[i];
		}
		System.out.println ();
		return pr;
	}

	public static void main (String args[]) throws IOException {

		C1 c1 = new C1 ();

		FileReader fr = new FileReader ("A-small-attempt0.in");
		BufferedReader br = new BufferedReader (fr);

		FileWriter fw = new FileWriter ("A-small.txt");
		BufferedWriter bw = new BufferedWriter (fw);

		String line;
		line = br.readLine ();
		int noOfLines = Integer.parseInt (line);
		for (int i=0; i<noOfLines; i++) {
			StringBuffer sb = new StringBuffer ("Case #"+(i+1)+": ");
			String line1 = br.readLine ();
			String line2 = br.readLine ();
			String spar[] = line1.split (" ");
			String sarr[] = line2.split (" ");
			int par[] = new int [3];
			int arr[] = new int [sarr.length];
			for (int j=0; j<3; j++)
				par[j] = Integer.parseInt (spar[j]);
			for (int j=0; j<sarr.length; j++)
				arr[j] = Integer.parseInt (sarr[j]);
			System.out.println ();

			long outputNumber = c1.keyPresses (par[0], par[1], par[2], arr);
			sb.append (outputNumber);
			bw.write (sb.toString ());
			bw.write ("\n");
		}
		br.close ();
		bw.close ();
	} 
}
