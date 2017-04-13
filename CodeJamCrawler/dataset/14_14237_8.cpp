import java.io.*;
import java.util.*;
import java.math.*;
public class NewLotteryGame{
	String data_name="B-small-attempt0";
	public static void main(String[] args){
		try{
			new NewLotteryGame().go();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
	String eol=System.getProperty("line.separator");
	File input_file=new File(data_name+".in");
	File output_file=new File(data_name+".out");
	void go() throws Exception{
		Scanner scan=new Scanner(input_file);
		int T=scan.nextInt();
		String output="";
		for(int i=1;i<=T;i++){
			long A=scan.nextLong();
			long B=scan.nextLong();
			long K=scan.nextLong();
			output+="Case #"+i+": "+getSolution(A,B,K)+eol;
		}
		PrintWriter printer=new PrintWriter(new FileWriter(output_file));
		printer.write(output);
		println(output);
		printer.close();
		scan.close();
	}
	public String getSolution(long A,long B,long K){
		String sol="";
		int counter=0;
		for(long i=0;i<A;i++){
			for(long j=0;j<B;j++){
				long result=(i&j);
				if(result<K) counter++;
			}
		}
		return sol+counter;	
	}
	void println(String s){
		System.out.println(s);
	}
}
