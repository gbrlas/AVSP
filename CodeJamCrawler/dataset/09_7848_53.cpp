import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class A {
	
	private File input = new File("/home/thiago/downloads/A-small.in");
	private File output = new File("/home/thiago/downloads/A-small.out");
	private BufferedWriter writer;
	private int caso = 1;
	private String[] palavrasValidas;
	
	public static void main(String[] args) {
		new A().init();
	}
	
	public void init() {
		
		
		try {
			/*
			 * Ler e tratar arquivo
			 */
			FileReader fileReader = new FileReader( input );
			BufferedReader reader = new BufferedReader( fileReader );
			
			String[] cabecalho = reader.readLine().split(" ");
			
			int linhas = Integer.parseInt( cabecalho[1] );
			palavrasValidas = new String[linhas];
			
			for (int i = 0; i < linhas; i++) {
				palavrasValidas[i] = reader.readLine();
			}
			
			int caracteres = Integer.parseInt( cabecalho[0] );
			linhas = Integer.parseInt( cabecalho[2] );
			
			for (int i = 0; i < linhas; i++) {
				String conteudo = reader.readLine();
				char[] letrasT = conteudo.toCharArray();
				
				char[][] letras = new char[caracteres][];
				int posicao = 0;
				int posicao2 = 0;
				boolean abriuParenteses = false;
				
				for( int j = 0; j < letrasT.length; j++ ) {
					if ( letrasT[j] == '(' ) {
						letras[posicao] = new char[ conteudo.substring( j+1 ).indexOf(')') ];
						abriuParenteses = true;
						posicao2 = 0;
					} else if ( letrasT[j] == ')' ) {
						abriuParenteses = false;
						posicao++;
					} else {
						if ( abriuParenteses ) {
							letras[posicao][posicao2++] = letrasT[j];
						} else {
							letras[posicao++] = new char[] { letrasT[j] };
						}
					}
				}
				
				write( ""+formarEContarPalavras( letras, 0, new char[ caracteres ] ) );
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
			System.out.println("Case #" + caso + ": " + linha);
			getWriter().write( "Case #" + caso++ + ": " + linha );
			getWriter().newLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public int formarEContarPalavras( char[][] letras, int atual, char[] conteudo ) {
		int result = 0;
		
		for (int j = 0; j < letras[atual].length; j++) {
			conteudo[ atual ] = letras[atual][j];
			if ( atual == letras.length-1 ) {
				for( String palavra : palavrasValidas ) {
					if ( palavra.equals( new String( conteudo ) ) ) {
						result++;
					}
				}
			} else {
				for( String palavra : palavrasValidas ) {
					if ( palavra.startsWith( new String( conteudo ).trim() ) ) {
						result += formarEContarPalavras(letras, atual+1, conteudo );
						break;
					}
				}
			}
			conteudo[ atual ] = 0;
		}
		
		return result;
	}
	
}
