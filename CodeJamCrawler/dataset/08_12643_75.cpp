import java.util.*;
import java.io.*;
public class A {

	/**
	 * @param args
	 */
	public static int[] find(boolean input[][], int index, int cur) {
		int max = 0;
		int can = -1;

		for (int i=0; i<input.length; i++) {

			int imax=0;
			int j=0;
			if (i!=cur) {
				for (j=index; j<input[i].length; j++) {
					if (input[i][j]) {
						imax = j;
						j=input[i].length+2;
					}
				}
				if (j==input[i].length) {
					imax= input[i].length;
				}

				if (imax > max) {
					max = imax;
					can = i;
				}
			}
		}
		//System.out.println("can="+can);
		int result[] = new int[2];
		result[0] = max;
		result[1] = can;
		return result;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			BufferedReader br = new BufferedReader(new FileReader("a.in"));

			PrintWriter pw = new PrintWriter(new FileWriter("a_output.txt"));
			String s;
			int num = Integer.parseInt(br.readLine());

			for (int i=0; i<num; i++) {
				int p = Integer.parseInt(br.readLine());
				String ps[] = new String[p];
				for (int j=0; j<p; j++) {
					ps[j] = br.readLine();
					//System.out.println(ps[j]+" "+ps[j].length());
				}

				int q = Integer.parseInt(br.readLine());
				String qs[] = new String[q];
				for (int k=0; k<q; k++) {
					qs[k] = br.readLine();
					//System.out.println(qs[k]+" "+qs[k].length());
				}

				int result=q;
				boolean pqs[][] = new boolean[p][q];

				int pnum[] = new int[p];
				int pnummin = p;
				for (int j=0; j<p; j++) {
					pnum[j]=0;
					for (int k=0; k<q ; k++) {
						if (ps[j].equals(qs[k])) {
							pqs[j][k] = true;
							pnum[j]++;
						} else {
							pqs[j][k] = false;
						}
						//System.out.print(pqs[j][k]+" ");
					}
					//System.out.println(pnum[j]);
					if (pnum[j] < pnummin) {
						pnummin = pnum[j];
					}
				}

				if (false && pnummin==0 ) {
					result = pnummin;
				} else {
					result=0;
					int cur=-1;
					for (int j=0; j<q; j++) {
						int a[] = find(pqs,j,cur);
						int change= a[0];
						cur = a[1];
						//System.out.println(change+ " " +cur);
						if (change==q) {
							j=change;
						} else {
							j=change;

							result++;
						}

					}
				}
				System.out.println("Case #"+(i+1)+": "+result);
				pw.println("Case #"+(i+1)+": "+result);










			}
			pw.close();
		} catch (IOException e) {
			System.out.println("io error");
		}
	}

}
