import java.util.*;
import java.io.*;
public class A {

	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			BufferedReader br = new BufferedReader(new FileReader("a1.in"));

			PrintWriter pw = new PrintWriter(new FileWriter("a_output.txt"));
			
			int num = Integer.parseInt(br.readLine());
			String s;
			for (int i=0; i<num; i++) {
				s = br.readLine();
				StringTokenizer token= new StringTokenizer(s);
				int p = Integer.parseInt(token.nextToken());
				int k = Integer.parseInt(token.nextToken());
				int l = Integer.parseInt(token.nextToken());
				int ll[] = new int[l];
				s = br.readLine();
				token= new StringTokenizer(s);
				for (int j=0; j<l; j++) {
					ll[j] = Integer.parseInt(token.nextToken());
				}
				
				
				String result = "";
				if (p*k < l) {
					result = "Impossible";
				} else {
					Arrays.sort(ll);
					int count = 0;
					int incr = 1;
					int resulta=0;
					int a = l;
					while (a>0) {
						count++;
						resulta += incr*ll[a-1];
						if (count ==k) {
							count=0;
							incr++;
						}
						a--;
					}
					
					
					result += resulta;
					
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
