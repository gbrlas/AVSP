package phase1.problemA;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;

public class TTT {
    
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		TTT s = new TTT();
		try {
			s.doIt();
			//s.test();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void doIt() throws Exception {
		Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p1\\A-large.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p1\\A-small-attempt0.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p1\\test.in"));
		
		int T = Integer.valueOf(s.nextLine());
        int cont=1;
        
        Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p1\\A-large.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p1\\A-small-attempt0.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p1\\test.out"));
        
        while (cont<=T) {
        	out.write("Case #"+cont+": ");
        	out.write(verify(s.nextLine(), s.nextLine(), s.nextLine(), s.nextLine()));
        	out.write("\n");
        	try{s.nextLine();} catch (Exception e){};
        	cont++;
        }
        
        out.flush();
        out.close();
	}
	
	private String verify(String l0, String l1, String l2, String l3) {
		/*
		if ((l0.indexOf('T')==-1) && (l1.indexOf('T')==-1) && (l2.indexOf('T')==-1) && (l3.indexOf('T')==-1)) {
			return "Game has not completed";
		}
		*/
		
		boolean hasPoint = false;
		hasPoint = ((l0.indexOf('.')>-1) || (l1.indexOf('.')>-1) || (l2.indexOf('.')>-1) || (l3.indexOf('.')>-1));
		
		char[][] tab = new char[4][4];
		
		tab[0] = l0.toCharArray();
		tab[1] = l1.toCharArray();
		tab[2] = l2.toCharArray();
		tab[3] = l3.toCharArray();
		
		int cO = 0;
		int cX = 0;
		int cT = 0;
		int cP = 0;
		
		for (int x = 0; x < 4; x++) {
			for (int i = 0; i < 4; i++) {
				if (tab[x][i]=='O') cO++;
				else if (tab[x][i]=='X') cX++;
				else if (tab[x][i]=='T') cT++;
				else if (tab[x][i]=='.') cP++;
			}
			
			if (cP==0) {
				if (cO==4 || (cO==3 && cT==1)) return "O won";
				if (cX==4 || (cX==3 && cT==1)) return "X won";
			}
			
			cO = 0;
			cX = 0;
			cT = 0;
			cP = 0;
		}
		
		for (int i = 0; i < 4; i++) {
			for (int x = 0; x < 4; x++) {
				if (tab[x][i]=='O') cO++;
				else if (tab[x][i]=='X') cX++;
				else if (tab[x][i]=='T') cT++;
				else if (tab[x][i]=='.') cP++;
			}
			
			if (cP==0) {
				if (cO==4 || (cO==3 && cT==1)) return "O won";
				if (cX==4 || (cX==3 && cT==1)) return "X won";
			}
			
			cO = 0;
			cX = 0;
			cT = 0;
			cP = 0;
		}
		
		for (int k=0; k<4; k++) {
			if (tab[k][k]=='O') cO++;
			else if (tab[k][k]=='X') cX++;
			else if (tab[k][k]=='T') cT++;
			else if (tab[k][k]=='.') cP++;
		}
		if (cP==0) {
			if (cO==4 || (cO==3 && cT==1)) return "O won";
			if (cX==4 || (cX==3 && cT==1)) return "X won";
		}
		
		cO = 0;
		cX = 0;
		cT = 0;
		cP = 0;

		for (int k=3; k>=0; k--) {
			if (tab[3-k][k]=='O') cO++;
			else if (tab[3-k][k]=='X') cX++;
			else if (tab[3-k][k]=='T') cT++;
			else if (tab[3-k][k]=='.') cP++;
		}
		if (cP==0) {
			if (cO==4 || (cO==3 && cT==1)) return "O won";
			if (cX==4 || (cX==3 && cT==1)) return "X won";
		}
		
		if (hasPoint) return "Game has not completed";
		
		return "Draw";
	}
	
	private void test() {
		char[][] x = new char[4][4];
		x[0] = new char[]{'X','X','O','T'};
		
		
		System.out.println(x[0].toString());
	}

}













