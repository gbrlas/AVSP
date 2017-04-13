package phase1.problemA;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MagicTrick {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		MagicTrick s = new MagicTrick();
		try {
			s.doIt();
			//s.test();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void doIt() throws Exception {
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p1\\C-large-2.in"));
		Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p1\\A-small-attempt0.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p1\\test.in"));
		
		int T = Integer.valueOf(s.nextLine());
        int cont=1;
        
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p3\\C-large-2.out"));
        Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p1\\A-small-attempt0.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p1\\test.out"));
        
        while (cont<=T) {
        	out.write("Case #"+cont+": ");
        	System.out.println("Case #"+cont);
        	String row1 = s.nextLine();
        	Set<String> line1 = verificaCarta1(s, row1);
        	
        	String row2 = s.nextLine();
        	
        	out.write(verificaCarta2(s, row2, line1));
        	out.write("\n");
        	cont++;
        }
        
        out.flush();
        out.close();
	}
	
	private String verificaCarta2(Scanner s, String row, Set<String> line1) {
		int cont = 1;
		int card = 0;
		while (cont<5) {
			String[] linha = s.nextLine().split(" ");
			if (cont==Integer.parseInt(row)) {
				if (line1.remove(linha[0])) card = new Integer(linha[0]);
				if (line1.remove(linha[1])) card = new Integer(linha[1]);
				if (line1.remove(linha[2])) card = new Integer(linha[2]);
				if (line1.remove(linha[3])) card = new Integer(linha[3]);
			}
			cont++;
		}
		
		if (line1.size()==3) {
			return String.valueOf(card);
		}
		else
		if (line1.size()<3) {
			return "Bad magician!";
		}
		else
		if (line1.size()==4) {
			return "Volunteer cheated!";
		}
		
		return "null";
	}

	private Set<String> verificaCarta1(Scanner s, String row) {
		Set<String> c1 = new HashSet<String>();
		int cont = 1;
		while (cont<5) {
			String[] linha = s.nextLine().split(" ");
			if (cont==Integer.parseInt(row)) {
				c1.add(linha[0]);
				c1.add(linha[1]);
				c1.add(linha[2]);
				c1.add(linha[3]);
			}
			cont++;
		}
		return c1;
	}
	
	
}
