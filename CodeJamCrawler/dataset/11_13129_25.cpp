import java.io.*;
import java.util.*;
import java.math.*;

public class C {
	Scanner sc;
	PrintWriter pw ;
	public C(){
		try {
			sc = new Scanner(new File("C.in"));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("C.out"))));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public void run(){
		int t = sc.nextInt();
		for(int z =1;z <= t; z++ ){
			int n = sc.nextInt();
			long sum = 0;
			long xor = 0;
			long min = 2000000;
			for(int i=0; i < n ;i++){
				int c = sc.nextInt();
				sum += c;
				xor ^= c;
				min = Math.min(min,c);
			}
			pw.println("Case #"+z+": "+(xor==0?(sum-min):"NO"));
		}
		pw.close();
	}
	public static void main(String args[]){
		C c = new C();
		c.run();
	}
}
