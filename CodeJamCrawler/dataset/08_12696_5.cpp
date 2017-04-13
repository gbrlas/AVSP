import java.util.*;
import java.io.*;


public class D {

	public static long permu(String code, int k[], int depth) {
		long result = 50000;
		if (depth==k.length) {
			return cal(code, k);
		}
		for (int i=0; i<k.length; i++) {
			boolean already= false;
			for (int j=0; j<depth; j++) {
				if (k[j]==i) already=true;
			}
			if (already==false) {
				k[depth] = i;
				long a=permu(code, k,depth+1);
				if (a<result) {
					result = a;
				}
			}
		}
		return result;
	}

	public static long cal(String code, int k[]) {
		String result="";
		for (int i=0; i<code.length(); i++){
			result = result+code.charAt(i+k[i%k.length]-i%k.length);
		}
		for (int i=0; i<k.length;i++) {
			//System.out.print(k[i]);
		}
		//System.out.println();
		//System.out.print(result);
		char prev = ' ';
		long count=0;
		for (int i=0; i<code.length(); i++) {
			if (prev!=result.charAt(i)) {
				count++;
			}
			prev = result.charAt(i);

		}
		//System.out.println(" "+count);
		return count;

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			//int kk[] = new int[4];
			//System.out.println(permu("abcabcabcabc",kk,0));
			BufferedReader br = new BufferedReader(new FileReader("d2.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("d_output.txt"));

			String s="";
			String result="";

			int num = Integer.parseInt(br.readLine());

			for (int i=0; i<num; i++) {
				int k = Integer.parseInt(br.readLine());
				String code = br.readLine();


				int kk[] = new int[k];
				result = ""+permu(code,kk,0);
				System.out.println("Case #"+(i+1)+": "+result);
				pw.println("Case #"+(i+1)+": "+result);

			}
			pw.close();
		} catch (IOException e) {
			System.out.println("io error");
		}
	}

	/*
	public static per(String code, int k) {
		long result=code.length();
		int a[] = new int [k];
		if (k==1){

			a[0] = 0;
			return cal(code,a);
		} else if (k==2) {
			a[0] = 0;
			a[1] = 1;

			result=Math.min(result,cal(code,a));
			a[0] = 1;
			a[1] = 0;
			result=Math.min(result,cal(code,a));

		} else if (k==3) {
			a[0] = 0;
			a[1] = 1;
			a[2] = 2;
			result=Math.min(result,cal(code,a));
			a[0] = 0;
			a[1] = 2;
			a[2] = 1;
			result=Math.min(result,cal(code,a));
			a[0] = 1;
			a[1] = 0; 
			a[2] = 2;
			result=Math.min(result,cal(code,a));
			a[0] = 1;
			a[1] = 2; 
			a[2] = 0;
			result=Math.min(result,cal(code,a));
			a[0] = 2;
			a[1] = 0;
			a[2] =1;
			result=Math.min(result,cal(code,a));
			a[0] =2;
			a[1] = 1;
			a[2] = 0;
			result=Math.min(result,cal(code,a));


		} else if (k==4) {

		} else if (k==5) {

		}
		return result;

	}
	*/
}
