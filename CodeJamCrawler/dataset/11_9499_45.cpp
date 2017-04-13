import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class qualif1 {


	static int rob_last_position[] = {1,1};
	static int rob_completion_time[] = {0,0};
	static int last_robo = -1;
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static int getRobotIndex(String s){
		
		if(s.equalsIgnoreCase("B")){
			return 0;
		}
	

		if(s.equalsIgnoreCase("O")){
			return 1;
		}
		return 100;
	}
	

	
	static int getOtherRob(int rob){
		
		if(rob == 1)
			return 0;
		
		return 1;
	}
	
static int maximum(int a , int b){
	
	if(a>b) return a; 
	return b;
}



static int  runTestCase(String line){
		
		StringTokenizer tkns = new StringTokenizer(line);
		
		int n = Integer.parseInt(tkns.nextToken());
		
		
		int robo;

		robo =getRobotIndex(tkns.nextToken());
		
		int location = Integer.parseInt(tkns.nextToken());
		
		rob_completion_time[robo] = Math.abs(location - rob_last_position[robo]) + 1;
		
		rob_last_position[robo] = location;
		
		last_robo = robo;
		

		
		for(int i=1;i<n;i++){
			
			
			robo =getRobotIndex(tkns.nextToken());
			
			location = Integer.parseInt(tkns.nextToken());
			
			if( last_robo == robo){
			rob_completion_time[robo] += Math.abs(location - rob_last_position[robo]) + 1;
			}else {
				
				int start_time = maximum(rob_completion_time[getOtherRob(robo)],rob_completion_time[robo] +  Math.abs(location - rob_last_position[robo]));
				
				rob_completion_time[robo] = start_time + 1;
				
			}
			
			last_robo = robo;
			rob_last_position[robo] = location;
			
		}
		
		return rob_completion_time[robo];
}


		
	
	public static void main(String a[]) throws IOException{
		
			String line;
	
			line = br.readLine();

			int n_testcases = Integer.parseInt(line);

			
			for (int tc = 0;tc < n_testcases;tc++){

				int rslt = runTestCase(br.readLine());
				clear_counters();
				
				System.out.print("Case #"+(tc+1) + ": "+rslt);
				
				if( tc!= n_testcases - 1)
					System.out.println("");

				
	}

}



	private static void clear_counters() {
		rob_last_position[0] = 1;
		rob_completion_time[0] =0;
		rob_last_position[1] = 1;
		rob_completion_time[1] =0;
		
		last_robo = -1;
				
	}
}