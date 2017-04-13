package phase1.problemB;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;

public class Lawn {
    
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Lawn s = new Lawn();
		try {
			s.doIt();
			//s.test();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	// não posso estar cercado pelos 4 lados por numeros menores que o meu
	private void doIt() throws Exception {
		Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p2\\B-large.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p2\\B-small-attempt2.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p2\\test.in"));
		
		int T = Integer.valueOf(s.nextLine());
        int cont=1;
        
        Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p2\\B-large.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p2\\B-small-attempt2.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p2\\test.out"));
        
        while (cont<=T) {
        	out.write("Case #"+cont+": ");
        	
        	String[] values = s.nextLine().split(" ");
        	int[][] gramado = new int[Integer.parseInt(values[0])][Integer.parseInt(values[1])];
        	for (int y=0; y<gramado.length; y++) {
        		String[] alturas = s.nextLine().split(" ");
        		for (int w=0; w<alturas.length; w++) {
        			gramado[y][w] = Integer.parseInt(alturas[w]);	
        		}
        	}
        	
        	out.write(verify(gramado));
        	out.write("\n");
        	cont++;
        }
        
        out.flush();
        out.close();
	}
	
	private boolean ladosBloqueados(int[][] gramado, int linha, int col) {
		//if ((linha==0) || (col==0) || (linha==gramado.length-1) || (col==gramado[0].length-1)) return false;
		
		boolean menor1 = false;
		boolean menor2 = false;
		
		// pegar gramado[linha][], verificar todas as colunas se há algum maior
		// pegar gramado[][coluna], verifica todas as linhas se há algum maior
		// se ambos tiver algum maior, está bloqueado
		
		for (int x=0; x<gramado[linha].length; x++) {
			if (gramado[linha][x]>gramado[linha][col]) {
				menor1 = true;
				break;
			}
		}

		for (int y=0; y<gramado.length; y++) {
			if (gramado[y][col]>gramado[linha][col]) {
				menor2 = true;
				break;
			}
		}
		
		if (menor1==true && menor2==true) return true;
		
		return false;		
	}
	
	private String verify(int[][] gramado) {
		for (int linha = 0; linha < gramado.length; linha++) {
			for (int col = 0; col < gramado[0].length; col++) {
				if (ladosBloqueados(gramado, linha, col)) return "NO";
			}
		}
		
		return "YES";
	}
	
	private void test() {
		System.out.println(false && false);
		System.out.println(true && true);
		
	}

}













