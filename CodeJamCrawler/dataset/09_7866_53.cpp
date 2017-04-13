import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class C {
	
	private File input = new File("/home/thiago/downloads/C-small.in");
	private File output = new File("/home/thiago/downloads/C-small.out");
	private BufferedWriter writer;
	private int caso = 1;
	
	public static void main(String[] args) {
		new C().init();
	}
	
	public void init() {
		try {
			/*
			 * Ler e tratar arquivo
			 */
			FileReader fileReader = new FileReader( input );
			BufferedReader reader = new BufferedReader( fileReader );
			
			int linhas = Integer.parseInt( reader.readLine() );
			System.out.println( linhas + " linhas\n" );
			
			String procurada = "welcome to code jam";
			
			
			for (int i = 0; i < linhas; i++) {
				String conteudo = reader.readLine();

				int n = getCombinacoes(procurada, conteudo, 0, "");
				
				String valor = String.format("%1$04d", n );
				/*
				 * Escrever no arquivo
				 */
				write( valor );
			}
			
			/*
			 * Finalizar arquivo
			 */
			getWriter().flush();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	
	public BufferedWriter getWriter() {
		if ( writer == null ) {
			try {
				FileWriter fileWriter = new FileWriter( output );
				writer = new BufferedWriter( fileWriter );
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return writer;
	}
	
	
	public void write( String linha ) {
		try {
			System.out.println("Case #" + caso + ": " + linha );
			getWriter().write( "Case #" + caso++ + ": " + linha );
			getWriter().newLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public int getCombinacoes( String procurada, String conteudo, int posicao, String atual ) {
		int result = 0;
		
		for (int i = posicao; i < conteudo.length(); i++) {
			String novo = atual + conteudo.charAt( i );
			if ( novo.equals( procurada ) ) {
				result++;
			} else if ( procurada.startsWith( novo ) ) {
				result += getCombinacoes(procurada, conteudo, i+1, novo );
			}
		}
		
		return result;
	}
	
	
	
}
