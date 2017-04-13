import java.io.*;

class B1 {

	public long triangles (long n, long A, long B, long C, long D, long x, long y, long M) {

		long count = 0;
		long v[][] = generateVertices (n,A,B,C,D,x,y,M);
		for (int i=0; i<v.length; i++)
			System.out.println (v[i][0] +" "+v[i][1]);
		for (int i=0; i<v.length; i++) {
			for (int j=i; j<v.length; j++) {
				if (j == i)
					continue;
				for (int k=j; k<v.length; k++) {
					if ((k==i) || (k==j))
						continue;
					long xm = (v[i][0] +v[j][0] + v[k][0])%3;
					long ym = (v[i][1] +v[j][1] + v[k][1])%3;
					if ((xm==0) && (ym==0)) {
						count++;
					System.out.println ("("+i+","+j+","+k+")");
					}
				}
			}
		}
		return count;
		
	}

	private long[][] generateVertices (long n, long A, long B, long C, long D, long x, long y, long M) {

		long v[][] = new long [(int)n][2];
		v[0][0] = x;
		v[0][1] = y;

		for (int i=1; i<n; i++) {
			v[i][0] = (A*v[i-1][0] + B)%M;
			v[i][1] = (C*v[i-1][1] + D)%M;
		}
		return v;
	}

	public static void main (String args[]) throws IOException {

		B1 b1 = new B1 ();

		FileReader fr = new FileReader ("A-small-attempt0.in");
		BufferedReader br = new BufferedReader (fr);

		FileWriter fw = new FileWriter ("A-small.txt");
		BufferedWriter bw = new BufferedWriter (fw);

		String line;
		line = br.readLine ();
		int noOfLines = Integer.parseInt (line);
		for (int i=0; i<noOfLines; i++) {
			StringBuffer sb = new StringBuffer ("Case #"+(i+1)+": ");
			line = br.readLine ();
			String s[] = line.split (" ");
			long n[] = new long[8];
			for (int j=0; j<8; j++)
				n[j] = Long.parseLong (s[j]);

			long outputNumber = b1.triangles (n[0],n[1],n[2],n[3],n[4],n[5],n[6],n[7]);
			sb.append (outputNumber);
			bw.write (sb.toString ());
			bw.write ("\n");
		}
		br.close ();
		bw.close ();
	} 
}
