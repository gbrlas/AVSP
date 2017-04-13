package phase1.problemA;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;

public class SpeakingInTongues {
    static String TO   = "abcdefghijklmnopqrstuvxywz ";
    static String FROM = "ynficwlbkuomxsevzpdrjghatq ";
    
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		SpeakingInTongues s = new SpeakingInTongues();
		try {
			s.doIt();
			//s.test();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void doIt() throws Exception {
		Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p1\\A-small-attempt0.in"));
		int T = Integer.valueOf(s.nextLine());
        int cont=1;
		
        Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p1\\A-small-attempt0.out"));
        
        while (cont<=T) {
        	out.write("Case #"+cont+": ");
        	out.write(translate(s.nextLine()));
        	out.write("\n");
        	cont++;
        }
        
        out.flush();
        out.close();
	}
	
	private String translate(String text) {
		StringBuilder t = new StringBuilder(text.length());
				
		for (int k=0; k<text.length(); k++) {
			t.append(TO.charAt(FROM.indexOf(text.charAt(k))));
		}
		
		return t.toString();
	}
	
	private void test() {
		String a = "abcde ";
		String b = "12345 ";
		
		String x = "abdc ecdab";
		String r = "";
		
		for (int k=0; k<x.length(); k++) {
			r = r + b.charAt(a.indexOf(x.charAt(k)));
		}
		System.out.println(r);
	}

}













