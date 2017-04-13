import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
public class code3rev {
	public static void main(String[] args){
		try{
			//
			BufferedReader inStream = new BufferedReader(new FileReader("C-small-attempt3.in"));
			Scanner in = new Scanner(inStream);
			int T = in.nextInt();
			String out[] = new String[T];
			for (int i=0; i<T; i++){
				int N = in.nextInt();
				int[] Ci = new int[N];
				for (int j=0; j<N; j++){
					Ci[j] = in.nextInt();
				}
				int max=0;
				char dt[] = Integer.toBinaryString((int)(Math.pow(2,N))-1).toCharArray();
				for (int j=0; j<dt.length; j++) dt[j] = '0';
				int lbc=0,bbc=0;
				int lbr=0,bbr=0;
				for (int ii=1; ii<Math.pow(2,N)-1; ii++){
					char s[] = Integer.toBinaryString(ii).toCharArray();
					for (int ij=0; ij<s.length; ij++){
						dt[dt.length-ij-1] = s[s.length-ij-1];
					}
					lbc=0;bbc=0;
					lbr=0;bbr=0;
					for (int j=0; j<dt.length; j++){
						if (dt[j]=='0'){
							lbc ^= Ci[j];
							lbr += Ci[j];
						}else{
							bbc ^= Ci[j];
							bbr += Ci[j];
						}
					}
					if (bbr>=lbr){
						max = (lbc==bbc ? Math.max(max,bbr):max);
					}
				}
				if (max==0)	out[i] = "Case #" + (i+1) + ": NO";
				else out[i] = "Case #" + (i+1) + ": " + max;
			}
			try{
				PrintWriter outStream = new PrintWriter(new FileOutputStream("output.out"),true);
				for (int i=0; i<T; i++){
					outStream.println(out[i]);
				}
				outStream.close();
			}catch(IOException e2){}
		}catch(IOException e){}
	}
}