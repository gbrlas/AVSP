import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;


public class SaveUniverse {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		String input_file = "A-large.in.txt";
		BufferedReader reader = new BufferedReader(new FileReader(input_file));
		String output_file = "output.txt";
		FileOutputStream file_out = new FileOutputStream(output_file);
		
		int num_cases = Integer.parseInt(reader.readLine());
		for(int i=0; i<num_cases; i++){
			if(i == 6){
				System.out.println("investigation");
			}
			// Load the input from the file
			int num_search_engines = Integer.parseInt(reader.readLine());
			String[] search_engines = new String[num_search_engines];
			HashMap<String, ArrayList> occurence_map = new HashMap<String, ArrayList>();
			for(int j=0; j<num_search_engines; j++){
				search_engines[j] = reader.readLine();
				occurence_map.put(search_engines[j], new ArrayList()); 
			}
			int num_queries = Integer.parseInt(reader.readLine());
			String[] queries = new String[num_queries];
			for(int j=0; j<num_queries; j++){
				queries[j] = reader.readLine();
				ArrayList occurList = occurence_map.get(queries[j]);
				occurList.add(j);
			}
			// The logic
			int num_switches = 0;
			int position = 0;
			boolean done = false;
			while(!done){
				int[] position_table = new int[num_search_engines];
				for(int k=0; k<num_search_engines; k++){
					ArrayList occur_list = occurence_map.get(search_engines[k]);
					position_table[k] = findOccurenceAfterPosition(occur_list, position);
				}
				position = max(position_table);
				if(position == Integer.MAX_VALUE){
					done = true;
				}else{
					System.out.println("Switching for "+queries[position]+" "+position);
					num_switches++;
					//position++;
				}
			}
			
			// Now let's write the output to the file for this case
			String output = "Case #"+(i+1)+": "+num_switches+"\r\n";
			file_out.write(output.getBytes());
		}
		file_out.close();
	}
	
	public static int findOccurenceAfterPosition(ArrayList occur_list, int position)
	{
		for(int i=0; i<occur_list.size(); i++){
			int pos = (Integer)occur_list.get(i);
			if(pos>=position){
				return pos;
			}
		}
		return Integer.MAX_VALUE;
	}
	
	public static int max(int[] array)
	{
		int max = Integer.MIN_VALUE;
		for(int i=0; i<array.length; i++){
		   if(array[i] > max)  {
		      max = array[i];
		   }
		}
		return max;
	}

}
