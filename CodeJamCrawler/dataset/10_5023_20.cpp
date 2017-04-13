import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class RollerCoaster {

	static int num_tests = 0;
	static int[] result;
	
	static int num_seats = 0;
	static int num_rides = 0;
	static int num_groups = 0;
	static int num_people = 0;
	static int[] groups;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader(args[0]));
			read_data(reader);
			
			for (int i = 0; i < num_tests; i++) {
				read_test(reader);
				int index = 0;
				int start_index = 0;
				
				for (int k = 0; k < num_rides; k++) {
					int load = 0;
					while (load + groups[index] <= num_seats && load < num_people) {
						load += groups[index];
						index = (index+1) % num_groups;
					}
					result[i] += load;
				}
				
			}
			
			write_output();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	static void write_output() throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter("result_coaster.txt"));
		for (int i = 0; i < num_tests; i++) {
			writer.write("Case #"+(i+1)+": " + result[i]);
			writer.newLine();
		}
		writer.close();
	}
	
	static void read_data(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		num_tests = Integer.parseInt(line);
		result = new int[num_tests];
	}
	
	static void read_test(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		String[] tokens = line.split("\\s");
		
		num_rides = Integer.parseInt(tokens[0]);
		num_seats = Integer.parseInt(tokens[1]);
		num_groups = Integer.parseInt(tokens[2]);
		groups = new int[num_groups];
		
		line = reader.readLine();
		tokens = line.split("\\s");
		num_people = 0;
		for (int i = 0; i < num_groups; i++) {
			groups[i] = Integer.parseInt(tokens[i]);
			num_people += groups[i];
		}
	}

}
