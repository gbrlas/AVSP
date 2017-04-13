import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import com.ibm.keymanager.e.p;


public class Mousetrap {
	
	public String getOut(Integer K, List<Integer> ins){
		List<Integer> abc = new ArrayList<Integer>();
		List<Integer> out = new ArrayList<Integer>();
		for (int i=0;i<K;i++){
			abc.add(new Integer(i+1));
		}
		int pointer=0;
		for (int i=0;i<K;i++){
			 pointer=pointer+i;
			 pointer = pointer%(K-i);
			 Integer a=abc.get(pointer);
			 out.add(a);
			 abc.remove(pointer);
		}
		//System.out.print(out);
		
		StringBuffer sb = new StringBuffer();
		for (Integer i : ins){
		
			for (int j=0;j<out.size();j++){
				if (out.get(j).equals(i)){
					sb.append((j+1)+" ");
					break;
				}
			}
		}
		return sb.toString();
	}
	
	public static void main(String[] args) throws FileNotFoundException{
		Mousetrap tp = new Mousetrap();
		//tp.getOut(15, null);
		
		Scanner scan = new Scanner(new File("Input.txt"));
        PrintWriter pw = new PrintWriter("Output.txt");
        Integer count =new Integer(scan.nextLine());
        for (int i=0;i<count;i++){
        	Integer K = new Integer(scan.nextLine());
        	String abc = scan.nextLine();
        	String[] abcs=abc.split(" ");
        	List<Integer> ins = new ArrayList<Integer>();
        	for (int j=1; j<abcs.length;j++){
        		ins.add(new Integer(abcs[j]));
        		//System.out.println(ins);
        	}
        	pw.write("Case #"+(i+1)+": "+tp.getOut(K, ins)+"\n");
        }
        pw.close();
        scan.close();
	}

}
