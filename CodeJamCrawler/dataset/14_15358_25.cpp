import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class MagicTrick {

	private String folder = "/home/thiago/Downloads/";
	
	private static String BAD = "Bad magician!";
	private static String CHEATER = "Volunteer cheated!";


	public String whereTheMagicHappens( String line ) {
		
		String out = null;

		return out;
	}


	public static void main(String[] args) {
		try {
			new MagicTrick().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
		String fileName = "A-small-attempt1";
		String fileInExtension = ".in";
		String fileOutExtension = ".out";

		File fileIn = new File( folder + fileName + fileInExtension );

		FileReader reader = new FileReader(fileIn);
		BufferedReader buffer = new BufferedReader(reader);

		String line = buffer.readLine();

		int nLines = Integer.valueOf(line);

		String[] outs = new String[nLines];

		for (int i = 0; i < nLines; i++) {
			Integer optionA = Integer.parseInt(buffer.readLine())-1;
			ArrayList<Integer> lineA1 = getInts( buffer.readLine() );
			ArrayList<Integer> lineA2 = getInts( buffer.readLine() );
			ArrayList<Integer> lineA3 = getInts( buffer.readLine() );
			ArrayList<Integer> lineA4 = getInts( buffer.readLine() );
			
			Integer optionB = Integer.parseInt(buffer.readLine())-1;
			ArrayList<Integer> lineB1 = getInts( buffer.readLine() );
			ArrayList<Integer> lineB2 = getInts( buffer.readLine() );
			ArrayList<Integer> lineB3 = getInts( buffer.readLine() );
			ArrayList<Integer> lineB4 = getInts( buffer.readLine() );
			
			ArrayList<Integer>[] linesA = new ArrayList[] {lineA1, lineA2, lineA3, lineA4};
			ArrayList<Integer>[] linesB = new ArrayList[] {lineB1, lineB2, lineB3, lineB4};
			
			ArrayList<Integer> selectedA = linesA[ optionA ];
			ArrayList<Integer> selectedB = linesB[ optionB ];
			
			int s = 0;
			
			for (int a : selectedA) {
				for (int b : selectedB) {
					if ( a == b ) {
						if ( s == 0 ) {
							s = a;
						} else {
							s = -1;
						}
					}
				}
			}
			
			if ( s == 0 ) {
				outs[i] = CHEATER;
			} else if ( s >= 1 ) {
				outs[i] = ((Integer)s).toString();
			} else {
				outs[i] = BAD;
			}
		}

		buffer.close();
		reader.close();

		File fileOut = new File( folder + fileName + fileOutExtension );
		if ( !fileOut.exists() ) {
			fileOut.createNewFile();
		}

		FileWriter writer = new FileWriter(fileOut);
		BufferedWriter bufferWriter = new BufferedWriter(writer);

		for (int i = 0; i < outs.length; i++) {
			bufferWriter.write( "Case #" + (i+1) + ": " + outs[i] );
			System.out.println("Case #" + (i+1) + ": " + outs[i]);

			if ( (i+1) < outs.length ) {
				bufferWriter.newLine();
			}
		}

		bufferWriter.close();
		writer.close();
	}

	public ArrayList<Integer> getInts(String line) {
		String[] split = line.split(" ");
		ArrayList<Integer> ints = new ArrayList<>();
		for (String string : split) {
			ints.add( Integer.parseInt( string ) );
		}
		
		return ints;
	}
	
}
