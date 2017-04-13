import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
public class code2 {
	public static void main(String[] args){
		try{
			BufferedReader inStream = new BufferedReader(new FileReader("B-large.in"));
			Scanner in = new Scanner(inStream);
			int T = in.nextInt();
			String out[] = new String[T];
			for (int i=0; i<T; i++){
				int C = in.nextInt();
				String combo[] = new String[C];
				for (int j=0; j<C; j++){
					combo[j] = in.next();
				}
				int D = in.nextInt();
				String oppose[] = new String[D];
				for (int j=0; j<D; j++){
					oppose[j] = in.next();
				}
				int N = in.nextInt();
				String element = in.next();
				char e[] = element.toCharArray();
				ArrayList<String> h = new ArrayList<String>();
				for (int j=0; j<N; j++){
					if (h.isEmpty()){
						h.add(e[j]+"");
					} else {
						boolean find = false;
						for (int ii=0; ii<C; ii++){
							char x[] = combo[ii].toCharArray();
							if ((x[0]==e[j] && h.get(h.size()-1).equals(""+x[1])) || (x[1]==e[j] && h.get(h.size()-1).equals(""+x[0]))){
								h.set(h.size()-1, x[2]+"");
								e[j] = x[2];
								find = true;
							}
						}
						for (int ii=0; ii<D; ii++){
							char x[] = oppose[ii].toCharArray();
							if ((x[0]==e[j] && h.indexOf(x[1]+"")>-1) || (x[1]==e[j] && h.indexOf(x[0]+"")>-1)){
								h.clear();
								find = true;
							}
						}
						if (!find){
							h.add(e[j]+"");
						}
					}
				}
				out[i] = "Case #" + (i+1) + ": [";
				for (int j=0; j<h.size(); j++){
					if (j>0){
						out[i] += ", ";
					}
					out[i] += h.get(j);
				}
				out[i] += "]";
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