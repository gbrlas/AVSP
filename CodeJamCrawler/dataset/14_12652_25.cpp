package phase1.problemB;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Scanner;

public class CookieClickerAlpha {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		CookieClickerAlpha s = new CookieClickerAlpha();
		try {
			s.doIt();
			//s.test();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void doIt() throws Exception {
		Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p2\\B-large.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p2\\B-small-attempt0.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p2\\test.in"));
		
		int T = Integer.valueOf(s.nextLine());
        int cont=1;
        
        Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p2\\B-large.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p2\\B-small-attempt0.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p2\\test.out"));
        
        DecimalFormatSymbols otherSymbols = new DecimalFormatSymbols();
        otherSymbols.setDecimalSeparator('.');
        
        DecimalFormat d = new DecimalFormat("###########0.0000000", otherSymbols);
        
        while (cont<=T) {
        	out.write("Case #"+cont+": ");
        	System.out.println("Case #"+cont);
        	String[] row = s.nextLine().split(" ");
        	out.write(d.format((verifica(row[0], row[1], row[2]))));
        	out.write("\n");
        	cont++;
        }
        
        out.flush();
        out.close();
	}
	
	private double verifica (String C, String F, String X) {
		double z = 0d;
		double c = Double.valueOf(C); // posso comprar uma fabrica
		double f = Double.valueOf(F); // extra cookies por segundo - inicia com 2
		double x = Double.valueOf(X); // tenho que ter pra vencer
		
		// com C posso comprar uma fábrica
		// K -> quantos segundos preciso para ter novo C? -> z+(C/2+(numero de fabricas*f)) 
		// Y -> quantos segundos preciso para ter X sem um novo C? z+(X/2+(numero de fabricas*f))
		// Y2 -> quantos segundos preciso para ter X com um novo C? z+k+(X/2+((numero de fabricas+1)*f))
		
		
		// com 0 fabricas, preciso de K segundos, Y ou Y2 segundos para alcançar X; Y2 > Y? 
		// -- não, somar Z = Z + K, somar mais uma fábrica e continuar
		// -- sim, somar Z = Z + Y -> retornar Z
		
		int fabricas = 0;
		double k=0d, y = 0d, y2=0d;
		
		do {
			z = z + k;
			k = c/(2+(fabricas*f));
			y = z+(x/(2+(fabricas*f)));
			y2 = z+k+(x/(2+((fabricas+1)*f)));
			fabricas++;
		} 
		while (y2<y);
		
		//z = z + y;
		
		return y;
	}
	
		
	
}
