import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class E {

	private File input = new File("/home/thiago/downloads/B-small-attempt2.in");
	private File output = new File("/home/thiago/downloads/B-small-attempt2.out");
	private BufferedWriter writer;
	private int caso = 1;

	public static void main(String[] args) {
		new E().init();
	}

	public void init() {

		try {
			/*
			 * Ler e tratar arquivo
			 */
			FileReader fileReader = new FileReader(input);
			BufferedReader reader = new BufferedReader(fileReader);

			int linhas = Integer.parseInt(reader.readLine());
			System.out.println(linhas + " linhas\n");
			for (int i = 0; i < linhas; i++) {
				String conteudo = reader.readLine();

				int nrAtual = Integer.parseInt(conteudo);
				int[] contagemCerta = countNros( conteudo );
				
				while( true ) {
					int[] contagemAtual = countNros( String.valueOf(++nrAtual) );
					boolean equals = true;
					for (int j = 1; j < contagemAtual.length; j++) {
						if ( contagemAtual[j] != contagemCerta[j] ) {
							equals = false;
							break;
						}
					}
					if ( equals ) {
						break;
					}
				}
				

				/*
				 * Escrever no arquivo
				 */
				write( String.valueOf( nrAtual ) );
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
		if (writer == null) {
			try {
				FileWriter fileWriter = new FileWriter(output);
				writer = new BufferedWriter(fileWriter);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return writer;
	}

	public void write(String linha) {
		try {
			System.out.println("Case #" + caso + ": " + linha);
			getWriter().write("Case #" + caso++ + ": " + linha);
			getWriter().newLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
	public int[] countNros( String nro ) {
		int[] result = new int[10];
		
		for( int i = 0; i < nro.length(); i++ ) {
			result[ Integer.parseInt( nro.substring(i, i+1) ) ]++;
		}
		
		return result;
	}

}
