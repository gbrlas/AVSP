import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

/**
 * 
 * @author "Blake Arnold"
 * 
 */
public class FileFixIt {

	private final static String filename = "A-small-attempt0.in";
	private final static String outFilename = "file-small-out.out";

	public static void main(String[] args) throws IOException,
			InterruptedException {
		
		Scanner sc = new Scanner(new File(filename));
		BufferedWriter out = new BufferedWriter(new FileWriter(outFilename));
		long time = System.currentTimeMillis();
		
		/* read in test size */
		int totalTests = sc.nextInt();
		
		String results[] = new String[totalTests + 1];
		
		/*create threads */
		Thread last[] = new Thread[totalTests + 1];
		
		
		for (int i = 1; i < totalTests + 1; i++) {
			int currentDirNum = sc.nextInt();
			int newDirNum = sc.nextInt();
			
			
			String[] current = new String[currentDirNum];
			for (int j = 0; j < currentDirNum; j++) {
				current[j] = sc.next();
			}
			
			String[] create = new String[newDirNum];
			for (int j = 0; j < newDirNum; j++) {
				create[j] = sc.next();
				
				
			}
			last[i] = new Thread(new findIt(results, i, current, create));
			last[i].start();

		}
		/*reap threads */
		for (int i = 1; i < totalTests + 1; i++) {

			last[i].join();
			System.out.println("reaped " + i);
			System.out.println(results[i]);

		}
		/*write results */
		for (int i = 1; i < totalTests + 1; i++) {

			out.write("Case #" + i + ": ");
			out.write(results[i]);
			out.write("\n");
		}
		System.out.println("Done. " + (System.currentTimeMillis() - time));
		out.close();

	}

	public static int gcd(int a, int b) {
		if (b == 0)
			return a;

		return gcd(b, a % b);
	}
}

class findIt implements Runnable {

	String[] results;
	int i;
	HashMap<String, HashMap> disk;
	String[] current;
	String[] create;

	public findIt(String[] results, int i, String[] current, String[] create) {
		
		this.results = results;
		this.i = i;
		this.current = current;
		this.create = create;
		disk = new HashMap<String, HashMap>();
	}

	@SuppressWarnings("unchecked")
	@Override
	public void run() {

		/* create hash*/
		HashMap<String, HashMap> cur;
		HashMap<String, HashMap> parent;
		for(String c :  current){
			 parent = disk;
			String[] split = c.split("/");
			for(String d :  split){
				if(d != split[0]){
					
			
					cur = parent.get(d);
					
					if(cur == null){
						parent.put(d, new HashMap<String, HashMap>());
						cur = parent.get(d);

				//		System.out.println(i+ "creating: " + d);
						
					}
					parent = cur;
					
				}
				
			}
		}
		int total = 0;
		//System.out.println(i+"--------------");
		for(String c :  create){
			parent = disk;
			String[] split = c.split("/");
			for(String d :  split){
				if(d != split[0]){
					cur = parent.get(d);
					
					if(cur == null){
						parent.put(d, new HashMap<String, HashMap>());
						total++;
						//System.out.println(i+"creating: " + d);
						cur = parent.get(d);
					}
					parent = cur;
					
				}
				
			}
		}
		synchronized (results) {

			results[i] = total + "";

		}

	}

}
