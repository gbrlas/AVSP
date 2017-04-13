import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class B {
	
	private File input = new File("/home/thiago/downloads/B-small.in");
	private File output = new File("/home/thiago/downloads/B-small.out");
	private BufferedWriter writer;
	
	private int caso = 1;
	
	private int[][] mapIn;
	private char[][] mapOut;
	char charAtual = 'a';
	
	public static void main(String[] args) {
		new B().init();
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
			for (int i = 0; i < linhas; i++) {
				charAtual = 'a';
				
				String conteudo = reader.readLine();

				int x = Integer.parseInt( conteudo.substring(0, conteudo.indexOf(' ') ).trim() );
				int y = Integer.parseInt( conteudo.substring( conteudo.indexOf(' ') ).trim() );
				
				mapIn  = new int[x][y];
				mapOut = new char[x][y];
				
				for (int j = 0; j < x; j++) {
					conteudo = reader.readLine();
					String[] partes = conteudo.split(" ");
					for (int k = 0; k < partes.length; k++) {
						mapIn[j][k] = Integer.parseInt( partes[k] );
					}
				}
				
				
				for (int j = 0; j < mapIn.length; j++) {
					for (int k = 0; k < mapIn[j].length; k++) {
						if ( mapOut[j][k] == ' ' ) {
							getLetraBacia( j, k );
						}
					}
				}
				
				for (int j = 0; j < mapIn.length; j++) {
					for (int k = 0; k < mapIn[j].length; k++) {
						if ( mapOut[j][k] == 0 ) {
							getLetraBacia( j, k );
						}
					}
				}
				

				/*
				 * Escrever no arquivo
				 */
				write();
				for (int j = 0; j < mapOut.length; j++) {
					String linha = "";
					for (int k = 0; k < mapOut[j].length; k++) {
						linha += mapOut[j][k] + " ";
					}
					getWriter().write( linha.trim() );
					System.out.println(linha.trim());
					getWriter().newLine();
				}
				
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
	
	public char getLetraBacia( int x, int y ) {
		char result = 0;
		
		if ( mapOut[x][y] != 0 ) {
			result = mapOut[x][y];
		} else {
			int valor = mapIn[x][y];
			
			int valorNorth = valor;
			int valorWest  = valor;
			int valorEast  = valor;
			int valorSouth = valor;
			
			if ( x != 0 ) {
				valorNorth = mapIn[x-1][y];
			} 
			if ( y != 0 ) {
				valorWest = mapIn[x][y-1];
			} 
			if ( y != (mapIn[x].length-1) ) {
				valorEast = mapIn[x][y+1];
			} 
			if ( x != (mapIn.length-1) ) {
				valorSouth = mapIn[x+1][y];
			}
			
			if ( valorNorth < valor && valorNorth <= valorEast && valorNorth <= valorWest && valorNorth <= valorSouth ) {
				result = getLetraBacia(x-1, y);
			} else if ( valorWest < valor && valorWest <= valorEast && valorWest <= valorSouth ) {
				result = getLetraBacia(x, y-1);
			} else if ( valorEast < valor && valorEast <= valorSouth ) {
				result = getLetraBacia(x, y+1);
			} else if ( valorSouth < valor ) {
				result = getLetraBacia(x+1, y);
			} else {
				result = charAtual++;
			}
			
			mapOut[x][y] = result;
		}
		
		return result;
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
	
	
	public void write() {
		try {
			System.out.println( "Case #" + caso + ": ");
			getWriter().write( "Case #" + caso++ + ": ");
			getWriter().newLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
}
