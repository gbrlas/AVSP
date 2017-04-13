import java.io.*;
import java.util.*;
import java.math.*;


public class A {
	Scanner sc;
	PrintWriter pw ;
	public A(){
		try {
			sc = new Scanner(new File("A.in"));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("A.out"))));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	class Corridor implements Comparable<Corridor>{
		long start ;
		long end;
		long speed;
		long length;
		Corridor(long st,long e,long sp){
			this.start = st;
			this.end = e;
			this.length = end-start;
			this.speed = sp;
		}
		@Override
		public int compareTo(Corridor arg0) {
			return this.speed>arg0.speed? 1 : this.speed==arg0.speed? 0: -1;
		}
	}
	
	public void run(){
		int TC = sc.nextInt();
		for(int z =1;z <= TC; z++ ){
			long X = sc.nextLong();
			long S  =sc.nextLong();
			long R = sc.nextLong();
			double t = sc.nextLong();
			int n = sc.nextInt();
			Corridor[] in = new Corridor[n+1];
			long X2 = X;
			for(int i = 0; i < n;i++){
				in[i] = new Corridor(sc.nextLong(),sc.nextLong(),sc.nextLong());
				X2 -= in[i].length;
			}
			in[n] = new Corridor(0,X2,0);
			Arrays.sort(in);
			double ret = 0;
			
			for(int i = 0; i < n+1; i++){
				if(in[i].length < t * (in[i].speed + R)){
					t -= (double)in[i].length / (double)(in[i].speed+R );
					ret += (double)in[i].length / (double)(in[i].speed+R);
				}else if(t > 0){
					double len2 = t * (in[i].speed+R); 
					double len3 = in[i].length - len2;
					ret += (double)len2 /(double) (in[i].speed + R);
					ret += (double)len3 /(double) (in[i].speed + S);
					t = 0;
				}else{
					ret += (double)in[i].length / (double)(in[i].speed + S);
				}
			}
			pw.println("Case #"+z+": "+ret);
		}
		pw.close();
	}
	public static void main(String args[]){
		A t = new A();
		t.run();
	}
}
