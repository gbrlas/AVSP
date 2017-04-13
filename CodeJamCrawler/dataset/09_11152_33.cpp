import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Alien_Patt_Large {

	public static void main(String[] args) {
		Scanner s = null;
		PrintWriter out = null;
		try  {
			s = new Scanner(new File("A-large.in"));
			out = new PrintWriter(new FileOutputStream("A-large.out"));
		} catch (Exception e) {}
		
		int L=s.nextInt();
		int D=s.nextInt();
		int N=s.nextInt();
		
		String Dic[]=new String[D];
		
		for (int j=0;j<D;j++){
			Dic[j]=s.next();
		}
		
		for(int i=0;i<N;i++){
			String exp=s.next();
			int k=0;
			exp=exp.replace('(', '[');
			exp=exp.replace(')', ']');

		

			for(int l=0;l<D;l++){
				Pattern patron = Pattern.compile(exp) ;
		        Matcher encajador = patron.matcher(Dic[l]) ; 
				if(encajador.matches())
					k++;
		}
			
			out.println("Case #" + (i+1) + ": " + k);
			out.flush();
		}
		out.close();
			
	}
	
}


