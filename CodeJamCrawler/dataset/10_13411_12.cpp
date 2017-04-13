import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Sub2 {
	int M = 0, N = 0;
	final int One = 1;
	FileWriter out; // = new FileWriter(new File("pro1.out"));
	private boolean RTrue = false;
	private boolean BTrue = false;
	
	LinkedList<String> pathsIHave ;
	LinkedList<String> pathsINeed ;

	public Sub2() {
		try {
			run();
		} catch (Exception e) {
			// System.err.println();
			e.printStackTrace();
		}
	}

	private void run() throws IOException {

		Scanner scan = new Scanner(new File("test.in"));
		out = new FileWriter(new File("pro1.out"));
		int numberOfTestCases = scan.nextInt();

		for (int i = 0; i < numberOfTestCases; i++) {
			N = scan.nextInt();
			M = scan.nextInt();
			pathsIHave = new LinkedList<String>();
			pathsINeed = new LinkedList<String>();
			int all = 0 ;
			for (int j = 0; j < N ; j++) {
				pathsIHave.add(scan.next());
//				System.out.println(pathsIHave.get(j));
			}
//			pathsIHave.add("/");
			
			for (int j = 0; j < M ; j++) {
				pathsINeed.add(scan.next());
			}
			
			for (int j = 0; j < pathsINeed.size(); j++) {
				
				String allPath = pathsINeed.get(j);
				
				String[] dirs = allPath.split("/");
				String path ="";
				for (int k = 0; k < dirs.length; k++) {
					if(!dirs[k].equals("")){
						path += "/" + dirs[k] ; 
						boolean found = checkIfFound(path);
						if(!found){
							all++;
							pathsIHave.add(path);
						}
					}
				}
				
			}

				out.write("Case #"+(i+1)+": "+(all)+"\n");

		}

		out.close();
		scan.close();
	}


	private boolean checkIfFound(String string) {
		
		for (int i = 0; i < pathsIHave.size(); i++) {
			if(string.equals(pathsIHave.get(i))){
				return true ;
			}
		}
		return false;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Sub2();
	}

}
