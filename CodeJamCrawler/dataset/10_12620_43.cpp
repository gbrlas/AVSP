import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


public class ThemePark {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(new File("C-small-attempt0.in"));
		BufferedWriter fo = new BufferedWriter(new FileWriter("theme.out"));
		int t = scan.nextInt();
		for(int i=0; i<t; i++){
			LinkedList list = new LinkedList();
			int r = scan.nextInt();
			int k = scan.nextInt();
			int n = scan.nextInt();
			for(int j=0; j<n; j++){
				int p = scan.nextInt();
				list.add(p);
			}
			int sum = 0;
			for(int j=0; j<r; j++){
				int total = 0;
				int count = 0;
				while(total<=k){
					total += (Integer)list.peek();
					count ++;
					if(total>k || count>n){
						total -= (Integer)list.peek();
						break;
					}
					list.add(list.pop());
				}
				sum += total;
			}
			fo.write("Case #"+(i+1)+": "+sum+"\n");
			
		}
		fo.close();
	}

}
