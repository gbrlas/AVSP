import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Messaging {
	
	public String getkeyPress(Integer P,Integer K,Integer L,List<Integer> abc){
		int keyPress=0;
		if (P*K<abc.size()){
			return "Impossible";
		}
		for (int i=0;i<abc.size();i++){
			//System.out.println(abc.get(i));
			keyPress+=abc.get(i)*((i/K)+1);
		}
		return keyPress+"";
	}

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Messaging ms = new Messaging();
		Scanner scan = new Scanner(new File("Input.txt"));
        PrintWriter pw = new PrintWriter("Output.txt");
        Integer count =new Integer(scan.nextLine());
        for (int i=0;i<count;i++){
        	String[] ins = scan.nextLine().split(" ");
        	Integer P = new Integer(ins[0]);
        	Integer K = new Integer(ins[1]);
        	Integer L = new Integer(ins[2]);
        	String[] freqs = scan.nextLine().split(" ");
        	List<Integer> abc = new ArrayList<Integer>();
        	for (String s: freqs){
        		abc.add(new Integer(s));
        	}
        	Collections.sort(abc);
        	Collections.reverse(abc);
        	
            pw.write("Case #"+(i+1)+": "+ms.getkeyPress(P, K, L, abc)+"\n");
        }
        pw.close();
        scan.close();
	}

}
