import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class SnapperChain{
	

	public static void main(String args[]) throws IOException{
		String inputFileName = "", outputStr = "";
		int n, k, c;
		
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
			outputStr += "Case #" + i + ": ";
			line = br.readLine();
			st = new StringTokenizer(line);
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			/*
			boolean[] state = new boolean[n];
			boolean power;
			for(int j = 0; j < k; j++){
				power = true;
				int p = 0;
				while(p < n && power){
					if(power){
						if(state[p]){
							state[p] = false;
						}else{
							state[p] = true;
							power = false;
						}	
					}
					p++;
				}
			}
			*/
			
			n = (int)Math.pow(2, n); 
			k = k - n + 1;
			k = k % n;
			if(k != 0){
				outputStr += "OFF\n";
			}else{
				outputStr += "ON\n";
			}
			
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