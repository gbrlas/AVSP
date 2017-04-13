import java.io.*;
import java.util.regex.*;
public class pq {

	public static BufferedReader sin=new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter sout= new PrintWriter(System.out, true);
	public static int L, D, N;
	public static String pals[];
	
	public static void main(String[] args) throws Exception{
		String line=sin.readLine();
		String s[]=line.split(" ");
		L=Integer.parseInt(s[0]);
		D=Integer.parseInt(s[1]);
		N=Integer.parseInt(s[2]);
		
		pals=new String[D];
		for(int i=0; i<D; i++) pals[i]=sin.readLine();
		Pattern pattern;
		Matcher matcher;
		int salida=0;
		for(int i=0; i<N; i++){
			salida=0;
			line=sin.readLine();
			line=line.replace('(', '[');
			line=line.replace(')', ']');
			pattern =  Pattern.compile(line);
			for(int j=0; j<D; j++){
				matcher= pattern.matcher(pals[j]);
				if(matcher.find()) salida++;
			}
			sout.println("Case #" + (i+1) + ": " + salida);
		}
	}
}
