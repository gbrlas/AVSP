import java.io.*;
import java.util.Scanner;
public class code1 {
	public static void main(String[] args){
		try{
			BufferedReader inStream = new BufferedReader(new FileReader("A-small-attempt0.in"));
			Scanner in = new Scanner(inStream);
			int T = in.nextInt();
			String out[] = new String[T];
			for (int i=0; i<T; i++){
				int N = in.nextInt();
				String LB[] = new String[N];
				int LW[] = new int[N];
				int CO = 1;
				int CB = 1;
				int turn = 0;
				int MO=0, MB=0;
				for (int j=0; j<N; j++){
					String w = in.next();
					int t = in.nextInt();
					int mn = (w.equals("O")? ((t>CO ? t-CO : CO-t) + 1):((t>CB ? t-CB : CB-t) + 1) );
					//System.out.print(w+mn+ " " );
					if (w.equals("O")){
						if (turn>=MO+mn){
							MO = turn + 1;
						} else {
							MO += mn;
						}
						turn = MO;
						CO = t;
					} else {
						if (turn>=MB+mn){
							MB = turn + 1;
						} else {
							MB += mn;
						}
						turn = MB;
						CB = t;
					}
					//System.out.print(LB[j] + "-" + LW[j] + " ");
				}
				//System.out.println();
				out[i] = "Case #" + (i+1) + ": " + turn;
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