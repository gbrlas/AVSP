import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Cookie {

	private String folder = "/home/thiago/Downloads/";
	private String fileName = "B-large";
	private String fileInExtension = ".in";
	private String fileOutExtension = ".out";
	boolean demo = false;
	
	double perSecond = 2d;


	public String whereTheMagicHappens( String line ) {
		String[] split = line.split(" ");
		double costFarm = Double.parseDouble(split[0]);
		double addPerSecond = Double.parseDouble(split[1]);
		double needed = Double.parseDouble(split[2]);
		
		int added = 0;
		
		double time = 0;
		
		while ( true ) {
			double totalTime = needed/(perSecond+(added*addPerSecond));
			double farmTime = costFarm/(perSecond+(added*addPerSecond));
			double posFarmTime = needed/(perSecond+((added+1)*addPerSecond));
			
			if ( totalTime > (farmTime+posFarmTime) ) {
				time += farmTime;
				added++;
			} else {
				time += totalTime;
				break;
			}
			
		}


		return Double.toString(time);
	}


	public static void main(String[] args) {
		try {
			new Cookie().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
	
		File fileIn = new File( folder + fileName + fileInExtension );

		FileReader reader = new FileReader(fileIn);
		BufferedReader buffer = new BufferedReader(reader);

		String line = buffer.readLine();

		int nLines = Integer.valueOf(line);

		String[] outs = new String[nLines];

		for (int i = 0; i < nLines; i++) {
			line = buffer.readLine();
			outs[i] = whereTheMagicHappens(line);

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
			if ( demo ) {
				System.out.println( "Case #" + (i+1) + ": " + outs[i] );
			}
			if ( (i+1) < outs.length ) {
				bufferWriter.newLine();
			}
		}

		bufferWriter.close();
		writer.close();
	}

}
