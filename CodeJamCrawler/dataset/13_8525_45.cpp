import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class FairSquare {

	public static void main(String[] args) {
		new FairSquare();
	}

	FileInputStream openFile() throws FileNotFoundException {
		File file = new File("C-large-1.in");
		return new FileInputStream(file);
	}

	PrintStream getOuputStream() throws FileNotFoundException {
		return new PrintStream(new File("outputl.txt"));
	}

	Scanner in = null;

	ArrayList<Long> list = new ArrayList<Long>();

	FairSquare() {
		long limit = Math.round(Math.ceil(Math.sqrt(Math.pow(10, 14))));
		StringBuilder builder = new StringBuilder();
		for (long i = 1; i <= limit; i++) {
			builder.setLength(0);
			if (builder.append(i).reverse().toString()
					.equals(String.valueOf(i))) {
				builder.setLength(0);
				long square = i * i;
				if (builder.append(square).reverse().toString()
						.equals(String.valueOf(square))) {
					list.add(square);
				}
			}
		}
		PrintStream out = null;
		try {
			out = getOuputStream();
		} catch (Exception e) {
			e.printStackTrace();
		}
		String[] outputs = getOutputs();
		for (int i = 0; i < outputs.length; i++)
			out.println(outputs[i]);
	}

	String[] getOutputs() {
		String[] outputs = null;
		try {
			Scanner in = new Scanner(openFile());
			int count = in.nextInt();
			outputs = new String[count];
			for (int i = 0; i < count; i++) {
				long min = in.nextLong();
				long max = in.nextLong();
				int number = 0;
				for (int j = 0; j < list.size(); j++) {
					if (list.get(j) < min)
						continue;
					else if (list.get(j) > max)
						break;
					else
						number++;
				}
				outputs[i] = "Case #" + (i + 1) + ": " + number;
			}
			in.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return outputs;
	}
}
