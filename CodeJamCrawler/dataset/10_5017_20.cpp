import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Snapper {

	static int num_tests = 0;
	
	static int[] num_snappers;
	static int[] num_snaps;
	
	static boolean[] power;
	static boolean[] on;
	// on - array in previous timestep
	static boolean[] on_previous;
	
	static boolean[] result;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader(args[0]));
			read_data(reader);
			result = new boolean[num_tests];
			
			for (int i = 0; i < num_tests; i++) {
			    power = new boolean[num_snappers[i]+1];
			    on = new boolean[num_snappers[i]];
			    on_previous = new boolean[num_snappers[i]];
			    power[0] = true;
			    
			    for (int k = 0; k < num_snappers[i]; k++) {
			    	on_previous[k] = false;
			    }
			    
			    for (int k = 0; k < num_snaps[i]; k++) {
			    	on[0] = !on_previous[0];
			    	for (int l = 1; l < num_snappers[i]; l++) {
			    		on[l] = power[l] ? !on_previous[l] : on_previous[l];
			    		power[l] = power[l-1] && on[l-1];
			    		
			    		/*if (!power[l+1]) {
			    			break;
			    		}*/
			    		
			    	}
			    	
			    	power[num_snappers[i]] = power[num_snappers[i]-1] && on[num_snappers[i]-1];
			    	boolean[] tmp = on_previous;
			    	on_previous = on;
			    	on = tmp;
			    }
			    //System.out.println("Result of test " + i + " power " + power[num_snappers[i]-1] + " on " + on[num_snappers[i]-1] + " output: " + power[num_snappers[i]]);
			    result[i] = power[num_snappers[i]];
			}
			
			write_output();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	static void write_output() throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter("result_snapper.txt"));
		for (int i = 0; i < num_tests; i++) {
			writer.write("Case #"+(i+1)+": " + (result[i] ? "ON" : "OFF" ));
			writer.newLine();
		}
		writer.close();
	}
	
	static void read_data(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		num_tests = Integer.parseInt(line);
		
		num_snappers = new int[num_tests];
		num_snaps = new int[num_tests];
		
		
		for (int i = 0; i < num_tests; i++) {
			line = reader.readLine();
			String[] tokens = line.split("\\s");
			num_snappers[i] = Integer.parseInt(tokens[0]);
			num_snaps[i] = Integer.parseInt(tokens[1]);
			//System.out.println("Num_tests: " + num_tests + " num_snappers "  + num_snappers[i] + " num_snaps " + num_snaps[i]);
		}
	}

}
