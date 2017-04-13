import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class CookieClicker {
	private static PrintWriter sortie;
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		scanner.useLocale(Locale.US);
		start();
		
	    int T = scanner.nextInt();
	    
	    for(int i = 0;i<T;++i) {
	    	double C = scanner.nextDouble();
	    	double F = scanner.nextDouble();
	    	double X = scanner.nextDouble();
	    	double speed = 2.;
	    	double result = 0;
	    	double best = Double.MAX_VALUE;

	    	while(true) {
	    		double delta = result + X/speed;
	    		
	    		if(delta < best) {
	    			best = delta;
	    			result += C / speed;
		    		speed += F;
	    		}
	    		else break;
	    	}
	    	
	    	sortie.println("Case #"+(i+1)+": "+best);
	    }
	    
	    end();
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
