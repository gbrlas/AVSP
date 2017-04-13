import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;


public class ProblemC {
	public static void main(String[] args) {
		try {
	    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	        int inputLines = Integer.parseInt(in.readLine());
	        
	        for (int i = 1, length = inputLines; i <= length; i++) {
	        	String ignore = in.readLine();
	        	String[] NaomiBlocks = in.readLine().split(" ");
	        	String[] KenBlocks = in.readLine().split(" ");
	        	
	        	int dWins = 0, Wins = 0;
	        	
	        	ArrayList<Double> kens = new ArrayList<Double>();
	        	ArrayList<Double> kens2 = new ArrayList<Double>();
	        	for (int j = 0; j < KenBlocks.length; j++) {
	        		double curBlock = Double.parseDouble(KenBlocks[j]);
	        		kens.add(curBlock);
	        		kens2.add(curBlock);
	        	}
	        	
	        	Collections.sort(kens);
	        	Collections.sort(kens2);
	        	
	        	ArrayList<Double> naomis = new ArrayList<Double>();
	        	ArrayList<Double> naomis2 = new ArrayList<Double>();
	        	for (int k = 0; k < NaomiBlocks.length; k++) {
	        		double curBlock = Double.parseDouble(NaomiBlocks[k]);
	        		naomis.add(curBlock);
	        		naomis2.add(curBlock);
	        	}
	        	
	        	Collections.sort(naomis);
	        	Collections.sort(naomis2);
	        	
	        	int nlen = naomis2.size();
	        	int n = 0;
	        	for (int m = 0; m < nlen; m++) {
	        		if (naomis2.get(m) > kens2.get(n)) {
	        			dWins++;
	        		} else {
	        			n--;
	        		}
	        		n++;
	        	}
	        	
	        	
	        	//System.out.println(naomis.toString());
	        	//System.out.println(kens.toString());
	        	
	        	int lengths = kens.size();
	        	for (int l = lengths - 1; l >= 0; l--) {
	        		if (naomis.get(l) > kens.get(l)) {
	        			Wins++;
	        			kens.remove(0);
	        		} else {
	        			kens.remove(l);
	        		}
	        		naomis.remove(l);
	        	}
	        	
	        	System.out.println("Case #" + i + ": " + dWins + " " + Wins);
	        	
	        	//System.out.println();
	        }
	    }
	    catch (IOException e) {
	    	
	    }
	}
}
