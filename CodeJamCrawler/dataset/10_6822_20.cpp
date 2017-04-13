import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;


public class SnapperChainSolutionSmall {
	private StringBuffer result = new StringBuffer();
	
	public static void main(String[] args) {
        try {
        	SnapperChainSolutionSmall p = new SnapperChainSolutionSmall();
        	p.doIt();
        }
        catch (Exception e) {
        	e.printStackTrace();
        }
	}

	public void doIt() throws Exception {
		BufferedReader br = this.carregaArquivo();
        int testCases = Integer.parseInt(br.readLine());
        int cont = 0;

        while (cont < testCases) {
        	String line = br.readLine();
    		int N = Integer.parseInt(line.substring(0, line.indexOf(' ')));
    		int K = Integer.parseInt(line.substring(line.indexOf(' ')+1));
    		if (K==0) {
    			result.append("Case #" + (cont+1) + ": OFF").append("\n");
    		}
    		else {
    			StringBuffer bits = mountSnapperBits(N);
    			if (isOnAfterSnappingFingers(K, bits, N-1)) {
    				result.append("Case #" + (cont+1) + ": ON").append("\n");
    			}
    			else {
    				result.append("Case #" + (cont+1) + ": OFF").append("\n");
    			}
    		}
    		
        	cont++;
        }
        
        gravaArquivo(result);
	}

	private boolean isOnAfterSnappingFingers(int snapNumber/*K*/, StringBuffer bits, int posE) {
		int newPosE = posE;
		
		while (snapNumber>0) {
		    for (int k=bits.length()-1; k>=newPosE; k--) {
		        char p = bits.charAt(k);
		        if (p=='0') {
		        	bits.setCharAt(k, '1');
		        }
		        else {
		        	bits.setCharAt(k, '0');
		        }
		    }

		    newPosE = bits.lastIndexOf("0");
		    
		    if (newPosE==-1) {
		    	newPosE=0;
		    }
		    
		    --snapNumber;
		}
		return (newPosE==0 && bits.charAt(0)=='1');
	}
	
	private StringBuffer mountSnapperBits(int N) {
		StringBuffer snappers = new StringBuffer(N);
		int count = 1;
		while (count<=N) {
			snappers.append("0");
			count++;
		}
		
		return snappers;
	}
	
	private void gravaArquivo(StringBuffer saida) throws Exception {
		File f = new File("A-small.out");  
		BufferedWriter o = new BufferedWriter(new FileWriter(f));
		o.write(saida.toString());
		o.close();
	}
	
	private BufferedReader carregaArquivo() {
		InputStream i = this.getClass().getResourceAsStream("A-small.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(i));
		return br;
	}

}





