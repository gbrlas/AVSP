import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.concurrent.ConcurrentHashMap;

public class Elf {
	private static PrintWriter sortie;
	private static Scanner scanner;
	private static boolean ok = true;
	private static int result = -42;
	
	public static class Age {
		public int gen;
		public boolean tested = false;
		
		public Age(int gen) {
			this.gen = gen;
		}
		
		public Age(int gen, boolean tested) {
			this.gen = gen;
			this.tested = tested;
		}
		
	}
	
	public static void main(String[] args) {
		start();
		scanner = new Scanner(System.in);

	    int T = scanner.nextInt();
	    
	    scanner.nextLine();
	    
	   

	    for(int i = 0;i<T;++i) {
	    	Elf test = new Elf();
	    	ok = true;
	    	result = -42;
	    	
	    	int res = test.getResult();
	    	
	    	if(res == -42) sortie.println("Case #"+(i+1)+": impossible");
	    	else sortie.println("Case #"+(i+1)+": "+res);
	    }
	    
	    end();
	}

	private int getResult() {
		String str = scanner.nextLine();
		
		int num = Integer.parseInt(str.substring(0, str.indexOf('/')));
		int denom = Integer.parseInt(str.substring(str.indexOf('/')+1));
		
		if(denom != 1 && denom != 2 && denom != 4 && denom != 8 && denom != 16 && denom != 32 && denom != 64 && denom != 128 && denom != 256 && denom != 512) 
			return -42;

		test(num, denom, 1);
		
		return result;
	}

	private void test(int num, int denom, int gen) {
		int prec = denom >> 1;
		double precd = (double) prec;
		
		double frac = (double) num / (double) denom;
		
		for(int i = 0;i<=prec;++i) {
			double frac2 = (double) i / precd;
			
			for(int j = i;j<=prec;++j) {
				double frac3 = (double) j / precd;
				
				if((frac2 + frac3)/2 == frac) {
					if(j == prec || i == prec) {
						if(gen < result || result == -42)
							result = gen;
					}
					else {
						if(prec > 1) {
							test(i, prec, gen+1);
							if(j != i)
								test(j, prec, gen+1);
						}
					}
				}
			}
		}
	}

	private static void end() {
	    sortie.close();
	    try {
		    InputStream ips=new FileInputStream("C:\\Users\\Thomas\\Desktop\\output.txt"); 
			InputStreamReader ipsr=new InputStreamReader(ips);
			BufferedReader br=new BufferedReader(ipsr);
			String ligne;
			while ((ligne=br.readLine())!=null) System.out.println(ligne);
			br.close(); 
	    } catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void start() {
		try {
			sortie =  new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Thomas\\Desktop\\output.txt")));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
