import java.util.*;
import java.io.*;

public class Snapper {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(new File("A-small-attempt1.in"));
		BufferedWriter fo = new BufferedWriter(new FileWriter("out"));
		int t = scan.nextInt();
		for(int i=0; i<t; i++){
			int n = scan.nextInt();
			int k = scan.nextInt();
			
			if((k+1)%(1<<n) == 0)
				fo.write("Case #"+(i+1)+": ON\n");
			else fo.write("Case #"+(i+1)+": OFF\n");
		}
		fo.close();
	}

}
