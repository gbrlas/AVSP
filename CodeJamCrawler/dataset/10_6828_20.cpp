import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;


public class ThemeParkSolutionSmall {
	private StringBuffer result = new StringBuffer();

	public static void main(String[] args) {
		try {
			ThemeParkSolutionSmall p = new ThemeParkSolutionSmall();
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
    		int R = Integer.parseInt(line.substring(0, line.indexOf(' ')));
    		int k = Integer.parseInt(line.substring(line.indexOf(' ')+1, line.lastIndexOf(' ')));
    		int N = Integer.parseInt(line.substring(line.lastIndexOf(' ')+1));
    		
            String[] groups = br.readLine().split(" ");
    		
            int index = 0;
            int contR = 0;
            int contP = 0;
            int contEuros = 0;
            
            while (contR<R){
            	int localCont=0;
            	while (true) {
            		if (index==N) index = 0;
            		if (localCont==N) break;
            		
            		int qtdG = Integer.parseInt(groups[index]);
            		
            		if (qtdG + contP > k) break;
            		contP = contP + qtdG;
            		index++;
            		localCont++;
            	}
            	
            	contEuros = contEuros + contP;
            	contP = 0;
            	contR++;
            }
            result.append("Case #" + (cont+1) + ": " + contEuros).append("\n");
        	cont++;
        }
        
        gravaArquivo(result);
        //System.out.println(result);
	}

	
	private void gravaArquivo(StringBuffer saida) throws Exception {
		File f = new File("C-small.out");  
		BufferedWriter o = new BufferedWriter(new FileWriter(f));
		o.write(saida.toString());
		o.close();
	}
	
	private BufferedReader carregaArquivo() {
		InputStream i = this.getClass().getResourceAsStream("C-small.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(i));
		return br;
	}

}
