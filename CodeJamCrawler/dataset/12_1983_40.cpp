import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class prob {
	private static int []chars=new int [30];
	private static TreeSet<Integer> set=new TreeSet<Integer>();
	private  static void init(){
		Arrays.fill(chars, -1);
		init1("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
		init1("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
		init1("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up");
		chars['q'-'a']='z'-'a';
		chars[25]=16;
	}
	private static void init1(String strin, String strout){
		StringTokenizer tokin=new StringTokenizer(strin);
		StringTokenizer tokout=new StringTokenizer(strout);
		while(tokin.hasMoreTokens()){
			String in=tokin.nextToken();
			String out=tokout.nextToken();
			for(int i=0; i<in.length(); i++){
				chars [in.charAt(i)-'a']=out.charAt(i)-'a';
				set.add(out.charAt(i)-'a');
			}
		}
	}
	public static void main(String args[]) throws IOException{
		init();
		PrintWriter out=new PrintWriter(new FileWriter("result.txt"));
		BufferedReader in=new BufferedReader(new FileReader("A-small-attempt0.in"));
		//BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(in.readLine());
		//System.out.println(Arrays.toString(chars));
		//System.out.println(set.toString());
		
		for(int i=1; i<=n; i++){
			String str=in.readLine();
			out.print("Case #"+i+": ");
			for(int j=0; j<str.length(); j++){
				if(str.charAt(j)==' ') out.print(" "); else
				{
					int ch='a'+chars[str.charAt(j)-'a'];
					out.print((char)ch);
				}
			}
			out.println();
		}
		out.flush();
	}
}
