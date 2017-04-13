import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		try {
			File f = new File("small.txt");
			FileReader freader = new FileReader(f);
			BufferedReader read = new BufferedReader(freader);
			String line;
			read.readLine(); //read cases
			int ncase = 1;
			while((line=read.readLine())!=null){
				int nOfEngines = Integer.parseInt(line);
				ArrayList<String> engines = new ArrayList<String>();
				for(int i=0;i<nOfEngines;i++){
					engines.add(read.readLine());
				}
				line=read.readLine();
				int nOfQueries = Integer.parseInt(line);
				ArrayList<String> queries = new ArrayList<String>();
				for(int i=0;i<nOfQueries;i++){
					queries.add(read.readLine());
				}
				Main.dump(engines, queries, ncase);
				ncase++;
			}

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public static void dump(ArrayList<String> engines, ArrayList<String> queries, int ncase) throws IOException{
		//File f = new File("small.out.txt");
		//FileWriter fw = new FileWriter(f);
		//BufferedWriter writer = new BufferedWriter(fw);

		int res = process(engines, queries);
		System.out.println("Case #"+ncase+": "+res);
		//writer.close();
	}

	public static int process(ArrayList<String> engines, ArrayList<String> queries){
		int index = 0;
		int counter = -1;
		while(index>-1){
			counter++;
			Pair p = getLatest(engines, queries,index);
			index = p.index;
		}

		return counter;
	}

	public static Pair getLatest(ArrayList<String> engines, ArrayList<String> queries,int start){
		int index=-1;
		boolean found = false;
		for(int i=0;i<engines.size();i++){
			for(int j=start;j<queries.size();j++){
				if(engines.get(i).equals(queries.get(j))){
					if(j>index){
						index = j;
					}
					found = true;
					break;
				}
			}
			if(!found){
				return new Pair(-1,engines.get(i));
			}
			found = false;
		}
		return new Pair(index, queries.get(index));
	}

	private static class Pair{
		public int index;
		public String engine;
		public Pair(int index, String engine){
			this.index = index;
			this.engine = engine;
		}
	}

}
