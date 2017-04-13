import java.io.*;

public class Snapper {
	public static void main(String args[]) {

		int T;
		int in[][];
		boolean snappers[][];
		String tmp[];

		try {
			BufferedReader reader = new BufferedReader(new FileReader("A-small-attempt1.in"));
			PrintWriter outputStream = new PrintWriter(new FileOutputStream("out.txt"));

			T = Integer.parseInt(reader.readLine());
			in = new int [T][2];
			snappers = new boolean [T][]; 
			
			for(int i = 0; i < T; i++) {
				tmp = reader.readLine().trim().split(" ");
				in[i][0] = Integer.parseInt(tmp[0]);
				in[i][1] = Integer.parseInt(tmp[1]);
			}
			
			for(int i = 0; i < T; i++) {
				snappers[i] = new boolean [in[i][0]];
				
				for(int j = 0 ; j < in[i][1]; j++) {
					snap(snappers[i], 0);
				}
				//printSnaps(snappers[i]);
			}

			for(int i = 0; i < in.length; i++) {
				outputStream.print("Case #" + (i+1) + ": ");
				
				if(isLight(snappers[i])) {
					outputStream.println("ON");
				}
				else {
					outputStream.println("OFF");
				}
			}
			
			reader.close();
			outputStream.close();
		}
		catch(Exception e) {
			System.out.println("Please don't go here");
		}
		
	}
	
	public static void snap(boolean snappers[], int i) {
		if(!snappers[i]) {
			snappers[i] = true;
		}
		else if(snappers.length == i+1) {
			snappers[snappers.length-1] = false;
		}
		else if(snappers.length > i+1) {
			snap(snappers, i+1);
			snappers[i] = false;
		}
	}

	public static boolean isLight(boolean snappers[]) {
		for(int i = 0; i < snappers.length; i++) {
			if(!snappers[i]) {
				return false;
			}
		}
		return true;
	}

	public static void printSnaps(boolean snappers[]) {
		for(int k = 0; k < snappers.length; k++) {
			if(snappers[k]) {
				System.out.print("1 ");
			}
			else {
				System.out.print("0 ");					
			}
		}
		System.out.println();
	}
}
