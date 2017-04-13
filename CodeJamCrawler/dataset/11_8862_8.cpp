import java.io.*;
import java.util.Scanner;
public class caseC {
	public static void main(String[] args){
		try{
			BufferedReader inStream = new BufferedReader(new FileReader("C-small-attempt0.in"));
			Scanner in = new Scanner(inStream);
			int T = in.nextInt();
			String out[] = new String[T];
			for (int i=0; i<T; i++){
				int N = in.nextInt();
				int L = in.nextInt();
				int H = in.nextInt();
				int a[] = new int[N];
				for (int j=0; j<N; j++){
					a[j] = in.nextInt();
				}
				int f = -1;
				for (int j=L; j<=H; j++){
					int x = 0;
					for (int k=0; k<N; k++){
						if (j%a[k]==0 || a[k]%j==0) x++;
					}
					if (x==N){
						f = j;
						break;
					}
				}
				if (f>0) out[i] = "Case #" + (i+1) + ": " + f;
				else out[i] = "Case #" + (i+1) + ": NO";
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