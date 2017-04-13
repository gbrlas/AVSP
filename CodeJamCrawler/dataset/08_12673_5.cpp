import java.util.*;
import java.io.*;
public class A {

	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			BufferedReader br = new BufferedReader(new FileReader("a.in"));

			PrintWriter pw = new PrintWriter(new FileWriter("a_output.txt"));
			
			int num = Integer.parseInt(br.readLine());

			for (int i=0; i<num; i++) {
				int p = Integer.parseInt(br.readLine());
				int a[] = new int[p];
				int b[] = new int[p];
				String tempA = br.readLine();
				StringTokenizer token= new StringTokenizer(tempA);
				for (int j=0; j<p; j++) {
					a[j] = Integer.parseInt(token.nextToken());
				}
				String tempB = br.readLine();
				token= new StringTokenizer(tempB);
				for (int j=0; j<p; j++) {
					b[j] = Integer.parseInt(token.nextToken());
					
				}

				int result = 0;
				Arrays.sort(a);
				Arrays.sort(b);
				for (int j=0; j<p; j++) {
					result = result + a[j]*b[p-1-j];
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
