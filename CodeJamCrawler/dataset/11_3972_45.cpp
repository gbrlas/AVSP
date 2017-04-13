import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class BotTrust {

	public static void main(String[] args) {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i=0, T = 0,j=0;
		try {
			T = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int[] time_array = new int[T];
		for (i=0;i<T;i++){
			int O = 1, B = 1, time = 0, Olast = 0, Blast = 0;
			String TC="";
			try {
				TC = br.readLine();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			String []test_cases = TC.split(" ");
			for (j=1;j<test_cases.length;j++){
				if (test_cases[j].equals("O")){
					j++;
					if (Olast >= Math.abs(Integer.parseInt(test_cases[j])-O)){
						Olast=0;
						time++;
						O = Integer.parseInt(test_cases[j]);
						Blast++;
					}
					else{
						time += Math.abs(Integer.parseInt(test_cases[j])-O)-Olast+1;
						Blast += Math.abs(Integer.parseInt(test_cases[j])-O)-Olast+1;
						Olast=0;
						O = Integer.parseInt(test_cases[j]);
					}
				}
				else if (test_cases[j].equals("B")){
					j++;
					if (Blast >= Math.abs(Integer.parseInt(test_cases[j])-B)){
						Blast=0;
						time++;
						B = Integer.parseInt(test_cases[j]);
						Olast++;
					}
					else{
						time += Math.abs(Integer.parseInt(test_cases[j])-B)-Blast+1;
						Olast += Math.abs(Integer.parseInt(test_cases[j])-B)-Blast+1;
						Blast=0;
						B = Integer.parseInt(test_cases[j]);
					}
				}
			}
			time_array[i] = time;
			
		}
		for (i=0;i<T;i++){
			System.out.print("Case #"+(i+1)+": "+time_array[i]);
			System.out.println();
		}
		

	}
	
}
