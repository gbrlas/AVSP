import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class SearchUniverse {
	public int getMin(String[] engines, String[] queries){
		
		List<String> engs = new ArrayList<String>(Arrays.asList(engines));
		int index=0;
		int switches=0;
		
		while (index<queries.length){
			engs.remove(queries[index]);
			if (engs.size()==0){
				switches++;
				engs= new ArrayList<String>(Arrays.asList(engines));
				engs.remove(queries[index]);
			}
			index++;
		}
		
		
		return switches;
	}
	
	public static void main(String[] args) throws FileNotFoundException{
		SearchUniverse su = new SearchUniverse();
		/*System.out.println(su.getMin(new String[]{"Yeehaw",
				"NSM",
				"Dont Ask",
				"B9",
				"Googol"}, new String[]{
				"Yeehaw",
				"Yeehaw",
				"Googol",
				"B9",
				"Googol",
				"NSM",
				"B9",
				"NSM",
				"Dont Ask",
				"Googol"}));
		
		System.out.println(su.getMin(new String[]{"Yeehaw",
				"NSM",
				"Dont Ask",
				"B9",
				"Googol"}, new String[]{
				"Googol",
				"Dont Ask",
				"NSM",
				"NSM",
				"Yeehaw",
				"Yeehaw",
				"Googol"}));*/
		
		Scanner scan = new Scanner(new File("Input.txt"));
        PrintWriter pw = new PrintWriter("Output.txt");
        Integer count =new Integer(scan.nextLine());
        for (int i=0;i<count;i++){
        	Integer sengs = new Integer(scan.nextLine());
        	String[] engines = new String[sengs];
        	for (int j=0;j<sengs;j++){
        		engines[j]=scan.nextLine();
        	}
        	Integer ss = new Integer(scan.nextLine());
        	String[] queries = new String[ss];
        	for (int j=0;j<ss;j++){
        		queries[j]=scan.nextLine();
        	}
            pw.write("Case #"+(i+1)+": "+su.getMin(engines, queries)+"\n");
        }
        pw.close();
        scan.close();

		
	}
}
