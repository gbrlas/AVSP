import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class ThemePark{
	

	public static void main(String args[]) throws IOException{
		String inputFileName = "", outputStr = "";
		int r, k, n, c, total = 0;
		
		if(args.length != 1){
			System.out.println("Please specify input file name as 1st argument.");
		}else{
			inputFileName = args[0];
		}
		
		FileReader fr = new FileReader(inputFileName);
		BufferedReader br = new BufferedReader(fr);
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		
		c = Integer.parseInt(st.nextToken());
		
		for(int i = 1; i <= c; i++){
			total = 0;
			outputStr += "Case #" + i + ": ";
			line = br.readLine();
			st = new StringTokenizer(line);
			r = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			
			int[] groups = new int[n];
			line = br.readLine();
			st = new StringTokenizer(line);
			for(int j = 0; j < n; j++){
				groups[j] = Integer.parseInt(st.nextToken());
			}
			
			int pos = 0;
			boolean stop;
			int subtotal, start;
			for(int p = 0; p < r; p++){
				subtotal = 0;
				stop = false;
				start = pos;
				while(!stop){
					if(subtotal + groups[pos] <= k){
						subtotal += groups[pos];
						pos++;
						if(pos == n){
							pos = 0;
						}
						if(start == pos){
							stop = true;
						}
					}else{
						stop = true;
					}
				}
				total += subtotal;
			}
			outputStr += total + "\n";
		}
		br.close();
		
		st = new StringTokenizer(inputFileName, ".");
		String outFileName = st.nextToken() + ".out";
		FileWriter fstream = new FileWriter(outFileName);
		BufferedWriter out = new BufferedWriter(fstream);
		//System.out.println(output);
		out.write(outputStr);
		out.close();
	}
	
}